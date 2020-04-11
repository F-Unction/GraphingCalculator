#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#include "ExDirectUI4.Constant.h"



#pragma warning(disable:4996)

//�������ģʽ,�����ü��ָ��(assert(x)��x��Ϊfalse����ж�)
#ifdef _DEBUG
	#include <assert.h>
	#define EXASSERT(exp) assert(exp)		//���
#else
	#define EXASSERT(exp)
#endif

#define EX_DEFINE_API(NAME,RET,ARGS)	typedef RET (WINAPI* ExPFN_##NAME)ARGS; extern ExPFN_##NAME	NAME					//����һ��API��������,������
#define EX_DECLEAR_API(NAME)			ExPFN_##NAME NAME																	//����һ������ָ�����

#define EX_GET_API(NAME)				NAME = (ExPFN_##NAME) ::GetProcAddress(hModule,#NAME);	EXASSERT(NAME != NULL)		//��ȡ����ָ��

// ����������
typedef UINT32 EXATOM;			// ԭ�Ӻ�
typedef HANDLE EXHANDLE;		// ���
typedef EXHANDLE HEXDUI;		// ������
typedef EXHANDLE HEXLAYOUT;		// ���־��
typedef EXHANDLE HEXTHEME;		// ������
typedef EXHANDLE HEXOBJ;		// �ؼ����
typedef EXHANDLE HEXCANVAS;		// �������
typedef EXHANDLE HEXBRUSH;		// ˢ�Ӿ��
typedef EXHANDLE HEXIMAGE;		// ͼƬ���
typedef EXHANDLE HEXFONT;		// ������
typedef EXHANDLE HEXEASING;		// �������/ָ��
typedef EXHANDLE HEXPATH;		// ·�����


// �ṹ��
struct EXDATA
{
	LPBYTE ptr;		//����ָ��
	size_t len;		//���ݳ���
};
struct EX_NMHDR
{
	HEXOBJ hObjFrom;			// 0	������
	int idFrom;					// 4	���ID
	int nCode;					// 8	֪ͨ��Ϣ
	WPARAM wParam;				// 12	�޷�������	::ͨ����һ������Ϣ�йصĳ���ֵ��Ҳ�����Ǵ��ڻ�ؼ��ľ��
	LPARAM lParam;				// 16	������		::ͨ����һ��ָ���ڴ������ݵ�ָ��
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
	HEXCANVAS hCanvas;		// 0	����
	int hTheme;				// 4	����
	int dwStyle;			// 8	���
	int dwStyleEx;			// 12	��չ���
	int dwTextFormat;		// 16	�ı���ʽ
	int dwState;			// 20	״̬
	int dwOwnerData;		// 24	��������
	int uWidth;				// 28	���
	int uHeight;			// 32	�߶�
	int pLeft;				// 36	���ƾ���::��
	int pTop;				// 40	���ƾ���::��
	int pRight;				// 44	���ƾ���::��
	int pBottom;			// 48	���ƾ���::��
	int tLeft;				// 52	�ı�����::��
	int tTop;				// 56	�ı�����::��
	int tRight;				// 60	�ı�����::��
	int tBottom;			// 64	�ı�����::��
	int dwReserved;			// 68	����
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
	int pEasing;		// 0  ����ָ��
	double nProgress;	// 4  ���� 0-1
	double nCurrent;	// 12 ��ǰֵ
	int pEasingContext;	// 20 ��������
	int nTimesSurplus;	// 24 ʣ����
	int p1;				// 28 ����1
	int p2;				// 32 ����2
	int p3;				// 36 ����3
	int p4;				// 40 ����4
};
#pragma pack()



//����ǹҽӻص��õ�
typedef BOOL(CALLBACK* ExMsgProc)(HWND hWnd, HEXDUI hExDui, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* lpResult);
//����ǹҽӵ�����Ϣ�õ�
typedef int(CALLBACK* ExObjEventHandler)(HEXOBJ hObj, int nID, int nCode, WPARAM wParam, LPARAM lParam);

//��ɫ
typedef UINT32	ARGB, RGB0;	//ARGB��RGB
typedef UINT8	CHANNEL;	//ͨ��

//��ɫ�Ĳ���
#define ExGetB(rgb)			(LOBYTE(rgb))
#define ExGetG(rgb)			(LOBYTE(((WORD)(rgb)) >> 8))
#define ExGetR(rgb)			(LOBYTE((rgb)>>16))
#define ExGetA(rgb)			(LOBYTE((rgb)>>24))
#define ExRGB(r,g,b)        ((RGB0)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((int)(BYTE)(b))<<16)))
#define ExRGBA(r,g,b,a)		((ARGB)(RGB(b,g,r)|(a<<24)))
#define ExARGB(r,g,b)		ExRGBA(r,g,b,0xFF)







//�����ǳ��ù��ܵķ�װ
//�����ﶨ��һ��,����cpp��������  

//��ʼ��ģ��
HMODULE ExEngineInit(LPCWSTR wzDllName);

//�����ļ�
BOOL ExReadAllBytes(LPCWSTR wzFileName, EXDATA* pData);

//�����ͷ�
void ExDataFree(EXDATA* pData);



static BOOL ExReadAllBytes(LPCWSTR wzFileName, EXDATA* pData)
{
	BOOL fOK = FALSE;
	//��������Ч��
	if (wzFileName && pData)
	{
		//���ļ�
		HANDLE hFile = CreateFileW(wzFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile != INVALID_HANDLE_VALUE)
		{
			//ȡ�ļ��ߴ�
			DWORD nSize = GetFileSize(hFile, NULL);
			if (nSize != INVALID_FILE_SIZE)
			{
				//�����ڴ�
				pData->ptr = (LPBYTE)malloc(nSize);
				pData->len = nSize;

				//�����ļ�
				fOK = ReadFile(hFile, pData->ptr, nSize, &nSize, NULL);
			}
			//�ر��ļ�
			CloseHandle(hFile);
		}
	}
	return fOK;
}
static void ExDataFree(EXDATA* pData)
{
	//��������Ч��
	if (pData && pData->ptr)
	{
		//�ͷ��ڴ�
		free(pData->ptr);

		//��սṹ����
		pData->ptr = NULL;
		pData->len = 0;
	}
}

#include "ExDirectUI.Function.h"