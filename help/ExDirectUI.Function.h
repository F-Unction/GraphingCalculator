#pragma once


//======================================================
// �������ƣ�Ex_Init
// �������ͣ�BOOL
// ����˵������ʼ������.
// ����<1>��hInstance, HINSTANCE, (ֵ��Ϊ0)
// ����<2>��dwGlobalFlags, int, ��س���:#EXGF_ .(ֵ��Ϊ0)
// ����<3>��hDefaultCursor, int, Ĭ�����ָ��.(ֵ��Ϊ0)
// ����<4>��lpszDefaultClassName, int, Ĭ�ϴ�������.(ֵ��Ϊ0)
// ����<5>��lpDefaultTheme, LPBYTE, Ĭ�������ָ��.
// ����<6>��dwDefaultThemeLen, size_t, Ĭ�����������.
// ����<7>��lpDefaultI18N, int, Ĭ�����԰�ָ��.(ֵ��Ϊ0)
// ����<8>��dwDefaultI18NLen, int, Ĭ�����԰�����.(ֵ��Ϊ0)
//======================================================
EX_DEFINE_API(Ex_Init, BOOL, (HINSTANCE hInstance, int dwGlobalFlags, int hDefaultCursor, int lpszDefaultClassName, LPBYTE lpDefaultTheme, size_t dwDefaultThemeLen, int lpDefaultI18N, int dwDefaultI18NLen));

//======================================================
// �������ƣ�Ex_UnInit
// �������ͣ�void
// ����˵��������ʼ������
//======================================================
EX_DEFINE_API(Ex_UnInit, void, ());

//======================================================
// �������ƣ�Ex_GetLastError
// �������ͣ�int
// ����˵������ȡ���������.��س��� :#ERROR_EX_
//======================================================
EX_DEFINE_API(Ex_GetLastError, int, ());

//======================================================
// �������ƣ�_img_createfrommemory
// �������ͣ�int
// ����˵�����������ڴ档�ɹ�����0��
// ����<1>��lpData, LPBYTE, ͼ��ָ��
// ����<2>��dwLen, size_t, ͼ�񳤶�
// ����<3>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfrommemory, int, (LPBYTE lpData, size_t dwLen, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_create
// �������ͣ�int
// ����˵��������ͼ�񡣳ɹ�����0��
// ����<1>��width, int, ͼ����
// ����<2>��height, int, ͼ��߶�
// ����<3>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_create, int, (int width, int height, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_lock
// �������ͣ�int
// ����˵��������ͼ��.�ɹ�����0.
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��lpRectL, int, ��������ָ�룬���Ϊ0������������ͼ��
// ����<3>��flags, int, READ:1 / WRITE:2 / READ&WRITE:3
// ����<4>��PixelFormat, int, �ο�:https://msdn.microsoft.com/en-us/library/ms534412(v=vs.85).aspx
// ����<5>��lpLockedBitmapData, EX_BITMAPDATA*, BITMAPDATA
//======================================================
EX_DEFINE_API(_img_lock, int, (HEXIMAGE hImg, int lpRectL, int flags, int PixelFormat, EX_BITMAPDATA* lpLockedBitmapData));

//======================================================
// �������ƣ�_img_unlock
// �������ͣ�int
// ����˵��������ͼ��.�ɹ�����0.
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��lpLockedBitmapData, EX_BITMAPDATA*, 
//======================================================
EX_DEFINE_API(_img_unlock, int, (HEXIMAGE hImg, EX_BITMAPDATA* lpLockedBitmapData));

//======================================================
// �������ƣ�_img_destroy
// �������ͣ�int
// ����˵��������ͼ��
// ����<1>��hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_destroy, int, (HEXIMAGE hImg));

//======================================================
// �������ƣ�Ex_SetLastError
// �������ͣ�void
// ����˵�����������������.��س��� :#ERROR_EX_
// ����<1>��nError, int, 
//======================================================
EX_DEFINE_API(Ex_SetLastError, void, (int nError));

//======================================================
// �������ƣ�_img_getframecount
// �������ͣ�int
// ����˵����ȡͼ��֡�����ɹ�����0��
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��nFrameCount, int, ����֡��.
//======================================================
EX_DEFINE_API(_img_getframecount, int, (HEXIMAGE hImg, int nFrameCount));

//======================================================
// �������ƣ�_img_selectactiveframe
// �������ͣ�int
// ����˵�������õ�ǰ�֡���ɹ�����0��
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��nIndex, int, 
//======================================================
EX_DEFINE_API(_img_selectactiveframe, int, (HEXIMAGE hImg, int nIndex));

//======================================================
// �������ƣ�_img_createfromstream
// �������ͣ�int
// ����˵�����������ֽ������ɹ�����0��
// ����<1>��lpStream, int, 
// ����<2>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromstream, int, (int lpStream, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_createfromcanvas
// �������ͣ�int
// ����˵����(����)�����Ի������ɹ�����0��
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromcanvas, int, (HEXCANVAS hCanvas, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_getframedelay
// �������ͣ�int
// ����˵����ȡͼ��֡��ʱ���ɹ�����0��
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��lpDelayAry, int, ָ��ָ��ͼ��֡��ʱ���顣
// ����<3>��nFrames, int, ������֡��
//======================================================
EX_DEFINE_API(_img_getframedelay, int, (HEXIMAGE hImg, int lpDelayAry, int nFrames));

//======================================================
// �������ƣ�_img_getsize
// �������ͣ�int
// ����˵������ȡͼ��ߴ�.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��lpWidth, int*, 
// ����<3>��lpHeight, int*, 
//======================================================
EX_DEFINE_API(_img_getsize, int, (HEXIMAGE hImg, int* lpWidth, int* lpHeight));

//======================================================
// �������ƣ�Ex_IsDxRender
// �������ͣ�BOOL
// ����˵�����Ƿ�ʹ��D2D��Ⱦ
//======================================================
EX_DEFINE_API(Ex_IsDxRender, BOOL, ());

//======================================================
// �������ƣ�_img_width
// �������ͣ�int
// ����˵�������ؿ��
// ����<1>��hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_width, int, (HEXIMAGE hImg));

//======================================================
// �������ƣ�_img_height
// �������ͣ�int
// ����˵�������ظ߶�
// ����<1>��hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_height, int, (HEXIMAGE hImg));

//======================================================
// �������ƣ�_img_copy
// �������ͣ�int
// ����˵��������ͼ��.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��dstImg, HEXIMAGE, ������ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_copy, int, (HEXIMAGE hImg, HEXIMAGE dstImg));

//======================================================
// �������ƣ�_img_copyrect
// �������ͣ�int
// ����˵�������Ʋ���ͼ��.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��x, int, 
// ����<3>��y, int, 
// ����<4>��width, int, 
// ����<5>��height, int, 
// ����<6>��dstImg, HEXIMAGE, ������ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_copyrect, int, (HEXIMAGE hImg, int x, int y, int width, int height, HEXIMAGE dstImg));

//======================================================
// �������ƣ�_img_createfromhbitmap
// �������ͣ�int
// ����˵����������GDIλͼ������ɹ�����0��
// ����<1>��hBitmap, int, 
// ����<2>��hPalette, int, 
// ����<3>��fPreAlpha, BOOL, �Ƿ�Ԥ��͸��ͨ��
// ����<4>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromhbitmap, int, (int hBitmap, int hPalette, BOOL fPreAlpha, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_createfromhicon
// �������ͣ�int
// ����˵����������ͼ�������ɹ�����0��
// ����<1>��hIcon, int, 
// ����<2>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromhicon, int, (int hIcon, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_createfromfile
// �������ͣ�int
// ����˵�����������ļ����ɹ�����0��
// ����<1>��wzFilename, LPCWSTR, 
// ����<2>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromfile, int, (LPCWSTR wzFilename, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_img_getpixel
// �������ͣ�int
// ����˵������ȡ������,�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��x, int, 
// ����<3>��y, int, 
// ����<4>��color, int, ����ARGB��ɫ
//======================================================
EX_DEFINE_API(_img_getpixel, int, (HEXIMAGE hImg, int x, int y, int color));

//======================================================
// �������ƣ�_img_setpixel
// �������ͣ�int
// ����˵�������õ�����.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��x, int, 
// ����<3>��y, int, 
// ����<4>��color, int, argb
//======================================================
EX_DEFINE_API(_img_setpixel, int, (HEXIMAGE hImg, int x, int y, int color));

//======================================================
// �������ƣ�_img_rotateflip
// �������ͣ�int
// ����˵������ת��תͼ��.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��rfType, int, �ο�:https://msdn.microsoft.com/en-us/library/windows/desktop/ms534171(v=vs.85).aspx
//======================================================
EX_DEFINE_API(_img_rotateflip, int, (HEXIMAGE hImg, int rfType));

//======================================================
// �������ƣ�_img_getthumbnail
// �������ͣ�int
// ����˵����ȡ����ͼ.�ɹ�����0
// ����<1>��hImg, HEXIMAGE, 
// ����<2>��thumbWidth, int, 
// ����<3>��thumbHeight, int, 
// ����<4>��hImgThumbnail, int, ��������ͼͼ��ָ��
//======================================================
EX_DEFINE_API(_img_getthumbnail, int, (HEXIMAGE hImg, int thumbWidth, int thumbHeight, int hImgThumbnail));

//======================================================
// �������ƣ�_canvas_resize
// �������ͣ�BOOL
// ����˵�����������óߴ硣
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��width, int, 
// ����<3>��height, int, 
// ����<4>��fCopy, BOOL, 
//======================================================
EX_DEFINE_API(_canvas_resize, BOOL, (HEXCANVAS hCanvas, int width, int height, BOOL fCopy));

//======================================================
// �������ƣ�_canvas_getcontext
// �������ͣ�int
// ����˵������ȡcanvas�����������Ϣ
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��nType, int, #CVC_
//======================================================
EX_DEFINE_API(_canvas_getcontext, int, (HEXCANVAS hCanvas, int nType));

//======================================================
// �������ƣ�Ex_DUIBindWindowEx
// �������ͣ�HEXDUI
// ����˵�����󶨴���,�ɹ�����������,ʧ�ܷ���0.
// ����<1>��hWnd, HWND, ���ھ��
// ����<2>��hTheme, int, ������.(ֵ��Ϊ0)
// ����<3>��dwStyle, DWORD, ��س���:#EWS_
// ����<4>��lParam, LPARAM, ���Ӳ���.(ֵ��Ϊ0)
// ����<5>��lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
//======================================================
EX_DEFINE_API(Ex_DUIBindWindowEx, HEXDUI, (HWND hWnd, int hTheme, DWORD dwStyle, LPARAM lParam, ExMsgProc lpfnMsgProc));

//======================================================
// �������ƣ�_canvas_createfromobj
// �������ͣ�int
// ����˵�����������������������ɹ����ػ��������ʧ�ܷ���0
// ����<1>��hObj, HEXOBJ, 
// ����<2>��uWidth, int, 
// ����<3>��uHeight, int, 
// ����<4>��dwFlags, int, CVF_
// ����<5>��nError, int, 
//======================================================
EX_DEFINE_API(_canvas_createfromobj, int, (HEXOBJ hObj, int uWidth, int uHeight, int dwFlags, int nError));

//======================================================
// �������ƣ�Ex_WndRegisterClass
// �������ͣ�int
// ����˵����ע�ᴰ����
// ����<1>��lpwzClassName, LPCWSTR, 
// ����<2>��hIcon, int, 
// ����<3>��hIconsm, int, 
// ����<4>��hCursor, int, 
//======================================================
EX_DEFINE_API(Ex_WndRegisterClass, int, (LPCWSTR lpwzClassName, int hIcon, int hIconsm, int hCursor));

//======================================================
// �������ƣ�Ex_WndCreate
// �������ͣ�HWND
// ����˵������������
// ����<1>��hWndParent, int, 
// ����<2>��lpwzClassName, LPCWSTR, 
// ����<3>��lpwzWindowName, LPCWSTR, 
// ����<4>��x, int, 
// ����<5>��y, int, 
// ����<6>��Width, int, 
// ����<7>��Height, int, 
// ����<8>��dwStyle, DWORD, 
// ����<9>��dwStyleEx, DWORD, 
//======================================================
EX_DEFINE_API(Ex_WndCreate, HWND, (int hWndParent, LPCWSTR lpwzClassName, LPCWSTR lpwzWindowName, int x, int y, int Width, int Height, DWORD dwStyle, DWORD dwStyleEx));

//======================================================
// �������ƣ�Ex_WndMsgLoop
// �������ͣ�int
// ����˵����������Ϣѭ��
//======================================================
EX_DEFINE_API(Ex_WndMsgLoop, int, ());

//======================================================
// �������ƣ�Ex_WndCenterFrom
// �������ͣ�void
// ����˵�������ھ���
// ����<1>��hWnd, HWND, Ԥ���е�ԭʼ����
// ����<2>��hWndFrom, int, Ԥ���е�Ŀ�괰��,���Ϊ0��Ϊ��Ļ����.
// ����<3>��bFullScreen, BOOL, �Ƿ�ȫ��ģʽ
//======================================================
EX_DEFINE_API(Ex_WndCenterFrom, void, (HWND hWnd, int hWndFrom, BOOL bFullScreen));

//======================================================
// �������ƣ�Ex_DUIShowWindow
// �������ͣ�BOOL
// ����˵������ʾ����
// ����<1>��hExDui, HEXDUI, ������
// ����<2>��nCmdShow, int, ��س���:#SW_
// ����<3>��dwTimer, int, ����ʱ����.(ms)
// ����<4>��dwFrames, int, ������֡��.
// ����<5>��dwFlags, int, �������.#EXA_
//======================================================
EX_DEFINE_API(Ex_DUIShowWindow, BOOL, (HEXDUI hExDui, int nCmdShow, int dwTimer, int dwFrames, int dwFlags));

//======================================================
// �������ƣ�Ex_DUIShowWindowEx
// �������ͣ�BOOL
// ����˵������ʾ����
// ����<1>��hExDui, HEXDUI, ������
// ����<2>��nCmdShow, int, ��س���:#SW_
// ����<3>��dwTimer, int, ����ʱ����.(ms)
// ����<4>��dwFrames, int, ������֡��.
// ����<5>��dwFlags, int, �������.#EXA_
// ����<6>��uEasing, int, #��������_
// ����<7>��wParam, WPARAM, ����1
// ����<8>��lParam, LPARAM, ����2
//======================================================
EX_DEFINE_API(Ex_DUIShowWindowEx, BOOL, (HEXDUI hExDui, int nCmdShow, int dwTimer, int dwFrames, int dwFlags, int uEasing, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�_canvas_destroy
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_destroy, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�_canvas_enddraw
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_enddraw, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�_canvas_clear
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��lColor, int, 
//======================================================
EX_DEFINE_API(_canvas_clear, BOOL, (HEXCANVAS hCanvas, int lColor));

//======================================================
// �������ƣ�_canvas_getdc
// �������ͣ�int
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_getdc, int, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�_canvas_releasedc
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_releasedc, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�_canvas_drawimage
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 0
// ����<2>��hImage, HEXIMAGE, 4
// ����<3>��left, float, 8
// ����<4>��top, float, 12
// ����<5>��alpha, int, 16
//======================================================
EX_DEFINE_API(_canvas_drawimage, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float left, float top, int alpha));

//======================================================
// �������ƣ�_canvas_drawimagerect
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hImage, HEXIMAGE, 
// ����<3>��left, float, 
// ����<4>��top, float, 
// ����<5>��right, float, 
// ����<6>��bottom, float, 
// ����<7>��alpha, int, 
//======================================================
EX_DEFINE_API(_canvas_drawimagerect, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float left, float top, float right, float bottom, int alpha));

//======================================================
// �������ƣ�_canvas_drawimagerectrect
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 0
// ����<2>��hImage, HEXIMAGE, 4
// ����<3>��dstLeft, float, 8
// ����<4>��dstTop, float, 12
// ����<5>��dstRight, float, 16
// ����<6>��dstBottom, float, 20
// ����<7>��srcLeft, float, 24
// ����<8>��srcTop, float, 28
// ����<9>��srcRight, float, 32
// ����<10>��srcBottom, float, 36
// ����<11>��alpha, int, 40
//======================================================
EX_DEFINE_API(_canvas_drawimagerectrect, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float dstLeft, float dstTop, float dstRight, float dstBottom, float srcLeft, float srcTop, float srcRight, float srcBottom, int alpha));

//======================================================
// �������ƣ�_canvas_drawimagefromgrid
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hImage, HEXIMAGE, 
// ����<3>��dstLeft, float, 
// ����<4>��dstTop, float, 
// ����<5>��dstRight, float, 
// ����<6>��dstBottom, float, 
// ����<7>��srcLeft, float, 
// ����<8>��srcTop, float, 
// ����<9>��srcRight, float, 
// ����<10>��srcBottom, float, 
// ����<11>��gridPaddingLeft, float, 
// ����<12>��gridPaddingTop, float, 
// ����<13>��gridPaddingRight, float, 
// ����<14>��gridPaddingBottom, float, 
// ����<15>��dwFlags, int, #bif_
// ����<16>��dwAlpha, int, 
//======================================================
EX_DEFINE_API(_canvas_drawimagefromgrid, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float dstLeft, float dstTop, float dstRight, float dstBottom, float srcLeft, float srcTop, float srcRight, float srcBottom, float gridPaddingLeft, float gridPaddingTop, float gridPaddingRight, float gridPaddingBottom, int dwFlags, int dwAlpha));

//======================================================
// �������ƣ�Ex_ObjDefProc
// �������ͣ�int
// ����˵�������Ĭ�Ϲ���
// ����<1>��hWnd, HWND, 
// ����<2>��hObj, HEXOBJ, 
// ����<3>��uMsg, UINT, 
// ����<4>��wParam, WPARAM, 
// ����<5>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDefProc, int, (HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�_canvas_fillrect
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��left, float, 
// ����<4>��top, float, 
// ����<5>��right, float, 
// ����<6>��bottom, float, 
//======================================================
EX_DEFINE_API(_canvas_fillrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom));

//======================================================
// �������ƣ�_brush_create
// �������ͣ�HEXBRUSH
// ����˵����
// ����<1>��argb, int, 
//======================================================
EX_DEFINE_API(_brush_create, HEXBRUSH, (int argb));

//======================================================
// �������ƣ�_brush_destroy
// �������ͣ�int
// ����˵����
// ����<1>��hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_brush_destroy, int, (HEXBRUSH hBrush));

//======================================================
// �������ƣ�_canvas_drawrect
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��left, float, 
// ����<4>��top, float, 
// ����<5>��right, float, 
// ����<6>��bottom, float, 
// ����<7>��strokeWidth, float, 
// ����<8>��strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float strokeWidth, int strokeStyle));

//======================================================
// �������ƣ�_canvas_drawroundedrect
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��left, float, 
// ����<4>��top, float, 
// ����<5>��right, float, 
// ����<6>��bottom, float, 
// ����<7>��radiusX, float, 
// ����<8>��radiusY, float, 
// ����<9>��strokeWidth, float, 
// ����<10>��strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawroundedrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float radiusX, float radiusY, float strokeWidth, int strokeStyle));

//======================================================
// �������ƣ�_canvas_fillroundedrect
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��left, float, 
// ����<4>��top, float, 
// ����<5>��right, float, 
// ����<6>��bottom, float, 
// ����<7>��radiusX, float, 
// ����<8>��radiusY, float, 
//======================================================
EX_DEFINE_API(_canvas_fillroundedrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float radiusX, float radiusY));

//======================================================
// �������ƣ�_canvas_drawellipse
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��x, float, 
// ����<4>��y, float, 
// ����<5>��radiusX, float, 
// ����<6>��radiusY, float, 
// ����<7>��strokeWidth, float, 
// ����<8>��strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawellipse, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float x, float y, float radiusX, float radiusY, float strokeWidth, int strokeStyle));

//======================================================
// �������ƣ�_canvas_fillellipse
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��x, float, 
// ����<4>��y, float, 
// ����<5>��radiusX, float, 
// ����<6>��radiusY, float, 
//======================================================
EX_DEFINE_API(_canvas_fillellipse, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float x, float y, float radiusX, float radiusY));

//======================================================
// �������ƣ�_canvas_drawline
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hBrush, HEXBRUSH, 
// ����<3>��X1, float, 
// ����<4>��Y1, float, 
// ����<5>��X2, float, 
// ����<6>��Y2, float, 
// ����<7>��strokeWidth, float, 
// ����<8>��strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawline, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float X1, float Y1, float X2, float Y2, float strokeWidth, int strokeStyle));

//======================================================
// �������ƣ�Ex_ObjRegister
// �������ͣ�int
// ����˵����ע�����.ʧ�ܷ���0
// ����<1>��lptszClassName, LPCWSTR, �������.���������:MAX_CLASS_NAME_LEN
// ����<2>��dwStyle, DWORD, ���Ĭ�Ϸ��
// ����<3>��dwStyleEx, DWORD, ���Ĭ����չ���
// ����<4>��dwTextFormat, int, ��س��� DT_
// ����<5>��cbObjExtra, int, �����������ֽ���(ֵ��Ϊ0)
// ����<6>��hCursor, int, ���Ĭ�����ָ����(ֵ��Ϊ0)
// ����<7>��dwFlags, int, ���־ #ECF_(ֵ��Ϊ0)
// ����<8>��pfnObjProc, ExMsgProc, ���Ĭ�ϻص�
//======================================================
EX_DEFINE_API(Ex_ObjRegister, int, (LPCWSTR lptszClassName, DWORD dwStyle, DWORD dwStyleEx, int dwTextFormat, int cbObjExtra, int hCursor, int dwFlags, ExMsgProc pfnObjProc));

//======================================================
// �������ƣ�Ex_ObjCreate
// �������ͣ�HEXOBJ
// ����˵�����������.
// ����<1>��lptszClassName, LPCWSTR, �������
// ����<2>��lptszObjTitle, LPCWSTR, �������
// ����<3>��dwStyle, DWORD, ������ ��س��� EOS_
// ����<4>��x, int, ���
// ����<5>��y, int, ����
// ����<6>��width, int, ���
// ����<7>��height, int, �߶�
// ����<8>��hParent, EXHANDLE, ��������
//======================================================
EX_DEFINE_API(Ex_ObjCreate, HEXOBJ, (LPCWSTR lptszClassName, LPCWSTR lptszObjTitle, DWORD dwStyle, int x, int y, int width, int height, EXHANDLE hParent));

//======================================================
// �������ƣ�Ex_ObjCreateEx
// �������ͣ�HEXOBJ
// ����˵�����������.
// ����<1>��dwStyleEx, DWORD, �����չ��� ��س��� EOS_EX_
// ����<2>��lptszClassName, LPCWSTR, �������
// ����<3>��lptszObjTitle, LPCWSTR, �������
// ����<4>��dwStyle, DWORD, ������ ��س��� EOS_
// ����<5>��x, int, ���
// ����<6>��y, int, ����
// ����<7>��width, int, ���
// ����<8>��height, int, �߶�
// ����<9>��hParent, EXHANDLE, ��������
// ����<10>��nID, int, 
// ����<11>��dwTextFormat, int, ��س��� DT_
// ����<12>��lParam, LPARAM, ���Ӳ���
// ����<13>��hTheme, int, ������.0ΪĬ��
// ����<14>��lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hObj,uMsg,wParam,lParam,lpReturn).
//======================================================
EX_DEFINE_API(Ex_ObjCreateEx, HEXOBJ, (DWORD dwStyleEx, LPCWSTR lptszClassName, LPCWSTR lptszObjTitle, DWORD dwStyle, int x, int y, int width, int height, EXHANDLE hParent, int nID, int dwTextFormat, LPARAM lParam, int hTheme, ExMsgProc lpfnMsgProc));

//======================================================
// �������ƣ�Ex_Scale
// �������ͣ�float
// ����˵����
// ����<1>��n, float, 
//======================================================
EX_DEFINE_API(Ex_Scale, float, (float n));

//======================================================
// �������ƣ�_rgn_createfromrect
// �������ͣ�int
// ����˵����
// ����<1>��left, float, 
// ����<2>��top, float, 
// ����<3>��right, float, 
// ����<4>��bottom, float, 
//======================================================
EX_DEFINE_API(_rgn_createfromrect, int, (float left, float top, float right, float bottom));

//======================================================
// �������ƣ�_rgn_createfromroundrect
// �������ͣ�int
// ����˵����
// ����<1>��left, float, 
// ����<2>��top, float, 
// ����<3>��right, float, 
// ����<4>��bottom, float, 
// ����<5>��radiusX, float, 
// ����<6>��radiusY, float, 
//======================================================
EX_DEFINE_API(_rgn_createfromroundrect, int, (float left, float top, float right, float bottom, float radiusX, float radiusY));

//======================================================
// �������ƣ�_rgn_destroy
// �������ͣ�BOOL
// ����˵����
// ����<1>��hRgn, int, 
//======================================================
EX_DEFINE_API(_rgn_destroy, BOOL, (int hRgn));

//======================================================
// �������ƣ�_rgn_combine
// �������ͣ�int
// ����˵����
// ����<1>��hRgnSrc, int, 
// ����<2>��hRgnDst, int, 
// ����<3>��nCombineMode, int, #RGN_COMBINE_
// ����<4>��dstOffsetX, int, 
// ����<5>��dstOffsetY, int, 
//======================================================
EX_DEFINE_API(_rgn_combine, int, (int hRgnSrc, int hRgnDst, int nCombineMode, int dstOffsetX, int dstOffsetY));

//======================================================
// �������ƣ�_canvas_fillregion
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hRgn, int, 
// ����<3>��hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_canvas_fillregion, BOOL, (HEXCANVAS hCanvas, int hRgn, HEXBRUSH hBrush));

//======================================================
// �������ƣ�_rgn_hittest
// �������ͣ�BOOL
// ����˵����
// ����<1>��hRgn, int, 
// ����<2>��x, float, 
// ����<3>��y, float, 
//======================================================
EX_DEFINE_API(_rgn_hittest, BOOL, (int hRgn, float x, float y));

//======================================================
// �������ƣ�Ex_ObjDestroy
// �������ͣ�int
// ����˵�����������
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjDestroy, int, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjSendMessage
// �������ͣ�int
// ����˵����������Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��uMsg, UINT, 
// ����<3>��wParam, WPARAM, 
// ����<4>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjSendMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�Ex_ObjBeginPaint
// �������ͣ�BOOL
// ����˵������ʼ����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpPS, EX_PAINTSTRUCT2*, 
//======================================================
EX_DEFINE_API(Ex_ObjBeginPaint, BOOL, (HEXOBJ hObj, EX_PAINTSTRUCT2* lpPS));

//======================================================
// �������ƣ�Ex_ObjEndPaint
// �������ͣ�BOOL
// ����˵������������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpPS, EX_PAINTSTRUCT2*, 
//======================================================
EX_DEFINE_API(Ex_ObjEndPaint, BOOL, (HEXOBJ hObj, EX_PAINTSTRUCT2* lpPS));

//======================================================
// �������ƣ�Ex_ObjGetRect
// �������ͣ�BOOL
// ����˵������ȡ�������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// �������ƣ�Ex_ObjClientToWindow
// �������ͣ�BOOL
// ����˵�����ͻ������굽��������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��x, int, 
// ����<3>��y, int, 
//======================================================
EX_DEFINE_API(Ex_ObjClientToWindow, BOOL, (HEXOBJ hObj, int x, int y));

//======================================================
// �������ƣ�_canvas_cliprect
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��left, int, 
// ����<3>��top, int, 
// ����<4>��right, int, 
// ����<5>��bottom, int, 
//======================================================
EX_DEFINE_API(_canvas_cliprect, BOOL, (HEXCANVAS hCanvas, int left, int top, int right, int bottom));

//======================================================
// �������ƣ�_canvas_resetclip
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_resetclip, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�Ex_ObjClientToScreen
// �������ͣ�BOOL
// ����˵�����ͻ������굽��Ļ����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��x, int, 
// ����<3>��y, int, 
//======================================================
EX_DEFINE_API(Ex_ObjClientToScreen, BOOL, (HEXOBJ hObj, int x, int y));

//======================================================
// �������ƣ�Ex_ObjInvalidateRect
// �������ͣ�BOOL
// ����˵���������ػ�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lprcRedraw, int, 
//======================================================
EX_DEFINE_API(Ex_ObjInvalidateRect, BOOL, (HEXOBJ hObj, int lprcRedraw));

//======================================================
// �������ƣ�Ex_ObjUpdate
// �������ͣ�BOOL
// ����˵���������������
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjUpdate, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjGetClientRect
// �������ͣ�BOOL
// ����˵������ȡ����ͻ�������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetClientRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// �������ƣ�Ex_ObjEnable
// �������ͣ�BOOL
// ����˵���������������״̬.
// ����<1>��hObj, HEXOBJ, ������
// ����<2>��fEnable, BOOL, �Ƿ����
//======================================================
EX_DEFINE_API(Ex_ObjEnable, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// �������ƣ�Ex_ObjIsEnable
// �������ͣ�BOOL
// ����˵��������Ƿ����
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjIsEnable, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjIsVisible
// �������ͣ�BOOL
// ����˵�����ж�����Ƿ����.
// ����<1>��hObj, HEXOBJ, ������
//======================================================
EX_DEFINE_API(Ex_ObjIsVisible, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjShow
// �������ͣ�BOOL
// ����˵���������������״̬
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fShow, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjShow, BOOL, (HEXOBJ hObj, BOOL fShow));

//======================================================
// �������ƣ�Ex_ObjGetLong
// �������ͣ�int
// ����˵������ȡ�����ֵ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nIndex, int, ��س��� #EOL_
//======================================================
EX_DEFINE_API(Ex_ObjGetLong, int, (HEXOBJ hObj, int nIndex));

//======================================================
// �������ƣ�Ex_ObjGetParent
// �������ͣ�int
// ����˵������ȡ�����
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetParent, int, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjSetLong
// �������ͣ�int
// ����˵�������������ֵ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nIndex, int, #EOL_
// ����<3>��dwNewLong, LONG, 
//======================================================
EX_DEFINE_API(Ex_ObjSetLong, int, (HEXOBJ hObj, int nIndex, LONG dwNewLong));

//======================================================
// �������ƣ�Ex_ObjSetPos
// �������ͣ�BOOL
// ����˵�����������λ��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��hObjInsertAfter, int, 
// ����<3>��x, int, 
// ����<4>��y, int, 
// ����<5>��width, int, 
// ����<6>��height, int, 
// ����<7>��flags, int, ��س��� #SWP_
//======================================================
EX_DEFINE_API(Ex_ObjSetPos, BOOL, (HEXOBJ hObj, int hObjInsertAfter, int x, int y, int width, int height, int flags));

//======================================================
// �������ƣ�Ex_ObjIsValidate
// �������ͣ�BOOL
// ����˵�����Ƿ���Ч�����
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjIsValidate, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjEnumChild
// �������ͣ�BOOL
// ����˵����ö�������.
// ����<1>��hObjParent, EXHANDLE, ������ľ�����Ӹ���ö����Ϊ��������
// ����<2>��lpEnumFunc, int, callback(hObj,lParam).����1����ö��,����0ֹͣö��.
// ����<3>��lParam, LPARAM, ��������
//======================================================
EX_DEFINE_API(Ex_ObjEnumChild, BOOL, (EXHANDLE hObjParent, int lpEnumFunc, LPARAM lParam));

//======================================================
// �������ƣ�Ex_ObjGetText
// �������ͣ�int
// ����˵������ȡ����ı�.����ֵ:�ѿ����ַ�����.
// ����<1>��hObj, HEXOBJ, ������.
// ����<2>��lpString, LPCWSTR, ������ָ��.
// ����<3>��nMaxCount, int, ����������.
//======================================================
EX_DEFINE_API(Ex_ObjGetText, int, (HEXOBJ hObj, LPCWSTR lpString, int nMaxCount));

//======================================================
// �������ƣ�Ex_ObjGetTextLength
// �������ͣ�int
// ����˵������ȡ����ı�����
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetTextLength, int, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjSetText
// �������ͣ�BOOL
// ����˵������������ı�.
// ����<1>��hObj, HEXOBJ, ������.
// ����<2>��lpString, LPCWSTR, ָ��һ���ս������ַ�����ָ��.
// ����<3>��fRedraw, BOOL, �Ƿ��ػ����
//======================================================
EX_DEFINE_API(Ex_ObjSetText, BOOL, (HEXOBJ hObj, LPCWSTR lpString, BOOL fRedraw));

//======================================================
// �������ƣ�Ex_ObjTooltipsPop
// �������ͣ�BOOL
// ����˵����������ر���ʾ�ı�
// ����<1>��hObj, HEXOBJ, ������.
// ����<2>��lpString, LPCWSTR, ��ʾ�ı�.��ֵΪ0��ر���ʾ�ı�
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsPop, BOOL, (HEXOBJ hObj, LPCWSTR lpString));

//======================================================
// �������ƣ�Ex_ObjTooltipsPopEx
// �������ͣ�BOOL
// ����˵����������ر���ʾ�ı�Ex
// ����<1>��hObj, HEXOBJ, ������.
// ����<2>��lpTitle, LPCWSTR, ��������
// ����<3>��lpText, LPCWSTR, ��ʾ�ı�.
// ����<4>��x, int, ��Ļ����.(-1:Ĭ��)
// ����<5>��y, int, ��Ļ����.(-1:Ĭ��)
// ����<6>��dwTime, int, ��λ:����.(-1:Ĭ��,0:ʼ����ʾ)
// ����<7>��nIcon, int, #����ͼ��_
// ����<8>��fShow, BOOL, �Ƿ�������ʾ
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsPopEx, BOOL, (HEXOBJ hObj, LPCWSTR lpTitle, LPCWSTR lpText, int x, int y, int dwTime, int nIcon, BOOL fShow));

//======================================================
// �������ƣ�Ex_DUIGetObjFromPoint
// �������ͣ�HEXOBJ
// ����˵������ȡ������ڴ���������
// ����<1>��handle, EXHANDLE, 0[�������ڴ���]/���ھ��/������/������
// ����<2>��x, int, handle:0�����Ļ/������Դ���
// ����<3>��y, int, 
//======================================================
EX_DEFINE_API(Ex_DUIGetObjFromPoint, HEXOBJ, (EXHANDLE handle, int x, int y));

//======================================================
// �������ƣ�Ex_ObjSetFocus
// �������ͣ�BOOL
// ����˵���������������
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFocus, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjKillFocus
// �������ͣ�BOOL
// ����˵���������������
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjKillFocus, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjGetProp
// �������ͣ�int
// ����˵������ȡ����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��dwKey, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetProp, int, (HEXOBJ hObj, int dwKey));

//======================================================
// �������ƣ�Ex_ObjSetProp
// �������ͣ�int
// ����˵�����������������Ŀ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��dwKey, int, 
// ����<3>��dwValue, int, 
//======================================================
EX_DEFINE_API(Ex_ObjSetProp, int, (HEXOBJ hObj, int dwKey, int dwValue));

//======================================================
// �������ƣ�Ex_ObjMove
// �������ͣ�BOOL
// ����˵�����ƶ����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��x, int, 
// ����<3>��y, int, 
// ����<4>��width, int, 
// ����<5>��height, int, 
// ����<6>��bRepaint, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjMove, BOOL, (HEXOBJ hObj, int x, int y, int width, int height, BOOL bRepaint));

//======================================================
// �������ƣ�Ex_ObjGetObj
// �������ͣ�HEXOBJ
// ����˵����������ָ��������ض���ϵ����Z��������ߣ�����������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nCmd, int, ��س��� #GW_
//======================================================
EX_DEFINE_API(Ex_ObjGetObj, HEXOBJ, (HEXOBJ hObj, int nCmd));

//======================================================
// �������ƣ�Ex_ObjFind
// �������ͣ�EXHANDLE
// ����˵�����������.
// ����<1>��hObjParent, EXHANDLE, �����������Ӹ���������Ϊ��������
// ����<2>��hObjChildAfter, HEXOBJ, �ɴ������ʼ���ң�������������������Ϊ0����ӵ�һ�������ʼ���ҡ�
// ����<3>��lpClassName, LPCWSTR, �����ҵ��������ָ��/Ex_ATOM()
// ����<4>��lpTitle, LPCWSTR, �����ҵ��������
//======================================================
EX_DEFINE_API(Ex_ObjFind, EXHANDLE, (EXHANDLE hObjParent, HEXOBJ hObjChildAfter, LPCWSTR lpClassName, LPCWSTR lpTitle));

//======================================================
// �������ƣ�Ex_ObjSetRedraw
// �������ͣ�BOOL
// ����˵������������Ƿ�����ػ�.��������չ������EOS_EX_COMPOSITED,��ú�����Ч.
// ����<1>��hObj, HEXOBJ, ������
// ����<2>��fCanbeRedraw, BOOL, �Ƿ���ػ�
//======================================================
EX_DEFINE_API(Ex_ObjSetRedraw, BOOL, (HEXOBJ hObj, BOOL fCanbeRedraw));

//======================================================
// �������ƣ�Ex_ThemeLoadFromFile
// �������ͣ�int
// ����˵�������������
// ����<1>��lptszFile, LPCWSTR, 
// ����<2>��lpKey, int, 
// ����<3>��dwKeyLen, int, 
// ����<4>��bDefault, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ThemeLoadFromFile, int, (LPCWSTR lptszFile, int lpKey, int dwKeyLen, BOOL bDefault));

//======================================================
// �������ƣ�Ex_ThemeLoadFromMemory
// �������ͣ�int
// ����˵�������������
// ����<1>��lpData, LPBYTE, 
// ����<2>��dwDataLen, int, 
// ����<3>��lpKey, int, 
// ����<4>��dwKeyLen, int, 
// ����<5>��bDefault, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ThemeLoadFromMemory, int, (LPBYTE lpData, int dwDataLen, int lpKey, int dwKeyLen, BOOL bDefault));

//======================================================
// �������ƣ�Ex_ThemeFree
// �������ͣ�BOOL
// ����˵�����ͷ�����
// ����<1>��hTheme, int, 
//======================================================
EX_DEFINE_API(Ex_ThemeFree, BOOL, (int hTheme));

//======================================================
// �������ƣ�Ex_Atom
// �������ͣ�EXATOM
// ����˵������ȡ�ַ���Ψһԭ�Ӻ�
// ����<1>��lptstring, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_Atom, EXATOM, (LPCWSTR lptstring));

//======================================================
// �������ƣ�_canvas_getsize
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��width, int*, 
// ����<3>��height, int*, 
//======================================================
EX_DEFINE_API(_canvas_getsize, BOOL, (HEXCANVAS hCanvas, int* width, int* height));

//======================================================
// �������ƣ�Ex_ThemeGetValuePtr
// �������ͣ�int
// ����˵������ȡ�������ֵָ��.
// ����<1>��hTheme, int, ������
// ����<2>��atomClass, int, 
// ����<3>��atomProp, int, 
//======================================================
EX_DEFINE_API(Ex_ThemeGetValuePtr, int, (int hTheme, int atomClass, int atomProp));

//======================================================
// �������ƣ�Ex_DUISetLong
// �������ͣ�int
// ����˵��������������ֵ
// ����<1>��hExDui, HEXDUI, 
// ����<2>��nIndex, int, #EWL_
// ����<3>��dwNewlong, int, 
//======================================================
EX_DEFINE_API(Ex_DUISetLong, int, (HEXDUI hExDui, int nIndex, int dwNewlong));

//======================================================
// �������ƣ�Ex_DUIGetLong
// �������ͣ�int
// ����˵������ȡ������ֵ
// ����<1>��hExDui, HEXDUI, ������
// ����<2>��nIndex, int, ��س���: EWL_
//======================================================
EX_DEFINE_API(Ex_DUIGetLong, int, (HEXDUI hExDui, int nIndex));

//======================================================
// �������ƣ�_font_create
// �������ͣ�HEXFONT
// ����˵��������Ĭ������
//======================================================
EX_DEFINE_API(_font_create, HEXFONT, ());

//======================================================
// �������ƣ�_font_createfromfamily
// �������ͣ�HEXFONT
// ����˵����
// ����<1>��lpwzFontFace, LPCWSTR, 
// ����<2>��dwFontSize, int, 
// ����<3>��dwFontStyle, int, 
//======================================================
EX_DEFINE_API(_font_createfromfamily, HEXFONT, (LPCWSTR lpwzFontFace, int dwFontSize, int dwFontStyle));

//======================================================
// �������ƣ�_font_createfromlogfont
// �������ͣ�HEXFONT
// ����˵����
// ����<1>��lpLogfont, int, 
//======================================================
EX_DEFINE_API(_font_createfromlogfont, HEXFONT, (int lpLogfont));

//======================================================
// �������ƣ�_font_getlogfont
// �������ͣ�BOOL
// ����˵������ȡ�߼�����
// ����<1>��hFont, HEXFONT, 
// ����<2>��lpLogFont, int, 
//======================================================
EX_DEFINE_API(_font_getlogfont, BOOL, (HEXFONT hFont, int lpLogFont));

//======================================================
// �������ƣ�Ex_DUICreateFromLayout
// �������ͣ�BOOL
// ����˵���������Բ���
// ����<1>��hParent, EXHANDLE, �����ھ��
// ����<2>��hTheme, int, ������
// ����<3>��lpLayout, int, ������Դ����ָ��
// ����<4>��cbLayout, int, ������Դ���ݳ���
// ����<5>��hWnd, HWND, (out)���ش��ھ��
// ����<6>��hExDui, HEXDUI, (out)����������
//======================================================
EX_DEFINE_API(Ex_DUICreateFromLayout, BOOL, (EXHANDLE hParent, int hTheme, int lpLayout, int cbLayout, HWND hWnd, HEXDUI hExDui));

//======================================================
// �������ƣ�Ex_DUICreateFromHRes
// �������ͣ�BOOL
// ����˵������������Դ�����
// ����<1>��hParent, EXHANDLE, �����ھ��
// ����<2>��hTheme, int, ������
// ����<3>��hRes, int, ��Դ���
// ����<4>��atomLayout, int, �����ļ���ԭ�Ӻ�
// ����<5>��hWnd, HWND, (out)���ش��ھ��
// ����<6>��hExDui, HEXDUI, (out)����������
//======================================================
EX_DEFINE_API(Ex_DUICreateFromHRes, BOOL, (EXHANDLE hParent, int hTheme, int hRes, int atomLayout, HWND hWnd, HEXDUI hExDui));

//======================================================
// �������ƣ�Ex_XmlRegisterCallback
// �������ͣ�void
// ����˵����ע��XML��ֵ�ص�
// ����<1>��atomValue, int, 
// ����<2>��pfnCallback, ExObjEventHandler, 
//======================================================
EX_DEFINE_API(Ex_XmlRegisterCallback, void, (int atomValue, ExObjEventHandler pfnCallback));

//======================================================
// �������ƣ�Ex_DUIGetClientRect
// �������ͣ�BOOL
// ����˵������ȡ�ͻ�������
// ����<1>��hExDui, HEXDUI, ������
// ����<2>��lpClientRect, RECT*, ����ָ��
//======================================================
EX_DEFINE_API(Ex_DUIGetClientRect, BOOL, (HEXDUI hExDui, RECT* lpClientRect));

//======================================================
// �������ƣ�Ex_ObjPostMessage
// �������ͣ�int
// ����˵����Ͷ����Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��uMsg, UINT, 
// ����<3>��wParam, WPARAM, 
// ����<4>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjPostMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�Ex_ObjSetBackgroundImage
// �������ͣ�BOOL
// ����˵�����������������Ϣ
// ����<1>��handle, EXHANDLE, ������/������
// ����<2>��lpImage, int, ͼƬָ��
// ����<3>��dwImageLen, int, ͼƬ����
// ����<4>��X, int, ƫ��X
// ����<5>��Y, int, ƫ��Y
// ����<6>��dwRepeat, int, ��س��� BIR_
// ����<7>��lpGird, int, �Ź�����ָ�� (ֵ��Ϊ0)
// ����<8>��dwFlags, int, ��س��� BIF_
// ����<9>��dwAlpha, int, ͸����(0-255)
// ����<10>��fUpdate, BOOL, �Ƿ�����ˢ��
//======================================================
EX_DEFINE_API(Ex_ObjSetBackgroundImage, BOOL, (EXHANDLE handle, int lpImage, int dwImageLen, int X, int Y, int dwRepeat, int lpGird, int dwFlags, int dwAlpha, BOOL fUpdate));

//======================================================
// �������ƣ�Ex_ObjGetBackgroundImage
// �������ͣ�BOOL
// ����˵������ȡ���������Ϣ
// ����<1>��handle, EXHANDLE, 
// ����<2>��lpBackgroundImage, int, ��ؽṹ EX_BACKGROUNDIMAGEINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetBackgroundImage, BOOL, (EXHANDLE handle, int lpBackgroundImage));

//======================================================
// �������ƣ�Ex_ObjSetBackgroundPlayState
// �������ͣ�BOOL
// ����˵���������������ͼƬ����״̬.
// ����<1>��handle, EXHANDLE, ������/������
// ����<2>��fPlayFrames, BOOL, �Ƿ񲥷�.
// ����<3>��fResetFrame, BOOL, �Ƿ����õ�ǰ֡Ϊ��֡.
// ����<4>��fUpdate, BOOL, �Ƿ���±���.
//======================================================
EX_DEFINE_API(Ex_ObjSetBackgroundPlayState, BOOL, (EXHANDLE handle, BOOL fPlayFrames, BOOL fResetFrame, BOOL fUpdate));

//======================================================
// �������ƣ�_canvas_blur
// �������ͣ�BOOL
// ����˵����ģ��
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��fDeviation, float, 
// ����<3>��lprc, int, 
//======================================================
EX_DEFINE_API(_canvas_blur, BOOL, (HEXCANVAS hCanvas, float fDeviation, int lprc));

//======================================================
// �������ƣ�_canvas_rotate_hue
// �������ͣ�BOOL
// ����˵������תɫ��
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��fAngle, float, 0-360
//======================================================
EX_DEFINE_API(_canvas_rotate_hue, BOOL, (HEXCANVAS hCanvas, float fAngle));

//======================================================
// �������ƣ�Ex_ObjSetTimer
// �������ͣ�int
// ����˵�����������ʱ��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��uElapse, int, 
//======================================================
EX_DEFINE_API(Ex_ObjSetTimer, int, (HEXOBJ hObj, int uElapse));

//======================================================
// �������ƣ�Ex_ObjKillTimer
// �������ͣ�BOOL
// ����˵�����������ʱ��
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjKillTimer, BOOL, (HEXOBJ hObj));

//======================================================
// �������ƣ�_canvas_drawtext
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hFont, HEXFONT, ���Ϊ0��ʹ��Ĭ��������
// ����<3>��crText, int, 
// ����<4>��lpwzText, LPCWSTR, 
// ����<5>��dwLen, size_t, -1���Զ�����ߴ�(������ָ����ַ�����ָ��)
// ����<6>��dwDTFormat, int, #DT_
// ����<7>��left, float, 
// ����<8>��top, float, 
// ����<9>��right, float, 
// ����<10>��bottom, float, 
//======================================================
EX_DEFINE_API(_canvas_drawtext, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, int crText, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, float left, float top, float right, float bottom));

//======================================================
// �������ƣ�_font_destroy
// �������ͣ�BOOL
// ����˵����
// ����<1>��hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_destroy, BOOL, (HEXFONT hFont));

//======================================================
// �������ƣ�_canvas_calctextsize
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hFont, HEXFONT, 
// ����<3>��lpwzText, LPCWSTR, 
// ����<4>��dwLen, size_t, 
// ����<5>��dwDTFormat, int, 
// ����<6>��lParam, LPARAM, 
// ����<7>��layoutWidth, float, 
// ����<8>��layoutHeight, float, 
// ����<9>��lpWidth, float*, 
// ����<10>��lpHeight, float*, 
//======================================================
EX_DEFINE_API(_canvas_calctextsize, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, LPARAM lParam, float layoutWidth, float layoutHeight, float* lpWidth, float* lpHeight));

//======================================================
// �������ƣ�_canvas_drawtextex
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hFont, HEXFONT, 
// ����<3>��crText, int, 
// ����<4>��lpwzText, LPCWSTR, 
// ����<5>��dwLen, size_t, -1���Զ�����ߴ�(������ָ����ַ�����ָ��)
// ����<6>��dwDTFormat, int, 
// ����<7>��left, float, 
// ����<8>��top, float, 
// ����<9>��right, float, 
// ����<10>��bottom, float, 
// ����<11>��iGlowsize, int, 
// ����<12>��crShadow, int, 
// ����<13>��lParam, LPARAM, 
// ����<14>��prclayout, int, 
//======================================================
EX_DEFINE_API(_canvas_drawtextex, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, int crText, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, float left, float top, float right, float bottom, int iGlowsize, int crShadow, LPARAM lParam, int prclayout));

//======================================================
// �������ƣ�Ex_ObjDispatchMessage
// �������ͣ�int
// ����˵�����ַ���Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��uMsg, UINT, 
// ����<3>��wParam, WPARAM, 
// ����<4>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDispatchMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�_canvas_begindraw
// �������ͣ�BOOL
// ����˵����ok
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_begindraw, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�Ex_ObjSetUIState
// �������ͣ�BOOL
// ����˵�����������״̬,���ڸ������������ʾ״̬
// ����<1>��hObj, HEXOBJ, 
// ����<2>��dwState, int, 
// ����<3>��fRemove, BOOL, 
// ����<4>��lprcRedraw, int, 
// ����<5>��fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetUIState, BOOL, (HEXOBJ hObj, int dwState, BOOL fRemove, int lprcRedraw, BOOL fRedraw));

//======================================================
// �������ƣ�_canvas_flush
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_flush, BOOL, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�Ex_ObjScrollSetInfo
// �������ͣ�int
// ����˵�������ù�������Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fnBar, int, SB_
// ����<3>��fMask, int, SIF_
// ����<4>��nMin, int, 
// ����<5>��nMax, int, 
// ����<6>��nPage, int, 
// ����<7>��nPos, int, 
// ����<8>��fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetInfo, int, (HEXOBJ hObj, int fnBar, int fMask, int nMin, int nMax, int nPage, int nPos, BOOL fRedraw));

//======================================================
// �������ƣ�Ex_ObjScrollSetRange
// �������ͣ�BOOL
// ����˵�������ù�������Χ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, SB_
// ����<3>��nMin, int, 
// ����<4>��nMax, int, 
// ����<5>��bRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetRange, BOOL, (HEXOBJ hObj, int nBar, int nMin, int nMax, BOOL bRedraw));

//======================================================
// �������ƣ�Ex_ObjScrollSetPos
// �������ͣ�int
// ����˵�������ù�����λ��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, SB_
// ����<3>��nPos, int, 
// ����<4>��bRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetPos, int, (HEXOBJ hObj, int nBar, int nPos, BOOL bRedraw));

//======================================================
// �������ƣ�Ex_ObjScrollGetControl
// �������ͣ�int
// ����˵������ȡ���������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, ��س��� #SB_
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetControl, int, (HEXOBJ hObj, int nBar));

//======================================================
// �������ƣ�Ex_ObjCallProc
// �������ͣ�int
// ����˵�������ù���
// ����<1>��lpPrevObjProc, int, 
// ����<2>��hWnd, HWND, 
// ����<3>��hObj, HEXOBJ, 
// ����<4>��uMsg, UINT, 
// ����<5>��wParam, WPARAM, 
// ����<6>��lParam, LPARAM, 
// ����<7>��pvData, int, 
//======================================================
EX_DEFINE_API(Ex_ObjCallProc, int, (int lpPrevObjProc, HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, int pvData));

//======================================================
// �������ƣ�_canvas_createfromexdui
// �������ͣ�int
// ����˵��������������������
// ����<1>��hExDui, HEXDUI, 
// ����<2>��width, int, 
// ����<3>��height, int, 
// ����<4>��dwFlags, int, CVF_
//======================================================
EX_DEFINE_API(_canvas_createfromexdui, int, (HEXDUI hExDui, int width, int height, int dwFlags));

//======================================================
// �������ƣ�Ex_ObjScrollGetPos
// �������ͣ�int
// ����˵������ȡ������λ��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetPos, int, (HEXOBJ hObj, int nBar));

//======================================================
// �������ƣ�Ex_MessageBox
// �������ͣ�int
// ����˵����������Ϣ��
// ����<1>��handle, EXHANDLE, ������/������/���ھ��.(�����ֵΪ���ھ���Ҵ���δʹ��������Ⱦ,����Ĭ����Ϣ�򵯳�)
// ����<2>��lpText, LPCWSTR, ��Ϣ������
// ����<3>��lpCaption, int, ��Ϣ�����
// ����<4>��uType, int, ��س��� #MB_
// ����<5>��dwFlags, int, ��س��� #EMBF_
//======================================================
EX_DEFINE_API(Ex_MessageBox, int, (EXHANDLE handle, LPCWSTR lpText, int lpCaption, int uType, int dwFlags));

//======================================================
// �������ƣ�Ex_MessageBoxEx
// �������ͣ�int
// ����˵����������Ϣ��
// ����<1>��handle, EXHANDLE, ������/������/���ھ��.(�����ֵΪ���ھ���Ҵ���δʹ��������Ⱦ,����Ĭ����Ϣ�򵯳�)
// ����<2>��lpText, LPCWSTR, ��Ϣ������
// ����<3>��lpCaption, int, ��Ϣ�����
// ����<4>��uType, int, ��س��� #MB_
// ����<5>��lpCheckBox, int, �������(��Ϣ�����½���ʾһ���������).(����ô���δʹ��������Ⱦ,���ֵ��Ч)
// ����<6>��lpCheckBoxChecked, BOOL, ���ؼ���ѡ��״̬.(����ô���δʹ��������Ⱦ,���ֵ��Ч)
// ����<7>��dwMilliseconds, int, ��Ϣ���ӳٹر�ʱ�䣬��λ�����롣�����ֵ��Ϊ0,�ҳ�ʱ��(���û�δ����)����Ϣ���Զ��رգ�����32000��
// ����<8>��dwFlags, int, ��س��� #EMBF_
// ����<9>��lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
//======================================================
EX_DEFINE_API(Ex_MessageBoxEx, int, (EXHANDLE handle, LPCWSTR lpText, int lpCaption, int uType, int lpCheckBox, BOOL lpCheckBoxChecked, int dwMilliseconds, int dwFlags, ExMsgProc lpfnMsgProc));

//======================================================
// �������ƣ�Ex_DUIBindWindow
// �������ͣ�HEXDUI
// ����˵�����󶨴���,�ɹ�����������,ʧ�ܷ���0.
// ����<1>��hWnd, HWND, ���ھ��
// ����<2>��hTheme, int, ������.(ֵ��Ϊ0)
// ����<3>��dwStyle, DWORD, ��س���:#EWS_
//======================================================
EX_DEFINE_API(Ex_DUIBindWindow, HEXDUI, (HWND hWnd, int hTheme, DWORD dwStyle));

//======================================================
// �������ƣ�Ex_ObjGetFromID
// �������ͣ�HEXOBJ
// ����˵������ȡ��������ID
// ����<1>��hExDuiOrhObj, EXHANDLE, ���ָ��������,��ȫ������;���ָ��������,��Ӹ�������������ʼ����.
// ����<2>��nID, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromID, HEXOBJ, (EXHANDLE hExDuiOrhObj, int nID));

//======================================================
// �������ƣ�Ex_ObjGetFromName
// �������ͣ�int
// ����˵������ȡ��������NAME
// ����<1>��hExDuiOrhObj, EXHANDLE, ���ָ��������,��ȫ������;���ָ��������,��Ӹ�������������ʼ����.
// ����<2>��lpwzName, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromName, int, (EXHANDLE hExDuiOrhObj, LPCWSTR lpwzName));

//======================================================
// �������ƣ�Ex_ObjHandleEvent
// �������ͣ�BOOL
// ����˵�����ҽ�����¼��ص�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nEvent, int, #NM_
// ����<3>��pfnCallback, ExObjEventHandler, (Bool) Handler(hObj,nID,nCode,wParam,lParam) ���ؼټ����ַ��¼�,��������ֹͣ�����ַ��¼�
//======================================================
EX_DEFINE_API(Ex_ObjHandleEvent, BOOL, (HEXOBJ hObj, int nEvent, ExObjEventHandler pfnCallback));

//======================================================
// �������ƣ�Ex_ThemeGetColor
// �������ͣ�int
// ����˵������ȡ���������ɫֵ
// ����<1>��hTheme, int, ������
// ����<2>��nIndex, int, #COLOR_EX_
//======================================================
EX_DEFINE_API(Ex_ThemeGetColor, int, (int hTheme, int nIndex));

//======================================================
// �������ƣ�Ex_ObjGetUIState
// �������ͣ�int
// ����˵������ȡ���״̬
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetUIState, int, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjSetColor
// �������ͣ�int
// ����˵����������������ɫ,�����޸�ǰ�����ɫ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nIndex, int, ��س��� COLOR_EX_
// ����<3>��dwColor, int, 
// ����<4>��fRedraw, BOOL, �Ƿ��ػ�
//======================================================
EX_DEFINE_API(Ex_ObjSetColor, int, (HEXOBJ hObj, int nIndex, int dwColor, BOOL fRedraw));

//======================================================
// �������ƣ�Ex_ObjGetColor
// �������ͣ�int
// ����˵������ȡ��������ɫ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nIndex, int, ��س��� COLOR_EX_
//======================================================
EX_DEFINE_API(Ex_ObjGetColor, int, (HEXOBJ hObj, int nIndex));

//======================================================
// �������ƣ�_res_pack
// �������ͣ�void
// ����˵�������
// ����<1>��root, LPCSTR, �ļ���Ŀ¼
// ����<2>��file, LPCSTR, Ŀ���ļ�
// ����<3>��fSubDir, BOOL, �Ƿ�ɨ����Ŀ¼
// ����<4>��byteHeader, int, Ŀ���ļ�ͷ
// ����<5>��bPntBits, BOOL, Ԥ����PNG
//======================================================
EX_DEFINE_API(_res_pack, void, (LPCSTR root, LPCSTR file, BOOL fSubDir, int byteHeader, BOOL bPntBits));

//======================================================
// �������ƣ�Ex_ResLoadFromFile
// �������ͣ�int
// ����˵�������ļ�������Դ
// ����<1>��lpwzFile, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ResLoadFromFile, int, (LPCWSTR lpwzFile));

//======================================================
// �������ƣ�Ex_ResLoadFromMemory
// �������ͣ�int
// ����˵�������ڴ������Դ
// ����<1>��lpData, LPBYTE, 
// ����<2>��dwDataLen, int, 
//======================================================
EX_DEFINE_API(Ex_ResLoadFromMemory, int, (LPBYTE lpData, int dwDataLen));

//======================================================
// �������ƣ�Ex_I18NGetString
// �������ͣ�BOOL
// ����˵�������԰�_��ȡ�ı�
// ����<1>��lpwzID, LPCWSTR, 
// ����<2>��lpString, LPCWSTR, [out]ָ���ַ���ָ��.����ѱ���ʽ��,�û������ Ex_I18NFreeString() �����ͷ�.
// ����<3>��bFormat, BOOL, [in/out]�Ƿ���Ҫ��ʽ��
//======================================================
EX_DEFINE_API(Ex_I18NGetString, BOOL, (LPCWSTR lpwzID, LPCWSTR lpString, BOOL bFormat));

//======================================================
// �������ƣ�Ex_I18NGetStringFromAtom
// �������ͣ�BOOL
// ����˵�������԰�_��ȡ�ı�
// ����<1>��atomID, int, 
// ����<2>��lpString, LPCWSTR, [out]ָ���ַ���ָ��.����ѱ���ʽ��,�û������ Ex_FreeBuffer() �����ͷ�.
// ����<3>��bFormat, BOOL, [in/out]�Ƿ���Ҫ��ʽ��
//======================================================
EX_DEFINE_API(Ex_I18NGetStringFromAtom, BOOL, (int atomID, LPCWSTR lpString, BOOL bFormat));

//======================================================
// �������ƣ�Ex_ResGetFile
// �������ͣ�BOOL
// ����˵������ȡ��Դ�ļ�
// ����<1>��hRes, int, 
// ����<2>��lpwzPath, LPCWSTR, 
// ����<3>��lpFile, int, [out]�ļ�����ָ��.�û���Ӧ���ͷŸ��ڴ�.
// ����<4>��dwFileLen, int, [out]�ļ��ߴ�.
//======================================================
EX_DEFINE_API(Ex_ResGetFile, BOOL, (int hRes, LPCWSTR lpwzPath, int lpFile, int dwFileLen));

//======================================================
// �������ƣ�Ex_ResGetFileFromAtom
// �������ͣ�BOOL
// ����˵������ȡ��Դ�ļ�
// ����<1>��hRes, int, 
// ����<2>��atomPath, int, 
// ����<3>��lpFile, int, [out]�ļ�����ָ��.�û���Ӧ���ͷŸ��ڴ�.
// ����<4>��dwFileLen, int, [out]�ļ��ߴ�.
//======================================================
EX_DEFINE_API(Ex_ResGetFileFromAtom, BOOL, (int hRes, int atomPath, int lpFile, int dwFileLen));

//======================================================
// �������ƣ�Ex_ResFree
// �������ͣ�void
// ����˵�����ͷ���Դ
// ����<1>��hRes, int, 
//======================================================
EX_DEFINE_API(Ex_ResFree, void, (int hRes));

//======================================================
// �������ƣ�Ex_ObjDispatchNotify
// �������ͣ�int
// ����˵�����ַ��¼�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nCode, int, 
// ����<3>��wParam, WPARAM, 
// ����<4>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDispatchNotify, int, (HEXOBJ hObj, int nCode, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�Ex_I18NStringFormat
// �������ͣ�void
// ����˵�������԰�_�ı���ʽ��
// ����<1>��lppStringSrc, int, 
// ����<2>��lpStringFormated, int, 
//======================================================
EX_DEFINE_API(Ex_I18NStringFormat, void, (int lppStringSrc, int lpStringFormated));

//======================================================
// �������ƣ�Ex_I18NRegisterCallback
// �������ͣ�void
// ����˵�������԰�_ע��ص�
// ����<1>��pfnStringFormatCallback, int, [bool]callback(atomID,lppString)
//======================================================
EX_DEFINE_API(Ex_I18NRegisterCallback, void, (int pfnStringFormatCallback));

//======================================================
// �������ƣ�Ex_DUITrayIconSet
// �������ͣ�BOOL
// ����˵������������ͼ��
// ����<1>��hExdui, int, ������
// ����<2>��hIcon, int, ͼ����
// ����<3>��lpwzTips, LPCWSTR, ��ʾ�ı�ָ��
//======================================================
EX_DEFINE_API(Ex_DUITrayIconSet, BOOL, (int hExdui, int hIcon, LPCWSTR lpwzTips));

//======================================================
// �������ƣ�Ex_DUITrayIconPopup
// �������ͣ�BOOL
// ����˵������������ͼ��
// ����<1>��hExDui, HEXDUI, ������
// ����<2>��lpwzInfo, LPCWSTR, �����ı�����
// ����<3>��lpwzInfoTitle, LPCWSTR, ���������ı�
// ����<4>��dwInfoFlags, int, ��س��� #NIIF_
//======================================================
EX_DEFINE_API(Ex_DUITrayIconPopup, BOOL, (HEXDUI hExDui, LPCWSTR lpwzInfo, LPCWSTR lpwzInfoTitle, int dwInfoFlags));

//======================================================
// �������ƣ�Ex_FreeBuffer
// �������ͣ�void
// ����˵�����ͷ��ڴ�
// ����<1>��lpBuffer, LPBYTE, 
//======================================================
EX_DEFINE_API(Ex_FreeBuffer, void, (LPBYTE lpBuffer));

//======================================================
// �������ƣ�Ex_ObjDrawBackgroundProc
// �������ͣ�BOOL
// ����˵����Ĭ�ϻ��Ʊ�������
// ����<1>��hObj, HEXOBJ, 
// ����<2>��hCanvas, HEXCANVAS, 
// ����<3>��lprcPaint, int, 
//======================================================
EX_DEFINE_API(Ex_ObjDrawBackgroundProc, BOOL, (HEXOBJ hObj, HEXCANVAS hCanvas, int lprcPaint));

//======================================================
// �������ƣ�Ex_ObjGetFocus
// �������ͣ�HEXOBJ
// ����˵������ȡ�������
// ����<1>��hExDuiOrhObj, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFocus, HEXOBJ, (EXHANDLE hExDuiOrhObj));

//======================================================
// �������ƣ�_canvas_settransform
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��pMatrix, int, 0.������
//======================================================
EX_DEFINE_API(_canvas_settransform, BOOL, (HEXCANVAS hCanvas, int pMatrix));

//======================================================
// �������ƣ�_matrix_create
// �������ͣ�int
// ����˵����
//======================================================
EX_DEFINE_API(_matrix_create, int, ());

//======================================================
// �������ƣ�_matrix_destroy
// �������ͣ�BOOL
// ����˵����
// ����<1>��pMatrix, int, 
//======================================================
EX_DEFINE_API(_matrix_destroy, BOOL, (int pMatrix));

//======================================================
// �������ƣ�_matrix_reset
// �������ͣ�BOOL
// ����˵����
// ����<1>��pMatrix, int, 
//======================================================
EX_DEFINE_API(_matrix_reset, BOOL, (int pMatrix));

//======================================================
// �������ƣ�_matrix_translate
// �������ͣ�BOOL
// ����˵����
// ����<1>��pMatrix, int, 
// ����<2>��offsetX, float, 
// ����<3>��offsetY, float, 
//======================================================
EX_DEFINE_API(_matrix_translate, BOOL, (int pMatrix, float offsetX, float offsetY));

//======================================================
// �������ƣ�_matrix_rotate
// �������ͣ�BOOL
// ����˵����
// ����<1>��pMatrix, int, 
// ����<2>��fAngle, float, 
//======================================================
EX_DEFINE_API(_matrix_rotate, BOOL, (int pMatrix, float fAngle));

//======================================================
// �������ƣ�_matrix_scale
// �������ͣ�BOOL
// ����˵����
// ����<1>��pMatrix, int, 
// ����<2>��scaleX, float, 
// ����<3>��scaleY, float, 
//======================================================
EX_DEFINE_API(_matrix_scale, BOOL, (int pMatrix, float scaleX, float scaleY));

//======================================================
// �������ƣ�_img_createfromres
// �������ͣ�int
// ����˵��������ͼ������Դ�����ɹ�����0��
// ����<1>��hRes, int, 
// ����<2>��atomPath, int, 
// ����<3>��hImg, HEXIMAGE*, ����ͼ��ָ��
//======================================================
EX_DEFINE_API(_img_createfromres, int, (int hRes, int atomPath, HEXIMAGE* hImg));

//======================================================
// �������ƣ�_brush_setcolor
// �������ͣ�int
// ����˵����
// ����<1>��hBrush, HEXBRUSH, 
// ����<2>��argb, int, 
//======================================================
EX_DEFINE_API(_brush_setcolor, int, (HEXBRUSH hBrush, int argb));

//======================================================
// �������ƣ�Ex_ThemeDrawControl
// �������ͣ�BOOL
// ����˵����������������
// ����<1>��hTheme, int, ������
// ����<2>��hCanvas, HEXCANVAS, ������
// ����<3>��dstLeft, float, Ŀ�����
// ����<4>��dstTop, float, Ŀ�궥��
// ����<5>��dstRight, float, Ŀ���ұ�
// ����<6>��dstBottom, float, Ŀ��ױ�
// ����<7>��atomClass, int, 
// ����<8>��atomSrcRect, int, 
// ����<9>��dwAlpha, int, ͸����(0-255)
//======================================================
EX_DEFINE_API(Ex_ThemeDrawControl, BOOL, (int hTheme, HEXCANVAS hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom, int atomClass, int atomSrcRect, int dwAlpha));

//======================================================
// �������ƣ�_brush_createfromimg
// �������ͣ�HEXBRUSH
// ����˵����
// ����<1>��hImg, HEXIMAGE*, 
//======================================================
EX_DEFINE_API(_brush_createfromimg, HEXBRUSH, (HEXIMAGE* hImg));

//======================================================
// �������ƣ�_path_create
// �������ͣ�int
// ����˵��������·��
// ����<1>��brushmode, int, 
// ����<2>��dwFlags, int, EPF_
// ����<3>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_create, int, (int brushmode, int dwFlags, HEXPATH* hPath));

//======================================================
// �������ƣ�_path_destroy
// �������ͣ�int
// ����˵��������·��
// ����<1>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_destroy, int, (HEXPATH* hPath));

//======================================================
// �������ƣ�_path_addline
// �������ͣ�int
// ����˵���������
// ����<1>��hPath, HEXPATH*, 
// ����<2>��x1, float, 
// ����<3>��y1, float, 
// ����<4>��x2, float, 
// ����<5>��y2, float, 
//======================================================
EX_DEFINE_API(_path_addline, int, (HEXPATH* hPath, float x1, float y1, float x2, float y2));

//======================================================
// �������ƣ�_path_beginfigure
// �������ͣ�int
// ����˵������ʼ��ͼ��
// ����<1>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_beginfigure, int, (HEXPATH* hPath));

//======================================================
// �������ƣ�_path_endfigure
// �������ͣ�int
// ����˵����������ǰͼ��
// ����<1>��hPath, HEXPATH*, 
// ����<2>��fCloseFigure, BOOL, �Ƿ���Ҫ�պ�ͼ��
//======================================================
EX_DEFINE_API(_path_endfigure, int, (HEXPATH* hPath, BOOL fCloseFigure));

//======================================================
// �������ƣ�Ex_AllocBuffer
// �������ͣ�int
// ����˵���������ڴ�
// ����<1>��dwLen, size_t, 
//======================================================
EX_DEFINE_API(Ex_AllocBuffer, int, (size_t dwLen));

//======================================================
// �������ƣ�_img_scale
// �������ͣ�int
// ����˵��������ͼ��.�ɹ�����0
// ����<1>��hImage, HEXIMAGE, 
// ����<2>��dstWidth, int, 
// ����<3>��dstHeight, int, 
// ����<4>��dstImg, HEXIMAGE, ������ͼ��
//======================================================
EX_DEFINE_API(_img_scale, int, (HEXIMAGE hImage, int dstWidth, int dstHeight, HEXIMAGE dstImg));

//======================================================
// �������ƣ�_fmt_int
// �������ͣ�int
// ����˵������ʽ��_�ı�������
// ����<1>��lpValue, int, �ַ���ָ��
// ����<2>��lpdwPercentFlags, int, (out)�����Ƿ�Ϊ�ٷֱȵ�λ
//======================================================
EX_DEFINE_API(_fmt_int, int, (int lpValue, int lpdwPercentFlags));

//======================================================
// �������ƣ�_fmt_intary
// �������ͣ�int
// ����˵������ʽ��_�ı�����������
// ����<1>��lpValue, int, �ַ���ָ��
// ����<2>��lpAry, int, ����ָ��
// ����<3>��nMaxCount, int, �������
// ����<4>��fZero, BOOL, �Ƿ����
// ����<5>��lpdwPercentFlags, int, (out)���ذٷֱȱ��λ(0-31λ)
//======================================================
EX_DEFINE_API(_fmt_intary, int, (int lpValue, int lpAry, int nMaxCount, BOOL fZero, int lpdwPercentFlags));

//======================================================
// �������ƣ�_fmt_rect
// �������ͣ�BOOL
// ����˵������ʽ��_�ı�������
// ����<1>��lpValue, int, �ַ���ָ��
// ����<2>��lpRect, RECT*, ����ָ��
// ����<3>��lpdwPercentFlags, int, (out)���ذٷֱȱ��λ(0-31λ)
//======================================================
EX_DEFINE_API(_fmt_rect, BOOL, (int lpValue, RECT* lpRect, int lpdwPercentFlags));

//======================================================
// �������ƣ�_fmt_string
// �������ͣ�BOOL
// ����˵������ʽ��_�ı����ı�_���԰�
// ����<1>��hRes, int, ��Դ���.(ֵ��Ϊ0)
// ����<2>��lpValue, int, �ַ���ָ��
// ����<3>��lpString, LPCWSTR, (out)
// ����<4>��bDispatchI18NCallback, BOOL, (in/out)
//======================================================
EX_DEFINE_API(_fmt_string, BOOL, (int hRes, int lpValue, LPCWSTR lpString, BOOL bDispatchI18NCallback));

//======================================================
// �������ƣ�_fmt_color
// �������ͣ�BOOL
// ����˵������ʽ��_�ı�����ɫ
// ����<1>��lpValue, int, �ַ���ָ��
// ����<2>��lpColor, int, (out)������ɫ
//======================================================
EX_DEFINE_API(_fmt_color, BOOL, (int lpValue, int lpColor));

//======================================================
// �������ƣ�_fmt_bin
// �������ͣ�BOOL
// ����˵������ʽ��_����������
// ����<1>��hRes, int, ��Դ���
// ����<2>��lpValue, int, ����ָ��
// ����<3>��lpBin, int, (out)���ض���������ָ��
// ����<4>��lpLen, int, (out)�������ݳ���
// ����<5>��lpFreeBuffer, BOOL, (out)�����Ƿ���Ҫ�ͷ�����
//======================================================
EX_DEFINE_API(_fmt_bin, BOOL, (int hRes, int lpValue, int lpBin, int lpLen, BOOL lpFreeBuffer));

//======================================================
// �������ƣ�_fmt_getvalue
// �������ͣ�BOOL
// ����˵������ʽ��_��ȡ����ƫ�Ƶ�ַ
// ����<1>��lpValue, int, 
// ����<2>��atomDest, int, 
//======================================================
EX_DEFINE_API(_fmt_getvalue, BOOL, (int lpValue, int atomDest));

//======================================================
// �������ƣ�_fmt_getatom
// �������ͣ�int
// ����˵������ʽ��_��ȡ����ƫ�Ƶ�ַ
// ����<1>��lpValue, int, 
// ����<2>��lpValueOffset, int, 
//======================================================
EX_DEFINE_API(_fmt_getatom, int, (int lpValue, int lpValueOffset));

//======================================================
// �������ƣ�_layout_register
// �������ͣ�BOOL
// ����˵����
// ����<1>��nType, int, ��������
// ����<2>��lpfnLayoutProc, int, ���ֹ������ص�����(lpLayout[�п�����NULL],nEevent,wParam,lParam)��������
//======================================================
EX_DEFINE_API(_layout_register, BOOL, (int nType, int lpfnLayoutProc));

//======================================================
// �������ƣ�_layout_unregister
// �������ͣ�BOOL
// ����˵����
// ����<1>��nType, int, ��������
//======================================================
EX_DEFINE_API(_layout_unregister, BOOL, (int nType));

//======================================================
// �������ƣ�_layout_create
// �������ͣ�HEXLAYOUT
// ����˵����hLayout
// ����<1>��nType, int, #ELT_ ��������
// ����<2>��hObjBind, EXHANDLE, ���󶨵�HOBJ��HEXDUI
//======================================================
EX_DEFINE_API(_layout_create, HEXLAYOUT, (int nType, EXHANDLE hObjBind));

//======================================================
// �������ƣ�_layout_destroy
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_destroy, BOOL, (HEXLAYOUT hLayout));

//======================================================
// �������ƣ�_layout_addchild
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(_layout_addchild, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj));

//======================================================
// �������ƣ�_layout_addchildren
// �������ͣ�BOOL
// ����˵�����ѱ�����Ĳ����ظ����(ϵͳ��ť������)
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��fDesc, BOOL, �Ƿ���
// ����<3>��dwObjClassATOM, int, 0���Ϊ����
// ����<4>��nCount, int, ����ĸ���
//======================================================
EX_DEFINE_API(_layout_addchildren, BOOL, (HEXLAYOUT hLayout, BOOL fDesc, int dwObjClassATOM, int nCount));

//======================================================
// �������ƣ�_layout_deletechild
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(_layout_deletechild, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj));

//======================================================
// �������ƣ�_layout_deletechildren
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��dwObjClassATOM, int, 0���Ϊ����
//======================================================
EX_DEFINE_API(_layout_deletechildren, BOOL, (HEXLAYOUT hLayout, int dwObjClassATOM));

//======================================================
// �������ƣ�_layout_setchildprop
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObj, HEXOBJ, 
// ����<3>��dwPropID, int, 
// ����<4>��pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_setchildprop, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int dwPropID, int pvValue));

//======================================================
// �������ƣ�_layout_getchildprop
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObj, HEXOBJ, 
// ����<3>��dwPropID, int, 
// ����<4>��pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_getchildprop, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int dwPropID, int pvValue));

//======================================================
// �������ƣ�_layout_getchildproplist
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObj, HEXOBJ, 
// ����<3>��lpProps, int, ���ͷ�
//======================================================
EX_DEFINE_API(_layout_getchildproplist, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int lpProps));

//======================================================
// �������ƣ�_layout_getprop
// �������ͣ�int
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��dwPropID, int, 
//======================================================
EX_DEFINE_API(_layout_getprop, int, (HEXLAYOUT hLayout, int dwPropID));

//======================================================
// �������ƣ�_layout_setprop
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��dwPropID, int, 
// ����<3>��pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_setprop, BOOL, (HEXLAYOUT hLayout, int dwPropID, int pvValue));

//======================================================
// �������ƣ�_layout_getproplist
// �������ͣ�int
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_getproplist, int, (HEXLAYOUT hLayout));

//======================================================
// �������ƣ�_layout_update
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_update, BOOL, (HEXLAYOUT hLayout));

//======================================================
// �������ƣ�_layout_gettype
// �������ͣ�int
// ����˵������������typeӦ�����´���LM
// ����<1>��hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_gettype, int, (HEXLAYOUT hLayout));

//======================================================
// �������ƣ�_layout_enableupdate
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��fUpdateable, BOOL, 
//======================================================
EX_DEFINE_API(_layout_enableupdate, BOOL, (HEXLAYOUT hLayout, BOOL fUpdateable));

//======================================================
// �������ƣ�_layout_notify
// �������ͣ�int
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��nEvent, int, 
// ����<3>��wParam, WPARAM, 
// ����<4>��lParam, LPARAM, 
//======================================================
EX_DEFINE_API(_layout_notify, int, (HEXLAYOUT hLayout, int nEvent, WPARAM wParam, LPARAM lParam));

//======================================================
// �������ƣ�Ex_ObjGetParentEx
// �������ͣ�int
// ����˵������ȡ�������EXDUI���
// ����<1>��hObj, HEXOBJ, 
// ����<2>��phExDUI, HEXDUI*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetParentEx, int, (HEXOBJ hObj, HEXDUI* phExDUI));

//======================================================
// �������ƣ�Ex_ObjGetTextRect
// �������ͣ�BOOL
// ����˵������ȡ����ı�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetTextRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// �������ƣ�Ex_ThemeDrawControlEx
// �������ͣ�BOOL
// ����˵���������������ݼ�ǿ��
// ����<1>��hTheme, int, ������
// ����<2>��hCanvas, HEXCANVAS, ������
// ����<3>��dstLeft, float, Ŀ�����
// ����<4>��dstTop, float, Ŀ�궥��
// ����<5>��dstRight, float, Ŀ���ұ�
// ����<6>��dstBottom, float, Ŀ��ױ�
// ����<7>��atomClass, int, 
// ����<8>��atomSrcRect, int, 
// ����<9>��atomBackgroundRepeat, int, 
// ����<10>��atomBackgroundPositon, int, 
// ����<11>��atomBackgroundGrid, int, 
// ����<12>��atomBackgroundFlags, int, 
// ����<13>��dwAlpha, int, ͸����(0-255)
//======================================================
EX_DEFINE_API(Ex_ThemeDrawControlEx, BOOL, (int hTheme, HEXCANVAS hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom, int atomClass, int atomSrcRect, int atomBackgroundRepeat, int atomBackgroundPositon, int atomBackgroundGrid, int atomBackgroundFlags, int dwAlpha));

//======================================================
// �������ƣ�_font_getcontext
// �������ͣ�int
// ����˵����
// ����<1>��hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_getcontext, int, (HEXFONT hFont));

//======================================================
// �������ƣ�Ex_ObjTooltipsSetText
// �������ͣ�BOOL
// ����˵����������ʾ�ı�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpString, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsSetText, BOOL, (HEXOBJ hObj, LPCWSTR lpString));

//======================================================
// �������ƣ�Ex_TrackPopupMenu
// �������ͣ�BOOL
// ����˵���������˵�
// ����<1>��hMenu, int, �˵����
// ����<2>��uFlags, int, ��س��� TPM_
// ����<3>��x, int, ��������X(��Ļ����)
// ����<4>��y, int, ��������Y(��Ļ����)
// ����<5>��nReserved, int, 0.����
// ����<6>��handle, EXHANDLE, ������/������/���ھ��.(�����ֵΪ���ھ���Ҵ���δʹ��������Ⱦ,����Ĭ�ϲ˵�����)
// ����<7>��lpRc, int, 0.����
// ����<8>��pfnCallback, ExObjEventHandler, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
// ����<9>��dwFlags, int, ��س��� EMNF_
//======================================================
EX_DEFINE_API(Ex_TrackPopupMenu, BOOL, (int hMenu, int uFlags, int x, int y, int nReserved, EXHANDLE handle, int lpRc, ExObjEventHandler pfnCallback, int dwFlags));

//======================================================
// �������ƣ�Ex_DUIFromWindow
// �������ͣ�int
// ����˵�����Ӵ��ھ����ȡ������
// ����<1>��hWnd, HWND, 
//======================================================
EX_DEFINE_API(Ex_DUIFromWindow, int, (HWND hWnd));

//======================================================
// �������ƣ�Ex_ObjScrollGetRange
// �������ͣ�BOOL
// ����˵������ȡ��������Χ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, 
// ����<3>��lpnMinPos, int, 
// ����<4>��lpnMaxPos, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetRange, BOOL, (HEXOBJ hObj, int nBar, int lpnMinPos, int lpnMaxPos));

//======================================================
// �������ƣ�Ex_ObjScrollGetTrackPos
// �������ͣ�int
// ����˵������ȡ�������϶�λ��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nBar, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetTrackPos, int, (HEXOBJ hObj, int nBar));

//======================================================
// �������ƣ�Ex_ObjScrollGetInfo
// �������ͣ�BOOL
// ����˵������ȡ��������Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fnBar, int, 
// ����<3>��lpnMin, int, 
// ����<4>��lpnMax, int, 
// ����<5>��lpnPos, int, 
// ����<6>��lpnTrackPos, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetInfo, BOOL, (HEXOBJ hObj, int fnBar, int lpnMin, int lpnMax, int lpnPos, int lpnTrackPos));

//======================================================
// �������ƣ�Ex_ObjLoadFromLayout
// �������ͣ�BOOL
// ����˵��������XML����
// ����<1>��handle, EXHANDLE, ���ھ��/������/������
// ����<2>��hRes, int, ��Դ���.(ֵ��Ϊ0)
// ����<3>��lpLayout, int, ������Դָ��
// ����<4>��cbLayout, int, ������Դ����
//======================================================
EX_DEFINE_API(Ex_ObjLoadFromLayout, BOOL, (EXHANDLE handle, int hRes, int lpLayout, int cbLayout));

//======================================================
// �������ƣ�Ex_ObjGetFromNodeID
// �������ͣ�int
// ����˵����
// ����<1>��hExDUIOrObj, int, 
// ����<2>��nNodeID, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromNodeID, int, (int hExDUIOrObj, int nNodeID));

//======================================================
// �������ƣ�_fmt_const
// �������ͣ�BOOL
// ����˵����
// ����<1>��const, int, in/out
// ����<2>��consts, int, atom
// ����<3>��values, int, value
// ����<4>��nCount, int, 
//======================================================
EX_DEFINE_API(_fmt_const, BOOL, (int const, int consts, int values, int nCount));

//======================================================
// �������ƣ�Ex_JSBindObject
// �������ͣ�int
// ����˵�������Լ���JS����
// ����<1>��hExDUI_hObj, int, ������ΪDUI
// ����<2>��szObjName, int, 
// ����<3>��lpfnDispatch, int, HRESULT DispatchFunc (this,atomName,hExDUI,pvParam,wFlags,pDispParams,pVarResult,lpDispInfo)
// ����<4>��pvParam, int, 
//======================================================
EX_DEFINE_API(Ex_JSBindObject, int, (int hExDUI_hObj, int szObjName, int lpfnDispatch, int pvParam));

//======================================================
// �������ƣ�Ex_JSEval
// �������ͣ�int
// ����˵����
// ����<1>��hExDUI_hObj, int, 
// ����<2>��szExpression, int, 
// ����<3>��fUseThis, BOOL, Ϊ��ʱ���ʽ��this�������1��Ӧ��JS����
// ����<4>��pVarResult, int, ��ΪNULLʱ�Ὣ����ֵд��,ע���ͷ�
//======================================================
EX_DEFINE_API(Ex_JSEval, int, (int hExDUI_hObj, int szExpression, BOOL fUseThis, int pVarResult));

//======================================================
// �������ƣ�Ex_JSAddCode
// �������ͣ�BOOL
// ����˵����
// ����<1>��hExDUI_hObj, int, 
// ����<2>��szCode, LPCSTR, 
//======================================================
EX_DEFINE_API(Ex_JSAddCode, BOOL, (int hExDUI_hObj, LPCSTR szCode));

//======================================================
// �������ƣ�Ex_JSGetLastError
// �������ͣ�BOOL
// ����˵����
// ����<1>��hExDUI_hObj, int, 
// ����<2>��nErrCode, int, 
// ����<3>��nErrLine, int, 
// ����<4>��szErrMsg, int, char[1024]
//======================================================
EX_DEFINE_API(Ex_JSGetLastError, BOOL, (int hExDUI_hObj, int nErrCode, int nErrLine, int szErrMsg));

//======================================================
// �������ƣ�Ex_JSRegisterFunction
// �������ͣ�BOOL
// ����˵����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��notyfiCode, int, 
// ����<3>��szFuncName, int, 
//======================================================
EX_DEFINE_API(Ex_JSRegisterFunction, BOOL, (HEXOBJ hObj, int notyfiCode, int szFuncName));

//======================================================
// �������ƣ�Ex_JSSetVariant
// �������ͣ�void
// ����˵����
// ����<1>��pVariant, int, 
// ����<2>��nType, int, 
// ����<3>��dwValue, int, 
//======================================================
EX_DEFINE_API(Ex_JSSetVariant, void, (int pVariant, int nType, int dwValue));

//======================================================
// �������ƣ�Ex_JSSetVariantPtr
// �������ͣ�void
// ����˵����
// ����<1>��pVariant, int, 
// ����<2>��nType, int, 
// ����<3>��pValue, int, 
// ����<4>��cbSize, int, 1,2,4,8
//======================================================
EX_DEFINE_API(Ex_JSSetVariantPtr, void, (int pVariant, int nType, int pValue, int cbSize));

//======================================================
// �������ƣ�Ex_JSGetParamCount
// �������ͣ�int
// ����˵����
// ����<1>��lpParams, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamCount, int, (int lpParams));

//======================================================
// �������ƣ�Ex_JSGetParamType
// �������ͣ�int
// ����˵����
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamType, int, (int lpParams, int nIndex));

//======================================================
// �������ƣ�Ex_JSGetParam
// �������ͣ�int
// ����˵��������pVar
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParam, int, (int lpParams, int nIndex));

//======================================================
// �������ƣ�Ex_JSGetParamNumber
// �������ͣ�double
// ����˵����
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
// ����<3>��nDefault, double, 
// ����<4>��pType, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamNumber, double, (int lpParams, int nIndex, double nDefault, int pType));

//======================================================
// �������ƣ�Ex_JSGetParamInt
// �������ͣ�int
// ����˵����
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
// ����<3>��nDefault, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamInt, int, (int lpParams, int nIndex, int nDefault));

//======================================================
// �������ƣ�Ex_JSGetParamFloat
// �������ͣ�float
// ����˵����
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
// ����<3>��nDefault, float, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamFloat, float, (int lpParams, int nIndex, float nDefault));

//======================================================
// �������ƣ�Ex_JSGetParamDouble
// �������ͣ�double
// ����˵����
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
// ����<3>��nDefault, double, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamDouble, double, (int lpParams, int nIndex, double nDefault));

//======================================================
// �������ƣ�Ex_JSGetParamString
// �������ͣ�int
// ����˵����wchar_t* ��Ҫ�ͷ�
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamString, int, (int lpParams, int nIndex));

//======================================================
// �������ƣ�Ex_JSGetParamToString
// �������ͣ�int
// ����˵����wchar_t* ��Ҫ�Լ��ͷ�
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
// ����<3>��wzDefault, int, 
// ����<4>��pType, int, 
// ����<5>��fFormat, BOOL, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamToString, int, (int lpParams, int nIndex, int wzDefault, int pType, BOOL fFormat));

//======================================================
// �������ƣ�Ex_JSGetParamFormatString
// �������ͣ�int
// ����˵����wchar_t* ��Ҫ�Լ��ͷ�
// ����<1>��lpParams, int, 
// ����<2>��nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamFormatString, int, (int lpParams, int nIndex));

//======================================================
// �������ƣ�Ex_ObjGetRectEx
// �������ͣ�BOOL
// ����˵����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpRect, RECT*, 
// ����<3>��nType, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetRectEx, BOOL, (HEXOBJ hObj, RECT* lpRect, int nType));

//======================================================
// �������ƣ�Ex_ObjLayoutGet
// �������ͣ�int
// ����˵������ȡ���ֶ�����
// ����<1>��handle, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutGet, int, (EXHANDLE handle));

//======================================================
// �������ƣ�Ex_ObjLayoutSet
// �������ͣ�BOOL
// ����˵�������ò��ֶ�����
// ����<1>��handle, EXHANDLE, 
// ����<2>��hLayout, HEXLAYOUT, 
// ����<3>��fUpdate, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutSet, BOOL, (EXHANDLE handle, HEXLAYOUT hLayout, BOOL fUpdate));

//======================================================
// �������ƣ�Ex_ObjLayoutUpdate
// �������ͣ�BOOL
// ����˵�������¶��󲼾�
// ����<1>��handle, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutUpdate, BOOL, (EXHANDLE handle));

//======================================================
// �������ƣ�Ex_ObjLayoutClear
// �������ͣ�BOOL
// ����˵������ն��󲼾���Ϣ
// ����<1>��handle, EXHANDLE, 
// ����<2>��bChildren, BOOL, �Ƿ�������������,����Ϊ��ǰ���.
//======================================================
EX_DEFINE_API(Ex_ObjLayoutClear, BOOL, (EXHANDLE handle, BOOL bChildren));

//======================================================
// �������ƣ�_layout_table_setinfo
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��aRowHeight, int, 
// ����<3>��cRows, int, 
// ����<4>��aCellWidth, int, 
// ����<5>��cCells, int, 
//======================================================
EX_DEFINE_API(_layout_table_setinfo, BOOL, (HEXLAYOUT hLayout, int aRowHeight, int cRows, int aCellWidth, int cCells));

//======================================================
// �������ƣ�Ex_ObjSetPadding
// �������ͣ�BOOL
// ����˵�����������ƫ�ƾ���
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nPaddingType, int, EOPT_TEXT=0
// ����<3>��left, int, 
// ����<4>��top, int, 
// ����<5>��right, int, 
// ����<6>��bottom, int, 
// ����<7>��fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetPadding, BOOL, (HEXOBJ hObj, int nPaddingType, int left, int top, int right, int bottom, BOOL fRedraw));

//======================================================
// �������ƣ�Ex_ObjSetFontFromFamily
// �������ͣ�BOOL
// ����˵������������ı�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpszFontfamily, LPCWSTR, -1 ΪĬ������
// ����<3>��dwFontsize, int, -1 ΪĬ�ϳߴ�
// ����<4>��dwFontstyle, int, -1 ΪĬ�Ϸ��
// ����<5>��fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFontFromFamily, BOOL, (HEXOBJ hObj, LPCWSTR lpszFontfamily, int dwFontsize, int dwFontstyle, BOOL fRedraw));

//======================================================
// �������ƣ�Ex_ObjGetFont
// �������ͣ�HEXFONT
// ����˵������ȡ���塣�û���Ӧ�����ٸ��������
// ����<1>��hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFont, HEXFONT, (HEXOBJ hObj));

//======================================================
// �������ƣ�Ex_ObjPointTransform
// �������ͣ�void
// ����˵����
// ����<1>��hObjSrc, int, 
// ����<2>��hObjDst, int, 0Ϊ��������
// ����<3>��ptX, int, in/out
// ����<4>��ptY, int, in/out
//======================================================
EX_DEFINE_API(Ex_ObjPointTransform, void, (int hObjSrc, int hObjDst, int ptX, int ptY));

//======================================================
// �������ƣ�Ex_ObjEnableEventBubble
// �������ͣ�BOOL
// ����˵�������øÿؼ��Ƿ������¼�ð��
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fEnable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjEnableEventBubble, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// �������ƣ�Ex_ObjGetClassInfo
// �������ͣ�BOOL
// ����˵������ȡ�������Ϣ
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpClassInfo, int, ��ؽṹ EX_CLASSINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetClassInfo, BOOL, (HEXOBJ hObj, int lpClassInfo));

//======================================================
// �������ƣ�Ex_ObjGetClassInfoEx
// �������ͣ�BOOL
// ����˵����ͨ������/��ATOM��ȡ����Ϣ
// ����<1>��wzClassName, int, wzClassName/AtomClassName
// ����<2>��lpClassInfo, int, ��ؽṹ EX_CLASSINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetClassInfoEx, BOOL, (int wzClassName, int lpClassInfo));

//======================================================
// �������ƣ�_easing_curve_load
// �������ͣ�int
// ����˵����
// ����<1>��lpCurveInfo, int, 
// ����<2>��cbCurveInfo, int, 
//======================================================
EX_DEFINE_API(_easing_curve_load, int, (int lpCurveInfo, int cbCurveInfo));

//======================================================
// �������ƣ�_easing_curve_free
// �������ͣ�void
// ����˵����
// ����<1>��pCurveInfo, int, 
//======================================================
EX_DEFINE_API(_easing_curve_free, void, (int pCurveInfo));

//======================================================
// �������ƣ�_easing_create
// �������ͣ�int
// ����˵����
// ����<1>��dwType, int, #��������_
// ����<2>��pEasingContext, int, 
// ����<3>��dwMode, int, #����ģʽ_ �����
// ����<4>��pContext, int, 
// ����<5>��nTotalTime, int, ms
// ����<6>��nInterval, int, ms
// ����<7>��nState, int, #EES_
// ����<8>��nStart, int, 
// ����<9>��nStop, int, 
// ����<10>��param1, int, 
// ����<11>��param2, int, 
// ����<12>��param3, int, 
// ����<13>��param4, int, 
//======================================================
EX_DEFINE_API(_easing_create, int, (int dwType, int pEasingContext, int dwMode, int pContext, int nTotalTime, int nInterval, int nState, int nStart, int nStop, int param1, int param2, int param3, int param4));

//======================================================
// �������ƣ�_easing_setstate
// �������ͣ�BOOL
// ����˵����
// ����<1>��pEasing, HEXEASING, 
// ����<2>��nState, int, #EES_
//======================================================
EX_DEFINE_API(_easing_setstate, BOOL, (HEXEASING pEasing, int nState));

//======================================================
// �������ƣ�Ex_Sleep
// �������ͣ�void
// ����˵����
// ����<1>��us, int, 
//======================================================
EX_DEFINE_API(Ex_Sleep, void, (int us));

//======================================================
// �������ƣ�_easing_getstate
// �������ͣ�int
// ����˵����
// ����<1>��pEasing, HEXEASING, 
//======================================================
EX_DEFINE_API(_easing_getstate, int, (HEXEASING pEasing));

//======================================================
// �������ƣ�_layout_absolute_setedge
// �������ͣ�BOOL
// ����˵����
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObjChild, HEXOBJ, 
// ����<3>��dwEdge, int, #ELCP_ABSOLUTE_XXX
// ����<4>��dwType, int, 
// ����<5>��nValue, int, 
//======================================================
EX_DEFINE_API(_layout_absolute_setedge, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObjChild, int dwEdge, int dwType, int nValue));

//======================================================
// �������ƣ�_layout_absolute_lock
// �������ͣ�BOOL
// ����˵��������ǰλ������
// ����<1>��hLayout, HEXLAYOUT, 
// ����<2>��hObjChild, HEXOBJ, 
// ����<3>��tLeft, int, #ELCP_ABSOLUTE_XXX_TYPE ��ͬ
// ����<4>��tTop, int, 
// ����<5>��tRight, int, 
// ����<6>��tBottom, int, 
// ����<7>��tWidth, int, 
// ����<8>��tHeight, int, 
//======================================================
EX_DEFINE_API(_layout_absolute_lock, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObjChild, int tLeft, int tTop, int tRight, int tBottom, int tWidth, int tHeight));

//======================================================
// �������ƣ�Ex_ObjInitPropList
// �������ͣ�BOOL
// ����˵����Ҫע��ÿ�γ�ʼ���������֮ǰ�洢������,���洢����ָ����Ҫ�Լ������ͷ�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��nPropCount, int, -1Ϊ��ϣ��ģʽ,0Ϊ���洢����,����Ϊ���Ը���(ÿ��4�ֽ�)
//======================================================
EX_DEFINE_API(Ex_ObjInitPropList, BOOL, (HEXOBJ hObj, int nPropCount));

//======================================================
// �������ƣ�Ex_ObjRemoveProp
// �������ͣ�int
// ����˵�����Ƴ�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��dwKey, int, 
//======================================================
EX_DEFINE_API(Ex_ObjRemoveProp, int, (HEXOBJ hObj, int dwKey));

//======================================================
// �������ƣ�Ex_ObjEnumProps
// �������ͣ�int
// ����˵�������ظ���.ö�����Ա�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��lpfnCbk, int, bool enum(hObj,dwKey,dwValue,param)
// ����<3>��param, int, 
//======================================================
EX_DEFINE_API(Ex_ObjEnumProps, int, (HEXOBJ hObj, int lpfnCbk, int param));

//======================================================
// �������ƣ�_brush_createfromcanvas
// �������ͣ�HEXBRUSH
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_brush_createfromcanvas, HEXBRUSH, (HEXCANVAS hCanvas));

//======================================================
// �������ƣ�Ex_ObjSetRadius
// �������ͣ�BOOL
// ����˵�����������Բ�Ƕ�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��topleft, float, ���Ͻ�
// ����<3>��topright, float, ���Ͻ�
// ����<4>��bottomright, float, ���½�
// ����<5>��bottomleft, float, ���½�
// ����<6>��fUpdate, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetRadius, BOOL, (HEXOBJ hObj, float topleft, float topright, float bottomright, float bottomleft, BOOL fUpdate));

//======================================================
// �������ƣ�_path_reset
// �������ͣ�int
// ����˵��������·��
// ����<1>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_reset, int, (HEXPATH* hPath));

//======================================================
// �������ƣ�_path_getbounds
// �������ͣ�int
// ����˵����ȡ·���߽����
// ����<1>��hPath, HEXPATH*, 
// ����<2>��lpBounds, int, RECTF
//======================================================
EX_DEFINE_API(_path_getbounds, int, (HEXPATH* hPath, int lpBounds));

//======================================================
// �������ƣ�_path_close
// �������ͣ�int
// ����˵�����ر�·��
// ����<1>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_close, int, (HEXPATH* hPath));

//======================================================
// �������ƣ�_path_open
// �������ͣ�int
// ����˵������·��
// ����<1>��hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_open, int, (HEXPATH* hPath));

//======================================================
// �������ƣ�_path_addarc
// �������ͣ�int
// ����˵������ӻ� (�ѹ�ʱ,���Ƽ�ʹ��)
// ����<1>��hPath, HEXPATH*, 
// ����<2>��x1, float, ��ʼ����X
// ����<3>��y1, float, ��ʼ����Y
// ����<4>��x2, float, �յ�����X
// ����<5>��y2, float, �յ�����Y
// ����<6>��radiusX, float, �뾶X
// ����<7>��radiusY, float, �뾶Y
// ����<8>��fClockwise, BOOL, �Ƿ�˳ʱ��
//======================================================
EX_DEFINE_API(_path_addarc, int, (HEXPATH* hPath, float x1, float y1, float x2, float y2, float radiusX, float radiusY, BOOL fClockwise));

//======================================================
// �������ƣ�_path_addarc2
// �������ͣ�int
// ����˵������ӻ� v2
// ����<1>��hPath, HEXPATH*, 
// ����<2>��x, float, 
// ����<3>��y, float, 
// ����<4>��width, float, ���
// ����<5>��height, float, �߶�
// ����<6>��startAngle, float, ��ʼ�Ƕ�
// ����<7>��sweepAngle, float, ɨ��Ƕ�
//======================================================
EX_DEFINE_API(_path_addarc2, int, (HEXPATH* hPath, float x, float y, float width, float height, float startAngle, float sweepAngle));

//======================================================
// �������ƣ�_canvas_drawpath
// �������ͣ�int
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hPath, HEXPATH*, 
// ����<3>��hBrush, HEXBRUSH, 
// ����<4>��strokeWidth, float, 
// ����<5>��strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawpath, int, (HEXCANVAS hCanvas, HEXPATH* hPath, HEXBRUSH hBrush, float strokeWidth, int strokeStyle));

//======================================================
// �������ƣ�_canvas_fillpath
// �������ͣ�int
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��hPath, HEXPATH*, 
// ����<3>��hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_canvas_fillpath, int, (HEXCANVAS hCanvas, HEXPATH* hPath, HEXBRUSH hBrush));

//======================================================
// �������ƣ�_path_addrect
// �������ͣ�int
// ����˵������Ӿ���
// ����<1>��hPath, HEXPATH*, 
// ����<2>��left, float, 
// ����<3>��top, float, 
// ����<4>��right, float, 
// ����<5>��bottom, float, 
//======================================================
EX_DEFINE_API(_path_addrect, int, (HEXPATH* hPath, float left, float top, float right, float bottom));

//======================================================
// �������ƣ�_path_addroundedrect
// �������ͣ�int
// ����˵�������Բ�Ǿ���
// ����<1>��hPath, HEXPATH*, 
// ����<2>��left, float, 
// ����<3>��top, float, 
// ����<4>��right, float, 
// ����<5>��bottom, float, 
// ����<6>��radiusTopLeft, float, 
// ����<7>��radiusTopRight, float, 
// ����<8>��radiusBottomLeft, float, 
// ����<9>��radiusBottomRight, float, 
// ����<10>��unit, int, 
//======================================================
EX_DEFINE_API(_path_addroundedrect, int, (HEXPATH* hPath, float left, float top, float right, float bottom, float radiusTopLeft, float radiusTopRight, float radiusBottomLeft, float radiusBottomRight, int unit));

//======================================================
// �������ƣ�_path_hittest
// �������ͣ�BOOL
// ����˵�������������Ƿ��ڿɼ�·����
// ����<1>��hPath, HEXPATH*, 
// ����<2>��x, float, 
// ����<3>��y, float, 
//======================================================
EX_DEFINE_API(_path_hittest, BOOL, (HEXPATH* hPath, float x, float y));

//======================================================
// �������ƣ�_brush_settransform
// �������ͣ�int
// ����˵����
// ����<1>��hBrush, HEXBRUSH, 
// ����<2>��matrix, int, 
//======================================================
EX_DEFINE_API(_brush_settransform, int, (HEXBRUSH hBrush, int matrix));

//======================================================
// �������ƣ�Ex_ObjScrollShow
// �������ͣ�BOOL
// ����˵������ʾ/���ع�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��wBar, int, ֧��SB_BOTH
// ����<3>��fShow, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollShow, BOOL, (HEXOBJ hObj, int wBar, BOOL fShow));

//======================================================
// �������ƣ�Ex_ObjScrollEnable
// �������ͣ�BOOL
// ����˵��������/���ù�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��wSB, int, ֧��SB_BOTH
// ����<3>��wArrows, int, ��س��� ESB_
//======================================================
EX_DEFINE_API(Ex_ObjScrollEnable, BOOL, (HEXOBJ hObj, int wSB, int wArrows));

//======================================================
// �������ƣ�_font_copy
// �������ͣ�int
// ����˵����
// ����<1>��hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_copy, int, (HEXFONT hFont));

//======================================================
// �������ƣ�Ex_JSLoadConst
// �������ͣ�void
// ����˵��������JS����
// ����<1>��szConst, LPCSTR, 
//======================================================
EX_DEFINE_API(Ex_JSLoadConst, void, (LPCSTR szConst));

//======================================================
// �������ƣ�Ex_ObjSetFont
// �������ͣ�BOOL
// ����˵������������ı�����
// ����<1>��hObj, HEXOBJ, 
// ����<2>��hFont, HEXFONT, _font_createxxx
// ����<3>��fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFont, BOOL, (HEXOBJ hObj, HEXFONT hFont, BOOL fRedraw));

//======================================================
// �������ƣ�_imglist_create
// �������ͣ�int
// ����˵��������ͼƬ��
// ����<1>��nWidth, int, ���
// ����<2>��nHeight, int, �߶�
//======================================================
EX_DEFINE_API(_imglist_create, int, (int nWidth, int nHeight));

//======================================================
// �������ƣ�_imglist_destroy
// �������ͣ�void
// ����˵��������ͼƬ��
// ����<1>��hImageList, int, ͼƬ����
//======================================================
EX_DEFINE_API(_imglist_destroy, void, (int hImageList));

//======================================================
// �������ƣ�_imglist_add
// �������ͣ�int
// ����˵�������ͼƬ
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��lpImage, int, ͼ������ָ��
// ����<3>��cbImage, int, ͼ�����ݳ���
// ����<4>��nIndexInsert, int, ����λ��(0Ϊ���)
//======================================================
EX_DEFINE_API(_imglist_add, int, (int hImageList, int lpImage, int cbImage, int nIndexInsert));

//======================================================
// �������ƣ�_imglist_addimage
// �������ͣ�int
// ����˵�������ͼƬ
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��hImage, HEXIMAGE, ͼ�������
// ����<3>��nIndexInsert, int, ����λ��(0Ϊ���)
//======================================================
EX_DEFINE_API(_imglist_addimage, int, (int hImageList, HEXIMAGE hImage, int nIndexInsert));

//======================================================
// �������ƣ�_imglist_del
// �������ͣ�int
// ����˵����ɾ��ͼƬ
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��nIndex, int, ͼƬ����
//======================================================
EX_DEFINE_API(_imglist_del, int, (int hImageList, int nIndex));

//======================================================
// �������ƣ�_imglist_get
// �������ͣ�int
// ����˵������ȡͼƬ���
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��nIndex, int, ͼƬ����
//======================================================
EX_DEFINE_API(_imglist_get, int, (int hImageList, int nIndex));

//======================================================
// �������ƣ�_imglist_set
// �������ͣ�int
// ����˵��������ͼƬ
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��nIndex, int, ͼƬ����
// ����<3>��lpImage, int, ͼƬ����ָ��
// ����<4>��cbImage, int, ͼƬ���ݳ���
//======================================================
EX_DEFINE_API(_imglist_set, int, (int hImageList, int nIndex, int lpImage, int cbImage));

//======================================================
// �������ƣ�_imglist_setimage
// �������ͣ�int
// ����˵��������ͼƬ
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��nIndex, int, ͼƬ����
// ����<3>��hImage, HEXIMAGE, ͼ�������
//======================================================
EX_DEFINE_API(_imglist_setimage, int, (int hImageList, int nIndex, HEXIMAGE hImage));

//======================================================
// �������ƣ�_imglist_count
// �������ͣ�int
// ����˵������ȡͼƬ��ͼƬ����
// ����<1>��hImageList, int, ͼƬ����
//======================================================
EX_DEFINE_API(_imglist_count, int, (int hImageList));

//======================================================
// �������ƣ�_imglist_size
// �������ͣ�void
// ����˵������ȡͼƬ��ͼƬ�ߴ�
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��pWidth, int, ͼƬ���
// ����<3>��pHeight, int, ͼƬ�߶�
//======================================================
EX_DEFINE_API(_imglist_size, void, (int hImageList, int pWidth, int pHeight));

//======================================================
// �������ƣ�_imglist_draw
// �������ͣ�BOOL
// ����˵��������ͼƬ(ͼƬ�������л��Ƶ��ṩ�ľ�����)
// ����<1>��hImageList, int, ͼƬ����
// ����<2>��nIndex, int, ͼƬ����
// ����<3>��hCanvas, HEXCANVAS, �������
// ����<4>��nLeft, int, ���
// ����<5>��nTop, int, ����
// ����<6>��nRight, int, �ұ�
// ����<7>��nBottom, int, �ױ�
// ����<8>��nAlpha, int, ͸����0-255
//======================================================
EX_DEFINE_API(_imglist_draw, BOOL, (int hImageList, int nIndex, HEXCANVAS hCanvas, int nLeft, int nTop, int nRight, int nBottom, int nAlpha));

//======================================================
// �������ƣ�Ex_ObjEnableIME
// �������ͣ�BOOL
// ����˵�����Ƿ������������뷨
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fEnable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjEnableIME, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// �������ƣ�Ex_ObjSetIMEState
// �������ͣ�BOOL
// ����˵�������ô��ڵ����뷨״̬
// ����<1>��hObjOrExDui, int, 
// ����<2>��fOpen, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetIMEState, BOOL, (int hObjOrExDui, BOOL fOpen));

//======================================================
// �������ƣ�Ex_ObjDisableTranslateSpaceAndEnterToClick
// �������ͣ�BOOL
// ����˵�������ÿؼ��Ƿ��ֹת���ո�ͻس�Ϊ�����¼�
// ����<1>��hObj, HEXOBJ, 
// ����<2>��fDisable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjDisableTranslateSpaceAndEnterToClick, BOOL, (HEXOBJ hObj, BOOL fDisable));

//======================================================
// �������ƣ�_canvas_settextantialiasmode
// �������ͣ�BOOL
// ����˵�������û����ı������ģʽ
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��textAntialiasMode, int, 0.������� 1.����� 2.ClearType
//======================================================
EX_DEFINE_API(_canvas_settextantialiasmode, BOOL, (HEXCANVAS hCanvas, int textAntialiasMode));

//======================================================
// �������ƣ�_canvas_setantialias
// �������ͣ�BOOL
// ����˵�������û���ͼ�ο����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��antialias, BOOL, �Ƿ񿹾��
//======================================================
EX_DEFINE_API(_canvas_setantialias, BOOL, (HEXCANVAS hCanvas, BOOL antialias));

//======================================================
// �������ƣ�_canvas_setimageantialias
// �������ͣ�BOOL
// ����˵�������û���ͼ�񿹾��
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��antialias, BOOL, �Ƿ񿹾��
//======================================================
EX_DEFINE_API(_canvas_setimageantialias, BOOL, (HEXCANVAS hCanvas, BOOL antialias));

//======================================================
// �������ƣ�Ex_ObjSetParent
// �������ͣ�int
// ����˵�����ø�
// ����<1>��hObj, HEXOBJ, ���ø����ӿؼ�
// ����<2>��hParent, EXHANDLE, �µĸ��ؼ�/Ƥ��/���� ���
//======================================================
EX_DEFINE_API(Ex_ObjSetParent, int, (HEXOBJ hObj, EXHANDLE hParent));

//======================================================
// �������ƣ�_brush_createlinear
// �������ͣ�HEXBRUSH
// ����˵�����������Խ��仭ˢ
// ����<1>��xs, float, ���X
// ����<2>��ys, float, ���Y
// ����<3>��xe, float, �յ�X
// ����<4>��ye, float, �յ�Y
// ����<5>��crBegin, int, �����ɫARGB
// ����<6>��crEnd, int, �յ���ɫARGB
//======================================================
EX_DEFINE_API(_brush_createlinear, HEXBRUSH, (float xs, float ys, float xe, float ye, int crBegin, int crEnd));

//======================================================
// �������ƣ�_brush_createlinear_ex
// �������ͣ�HEXBRUSH
// ����˵�����������Խ��仭ˢ2
// ����<1>��xs, float, ���X
// ����<2>��ys, float, ���Y
// ����<3>��xe, float, �յ�X
// ����<4>��ye, float, �յ�Y
// ����<5>��arrStopPts, int, ֹͣ��ָ��,{λ��(0-100),��ɫ(ARGB),λ��,��ɫ,...}
// ����<6>��cStopPts, int, ֹͣ�����
//======================================================
EX_DEFINE_API(_brush_createlinear_ex, HEXBRUSH, (float xs, float ys, float xe, float ye, int arrStopPts, int cStopPts));

//======================================================
// �������ƣ�_path_beginfigure2
// �������ͣ�int
// ����˵������ʼͼ��(��������ʼ��,D2D��Ч,GDIģʽ��beginfigureһ��)
// ����<1>��hPath, HEXPATH*, 
// ����<2>��x, float, ��ʼ����
// ����<3>��y, float, ��ʼ����
//======================================================
EX_DEFINE_API(_path_beginfigure2, int, (HEXPATH* hPath, float x, float y));

//======================================================
// �������ƣ�Ex_LoadImageFromMemory
// �������ͣ�int
// ����˵��������ͼ��������ڴ�(����λͼ�����ͼ����)
// ����<1>��lpData, LPBYTE, ͼ������ָ��
// ����<2>��dwLen, size_t, ͼ�����ݳ���
// ����<3>��uType, int, ͼ������ #IMAGE_
// ����<4>��nIndex, int, ����
//======================================================
EX_DEFINE_API(Ex_LoadImageFromMemory, int, (LPBYTE lpData, size_t dwLen, int uType, int nIndex));

//======================================================
// �������ƣ�_brush_createfromcanvas2
// �������ͣ�HEXBRUSH
// ����˵������ˢ_�����Ի���2
// ����<1>��hCanvas, HEXCANVAS, �������
// ����<2>��nAlpha, int, ͸����
//======================================================
EX_DEFINE_API(_brush_createfromcanvas2, HEXBRUSH, (HEXCANVAS hCanvas, int nAlpha));

//======================================================
// �������ƣ�_img_savetofile
// �������ͣ�int
// ����˵����ͼ��_�����ļ�
// ����<1>��hImg, HEXIMAGE, ͼ����
// ����<2>��wzFileName, LPCWSTR, ������ļ���
//======================================================
EX_DEFINE_API(_img_savetofile, int, (HEXIMAGE hImg, LPCWSTR wzFileName));

//======================================================
// �������ƣ�_img_savetomemory
// �������ͣ�int
// ����˵�������س���
// ����<1>��hImg, HEXIMAGE, ͼ����
// ����<2>��lpBuffer, LPBYTE, ��䱣��Ļ�����(0��ֻ�Ƿ��س���)
//======================================================
EX_DEFINE_API(_img_savetomemory, int, (HEXIMAGE hImg, LPBYTE lpBuffer));

//======================================================
// �������ƣ�_canvas_drawcanvas
// �������ͣ�BOOL
// ����˵����
// ����<1>��hCanvas, HEXCANVAS, 
// ����<2>��sCanvas, int, 
// ����<3>��dstLeft, int, 
// ����<4>��dstTop, int, 
// ����<5>��dstRight, int, 
// ����<6>��dstBottom, int, 
// ����<7>��srcLeft, int, 
// ����<8>��srcTop, int, 
// ����<9>��dwAlpha, int, 
// ����<10>��dwCompositeMode, int, #CV_COMPOSITE_MODE_
//======================================================
EX_DEFINE_API(_canvas_drawcanvas, BOOL, (HEXCANVAS hCanvas, int sCanvas, int dstLeft, int dstTop, int dstRight, int dstBottom, int srcLeft, int srcTop, int dwAlpha, int dwCompositeMode));

