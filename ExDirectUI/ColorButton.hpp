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
//------------------
#define COLOR_EX_CBTN_CRBKG_NORMAL  100
#define COLOR_EX_CBTN_CRBKG_HOVER  101
#define COLOR_EX_CBTN_CRBKG_DOWN  102
#define COLOR_EX_CBTN_CRBKG_FOCUS  103
#define EOUL_CBTN_CRBKG_NORMAL  0
#define EOUL_CBTN_CRBKG_HOVER  1
#define EOUL_CBTN_CRBKG_DOWN  2
#define EOUL_CBTN_CRBKG_FOCUS  3
//------------------
bool CALLBACK _colorbutton_proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
int _colorbutton_paint(HEXOBJ hObj);
//------------------
 void _colorbutton_register()
{
	WCHAR wzCls[] = L"ColorButton";
	Ex_ObjRegister(wzCls, EOS_VISIBLE, EOS_EX_TABSTOP | EOS_EX_FOCUSABLE, DT_SINGLELINE | DT_CENTER | DT_VCENTER, 16, 0, 0, (ExMsgProc)&_colorbutton_proc);
	/*
	额外16字节尺寸包含以下数据:
	(内存偏移,成员名称,索引偏移)
	0 crBkgNormal 0
	4 crBkgHover 1
	8 crBkgDown 2
	8 crBkgFocus 3
	*/
}

bool CALLBACK _colorbutton_proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{
	if (uMsg == WM_MOUSEHOVER)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_点燃, false, 0, true);
	}
	else if (uMsg == WM_MOUSELEAVE)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_点燃, true, 0, true);
	}
	else if (uMsg == WM_LBUTTONDOWN)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_按下, false, 0, true);
	}
	else if (uMsg == WM_LBUTTONUP)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_按下, true, 0, true);
	}
	else if (uMsg == WM_SETFOCUS)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_焦点, false, 0, true);
	}
	else if (uMsg == WM_KILLFOCUS)
	{
		Ex_ObjSetUIState((HEXOBJ)hObj, 状态_焦点, true, 0, true);
	}
	else if (uMsg == WM_PAINT)
	{
		return (_colorbutton_paint(hObj));
	}
	else if (uMsg == WM_SYSCOLORCHANGE)
	{
		if (wParam == COLOR_EX_CBTN_CRBKG_NORMAL)
		{
			Ex_ObjSetLong(hObj, EOUL_CBTN_CRBKG_NORMAL, lParam);
		}
		else if (wParam == COLOR_EX_CBTN_CRBKG_HOVER)
		{
			Ex_ObjSetLong(hObj, EOUL_CBTN_CRBKG_HOVER, lParam);
		}
		else if (wParam == COLOR_EX_CBTN_CRBKG_DOWN)
		{
			Ex_ObjSetLong(hObj, EOUL_CBTN_CRBKG_DOWN, lParam);
		}
		else if (wParam == COLOR_EX_CBTN_CRBKG_FOCUS)
		{
			Ex_ObjSetLong(hObj, EOUL_CBTN_CRBKG_FOCUS, lParam);
		}
	}
	return (Ex_ObjDefProc(hWnd, hObj, uMsg, wParam, lParam));
}

int _colorbutton_paint(HEXOBJ hObj)
{
	EX_PAINTSTRUCT2 ps;
	int crBkg = 0, crText = 0;
	if (Ex_ObjBeginPaint(hObj, &ps))
	{
		if ((ps.dwState & 状态_按下) == 状态_按下)
		{
			crText = Ex_ObjGetColor(hObj, COLOR_EX_TEXT_DOWN);
			crBkg = Ex_ObjGetLong(hObj, EOUL_CBTN_CRBKG_DOWN);
		}
		else if ((ps.dwState & 状态_点燃) == 状态_点燃)
		{
			crText = Ex_ObjGetColor(hObj, COLOR_EX_TEXT_HOVER);
			crBkg = Ex_ObjGetLong(hObj, EOUL_CBTN_CRBKG_HOVER);
		}
		else if ((ps.dwState & 状态_焦点) == 状态_焦点)
		{
			crText = Ex_ObjGetColor(hObj, COLOR_EX_TEXT_FOCUS);
			crBkg = Ex_ObjGetLong(hObj, EOUL_CBTN_CRBKG_FOCUS);
		}

		if (crBkg == 0)
		{
			crBkg = Ex_ObjGetLong(hObj, EOUL_CBTN_CRBKG_NORMAL);
		}
		if (crText == 0)
		{
			crText = Ex_ObjGetColor(hObj, COLOR_EX_TEXT_NORMAL);
		}

		_canvas_clear(ps.hCanvas, crBkg);
		_canvas_drawtext(ps.hCanvas, Ex_ObjGetFont(hObj), crText, (LPCWSTR)Ex_ObjGetLong(hObj, EOL_LPWZTITLE), -1, ps.dwTextFormat, 0, 0, ps.uWidth + 0.0f, ps.uHeight + 0.0f);

		Ex_ObjEndPaint(hObj, &ps);
	}
	return 0;
}
