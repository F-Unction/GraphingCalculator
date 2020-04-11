#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#include "ExDirectUI4.Constant.h"



#pragma warning(disable:4996)

//如果调试模式,则启用检查指令(assert(x)中x若为false则会中断)
#ifdef _DEBUG
	#include <assert.h>
	#define EXASSERT(exp) assert(exp)		//检查
#else
	#define EXASSERT(exp)
#endif

#define EX_DEFINE_API(NAME,RET,ARGS)	typedef RET (WINAPI* ExPFN_##NAME)ARGS; extern ExPFN_##NAME	NAME					//定义一个API函数类型,并声明
#define EX_DECLEAR_API(NAME)			ExPFN_##NAME NAME																	//声明一个函数指针变量

#define EX_GET_API(NAME)				NAME = (ExPFN_##NAME) ::GetProcAddress(hModule,#NAME);	EXASSERT(NAME != NULL)		//获取函数指针

// 下面是类型
typedef UINT32 EXATOM;			// 原子号
typedef HANDLE EXHANDLE;		// 句柄
typedef EXHANDLE HEXDUI;		// 界面句柄
typedef EXHANDLE HEXLAYOUT;		// 布局句柄
typedef EXHANDLE HEXTHEME;		// 主题句柄
typedef EXHANDLE HEXOBJ;		// 控件句柄
typedef EXHANDLE HEXCANVAS;		// 画布句柄
typedef EXHANDLE HEXBRUSH;		// 刷子句柄
typedef EXHANDLE HEXIMAGE;		// 图片句柄
typedef EXHANDLE HEXFONT;		// 字体句柄
typedef EXHANDLE HEXEASING;		// 缓动句柄/指针
typedef EXHANDLE HEXPATH;		// 路径句柄


// 结构体
struct EXDATA
{
	LPBYTE ptr;		//数据指针
	size_t len;		//数据长度
};
struct EX_NMHDR
{
	HEXOBJ hObjFrom;			// 0	组件句柄
	int idFrom;					// 4	组件ID
	int nCode;					// 8	通知消息
	WPARAM wParam;				// 12	无符号整数	::通常是一个与消息有关的常量值，也可能是窗口或控件的句柄
	LPARAM lParam;				// 16	长整型		::通常是一个指向内存中数据的指针
};
struct RECTF
{
	float left;
	float top;
	float right;
	float bottom;
};
struct EX_CUSTOMDRAW {
	HEXCANVAS hCanvas;
	int hTheme;
	int dwState;
	int dwStyle;
	int left;
	int top;
	int right;
	int bottom;
	int iItem;
	int iItemParam;
};


struct EX_PAINTSTRUCT2
{
	HEXCANVAS hCanvas;		// 0	画布
	int hTheme;				// 4	主题
	int dwStyle;			// 8	风格
	int dwStyleEx;			// 12	扩展风格
	int dwTextFormat;		// 16	文本格式
	int dwState;			// 20	状态
	int dwOwnerData;		// 24	所有数据
	int uWidth;				// 28	宽度
	int uHeight;			// 32	高度
	int pLeft;				// 36	绘制矩形::左
	int pTop;				// 40	绘制矩形::顶
	int pRight;				// 44	绘制矩形::右
	int pBottom;			// 48	绘制矩形::底
	int tLeft;				// 52	文本矩形::左
	int tTop;				// 56	文本矩形::顶
	int tRight;				// 60	文本矩形::右
	int tBottom;			// 64	文本矩形::底
	int dwReserved;			// 68	保留
};
struct EX_BITMAPDATA {
	int Width;
	int Height;
	int Stride;
	int PixelFormat;
	int Scan0;
	int Reserved;
};
#pragma pack(1)
struct EX_EASINGINFO
{
	int pEasing;		// 0  缓动指针
	double nProgress;	// 4  进度 0-1
	double nCurrent;	// 12 当前值
	int pEasingContext;	// 20 缓动参数
	int nTimesSurplus;	// 24 剩余数
	int p1;				// 28 参数1
	int p2;				// 32 参数2
	int p3;				// 36 参数3
	int p4;				// 40 参数4
};
#pragma pack()



//这个是挂接回调用的
typedef BOOL(CALLBACK* ExMsgProc)(HWND hWnd, HEXDUI hExDui, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
//这个是挂接单个消息用的
typedef int(CALLBACK* ExObjEventHandler)(HEXOBJ hObj, int nID, int nCode, WPARAM wParam, LPARAM lParam);

//颜色
typedef UINT32	ARGB, RGB0;	//ARGB和RGB
typedef UINT8	CHANNEL;	//通道

//颜色的操作
#define ExGetB(rgb)			(LOBYTE(rgb))
#define ExGetG(rgb)			(LOBYTE(((WORD)(rgb)) >> 8))
#define ExGetR(rgb)			(LOBYTE((rgb)>>16))
#define ExGetA(rgb)			(LOBYTE((rgb)>>24))
#define ExRGB(r,g,b)        ((RGB0)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((int)(BYTE)(b))<<16)))
#define ExRGBA(r,g,b,a)		((ARGB)(RGB(b,g,r)|(a<<24)))
#define ExARGB(r,g,b)		ExRGBA(r,g,b,0xFF)







//下面是常用功能的封装
//在这里定义一下,其他cpp就能用了  

//初始化模块
HMODULE ExEngineInit(LPCWSTR wzDllName);

//读入文件
BOOL ExReadAllBytes(LPCWSTR wzFileName, EXDATA* pData);

//数据释放
void ExDataFree(EXDATA* pData);



static BOOL ExReadAllBytes(LPCWSTR wzFileName, EXDATA* pData)
{
	BOOL fOK = FALSE;
	//检查参数有效性
	if (wzFileName && pData)
	{
		//打开文件
		HANDLE hFile = CreateFileW(wzFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile != INVALID_HANDLE_VALUE)
		{
			//取文件尺寸
			DWORD nSize = GetFileSize(hFile, NULL);
			if (nSize != INVALID_FILE_SIZE)
			{
				//申请内存
				pData->ptr = (LPBYTE)malloc(nSize);
				pData->len = nSize;

				//读入文件
				fOK = ReadFile(hFile, pData->ptr, nSize, &nSize, NULL);
			}
			//关闭文件
			CloseHandle(hFile);
		}
	}
	return fOK;
}
static void ExDataFree(EXDATA* pData)
{
	//检查参数有效性
	if (pData && pData->ptr)
	{
		//释放内存
		free(pData->ptr);

		//清空结构变量
		pData->ptr = NULL;
		pData->len = 0;
	}
}

#include "ExDirectUI.Function.h"