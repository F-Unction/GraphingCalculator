#include "../help/ExDirectUI4.h"
//------------------
HEXIMAGE hImgLeft = NULL;
HEXOBJ hObj1, hObj2, hObj3, hObj4;
WCHAR wzStatic2[] = L"Static";

//------------------
BOOL CALLBACK hObj1Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
BOOL CALLBACK hObj2Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
//------------------
void ColorPickerCreate(HEXOBJ hParent)
{
	hObj1 = Ex_ObjCreateEx(EOS_EX_TABSTOP, wzStatic2, 0, -1, 2, 2, 150, 150, hParent, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 1, -1, 0, 0, (ExMsgProc)&hObj1Proc);
	hObj2 = Ex_ObjCreateEx(EOS_EX_TABSTOP, wzStatic2, 0, -1, 153, 2, 20, 150, hParent, Ex_ObjGetLong(hParent, EOL_ID) * 2 + 2, -1, 0, 0, (ExMsgProc)&hObj2Proc);
	if(hObj2!=NULL)
	{
		EXDATA imgRight;
		ExReadAllBytes(L".\imgRight",&imgRight);
		Ex_ObjSetBackgroundImage(hObj2, (int)imgRight.ptr, imgRight.len, 0, 0, BIR_DEFALUT, 0, -1, 255, true);
	}
	/*
	hObj3 = Ex_ObjCreateEx(-1, 取指针_字节集型(bin), 0, -1, 0, 0, 20, 4, hObj2, Ex_ObjGetLong(句柄, #EOL_ID) ＋ 3, -1, 0, 0, 0)
		Ex_ObjSetBackgroundImage(hObj3, 取指针_字节集型(#颜色选择器滑块), 取字节集长度(#颜色选择器滑块), 0, 0, #BIR_DEFALUT, 0, -1, 255, 真)
		hObj4 = Ex_ObjCreateEx(-1, 取指针_字节集型(bin), 0, -1, 0, 0, 14, 14, hObj1, Ex_ObjGetLong(句柄, #EOL_ID) ＋ 4, -1, 0, 0, 0)
		Ex_ObjSetBackgroundImage(hObj4, 取指针_字节集型(#颜色选择器选择块), 取字节集长度(#颜色选择器选择块), 0, 0, #BIR_DEFALUT, 0, -1, 255, 真)
		a = hObj1
		b = hObj2
		c = hObj3
		d = hObj4
		渐变条位图.创建(20, 150, 32, )
		渐变条位图.载入数据(#颜色选择器渐变条)
		*/
}

BOOL CALLBACK hObj1Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{

	return FALSE;
}

BOOL CALLBACK hObj2Proc(HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult)
{

	return FALSE;
}
