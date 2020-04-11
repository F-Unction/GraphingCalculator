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
short isChanging;
extern double DPI;
int color, rightColor, leftX = 0, leftY = 0, rightY = 0;
int LeftColors[150][150] = { 0 }, RightColors[] = { -55802,-55784,-55512,-55242,-55230,-54961,-54694,-54683,-54416,-53894,-53885,-53362,-53097,-52831,-52310,-52044,-51523,-51515,-50994,-50730,-50208,-49944,-49424,-48903,-48897,-442113,-1032193,-1556737,-2146817,-2671361,-3326977,-3851521,-4441345,-5031169,-5621249,-6277121,-6932481,-7588097,-8177921,-8833537,-9620225,-10209793,-10930945,-11717377,-12569601,-13356033,-14208001,-15125761,-16174081,-16436225,-16500993,-16564993,-16628481,-16757505,-16755457,-16752641,-16750593,-16748033,-16745729,-16743425,-16741121,-16738817,-16736769,-16734465,-16732161,-16729857,-16727809,-16725761,-16723457,-16721665,-16719361,-16717569,-16715265,-16713473,-16712196,-16712461,-16712469,-16712477,-16712742,-16712494,-16712759,-16712767,-16712777,-16712786,-16713051,-16712804,-16713070,-16713079,-16713090,-16713100,-16713110,-16713121,-16713389,-16713400,-16713413,-16713426,-16713441,-16713202,-16713472,-16713216,-16713472,-16713472,-15927040,-14026496,-12912128,-11929088,-11077120,-10225152,-9504256,-8783360,-8128000,-7341568,-6686208,-6030848,-5506560,-4851200,-4195584,-3606016,-3081472,-2426112,-1836544,-1312000,-722176,-132096,-2560,-4352,-6400,-8704,-10752,-12800,-14848,-17152,-19456,-21760,-24064,-26112,-28672,-30720,-33024,-35584,-38144,-40448,-42752,-45824,-48128,-50432,-52736,-54784,-449024,-16777216 };
LPBYTE imgLeft;
HEXOBJ hObj1, hObj2, hObj3, hObj4;
WCHAR wzStatic2[] = L"Static";

//------------------
BOOL CALLBACK hObj1Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
BOOL CALLBACK hObj2Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
void draw1(int x, int y);
void draw2(int y);
extern void ColorPickerFunc(int changer);
void GetRGBfromColor(int Color, unsigned char* R, unsigned char* G, unsigned char* B);
//------------------
void ColorPickerCreate(HEXOBJ hParent)
{
	hObj1 = Ex_ObjCreateEx(EOS_EX_TABSTOP | EOS_EX_CUSTOMDRAW, wzStatic2, NULL, -1, 2, 2, 150, 150, hParent, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 1, -1, NULL, NULL, (ExMsgProc)&hObj1Proc);
	hObj2 = Ex_ObjCreateEx(EOS_EX_TABSTOP, wzStatic2, NULL, -1, 153, 2, 20, 150, hParent, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 2, -1, NULL, NULL, (ExMsgProc)&hObj2Proc);
	if (hObj2 != NULL)
	{
		EXDATA imgRight;
		ExReadAllBytes(L"./res/imgRight.png", &imgRight);
		Ex_ObjSetBackgroundImage(hObj2, (int)imgRight.ptr, imgRight.len, 0, 0, BIR_DEFALUT, 0, -1, 255, true);
	}
	hObj3 = Ex_ObjCreateEx(-1, wzStatic2, NULL, -1, 0, 0, 20, 4, hObj2, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 3, -1, NULL, NULL, NULL);
	if (hObj3 != NULL)
	{
		EXDATA imgSlider;
		ExReadAllBytes(L"./res/imgSlider.png", &imgSlider);
		Ex_ObjSetBackgroundImage(hObj3, (int)imgSlider.ptr, imgSlider.len, 0, 0, BIR_DEFALUT, 0, -1, 255, true);
	}
	hObj4 = Ex_ObjCreateEx(-1, wzStatic2, 0, -1, -7, -7, 14, 14, hObj1, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 4, -1, NULL, NULL, NULL);
	if (hObj4 != NULL)
	{
		EXDATA imgBigSlider;
		ExReadAllBytes(L"./res/imgBigSlider.png", &imgBigSlider);
		Ex_ObjSetBackgroundImage(hObj4, (int)imgBigSlider.ptr, imgBigSlider.len, 0, 0, BIR_DEFALUT, 0, -1, 255, true);
	}
}

void ColorPickerInit(int leftx, int lefty, int righty, short changer)
{
	isChanging = changer;
	draw2(righty);
	draw1(leftx, lefty);
}

void draw1(int x, int y)
{
	Ex_ObjMove(hObj4, x - 7, y - 7, 14, 14, true);
	color = LeftColors[x][y];
	leftX = x;
	leftY = y;
	ColorPickerFunc(isChanging);
}

void draw2(int y)
{
	Ex_ObjMove(hObj3, 0, y - 1, 20, 4, true);
	rightColor = RightColors[y + 1];
	Ex_ObjSendMessage(hObj1, WM_PAINT, 0, 0);
	rightY = y;
	draw1(leftX, leftY);
	ColorPickerFunc(isChanging);
}

BOOL CALLBACK hObj1Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{
	EX_PAINTSTRUCT2 ps;
	static bool down = false;
	if (uMsg == WM_PAINT)
	{
		Ex_ObjBeginPaint(hObj, &ps);
		_canvas_clear(ps.hCanvas, ExRGBA(0, 0, 0, 255));
		HEXBRUSH br;
		unsigned char Color1R, Color1G, Color1B, Color2R = 255, Color2G = 255, Color2B = 255, Color3R = 0, Color3G = 0, Color3B = 0, R, B, G;
		double Color1Per, Color2Per, Color3Per, Color4Per;
		int ans;
		GetRGBfromColor(rightColor, &Color1B, &Color1G, &Color1R);

		for (int x = 1; x <= 150; x++)
		{
			Color1Per = x / 150.0;
			Color2Per = 1 - Color1Per;
			R = Color1R * Color1Per + Color2R * Color2Per;
			G = Color1G * Color1Per + Color2G * Color2Per;
			B = Color1B * Color1Per + Color2B * Color2Per;
			for (int y = 1; y <= 150; y++)
			{
				Color3Per = y / 150.0;
				Color4Per = 1 - Color3Per;
				ans = ExRGBA(R * Color3Per + Color3R * Color4Per, G * Color3Per + Color3R * Color4Per, B * Color3Per + Color3B * Color4Per, 255);
				LeftColors[x - 1][150 - y] = ans;
				br = _brush_create(ans);
				_canvas_fillrect(ps.hCanvas, br, int(x * DPI) + 0.5, int((150 - y) * DPI) + 0.5, int(x * DPI) - 0.5, int((150 - y) * DPI) - 0.5);
				_brush_destroy(br);
			}
		}
		Ex_ObjEndPaint(hObj, &ps);
	}
	if (uMsg == WM_MOUSEMOVE)
	{
		int x = LOWORD(lParam) / DPI, y = HIWORD(lParam) / DPI;
		if (down && x > 0 && x < 150 && y > 0 && y < 150)
		{
			draw1(x, y);
		}
	}
	else if (uMsg == WM_LBUTTONDOWN)
	{
		int x = LOWORD(lParam) / DPI, y = HIWORD(lParam) / DPI;
		if (x > 0 && x < 150 && y > 0 && y < 150)
		{
			down = true;
			draw1(x, y);
		}
	}
	else if (uMsg == WM_LBUTTONUP)
	{
		down = false;
	}
	return FALSE;
}

BOOL CALLBACK hObj2Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{
	static bool down;
	if (uMsg == WM_MOUSEMOVE)
	{
		int y = HIWORD(lParam) / DPI;
		if (down && y > 0 && y < 148)
		{
			draw2(y);
		}
	}
	else if (uMsg == WM_LBUTTONDOWN)
	{
		int y = HIWORD(lParam) / DPI;
		if (y > 0 && y < 150)
		{
			down = true;
			draw2(y);
		}
	}
	else if (uMsg == WM_LBUTTONUP)
	{
		down = false;
	}
	return FALSE;
}

void GetRGBfromColor(int Color, unsigned char* R, unsigned char* G, unsigned char* B)
{
	*R = *(byte*)&Color;
	*G = *((byte*)&Color + 1);
	*B = *((byte*)&Color + 2);
}
