/*
	  <GraphingCalculator. A software for drawing function image.>
	Copyright (C) 2020  F_Unction

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "../help/ExDirectUI4.h"
#include "ColorButton.hpp"
#include "ColorPicker.hpp"
#include "Tools.hpp"
#include "ExpressionCalculating.h"
#include <vector>

//------------------
BOOL CALLBACK WindowProc(HWND hWnd, HEXDUI hExDui, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK PaintStaticProc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
BOOL CALLBACK ListViewProc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
void ColorPickerFunc(int changer);
void PaintFunc();
//------------------
bool opened = false;
int sclected = 0, textColor = 0, bkgColor = 0, axisColor = 0, xLeft[4] = { 0,0,0,0 }, yLeft[4] = { 149,149,149,0 }, yRight[4] = { 1,1,1,1 }, clr[4] = { ExRGBA(2,2,2,255),ExRGBA(2,2,2,255),ExRGBA(2,2,2,255),ExRGBA(254,253,253,255) }, aa = -1, Width, Heigth, mouseX, mouseY;
vector<string> function;
vector<ListItem> listItems;
WCHAR wzStatic[] = L"Static";
HWND hWnd;
HEXDUI hExDui;
HEXLAYOUT hLayout;
double DPI, viewX, viewY, rMouseX, rMouseY, sc = 0.1;
HEXOBJ hObj, hPaintStatic, hSetColorStatic, hBackgroundColorStatic, hTextColorStatic, hAxisColorStatic, hColorPiclerStatic, hEdit, hListView, hRemoveButton, hBackButton;
//------------------
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hInstancePrev, _In_ LPWSTR wzCmd, _In_ int nCmdShow)
{
	BOOL CONSOLE = FALSE;
	if (CONSOLE)
	{
		AllocConsole();
		FILE* fp = freopen("CONOUT$", "w", stdout);
	}
	//------------------
	// Begin
	HMODULE hMod = ExEngineInit(L"./lib/libexdui.dll");
	if (hMod)
	{
		EXDATA Theme;
		ExReadAllBytes(L"./res/Default.ext", &Theme);
		Ex_Init(GetModuleHandle(NULL), EXGF_RENDER_METHOD_D2D_GDI_COMPATIBLE | EXGF_DPI_ENABLE, NULL, NULL, Theme.ptr, Theme.len, NULL, 0);
		ExDataFree(&Theme);
		//------------------
		_colorbutton_register();
		//------------------
		hWnd = Ex_WndCreate(NULL, NULL, L"函数画板 - 按F1显示提示", NULL, NULL, 920, 610, NULL, NULL);
		if (hWnd != NULL)
		{
			DPI = GetDPI(hWnd);
			hExDui = Ex_DUIBindWindowEx(hWnd, NULL, EWS_TITLE | EWS_HASICON | EWS_MAINWINDOW | EWS_CENTERWINDOW | EWS_SIZEABLE | EWS_BUTTON_CLOSE | EWS_BUTTON_MAX | EWS_BUTTON_MIN, NULL, (ExMsgProc)&WindowProc);
			if (hExDui != NULL)
			{
				Ex_DUISetLong(hExDui, EWL_CRBKG, ExRGBA(221, 221, 221, 255));
				Ex_ObjSetColor(Ex_ObjGetFromID(hExDui, EWS_TITLE), COLOR_EX_BACKGROUND, ExRGBA(221, 221, 221, 255), true);
				Ex_ObjSetColor(Ex_ObjGetFromID(hExDui, EWS_TITLE), COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
				Ex_ObjSetFont(Ex_ObjGetFromID(hExDui, EWS_TITLE), _font_createfromfamily(NULL, 13, NULL), true);
				//------------------
				hLayout = _layout_create(ELT_ABSOLUTE, hExDui);
				if (hLayout != NULL)
				{
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_CLOSE), ELCP_ABSOLUTE_RIGHT, ELCP_ABSOLUTE_TYPE_PX, 1);
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_MAX), ELCP_ABSOLUTE_RIGHT, ELCP_ABSOLUTE_TYPE_PX, 47);
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_MIN), ELCP_ABSOLUTE_RIGHT, ELCP_ABSOLUTE_TYPE_PX, 93);
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_CLOSE), ELCP_ABSOLUTE_TOP, ELCP_ABSOLUTE_TYPE_PX, 1);
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_MAX), ELCP_ABSOLUTE_TOP, ELCP_ABSOLUTE_TYPE_PX, 1);
					_layout_absolute_setedge(hLayout, Ex_ObjGetFromID(hExDui, EWS_BUTTON_MIN), ELCP_ABSOLUTE_TOP, ELCP_ABSOLUTE_TYPE_PX, 1);
					//------------------
					hPaintStatic = Ex_ObjCreateEx(EOS_EX_FOCUSABLE, wzStatic, NULL, -1, 0, 0, 50, 50, hExDui, 103, -1, NULL, NULL, (ExMsgProc)&PaintStaticProc);
					if (hPaintStatic != NULL)
					{
						Ex_ObjSetColor(hPaintStatic, COLOR_EX_BACKGROUND, ExRGBA(0, 0, 0, 255), true);
						Ex_ObjSetColor(hPaintStatic, COLOR_EX_TEXT_NORMAL, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetTimer(hPaintStatic, 17);
						_layout_absolute_setedge(hLayout, hPaintStatic, ELCP_ABSOLUTE_LEFT, ELCP_ABSOLUTE_TYPE_PX, 240);//65
						_layout_absolute_setedge(hLayout, hPaintStatic, ELCP_ABSOLUTE_TOP, ELCP_ABSOLUTE_TYPE_PX, 31);
						_layout_absolute_setedge(hLayout, hPaintStatic, ELCP_ABSOLUTE_RIGHT, ELCP_ABSOLUTE_TYPE_PX, 0);
						_layout_absolute_setedge(hLayout, hPaintStatic, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 0);
					}

					hObj = Ex_ObjCreateEx(-1, wzStatic, L"  y = ", -1, 0, 30, 30, 31, hExDui, 104, -1, NULL, NULL, NULL);
					if (hObj != NULL)
					{
						Ex_ObjSetColor(hObj, COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
						Ex_ObjSetColor(hObj, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
					}

					hSetColorStatic = Ex_ObjCreateEx(EOS_EX_FOCUSABLE, wzStatic, L"颜色", -1, 210, 30, 30, 31, hExDui, 105, DT_CENTER | DT_VCENTER, NULL, NULL, NULL);
					if (hSetColorStatic != NULL)
					{
						Ex_ObjSetColor(hSetColorStatic, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
						Ex_ObjSetColor(hSetColorStatic, COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
					}

					hBackgroundColorStatic = Ex_ObjCreateEx(EOS_EX_FOCUSABLE, wzStatic, L"背景颜色", -1, 0, 0, 80, 30, hExDui, 106, DT_CENTER | DT_VCENTER, NULL, NULL, NULL);
					if (hBackgroundColorStatic != NULL)
					{
						_layout_absolute_setedge(hLayout, hBackgroundColorStatic, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 32);
						Ex_ObjSetColor(hBackgroundColorStatic, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
						Ex_ObjSetColor(hBackgroundColorStatic, COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
					}

					hTextColorStatic = Ex_ObjCreateEx(EOS_EX_FOCUSABLE, wzStatic, L"坐标颜色", -1, 80, 0, 80, 30, hExDui, 107, DT_CENTER | DT_VCENTER, NULL, NULL, NULL);
					if (hTextColorStatic != NULL)
					{
						_layout_absolute_setedge(hLayout, hTextColorStatic, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 32);
						Ex_ObjSetColor(hTextColorStatic, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
					}

					hAxisColorStatic = Ex_ObjCreateEx(EOS_EX_FOCUSABLE, wzStatic, L"坐标轴颜色", -1, 160, 0, 80, 30, hExDui, 108, DT_CENTER | DT_VCENTER, NULL, NULL, NULL);
					if (hAxisColorStatic != NULL)
					{
						_layout_absolute_setedge(hLayout, hAxisColorStatic, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 32);
						Ex_ObjSetColor(hAxisColorStatic, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
						Ex_ObjSetColor(hAxisColorStatic, COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
					}
					//------------------
					WCHAR wzEdit[] = L"Edit";
					hEdit = Ex_ObjCreateEx(EOS_EX_COMPOSITED | EOS_EX_FOCUSABLE | EOS_EX_CUSTOMDRAW, wzEdit, NULL, 编辑框风格_总是显示提示文本 | EOS_VISIBLE, 25, 29, 186 , 34, hExDui, 109, DT_SINGLELINE | DT_VCENTER, NULL, NULL, NULL);
					if (hEdit != NULL)
					{
						Ex_ObjSetColor(hEdit, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
						Ex_ObjSetColor(hEdit, COLOR_EX_TEXT_NORMAL, ExRGBA(0, 0, 0, 255), true);
						Ex_ObjSetFontFromFamily(hEdit, NULL, 13, -1, true);
						Ex_ObjSendMessage(hEdit, 21, COLOR_EX_EDIT_CARET, ExRGBA(0, 0, 0, 255));
						Ex_ObjSendMessage(hEdit, EM_SETCUEBANNER, ExRGBA(0, 0, 0, 127), (LPARAM)L"表达式");
					}
					//------------------
					WCHAR wzListView[] = L"ListView";
					hListView = Ex_ObjCreateEx(-1, wzListView, NULL, -1, 0, 61, 240, 0, hExDui, 110, -1, NULL, NULL, (ExMsgProc)&ListViewProc);
					if (hListView != NULL)
					{
						Ex_ObjSetColor(hListView, COLOR_EX_BACKGROUND, ExRGBA(221, 221, 221, 255), true);
						_layout_absolute_setedge(hLayout, hListView, ELCP_ABSOLUTE_TOP, ELCP_ABSOLUTE_TYPE_PX, 61);
						_layout_absolute_setedge(hLayout, hListView, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 62);
					}
					//------------------
					WCHAR wzColorButton[] = L"ColorButton";
					hRemoveButton = Ex_ObjCreateEx(-1, wzColorButton, L"删除", -1, 0, 0, 120, 32, hExDui, 111, -1, NULL, NULL, NULL);
					if (hRemoveButton != 0)
					{
						Ex_ObjSetFont(hRemoveButton, _font_createfromfamily(NULL, 12, NULL), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_CBTN_CRBKG_NORMAL, ExRGBA(198, 40, 40, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_CBTN_CRBKG_HOVER, ExRGBA(230, 64, 64, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_CBTN_CRBKG_DOWN, ExRGBA(183, 28, 28, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_TEXT_NORMAL, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_TEXT_FOCUS, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_TEXT_HOVER, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hRemoveButton, COLOR_EX_TEXT_DOWN, ExRGBA(255, 255, 255, 255), true);
						_layout_absolute_setedge(hLayout, hRemoveButton, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 0);
						_layout_absolute_setedge(hLayout, hRemoveButton, ELCP_ABSOLUTE_LEFT, ELCP_ABSOLUTE_TYPE_PX, 120);
					}

					hBackButton = Ex_ObjCreateEx(-1, wzColorButton, L"复位", -1, 0, 0, 120, 32, hExDui, 112, -1, NULL, NULL, NULL);
					if (hBackButton != 0)
					{
						Ex_ObjSetFont(hBackButton, _font_createfromfamily(NULL, 12, NULL), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_CBTN_CRBKG_NORMAL, ExRGBA(0, 120, 212, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_CBTN_CRBKG_HOVER, ExRGBA(30, 150, 252, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_CBTN_CRBKG_DOWN, ExRGBA(0, 90, 158, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_TEXT_NORMAL, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_TEXT_FOCUS, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_TEXT_HOVER, ExRGBA(255, 255, 255, 255), true);
						Ex_ObjSetColor(hBackButton, COLOR_EX_TEXT_DOWN, ExRGBA(255, 255, 255, 255), true);
						_layout_absolute_setedge(hLayout, hBackButton, ELCP_ABSOLUTE_BOTTOM, ELCP_ABSOLUTE_TYPE_PX, 0);
					}
					//------------------
					hColorPiclerStatic = Ex_ObjCreateEx(-1, wzStatic, NULL, -1, 200, 50, 175, 154, hExDui, 113, -1, NULL, NULL, NULL);
					if (hColorPiclerStatic != NULL)
					{
						Ex_ObjShow(hColorPiclerStatic, false);
						Ex_ObjSetColor(hColorPiclerStatic, COLOR_EX_BACKGROUND, ExRGBA(208, 208, 208, 255), true);
						ColorPickerCreate(hColorPiclerStatic);
						ColorPickerInit(0, 150, 0, 1);
					}
					//------------------
					Ex_ObjLayoutSet(hWnd, hLayout, true);
				}
				Ex_DUIShowWindow(hExDui, SW_SHOW, NULL, NULL, NULL);
				//------------------
				viewX = Width / 2 * 0.1;
				viewY = Heigth / 2 * 0.1;
			}
			Ex_WndMsgLoop();
			Ex_UnInit();
		}
		// End
		//------------------
		if (CONSOLE)
		{
			fclose(stdout);
			FreeConsole();
		}
	}
	return 0;
}

BOOL CALLBACK WindowProc(HWND hWnd, HEXDUI hExDui, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	EX_NMHDR* ni;
	static bool changeSysButton;
	static int changeSysButtonTag;
	//------------------
	if (uMsg == WM_NOTIFY)
	{
		ni = (EX_NMHDR*)lParam;
		if (ni->nCode == NM_CLICK)
		{
			if (ni->hObjFrom != hObj1 && ni->hObjFrom != hObj2 && ni->hObjFrom != hObj3 && ni->hObjFrom != hObj4 && opened && ni->hObjFrom != hListView)
			{
				Ex_ObjShow(hColorPiclerStatic, false);
				opened = false;
				if (aa != -1)
				{
					xLeft[aa] = leftX;
					yLeft[aa] = leftY;
					yRight[aa] = rightY;
					aa = -1;
					return TRUE;
				}
			}
			if (ni->hObjFrom == hBackButton)
			{
				sc = 0.1;
				viewX = Width / 2 * 0.1;
				viewY = Heigth / 2 * 0.1;
			}
			else if (ni->hObjFrom == hRemoveButton && sclected != 0)
			{
				vector<ListItem>::iterator it = listItems.begin();
				if (sclected > listItems.size())
				{
					sclected = 0;
				}
				for (int i = 1; i < sclected; i++)
				{
					it++;
				}
				if (sclected > listItems.size())
				{
					sclected = 0;
				}
				if (sclected != 0)
				{
					listItems.erase(it);
				}
				Ex_ObjSendMessage(hListView, WM_PAINT, 0, 0);
			}
			else if (ni->hObjFrom == hListView && sclected != 0)
			{
				aa = -1;
				ColorPickerInit(listItems[sclected - 1].x1, listItems[sclected - 1].y1, listItems[sclected - 1].y2, 0);
				Ex_ObjMove(hColorPiclerStatic, LOWORD(ni->lParam), HIWORD(ni->lParam) + 61, 175, 154, true);
				Ex_ObjShow(hColorPiclerStatic, !opened);
				opened = !opened;
			}
			else if (ni->hObjFrom == hSetColorStatic)
			{
				aa = 0;
				ColorPickerInit(xLeft[0], yLeft[0], yRight[0], 1);
				Ex_ObjMove(hColorPiclerStatic, LOWORD(ni->lParam) + 145, HIWORD(ni->lParam) + 31, 175, 154, true);
				opened = !opened;
				Ex_ObjShow(hColorPiclerStatic, true);
				return TRUE;
			}
			else if (ni->hObjFrom == hTextColorStatic)
			{
				aa = 1;
				ColorPickerInit(xLeft[1], yLeft[1], yRight[1], 1);
				Ex_ObjMove(hColorPiclerStatic, LOWORD(ni->lParam) + 58, HIWORD(ni->lParam) + Ex_ObjGetTop(hTextColorStatic) - 154, 175, 154, true);
				opened = !opened;
				Ex_ObjShow(hColorPiclerStatic, opened);
			}
			else if (ni->hObjFrom == hAxisColorStatic)
			{
				aa = 2;
				ColorPickerInit(xLeft[2], yLeft[2], yRight[2], 1);
				Ex_ObjMove(hColorPiclerStatic, LOWORD(ni->lParam) + 117, HIWORD(ni->lParam) + Ex_ObjGetTop(hAxisColorStatic) - 154, 175, 154, true);
				opened = !opened;
				Ex_ObjShow(hColorPiclerStatic, opened);
			}
			else if (ni->hObjFrom == hBackgroundColorStatic)
			{
				aa = 3;
				ColorPickerInit(xLeft[3], yLeft[3], yRight[3], 1);
				Ex_ObjMove(hColorPiclerStatic, LOWORD(ni->lParam), HIWORD(ni->lParam) + Ex_ObjGetTop(hBackgroundColorStatic) - 154, 175, 154, true);
				opened = !opened;
				Ex_ObjShow(hColorPiclerStatic, opened);
			}
			return TRUE;
		}
		else if (ni->nCode == NM_TIMER)
		{
			Ex_ObjSendMessage(hPaintStatic, WM_PAINT, 0, 0);
			return TRUE;
		}
		else if (ni->nCode == NM_KEYDOWN)
		{
			if (ni->hObjFrom == hEdit && LOWORD(ni->wParam) == VK_RETURN)
			{
				int len = Ex_ObjGetTextLength(hEdit);
				LPCWSTR text = (LPWSTR)new WCHAR[len + 10];
				Ex_ObjGetText(hEdit, text, len + 1);
				if (text != L"")
				{
					AddListItem(text, clr[0], 1, xLeft[0], yLeft[0], yRight[0]);
					Ex_ObjSendMessage(hListView, LVM_SETITEMCOUNT, listItems.size(), listItems.size());
					Ex_ObjSetText(hEdit, NULL, true);
				}
			}
			else if (LOWORD(ni->wParam) == VK_F1)
			{
				MessageBox(hWnd,
					LR"(1) 表达式
 ·支持小数表示（如23.22）
 ·支持浮点表示（如2.322e1）
 ·支持任意层括号嵌套
 ·支持常量PI和E
 ·支持的运算符有 + -*/ % ^
 ·支持的函数有sin cos tan arcsin arccos arctan lg(求以十为低的对数) ln(求自然对数) log(求对数 需要两个参数) sqrt(求次方) abs(取模) int(取整) rand(取随机数 接受两个参数作为范围)
 ·自变量用小写x表示 建议加括号
2) 操作
 ·在“表达式”编辑框内输入数学表达式 按回车添加 点击颜色可以设置将添加函数的颜色
 ·点击左侧列表框任意表项 可设置该项颜色 选中后点击删除按钮 可删除此表项
 ·鼠标在右侧渲染框内拖动和滚轮可移动和缩放视角
 ·点击复位按钮可以使渲染框回到最初的视角和缩放
					)", L"提示", 0);
			}
		}
	}
	return FALSE;
}

BOOL CALLBACK PaintStaticProc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{
	int lx, ly;
	double ls;
	RECT tmp;
	if (uMsg == WM_PAINT)
	{
		PaintFunc();
	}
	if (uMsg == WM_MOUSEWHEEL)
	{
		ls = sc;
		sc *= pow(0.995, (short)HIWORD(wParam) / 10);
		viewX += mouseX * (sc - ls);
		viewY += mouseY * (sc - ls);
	}
	else if (uMsg == WM_MOUSEMOVE)
	{
		lx = mouseX;
		ly = mouseY;
		mouseX = (short)LOWORD(lParam) / DPI;
		mouseY = (short)HIWORD(lParam) / DPI;
		if (LOWORD(wParam) == 1)
		{
			viewX = viewX + (mouseX - lx) * sc;
			viewY = viewY + (mouseY - ly) * sc;
		}
		rMouseX = (mouseX - viewX / sc) * sc / 1;
		rMouseY = (mouseY - viewY / sc) * sc / 1;
	}
	return FALSE;
}

BOOL CALLBACK ListViewProc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{
	EX_NMHDR* ni;
	EX_CUSTOMDRAW* cd;
	HEXBRUSH  hBr;
	int crItemBkg = 0;
	if (uMsg == WM_NOTIFY)
	{
		ni = (EX_NMHDR*)lParam;
		if (ni->nCode == NM_CALCSIZE)
		{
			*(int*)((byte*)ni->lParam + 4) = 25;
			*lpResult = 1;
			return TRUE;
		}
		else if (ni->nCode == NM_CUSTOMDRAW)
		{
			cd = (EX_CUSTOMDRAW*)(ni->lParam);
			if (cd->iItem > 0 && cd->iItem <= listItems.size())
			{
				if ((状态_选择 & cd->dwState) != 0)
				{
					crItemBkg = ExRGBA(179, 179, 179, 255);
				}
				else if ((状态_点燃 & cd->dwState) != 0)
				{
					crItemBkg = ExRGBA(213, 213, 213, 255);
				}
				if (crItemBkg != 0)
				{
					hBr = _brush_create(crItemBkg);
					_canvas_fillrect(cd->hCanvas, hBr, cd->left + 0.5, cd->top - 0.5, cd->right + 0.5, cd->bottom - 0.5);
					_brush_destroy(hBr);
				}
				const wchar_t* s = listItems[cd->iItem - 1].text.c_str();
				_canvas_drawtext(cd->hCanvas, Ex_ObjGetFont(hObj), listItems[cd->iItem - 1].color, (LPWSTR)s, -1, DT_SINGLELINE | DT_VCENTER, cd->left + listItems[cd->iItem - 1].depth * 5, cd->top, cd->right, cd->bottom);
			}
			*lpResult = 1;
			return TRUE;
		}
		else if (ni->nCode == LVN_ITEMCHANGED)
		{
			sclected = ni->wParam;
			if (sclected == 0)
			{
				Ex_ObjShow(hColorPiclerStatic, false);
				opened = false;
				if (aa != -1)
				{
					xLeft[aa] = leftX;
					yLeft[aa] = leftY;
					yRight[aa] = rightY;
					aa = -1;
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

void ColorPickerFunc(int changer)
{
	if (aa != -1)
	{
		clr[aa] = color;
	}
	else if (opened && sclected != 0)
	{
		listItems[sclected - 1].color = color;
		listItems[sclected - 1].x1 = leftX;
		listItems[sclected - 1].y1 = leftY;
		listItems[sclected - 1].y2 = rightY;
	}
	Ex_ObjSendMessage(hPaintStatic, WM_PAINT, 0, 0);
	Ex_ObjSendMessage(hListView, WM_PAINT, 0, 0);
}

void PaintFunc()
{
	double y, newy, x, newx, xadd;
	string exp;
	HEXBRUSH hBr;
	EX_PAINTSTRUCT2 ps;
	RECT PaintStaticRect;
	Ex_ObjGetRect(hPaintStatic, &PaintStaticRect);
	Width = PaintStaticRect.right - PaintStaticRect.left;
	Heigth = PaintStaticRect.bottom - PaintStaticRect.top;
	Ex_ObjBeginPaint(hPaintStatic, &ps);
	_canvas_clear(ps.hCanvas, clr[3]);
	hBr = _brush_create(clr[2]);
	_canvas_drawline(ps.hCanvas, hBr, -1 * sc * DPI, viewY / sc * DPI, Width * DPI, viewY / sc * DPI, 1, 0);
	_canvas_drawline(ps.hCanvas, hBr, viewX / sc * DPI, -1 / sc * DPI, viewX / sc * DPI, Heigth * DPI, 1, 0);
	_canvas_drawline(ps.hCanvas, hBr, mouseX * DPI, mouseY * DPI, mouseX * DPI, viewY / sc * DPI, 1, 0);
	_canvas_drawline(ps.hCanvas, hBr, mouseX * DPI, mouseY * DPI, viewX / sc * DPI, mouseY * DPI, 1, 0);
	for (vector<ListItem>::iterator it = listItems.begin(); it != listItems.end(); it++)
	{
		bool isSuccess = false;
		_brush_setcolor(hBr, (*it).color);
		xadd = 1 * sc;
		x = -1 * viewX - 2 * xadd;

		exp = allreplace(wstring2string((*it).text), "x", to_string(x));
		expCalculate(exp, y);
		y = y * -1;
		for (int i = 1; i <= Width; i++)
		{
			newx = x + xadd;
			if (newx >= 0)
			{
				exp = allreplace(wstring2string((*it).text), "x", "(" + to_string(x) + ")");
				isSuccess = expCalculate(exp, newy);
				newy *= -1;
			}
			else
			{
				exp = allreplace(wstring2string((*it).text), "x", "(0-" + to_string(-x) + ")");
				isSuccess = expCalculate(exp, newy);
				newy *= -1;
			}
			if (isSuccess)
			{
				_canvas_drawline(ps.hCanvas, hBr, (newx + viewX) / sc * DPI, (newy + viewY) / sc * DPI, (x + viewX) / sc * DPI, (y + viewY) / sc * DPI, 1, 0);
			}
			x = newx;
			y = newy;
		}
	}
	wstring str = L"(" + to_wstring(rMouseX) + L", " + to_wstring(-rMouseY) + L")";
	const wchar_t* s = str.c_str();

	_canvas_drawtext(ps.hCanvas, Ex_ObjGetFont(hPaintStatic), clr[1], (LPCWSTR)s, -1, 0 | DT_SINGLELINE, mouseX* DPI, mouseY* DPI, (mouseX + Width)* DPI, (mouseY + Heigth)* DPI);
	_brush_destroy(hBr);
	Ex_ObjEndPaint(hPaintStatic, &ps);
}
