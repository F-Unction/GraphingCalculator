#pragma once


//======================================================
// 函数名称：Ex_Init
// 返回类型：BOOL
// 函数说明：初始化引擎.
// 参数<1>：hInstance, HINSTANCE, (值可为0)
// 参数<2>：dwGlobalFlags, int, 相关常量:#EXGF_ .(值可为0)
// 参数<3>：hDefaultCursor, int, 默认鼠标指针.(值可为0)
// 参数<4>：lpszDefaultClassName, int, 默认窗口类名.(值可为0)
// 参数<5>：lpDefaultTheme, LPBYTE, 默认主题包指针.
// 参数<6>：dwDefaultThemeLen, size_t, 默认主题包长度.
// 参数<7>：lpDefaultI18N, int, 默认语言包指针.(值可为0)
// 参数<8>：dwDefaultI18NLen, int, 默认语言包长度.(值可为0)
//======================================================
EX_DEFINE_API(Ex_Init, BOOL, (HINSTANCE hInstance, int dwGlobalFlags, int hDefaultCursor, int lpszDefaultClassName, LPBYTE lpDefaultTheme, size_t dwDefaultThemeLen, int lpDefaultI18N, int dwDefaultI18NLen));

//======================================================
// 函数名称：Ex_UnInit
// 返回类型：void
// 函数说明：反初始化引擎
//======================================================
EX_DEFINE_API(Ex_UnInit, void, ());

//======================================================
// 函数名称：Ex_GetLastError
// 返回类型：int
// 函数说明：获取最后错误代码.相关常量 :#ERROR_EX_
//======================================================
EX_DEFINE_API(Ex_GetLastError, int, ());

//======================================================
// 函数名称：_img_createfrommemory
// 返回类型：int
// 函数说明：创建自内存。成功返回0。
// 参数<1>：lpData, LPBYTE, 图像指针
// 参数<2>：dwLen, size_t, 图像长度
// 参数<3>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfrommemory, int, (LPBYTE lpData, size_t dwLen, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_create
// 返回类型：int
// 函数说明：创建图像。成功返回0。
// 参数<1>：width, int, 图像宽度
// 参数<2>：height, int, 图像高度
// 参数<3>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_create, int, (int width, int height, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_lock
// 返回类型：int
// 函数说明：锁定图像.成功返回0.
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：lpRectL, int, 锁定矩形指针，如果为0，则锁定整张图像。
// 参数<3>：flags, int, READ:1 / WRITE:2 / READ&WRITE:3
// 参数<4>：PixelFormat, int, 参考:https://msdn.microsoft.com/en-us/library/ms534412(v=vs.85).aspx
// 参数<5>：lpLockedBitmapData, EX_BITMAPDATA*, BITMAPDATA
//======================================================
EX_DEFINE_API(_img_lock, int, (HEXIMAGE hImg, int lpRectL, int flags, int PixelFormat, EX_BITMAPDATA* lpLockedBitmapData));

//======================================================
// 函数名称：_img_unlock
// 返回类型：int
// 函数说明：解锁图像.成功返回0.
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：lpLockedBitmapData, EX_BITMAPDATA*, 
//======================================================
EX_DEFINE_API(_img_unlock, int, (HEXIMAGE hImg, EX_BITMAPDATA* lpLockedBitmapData));

//======================================================
// 函数名称：_img_destroy
// 返回类型：int
// 函数说明：销毁图像
// 参数<1>：hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_destroy, int, (HEXIMAGE hImg));

//======================================================
// 函数名称：Ex_SetLastError
// 返回类型：void
// 函数说明：设置最后错误代码.相关常量 :#ERROR_EX_
// 参数<1>：nError, int, 
//======================================================
EX_DEFINE_API(Ex_SetLastError, void, (int nError));

//======================================================
// 函数名称：_img_getframecount
// 返回类型：int
// 函数说明：取图像帧数。成功返回0。
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：nFrameCount, int, 返回帧数.
//======================================================
EX_DEFINE_API(_img_getframecount, int, (HEXIMAGE hImg, int nFrameCount));

//======================================================
// 函数名称：_img_selectactiveframe
// 返回类型：int
// 函数说明：设置当前活动帧。成功返回0。
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：nIndex, int, 
//======================================================
EX_DEFINE_API(_img_selectactiveframe, int, (HEXIMAGE hImg, int nIndex));

//======================================================
// 函数名称：_img_createfromstream
// 返回类型：int
// 函数说明：创建自字节流。成功返回0。
// 参数<1>：lpStream, int, 
// 参数<2>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromstream, int, (int lpStream, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_createfromcanvas
// 返回类型：int
// 函数说明：(拷贝)创建自画布。成功返回0。
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromcanvas, int, (HEXCANVAS hCanvas, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_getframedelay
// 返回类型：int
// 函数说明：取图像帧延时。成功返回0。
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：lpDelayAry, int, 指针指向图像帧延时数组。
// 参数<3>：nFrames, int, 返回总帧数
//======================================================
EX_DEFINE_API(_img_getframedelay, int, (HEXIMAGE hImg, int lpDelayAry, int nFrames));

//======================================================
// 函数名称：_img_getsize
// 返回类型：int
// 函数说明：获取图像尺寸.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：lpWidth, int*, 
// 参数<3>：lpHeight, int*, 
//======================================================
EX_DEFINE_API(_img_getsize, int, (HEXIMAGE hImg, int* lpWidth, int* lpHeight));

//======================================================
// 函数名称：Ex_IsDxRender
// 返回类型：BOOL
// 函数说明：是否使用D2D渲染
//======================================================
EX_DEFINE_API(Ex_IsDxRender, BOOL, ());

//======================================================
// 函数名称：_img_width
// 返回类型：int
// 函数说明：返回宽度
// 参数<1>：hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_width, int, (HEXIMAGE hImg));

//======================================================
// 函数名称：_img_height
// 返回类型：int
// 函数说明：返回高度
// 参数<1>：hImg, HEXIMAGE, 
//======================================================
EX_DEFINE_API(_img_height, int, (HEXIMAGE hImg));

//======================================================
// 函数名称：_img_copy
// 返回类型：int
// 函数说明：复制图像.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：dstImg, HEXIMAGE, 返回新图像指针
//======================================================
EX_DEFINE_API(_img_copy, int, (HEXIMAGE hImg, HEXIMAGE dstImg));

//======================================================
// 函数名称：_img_copyrect
// 返回类型：int
// 函数说明：复制部分图像.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
// 参数<4>：width, int, 
// 参数<5>：height, int, 
// 参数<6>：dstImg, HEXIMAGE, 返回新图像指针
//======================================================
EX_DEFINE_API(_img_copyrect, int, (HEXIMAGE hImg, int x, int y, int width, int height, HEXIMAGE dstImg));

//======================================================
// 函数名称：_img_createfromhbitmap
// 返回类型：int
// 函数说明：创建自GDI位图句柄。成功返回0。
// 参数<1>：hBitmap, int, 
// 参数<2>：hPalette, int, 
// 参数<3>：fPreAlpha, BOOL, 是否预乘透明通道
// 参数<4>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromhbitmap, int, (int hBitmap, int hPalette, BOOL fPreAlpha, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_createfromhicon
// 返回类型：int
// 函数说明：创建自图标句柄。成功返回0。
// 参数<1>：hIcon, int, 
// 参数<2>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromhicon, int, (int hIcon, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_createfromfile
// 返回类型：int
// 函数说明：创建自文件。成功返回0。
// 参数<1>：wzFilename, LPCWSTR, 
// 参数<2>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromfile, int, (LPCWSTR wzFilename, HEXIMAGE* hImg));

//======================================================
// 函数名称：_img_getpixel
// 返回类型：int
// 函数说明：获取点像素,成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
// 参数<4>：color, int, 返回ARGB颜色
//======================================================
EX_DEFINE_API(_img_getpixel, int, (HEXIMAGE hImg, int x, int y, int color));

//======================================================
// 函数名称：_img_setpixel
// 返回类型：int
// 函数说明：设置点像素.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
// 参数<4>：color, int, argb
//======================================================
EX_DEFINE_API(_img_setpixel, int, (HEXIMAGE hImg, int x, int y, int color));

//======================================================
// 函数名称：_img_rotateflip
// 返回类型：int
// 函数说明：旋转翻转图像.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：rfType, int, 参考:https://msdn.microsoft.com/en-us/library/windows/desktop/ms534171(v=vs.85).aspx
//======================================================
EX_DEFINE_API(_img_rotateflip, int, (HEXIMAGE hImg, int rfType));

//======================================================
// 函数名称：_img_getthumbnail
// 返回类型：int
// 函数说明：取缩略图.成功返回0
// 参数<1>：hImg, HEXIMAGE, 
// 参数<2>：thumbWidth, int, 
// 参数<3>：thumbHeight, int, 
// 参数<4>：hImgThumbnail, int, 返回缩略图图像指针
//======================================================
EX_DEFINE_API(_img_getthumbnail, int, (HEXIMAGE hImg, int thumbWidth, int thumbHeight, int hImgThumbnail));

//======================================================
// 函数名称：_canvas_resize
// 返回类型：BOOL
// 函数说明：重新设置尺寸。
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：width, int, 
// 参数<3>：height, int, 
// 参数<4>：fCopy, BOOL, 
//======================================================
EX_DEFINE_API(_canvas_resize, BOOL, (HEXCANVAS hCanvas, int width, int height, BOOL fCopy));

//======================================================
// 函数名称：_canvas_getcontext
// 返回类型：int
// 函数说明：获取canvas上下文相关信息
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：nType, int, #CVC_
//======================================================
EX_DEFINE_API(_canvas_getcontext, int, (HEXCANVAS hCanvas, int nType));

//======================================================
// 函数名称：Ex_DUIBindWindowEx
// 返回类型：HEXDUI
// 函数说明：绑定窗口,成功返回引擎句柄,失败返回0.
// 参数<1>：hWnd, HWND, 窗口句柄
// 参数<2>：hTheme, int, 主题句柄.(值可为0)
// 参数<3>：dwStyle, DWORD, 相关常量:#EWS_
// 参数<4>：lParam, LPARAM, 附加参数.(值可为0)
// 参数<5>：lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
//======================================================
EX_DEFINE_API(Ex_DUIBindWindowEx, HEXDUI, (HWND hWnd, int hTheme, DWORD dwStyle, LPARAM lParam, ExMsgProc lpfnMsgProc));

//======================================================
// 函数名称：_canvas_createfromobj
// 返回类型：int
// 函数说明：创建画布自组件句柄。成功返回画布句柄，失败返回0
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：uWidth, int, 
// 参数<3>：uHeight, int, 
// 参数<4>：dwFlags, int, CVF_
// 参数<5>：nError, int, 
//======================================================
EX_DEFINE_API(_canvas_createfromobj, int, (HEXOBJ hObj, int uWidth, int uHeight, int dwFlags, int nError));

//======================================================
// 函数名称：Ex_WndRegisterClass
// 返回类型：int
// 函数说明：注册窗口类
// 参数<1>：lpwzClassName, LPCWSTR, 
// 参数<2>：hIcon, int, 
// 参数<3>：hIconsm, int, 
// 参数<4>：hCursor, int, 
//======================================================
EX_DEFINE_API(Ex_WndRegisterClass, int, (LPCWSTR lpwzClassName, int hIcon, int hIconsm, int hCursor));

//======================================================
// 函数名称：Ex_WndCreate
// 返回类型：HWND
// 函数说明：创建窗口
// 参数<1>：hWndParent, int, 
// 参数<2>：lpwzClassName, LPCWSTR, 
// 参数<3>：lpwzWindowName, LPCWSTR, 
// 参数<4>：x, int, 
// 参数<5>：y, int, 
// 参数<6>：Width, int, 
// 参数<7>：Height, int, 
// 参数<8>：dwStyle, DWORD, 
// 参数<9>：dwStyleEx, DWORD, 
//======================================================
EX_DEFINE_API(Ex_WndCreate, HWND, (int hWndParent, LPCWSTR lpwzClassName, LPCWSTR lpwzWindowName, int x, int y, int Width, int Height, DWORD dwStyle, DWORD dwStyleEx));

//======================================================
// 函数名称：Ex_WndMsgLoop
// 返回类型：int
// 函数说明：窗口消息循环
//======================================================
EX_DEFINE_API(Ex_WndMsgLoop, int, ());

//======================================================
// 函数名称：Ex_WndCenterFrom
// 返回类型：void
// 函数说明：窗口居中
// 参数<1>：hWnd, HWND, 预居中的原始窗口
// 参数<2>：hWndFrom, int, 预居中的目标窗口,如果为0则为屏幕居中.
// 参数<3>：bFullScreen, BOOL, 是否全屏模式
//======================================================
EX_DEFINE_API(Ex_WndCenterFrom, void, (HWND hWnd, int hWndFrom, BOOL bFullScreen));

//======================================================
// 函数名称：Ex_DUIShowWindow
// 返回类型：BOOL
// 函数说明：显示窗口
// 参数<1>：hExDui, HEXDUI, 引擎句柄
// 参数<2>：nCmdShow, int, 相关常量:#SW_
// 参数<3>：dwTimer, int, 动画时间间隔.(ms)
// 参数<4>：dwFrames, int, 动画总帧数.
// 参数<5>：dwFlags, int, 动画标记.#EXA_
//======================================================
EX_DEFINE_API(Ex_DUIShowWindow, BOOL, (HEXDUI hExDui, int nCmdShow, int dwTimer, int dwFrames, int dwFlags));

//======================================================
// 函数名称：Ex_DUIShowWindowEx
// 返回类型：BOOL
// 函数说明：显示窗口
// 参数<1>：hExDui, HEXDUI, 引擎句柄
// 参数<2>：nCmdShow, int, 相关常量:#SW_
// 参数<3>：dwTimer, int, 动画时间间隔.(ms)
// 参数<4>：dwFrames, int, 动画总帧数.
// 参数<5>：dwFlags, int, 动画标记.#EXA_
// 参数<6>：uEasing, int, #缓动类型_
// 参数<7>：wParam, WPARAM, 参数1
// 参数<8>：lParam, LPARAM, 参数2
//======================================================
EX_DEFINE_API(Ex_DUIShowWindowEx, BOOL, (HEXDUI hExDui, int nCmdShow, int dwTimer, int dwFrames, int dwFlags, int uEasing, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：_canvas_destroy
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_destroy, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：_canvas_enddraw
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_enddraw, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：_canvas_clear
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：lColor, int, 
//======================================================
EX_DEFINE_API(_canvas_clear, BOOL, (HEXCANVAS hCanvas, int lColor));

//======================================================
// 函数名称：_canvas_getdc
// 返回类型：int
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_getdc, int, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：_canvas_releasedc
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_releasedc, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：_canvas_drawimage
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 0
// 参数<2>：hImage, HEXIMAGE, 4
// 参数<3>：left, float, 8
// 参数<4>：top, float, 12
// 参数<5>：alpha, int, 16
//======================================================
EX_DEFINE_API(_canvas_drawimage, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float left, float top, int alpha));

//======================================================
// 函数名称：_canvas_drawimagerect
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hImage, HEXIMAGE, 
// 参数<3>：left, float, 
// 参数<4>：top, float, 
// 参数<5>：right, float, 
// 参数<6>：bottom, float, 
// 参数<7>：alpha, int, 
//======================================================
EX_DEFINE_API(_canvas_drawimagerect, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float left, float top, float right, float bottom, int alpha));

//======================================================
// 函数名称：_canvas_drawimagerectrect
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 0
// 参数<2>：hImage, HEXIMAGE, 4
// 参数<3>：dstLeft, float, 8
// 参数<4>：dstTop, float, 12
// 参数<5>：dstRight, float, 16
// 参数<6>：dstBottom, float, 20
// 参数<7>：srcLeft, float, 24
// 参数<8>：srcTop, float, 28
// 参数<9>：srcRight, float, 32
// 参数<10>：srcBottom, float, 36
// 参数<11>：alpha, int, 40
//======================================================
EX_DEFINE_API(_canvas_drawimagerectrect, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float dstLeft, float dstTop, float dstRight, float dstBottom, float srcLeft, float srcTop, float srcRight, float srcBottom, int alpha));

//======================================================
// 函数名称：_canvas_drawimagefromgrid
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hImage, HEXIMAGE, 
// 参数<3>：dstLeft, float, 
// 参数<4>：dstTop, float, 
// 参数<5>：dstRight, float, 
// 参数<6>：dstBottom, float, 
// 参数<7>：srcLeft, float, 
// 参数<8>：srcTop, float, 
// 参数<9>：srcRight, float, 
// 参数<10>：srcBottom, float, 
// 参数<11>：gridPaddingLeft, float, 
// 参数<12>：gridPaddingTop, float, 
// 参数<13>：gridPaddingRight, float, 
// 参数<14>：gridPaddingBottom, float, 
// 参数<15>：dwFlags, int, #bif_
// 参数<16>：dwAlpha, int, 
//======================================================
EX_DEFINE_API(_canvas_drawimagefromgrid, BOOL, (HEXCANVAS hCanvas, HEXIMAGE hImage, float dstLeft, float dstTop, float dstRight, float dstBottom, float srcLeft, float srcTop, float srcRight, float srcBottom, float gridPaddingLeft, float gridPaddingTop, float gridPaddingRight, float gridPaddingBottom, int dwFlags, int dwAlpha));

//======================================================
// 函数名称：Ex_ObjDefProc
// 返回类型：int
// 函数说明：组件默认过程
// 参数<1>：hWnd, HWND, 
// 参数<2>：hObj, HEXOBJ, 
// 参数<3>：uMsg, UINT, 
// 参数<4>：wParam, WPARAM, 
// 参数<5>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDefProc, int, (HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：_canvas_fillrect
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：left, float, 
// 参数<4>：top, float, 
// 参数<5>：right, float, 
// 参数<6>：bottom, float, 
//======================================================
EX_DEFINE_API(_canvas_fillrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom));

//======================================================
// 函数名称：_brush_create
// 返回类型：HEXBRUSH
// 函数说明：
// 参数<1>：argb, int, 
//======================================================
EX_DEFINE_API(_brush_create, HEXBRUSH, (int argb));

//======================================================
// 函数名称：_brush_destroy
// 返回类型：int
// 函数说明：
// 参数<1>：hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_brush_destroy, int, (HEXBRUSH hBrush));

//======================================================
// 函数名称：_canvas_drawrect
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：left, float, 
// 参数<4>：top, float, 
// 参数<5>：right, float, 
// 参数<6>：bottom, float, 
// 参数<7>：strokeWidth, float, 
// 参数<8>：strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float strokeWidth, int strokeStyle));

//======================================================
// 函数名称：_canvas_drawroundedrect
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：left, float, 
// 参数<4>：top, float, 
// 参数<5>：right, float, 
// 参数<6>：bottom, float, 
// 参数<7>：radiusX, float, 
// 参数<8>：radiusY, float, 
// 参数<9>：strokeWidth, float, 
// 参数<10>：strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawroundedrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float radiusX, float radiusY, float strokeWidth, int strokeStyle));

//======================================================
// 函数名称：_canvas_fillroundedrect
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：left, float, 
// 参数<4>：top, float, 
// 参数<5>：right, float, 
// 参数<6>：bottom, float, 
// 参数<7>：radiusX, float, 
// 参数<8>：radiusY, float, 
//======================================================
EX_DEFINE_API(_canvas_fillroundedrect, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float left, float top, float right, float bottom, float radiusX, float radiusY));

//======================================================
// 函数名称：_canvas_drawellipse
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：x, float, 
// 参数<4>：y, float, 
// 参数<5>：radiusX, float, 
// 参数<6>：radiusY, float, 
// 参数<7>：strokeWidth, float, 
// 参数<8>：strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawellipse, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float x, float y, float radiusX, float radiusY, float strokeWidth, int strokeStyle));

//======================================================
// 函数名称：_canvas_fillellipse
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：x, float, 
// 参数<4>：y, float, 
// 参数<5>：radiusX, float, 
// 参数<6>：radiusY, float, 
//======================================================
EX_DEFINE_API(_canvas_fillellipse, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float x, float y, float radiusX, float radiusY));

//======================================================
// 函数名称：_canvas_drawline
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hBrush, HEXBRUSH, 
// 参数<3>：X1, float, 
// 参数<4>：Y1, float, 
// 参数<5>：X2, float, 
// 参数<6>：Y2, float, 
// 参数<7>：strokeWidth, float, 
// 参数<8>：strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawline, BOOL, (HEXCANVAS hCanvas, HEXBRUSH hBrush, float X1, float Y1, float X2, float Y2, float strokeWidth, int strokeStyle));

//======================================================
// 函数名称：Ex_ObjRegister
// 返回类型：int
// 函数说明：注册组件.失败返回0
// 参数<1>：lptszClassName, LPCWSTR, 组件类名.最大允许长度:MAX_CLASS_NAME_LEN
// 参数<2>：dwStyle, DWORD, 组件默认风格
// 参数<3>：dwStyleEx, DWORD, 组件默认扩展风格
// 参数<4>：dwTextFormat, int, 相关常量 DT_
// 参数<5>：cbObjExtra, int, 组件额外分配字节数(值可为0)
// 参数<6>：hCursor, int, 组件默认鼠标指针句柄(值可为0)
// 参数<7>：dwFlags, int, 类标志 #ECF_(值可为0)
// 参数<8>：pfnObjProc, ExMsgProc, 组件默认回调
//======================================================
EX_DEFINE_API(Ex_ObjRegister, int, (LPCWSTR lptszClassName, DWORD dwStyle, DWORD dwStyleEx, int dwTextFormat, int cbObjExtra, int hCursor, int dwFlags, ExMsgProc pfnObjProc));

//======================================================
// 函数名称：Ex_ObjCreate
// 返回类型：HEXOBJ
// 函数说明：创建组件.
// 参数<1>：lptszClassName, LPCWSTR, 组件类名
// 参数<2>：lptszObjTitle, LPCWSTR, 组件标题
// 参数<3>：dwStyle, DWORD, 组件风格 相关常量 EOS_
// 参数<4>：x, int, 左边
// 参数<5>：y, int, 顶边
// 参数<6>：width, int, 宽度
// 参数<7>：height, int, 高度
// 参数<8>：hParent, EXHANDLE, 父组件句柄
//======================================================
EX_DEFINE_API(Ex_ObjCreate, HEXOBJ, (LPCWSTR lptszClassName, LPCWSTR lptszObjTitle, DWORD dwStyle, int x, int y, int width, int height, EXHANDLE hParent));

//======================================================
// 函数名称：Ex_ObjCreateEx
// 返回类型：HEXOBJ
// 函数说明：创建组件.
// 参数<1>：dwStyleEx, DWORD, 组件扩展风格 相关常量 EOS_EX_
// 参数<2>：lptszClassName, LPCWSTR, 组件类名
// 参数<3>：lptszObjTitle, LPCWSTR, 组件标题
// 参数<4>：dwStyle, DWORD, 组件风格 相关常量 EOS_
// 参数<5>：x, int, 左边
// 参数<6>：y, int, 顶边
// 参数<7>：width, int, 宽度
// 参数<8>：height, int, 高度
// 参数<9>：hParent, EXHANDLE, 父组件句柄
// 参数<10>：nID, int, 
// 参数<11>：dwTextFormat, int, 相关常量 DT_
// 参数<12>：lParam, LPARAM, 附加参数
// 参数<13>：hTheme, int, 主题句柄.0为默认
// 参数<14>：lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hObj,uMsg,wParam,lParam,lpReturn).
//======================================================
EX_DEFINE_API(Ex_ObjCreateEx, HEXOBJ, (DWORD dwStyleEx, LPCWSTR lptszClassName, LPCWSTR lptszObjTitle, DWORD dwStyle, int x, int y, int width, int height, EXHANDLE hParent, int nID, int dwTextFormat, LPARAM lParam, int hTheme, ExMsgProc lpfnMsgProc));

//======================================================
// 函数名称：Ex_Scale
// 返回类型：float
// 函数说明：
// 参数<1>：n, float, 
//======================================================
EX_DEFINE_API(Ex_Scale, float, (float n));

//======================================================
// 函数名称：_rgn_createfromrect
// 返回类型：int
// 函数说明：
// 参数<1>：left, float, 
// 参数<2>：top, float, 
// 参数<3>：right, float, 
// 参数<4>：bottom, float, 
//======================================================
EX_DEFINE_API(_rgn_createfromrect, int, (float left, float top, float right, float bottom));

//======================================================
// 函数名称：_rgn_createfromroundrect
// 返回类型：int
// 函数说明：
// 参数<1>：left, float, 
// 参数<2>：top, float, 
// 参数<3>：right, float, 
// 参数<4>：bottom, float, 
// 参数<5>：radiusX, float, 
// 参数<6>：radiusY, float, 
//======================================================
EX_DEFINE_API(_rgn_createfromroundrect, int, (float left, float top, float right, float bottom, float radiusX, float radiusY));

//======================================================
// 函数名称：_rgn_destroy
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hRgn, int, 
//======================================================
EX_DEFINE_API(_rgn_destroy, BOOL, (int hRgn));

//======================================================
// 函数名称：_rgn_combine
// 返回类型：int
// 函数说明：
// 参数<1>：hRgnSrc, int, 
// 参数<2>：hRgnDst, int, 
// 参数<3>：nCombineMode, int, #RGN_COMBINE_
// 参数<4>：dstOffsetX, int, 
// 参数<5>：dstOffsetY, int, 
//======================================================
EX_DEFINE_API(_rgn_combine, int, (int hRgnSrc, int hRgnDst, int nCombineMode, int dstOffsetX, int dstOffsetY));

//======================================================
// 函数名称：_canvas_fillregion
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hRgn, int, 
// 参数<3>：hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_canvas_fillregion, BOOL, (HEXCANVAS hCanvas, int hRgn, HEXBRUSH hBrush));

//======================================================
// 函数名称：_rgn_hittest
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hRgn, int, 
// 参数<2>：x, float, 
// 参数<3>：y, float, 
//======================================================
EX_DEFINE_API(_rgn_hittest, BOOL, (int hRgn, float x, float y));

//======================================================
// 函数名称：Ex_ObjDestroy
// 返回类型：int
// 函数说明：销毁组件
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjDestroy, int, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjSendMessage
// 返回类型：int
// 函数说明：发送消息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：uMsg, UINT, 
// 参数<3>：wParam, WPARAM, 
// 参数<4>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjSendMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：Ex_ObjBeginPaint
// 返回类型：BOOL
// 函数说明：开始绘制
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpPS, EX_PAINTSTRUCT2*, 
//======================================================
EX_DEFINE_API(Ex_ObjBeginPaint, BOOL, (HEXOBJ hObj, EX_PAINTSTRUCT2* lpPS));

//======================================================
// 函数名称：Ex_ObjEndPaint
// 返回类型：BOOL
// 函数说明：结束绘制
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpPS, EX_PAINTSTRUCT2*, 
//======================================================
EX_DEFINE_API(Ex_ObjEndPaint, BOOL, (HEXOBJ hObj, EX_PAINTSTRUCT2* lpPS));

//======================================================
// 函数名称：Ex_ObjGetRect
// 返回类型：BOOL
// 函数说明：获取组件矩形
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// 函数名称：Ex_ObjClientToWindow
// 返回类型：BOOL
// 函数说明：客户区坐标到窗口坐标
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
//======================================================
EX_DEFINE_API(Ex_ObjClientToWindow, BOOL, (HEXOBJ hObj, int x, int y));

//======================================================
// 函数名称：_canvas_cliprect
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：left, int, 
// 参数<3>：top, int, 
// 参数<4>：right, int, 
// 参数<5>：bottom, int, 
//======================================================
EX_DEFINE_API(_canvas_cliprect, BOOL, (HEXCANVAS hCanvas, int left, int top, int right, int bottom));

//======================================================
// 函数名称：_canvas_resetclip
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_resetclip, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：Ex_ObjClientToScreen
// 返回类型：BOOL
// 函数说明：客户区坐标到屏幕坐标
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
//======================================================
EX_DEFINE_API(Ex_ObjClientToScreen, BOOL, (HEXOBJ hObj, int x, int y));

//======================================================
// 函数名称：Ex_ObjInvalidateRect
// 返回类型：BOOL
// 函数说明：设置重画区域
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lprcRedraw, int, 
//======================================================
EX_DEFINE_API(Ex_ObjInvalidateRect, BOOL, (HEXOBJ hObj, int lprcRedraw));

//======================================================
// 函数名称：Ex_ObjUpdate
// 返回类型：BOOL
// 函数说明：立即更新组件
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjUpdate, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjGetClientRect
// 返回类型：BOOL
// 函数说明：获取组件客户区矩形
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetClientRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// 函数名称：Ex_ObjEnable
// 返回类型：BOOL
// 函数说明：设置组件可用状态.
// 参数<1>：hObj, HEXOBJ, 组件句柄
// 参数<2>：fEnable, BOOL, 是否可用
//======================================================
EX_DEFINE_API(Ex_ObjEnable, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// 函数名称：Ex_ObjIsEnable
// 返回类型：BOOL
// 函数说明：组件是否可用
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjIsEnable, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjIsVisible
// 返回类型：BOOL
// 函数说明：判断组件是否可视.
// 参数<1>：hObj, HEXOBJ, 组件句柄
//======================================================
EX_DEFINE_API(Ex_ObjIsVisible, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjShow
// 返回类型：BOOL
// 函数说明：设置组件可视状态
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fShow, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjShow, BOOL, (HEXOBJ hObj, BOOL fShow));

//======================================================
// 函数名称：Ex_ObjGetLong
// 返回类型：int
// 函数说明：获取组件数值
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nIndex, int, 相关常量 #EOL_
//======================================================
EX_DEFINE_API(Ex_ObjGetLong, int, (HEXOBJ hObj, int nIndex));

//======================================================
// 函数名称：Ex_ObjGetParent
// 返回类型：int
// 函数说明：获取父组件
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetParent, int, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjSetLong
// 返回类型：int
// 函数说明：设置组件数值
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nIndex, int, #EOL_
// 参数<3>：dwNewLong, LONG, 
//======================================================
EX_DEFINE_API(Ex_ObjSetLong, int, (HEXOBJ hObj, int nIndex, LONG dwNewLong));

//======================================================
// 函数名称：Ex_ObjSetPos
// 返回类型：BOOL
// 函数说明：设置组件位置
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：hObjInsertAfter, int, 
// 参数<3>：x, int, 
// 参数<4>：y, int, 
// 参数<5>：width, int, 
// 参数<6>：height, int, 
// 参数<7>：flags, int, 相关常量 #SWP_
//======================================================
EX_DEFINE_API(Ex_ObjSetPos, BOOL, (HEXOBJ hObj, int hObjInsertAfter, int x, int y, int width, int height, int flags));

//======================================================
// 函数名称：Ex_ObjIsValidate
// 返回类型：BOOL
// 函数说明：是否有效的组件
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjIsValidate, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjEnumChild
// 返回类型：BOOL
// 函数说明：枚举子组件.
// 参数<1>：hObjParent, EXHANDLE, 父组件的句柄。从根部枚举则为引擎句柄。
// 参数<2>：lpEnumFunc, int, callback(hObj,lParam).返回1继续枚举,返回0停止枚举.
// 参数<3>：lParam, LPARAM, 附带参数
//======================================================
EX_DEFINE_API(Ex_ObjEnumChild, BOOL, (EXHANDLE hObjParent, int lpEnumFunc, LPARAM lParam));

//======================================================
// 函数名称：Ex_ObjGetText
// 返回类型：int
// 函数说明：获取组件文本.返回值:已拷贝字符长度.
// 参数<1>：hObj, HEXOBJ, 组件句柄.
// 参数<2>：lpString, LPCWSTR, 缓冲区指针.
// 参数<3>：nMaxCount, int, 缓冲区长度.
//======================================================
EX_DEFINE_API(Ex_ObjGetText, int, (HEXOBJ hObj, LPCWSTR lpString, int nMaxCount));

//======================================================
// 函数名称：Ex_ObjGetTextLength
// 返回类型：int
// 函数说明：获取组件文本长度
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetTextLength, int, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjSetText
// 返回类型：BOOL
// 函数说明：设置组件文本.
// 参数<1>：hObj, HEXOBJ, 组件句柄.
// 参数<2>：lpString, LPCWSTR, 指向一个空结束的字符串的指针.
// 参数<3>：fRedraw, BOOL, 是否重画组件
//======================================================
EX_DEFINE_API(Ex_ObjSetText, BOOL, (HEXOBJ hObj, LPCWSTR lpString, BOOL fRedraw));

//======================================================
// 函数名称：Ex_ObjTooltipsPop
// 返回类型：BOOL
// 函数说明：弹出或关闭提示文本
// 参数<1>：hObj, HEXOBJ, 组件句柄.
// 参数<2>：lpString, LPCWSTR, 提示文本.该值为0则关闭提示文本
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsPop, BOOL, (HEXOBJ hObj, LPCWSTR lpString));

//======================================================
// 函数名称：Ex_ObjTooltipsPopEx
// 返回类型：BOOL
// 函数说明：弹出或关闭提示文本Ex
// 参数<1>：hObj, HEXOBJ, 组件句柄.
// 参数<2>：lpTitle, LPCWSTR, 标题内容
// 参数<3>：lpText, LPCWSTR, 提示文本.
// 参数<4>：x, int, 屏幕坐标.(-1:默认)
// 参数<5>：y, int, 屏幕坐标.(-1:默认)
// 参数<6>：dwTime, int, 单位:毫秒.(-1:默认,0:始终显示)
// 参数<7>：nIcon, int, #气泡图标_
// 参数<8>：fShow, BOOL, 是否立即显示
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsPopEx, BOOL, (HEXOBJ hObj, LPCWSTR lpTitle, LPCWSTR lpText, int x, int y, int dwTime, int nIcon, BOOL fShow));

//======================================================
// 函数名称：Ex_DUIGetObjFromPoint
// 返回类型：HEXOBJ
// 函数说明：获取鼠标所在窗口组件句柄
// 参数<1>：handle, EXHANDLE, 0[坐标所在窗口]/窗口句柄/引擎句柄/组件句柄
// 参数<2>：x, int, handle:0相对屏幕/其他相对窗口
// 参数<3>：y, int, 
//======================================================
EX_DEFINE_API(Ex_DUIGetObjFromPoint, HEXOBJ, (EXHANDLE handle, int x, int y));

//======================================================
// 函数名称：Ex_ObjSetFocus
// 返回类型：BOOL
// 函数说明：设置组件焦点
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFocus, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjKillFocus
// 返回类型：BOOL
// 函数说明：销毁组件焦点
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjKillFocus, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjGetProp
// 返回类型：int
// 函数说明：获取属性
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：dwKey, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetProp, int, (HEXOBJ hObj, int dwKey));

//======================================================
// 函数名称：Ex_ObjSetProp
// 返回类型：int
// 函数说明：设置组件属性条目
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：dwKey, int, 
// 参数<3>：dwValue, int, 
//======================================================
EX_DEFINE_API(Ex_ObjSetProp, int, (HEXOBJ hObj, int dwKey, int dwValue));

//======================================================
// 函数名称：Ex_ObjMove
// 返回类型：BOOL
// 函数说明：移动组件
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：x, int, 
// 参数<3>：y, int, 
// 参数<4>：width, int, 
// 参数<5>：height, int, 
// 参数<6>：bRepaint, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjMove, BOOL, (HEXOBJ hObj, int x, int y, int width, int height, BOOL bRepaint));

//======================================================
// 函数名称：Ex_ObjGetObj
// 返回类型：HEXOBJ
// 函数说明：返回与指定组件有特定关系（如Z序或所有者）的组件句柄。
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nCmd, int, 相关常量 #GW_
//======================================================
EX_DEFINE_API(Ex_ObjGetObj, HEXOBJ, (HEXOBJ hObj, int nCmd));

//======================================================
// 函数名称：Ex_ObjFind
// 返回类型：EXHANDLE
// 函数说明：查找组件.
// 参数<1>：hObjParent, EXHANDLE, 父组件句柄。从根部查找则为引擎句柄。
// 参数<2>：hObjChildAfter, HEXOBJ, 由此组件开始查找（不包含该组件）。如果为0，则从第一个组件开始查找。
// 参数<3>：lpClassName, LPCWSTR, 欲查找的组件类名指针/Ex_ATOM()
// 参数<4>：lpTitle, LPCWSTR, 欲查找的组件标题
//======================================================
EX_DEFINE_API(Ex_ObjFind, EXHANDLE, (EXHANDLE hObjParent, HEXOBJ hObjChildAfter, LPCWSTR lpClassName, LPCWSTR lpTitle));

//======================================================
// 函数名称：Ex_ObjSetRedraw
// 返回类型：BOOL
// 函数说明：设置组件是否可以重画.如果组件扩展风格存在EOS_EX_COMPOSITED,则该函数无效.
// 参数<1>：hObj, HEXOBJ, 组件句柄
// 参数<2>：fCanbeRedraw, BOOL, 是否可重画
//======================================================
EX_DEFINE_API(Ex_ObjSetRedraw, BOOL, (HEXOBJ hObj, BOOL fCanbeRedraw));

//======================================================
// 函数名称：Ex_ThemeLoadFromFile
// 返回类型：int
// 函数说明：加载主题包
// 参数<1>：lptszFile, LPCWSTR, 
// 参数<2>：lpKey, int, 
// 参数<3>：dwKeyLen, int, 
// 参数<4>：bDefault, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ThemeLoadFromFile, int, (LPCWSTR lptszFile, int lpKey, int dwKeyLen, BOOL bDefault));

//======================================================
// 函数名称：Ex_ThemeLoadFromMemory
// 返回类型：int
// 函数说明：加载主题包
// 参数<1>：lpData, LPBYTE, 
// 参数<2>：dwDataLen, int, 
// 参数<3>：lpKey, int, 
// 参数<4>：dwKeyLen, int, 
// 参数<5>：bDefault, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ThemeLoadFromMemory, int, (LPBYTE lpData, int dwDataLen, int lpKey, int dwKeyLen, BOOL bDefault));

//======================================================
// 函数名称：Ex_ThemeFree
// 返回类型：BOOL
// 函数说明：释放主题
// 参数<1>：hTheme, int, 
//======================================================
EX_DEFINE_API(Ex_ThemeFree, BOOL, (int hTheme));

//======================================================
// 函数名称：Ex_Atom
// 返回类型：EXATOM
// 函数说明：获取字符串唯一原子号
// 参数<1>：lptstring, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_Atom, EXATOM, (LPCWSTR lptstring));

//======================================================
// 函数名称：_canvas_getsize
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：width, int*, 
// 参数<3>：height, int*, 
//======================================================
EX_DEFINE_API(_canvas_getsize, BOOL, (HEXCANVAS hCanvas, int* width, int* height));

//======================================================
// 函数名称：Ex_ThemeGetValuePtr
// 返回类型：int
// 函数说明：获取组件属性值指针.
// 参数<1>：hTheme, int, 主题句柄
// 参数<2>：atomClass, int, 
// 参数<3>：atomProp, int, 
//======================================================
EX_DEFINE_API(Ex_ThemeGetValuePtr, int, (int hTheme, int atomClass, int atomProp));

//======================================================
// 函数名称：Ex_DUISetLong
// 返回类型：int
// 函数说明：设置引擎数值
// 参数<1>：hExDui, HEXDUI, 
// 参数<2>：nIndex, int, #EWL_
// 参数<3>：dwNewlong, int, 
//======================================================
EX_DEFINE_API(Ex_DUISetLong, int, (HEXDUI hExDui, int nIndex, int dwNewlong));

//======================================================
// 函数名称：Ex_DUIGetLong
// 返回类型：int
// 函数说明：获取引擎数值
// 参数<1>：hExDui, HEXDUI, 引擎句柄
// 参数<2>：nIndex, int, 相关常量: EWL_
//======================================================
EX_DEFINE_API(Ex_DUIGetLong, int, (HEXDUI hExDui, int nIndex));

//======================================================
// 函数名称：_font_create
// 返回类型：HEXFONT
// 函数说明：创建默认字体
//======================================================
EX_DEFINE_API(_font_create, HEXFONT, ());

//======================================================
// 函数名称：_font_createfromfamily
// 返回类型：HEXFONT
// 函数说明：
// 参数<1>：lpwzFontFace, LPCWSTR, 
// 参数<2>：dwFontSize, int, 
// 参数<3>：dwFontStyle, int, 
//======================================================
EX_DEFINE_API(_font_createfromfamily, HEXFONT, (LPCWSTR lpwzFontFace, int dwFontSize, int dwFontStyle));

//======================================================
// 函数名称：_font_createfromlogfont
// 返回类型：HEXFONT
// 函数说明：
// 参数<1>：lpLogfont, int, 
//======================================================
EX_DEFINE_API(_font_createfromlogfont, HEXFONT, (int lpLogfont));

//======================================================
// 函数名称：_font_getlogfont
// 返回类型：BOOL
// 函数说明：获取逻辑字体
// 参数<1>：hFont, HEXFONT, 
// 参数<2>：lpLogFont, int, 
//======================================================
EX_DEFINE_API(_font_getlogfont, BOOL, (HEXFONT hFont, int lpLogFont));

//======================================================
// 函数名称：Ex_DUICreateFromLayout
// 返回类型：BOOL
// 函数说明：创建自布局
// 参数<1>：hParent, EXHANDLE, 父窗口句柄
// 参数<2>：hTheme, int, 主题句柄
// 参数<3>：lpLayout, int, 布局资源数据指针
// 参数<4>：cbLayout, int, 布局资源数据长度
// 参数<5>：hWnd, HWND, (out)返回窗口句柄
// 参数<6>：hExDui, HEXDUI, (out)返回引擎句柄
//======================================================
EX_DEFINE_API(Ex_DUICreateFromLayout, BOOL, (EXHANDLE hParent, int hTheme, int lpLayout, int cbLayout, HWND hWnd, HEXDUI hExDui));

//======================================================
// 函数名称：Ex_DUICreateFromHRes
// 返回类型：BOOL
// 函数说明：创建自资源包句柄
// 参数<1>：hParent, EXHANDLE, 父窗口句柄
// 参数<2>：hTheme, int, 主题句柄
// 参数<3>：hRes, int, 资源句柄
// 参数<4>：atomLayout, int, 布局文件名原子号
// 参数<5>：hWnd, HWND, (out)返回窗口句柄
// 参数<6>：hExDui, HEXDUI, (out)返回引擎句柄
//======================================================
EX_DEFINE_API(Ex_DUICreateFromHRes, BOOL, (EXHANDLE hParent, int hTheme, int hRes, int atomLayout, HWND hWnd, HEXDUI hExDui));

//======================================================
// 函数名称：Ex_XmlRegisterCallback
// 返回类型：void
// 函数说明：注册XML键值回调
// 参数<1>：atomValue, int, 
// 参数<2>：pfnCallback, ExObjEventHandler, 
//======================================================
EX_DEFINE_API(Ex_XmlRegisterCallback, void, (int atomValue, ExObjEventHandler pfnCallback));

//======================================================
// 函数名称：Ex_DUIGetClientRect
// 返回类型：BOOL
// 函数说明：获取客户区矩形
// 参数<1>：hExDui, HEXDUI, 引擎句柄
// 参数<2>：lpClientRect, RECT*, 矩形指针
//======================================================
EX_DEFINE_API(Ex_DUIGetClientRect, BOOL, (HEXDUI hExDui, RECT* lpClientRect));

//======================================================
// 函数名称：Ex_ObjPostMessage
// 返回类型：int
// 函数说明：投递消息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：uMsg, UINT, 
// 参数<3>：wParam, WPARAM, 
// 参数<4>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjPostMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：Ex_ObjSetBackgroundImage
// 返回类型：BOOL
// 函数说明：设置组件背景信息
// 参数<1>：handle, EXHANDLE, 引擎句柄/组件句柄
// 参数<2>：lpImage, int, 图片指针
// 参数<3>：dwImageLen, int, 图片长度
// 参数<4>：X, int, 偏移X
// 参数<5>：Y, int, 偏移Y
// 参数<6>：dwRepeat, int, 相关常量 BIR_
// 参数<7>：lpGird, int, 九宫矩形指针 (值可为0)
// 参数<8>：dwFlags, int, 相关常量 BIF_
// 参数<9>：dwAlpha, int, 透明度(0-255)
// 参数<10>：fUpdate, BOOL, 是否立即刷新
//======================================================
EX_DEFINE_API(Ex_ObjSetBackgroundImage, BOOL, (EXHANDLE handle, int lpImage, int dwImageLen, int X, int Y, int dwRepeat, int lpGird, int dwFlags, int dwAlpha, BOOL fUpdate));

//======================================================
// 函数名称：Ex_ObjGetBackgroundImage
// 返回类型：BOOL
// 函数说明：获取组件背景信息
// 参数<1>：handle, EXHANDLE, 
// 参数<2>：lpBackgroundImage, int, 相关结构 EX_BACKGROUNDIMAGEINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetBackgroundImage, BOOL, (EXHANDLE handle, int lpBackgroundImage));

//======================================================
// 函数名称：Ex_ObjSetBackgroundPlayState
// 返回类型：BOOL
// 函数说明：设置组件背景图片播放状态.
// 参数<1>：handle, EXHANDLE, 引擎句柄/组件句柄
// 参数<2>：fPlayFrames, BOOL, 是否播放.
// 参数<3>：fResetFrame, BOOL, 是否重置当前帧为首帧.
// 参数<4>：fUpdate, BOOL, 是否更新背景.
//======================================================
EX_DEFINE_API(Ex_ObjSetBackgroundPlayState, BOOL, (EXHANDLE handle, BOOL fPlayFrames, BOOL fResetFrame, BOOL fUpdate));

//======================================================
// 函数名称：_canvas_blur
// 返回类型：BOOL
// 函数说明：模糊
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：fDeviation, float, 
// 参数<3>：lprc, int, 
//======================================================
EX_DEFINE_API(_canvas_blur, BOOL, (HEXCANVAS hCanvas, float fDeviation, int lprc));

//======================================================
// 函数名称：_canvas_rotate_hue
// 返回类型：BOOL
// 函数说明：旋转色相
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：fAngle, float, 0-360
//======================================================
EX_DEFINE_API(_canvas_rotate_hue, BOOL, (HEXCANVAS hCanvas, float fAngle));

//======================================================
// 函数名称：Ex_ObjSetTimer
// 返回类型：int
// 函数说明：设置组件时钟
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：uElapse, int, 
//======================================================
EX_DEFINE_API(Ex_ObjSetTimer, int, (HEXOBJ hObj, int uElapse));

//======================================================
// 函数名称：Ex_ObjKillTimer
// 返回类型：BOOL
// 函数说明：销毁组件时钟
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjKillTimer, BOOL, (HEXOBJ hObj));

//======================================================
// 函数名称：_canvas_drawtext
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hFont, HEXFONT, 如果为0则使用默认字体句柄
// 参数<3>：crText, int, 
// 参数<4>：lpwzText, LPCWSTR, 
// 参数<5>：dwLen, size_t, -1则自动计算尺寸(必须是指向空字符串的指针)
// 参数<6>：dwDTFormat, int, #DT_
// 参数<7>：left, float, 
// 参数<8>：top, float, 
// 参数<9>：right, float, 
// 参数<10>：bottom, float, 
//======================================================
EX_DEFINE_API(_canvas_drawtext, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, int crText, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, float left, float top, float right, float bottom));

//======================================================
// 函数名称：_font_destroy
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_destroy, BOOL, (HEXFONT hFont));

//======================================================
// 函数名称：_canvas_calctextsize
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hFont, HEXFONT, 
// 参数<3>：lpwzText, LPCWSTR, 
// 参数<4>：dwLen, size_t, 
// 参数<5>：dwDTFormat, int, 
// 参数<6>：lParam, LPARAM, 
// 参数<7>：layoutWidth, float, 
// 参数<8>：layoutHeight, float, 
// 参数<9>：lpWidth, float*, 
// 参数<10>：lpHeight, float*, 
//======================================================
EX_DEFINE_API(_canvas_calctextsize, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, LPARAM lParam, float layoutWidth, float layoutHeight, float* lpWidth, float* lpHeight));

//======================================================
// 函数名称：_canvas_drawtextex
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hFont, HEXFONT, 
// 参数<3>：crText, int, 
// 参数<4>：lpwzText, LPCWSTR, 
// 参数<5>：dwLen, size_t, -1则自动计算尺寸(必须是指向空字符串的指针)
// 参数<6>：dwDTFormat, int, 
// 参数<7>：left, float, 
// 参数<8>：top, float, 
// 参数<9>：right, float, 
// 参数<10>：bottom, float, 
// 参数<11>：iGlowsize, int, 
// 参数<12>：crShadow, int, 
// 参数<13>：lParam, LPARAM, 
// 参数<14>：prclayout, int, 
//======================================================
EX_DEFINE_API(_canvas_drawtextex, BOOL, (HEXCANVAS hCanvas, HEXFONT hFont, int crText, LPCWSTR lpwzText, size_t dwLen, int dwDTFormat, float left, float top, float right, float bottom, int iGlowsize, int crShadow, LPARAM lParam, int prclayout));

//======================================================
// 函数名称：Ex_ObjDispatchMessage
// 返回类型：int
// 函数说明：分发消息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：uMsg, UINT, 
// 参数<3>：wParam, WPARAM, 
// 参数<4>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDispatchMessage, int, (HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：_canvas_begindraw
// 返回类型：BOOL
// 函数说明：ok
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_begindraw, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：Ex_ObjSetUIState
// 返回类型：BOOL
// 函数说明：设置组件状态,用于更新组件界面显示状态
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：dwState, int, 
// 参数<3>：fRemove, BOOL, 
// 参数<4>：lprcRedraw, int, 
// 参数<5>：fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetUIState, BOOL, (HEXOBJ hObj, int dwState, BOOL fRemove, int lprcRedraw, BOOL fRedraw));

//======================================================
// 函数名称：_canvas_flush
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_canvas_flush, BOOL, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：Ex_ObjScrollSetInfo
// 返回类型：int
// 函数说明：设置滚动条信息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fnBar, int, SB_
// 参数<3>：fMask, int, SIF_
// 参数<4>：nMin, int, 
// 参数<5>：nMax, int, 
// 参数<6>：nPage, int, 
// 参数<7>：nPos, int, 
// 参数<8>：fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetInfo, int, (HEXOBJ hObj, int fnBar, int fMask, int nMin, int nMax, int nPage, int nPos, BOOL fRedraw));

//======================================================
// 函数名称：Ex_ObjScrollSetRange
// 返回类型：BOOL
// 函数说明：设置滚动条范围
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, SB_
// 参数<3>：nMin, int, 
// 参数<4>：nMax, int, 
// 参数<5>：bRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetRange, BOOL, (HEXOBJ hObj, int nBar, int nMin, int nMax, BOOL bRedraw));

//======================================================
// 函数名称：Ex_ObjScrollSetPos
// 返回类型：int
// 函数说明：设置滚动条位置
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, SB_
// 参数<3>：nPos, int, 
// 参数<4>：bRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollSetPos, int, (HEXOBJ hObj, int nBar, int nPos, BOOL bRedraw));

//======================================================
// 函数名称：Ex_ObjScrollGetControl
// 返回类型：int
// 函数说明：获取滚动条句柄
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, 相关常量 #SB_
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetControl, int, (HEXOBJ hObj, int nBar));

//======================================================
// 函数名称：Ex_ObjCallProc
// 返回类型：int
// 函数说明：调用过程
// 参数<1>：lpPrevObjProc, int, 
// 参数<2>：hWnd, HWND, 
// 参数<3>：hObj, HEXOBJ, 
// 参数<4>：uMsg, UINT, 
// 参数<5>：wParam, WPARAM, 
// 参数<6>：lParam, LPARAM, 
// 参数<7>：pvData, int, 
//======================================================
EX_DEFINE_API(Ex_ObjCallProc, int, (int lpPrevObjProc, HWND hWnd, HEXOBJ hObj, UINT uMsg, WPARAM wParam, LPARAM lParam, int pvData));

//======================================================
// 函数名称：_canvas_createfromexdui
// 返回类型：int
// 函数说明：创建画布自引擎句柄
// 参数<1>：hExDui, HEXDUI, 
// 参数<2>：width, int, 
// 参数<3>：height, int, 
// 参数<4>：dwFlags, int, CVF_
//======================================================
EX_DEFINE_API(_canvas_createfromexdui, int, (HEXDUI hExDui, int width, int height, int dwFlags));

//======================================================
// 函数名称：Ex_ObjScrollGetPos
// 返回类型：int
// 函数说明：获取滚动条位置
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetPos, int, (HEXOBJ hObj, int nBar));

//======================================================
// 函数名称：Ex_MessageBox
// 返回类型：int
// 函数说明：弹出信息框
// 参数<1>：handle, EXHANDLE, 组件句柄/引擎句柄/窗口句柄.(如果该值为窗口句柄且窗口未使用引擎渲染,则以默认信息框弹出)
// 参数<2>：lpText, LPCWSTR, 消息框内容
// 参数<3>：lpCaption, int, 消息框标题
// 参数<4>：uType, int, 相关常量 #MB_
// 参数<5>：dwFlags, int, 相关常量 #EMBF_
//======================================================
EX_DEFINE_API(Ex_MessageBox, int, (EXHANDLE handle, LPCWSTR lpText, int lpCaption, int uType, int dwFlags));

//======================================================
// 函数名称：Ex_MessageBoxEx
// 返回类型：int
// 函数说明：弹出信息框
// 参数<1>：handle, EXHANDLE, 组件句柄/引擎句柄/窗口句柄.(如果该值为窗口句柄且窗口未使用引擎渲染,则以默认信息框弹出)
// 参数<2>：lpText, LPCWSTR, 消息框内容
// 参数<3>：lpCaption, int, 消息框标题
// 参数<4>：uType, int, 相关常量 #MB_
// 参数<5>：lpCheckBox, int, 检查框标题(消息框左下角显示一个检查框组件).(如果该窗口未使用引擎渲染,则该值无效)
// 参数<6>：lpCheckBoxChecked, BOOL, 返回检查框选中状态.(如果该窗口未使用引擎渲染,则该值无效)
// 参数<7>：dwMilliseconds, int, 消息框延迟关闭时间，单位：毫秒。如果该值不为0,且超时后(即用户未操作)，消息框自动关闭，返回32000。
// 参数<8>：dwFlags, int, 相关常量 #EMBF_
// 参数<9>：lpfnMsgProc, ExMsgProc, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
//======================================================
EX_DEFINE_API(Ex_MessageBoxEx, int, (EXHANDLE handle, LPCWSTR lpText, int lpCaption, int uType, int lpCheckBox, BOOL lpCheckBoxChecked, int dwMilliseconds, int dwFlags, ExMsgProc lpfnMsgProc));

//======================================================
// 函数名称：Ex_DUIBindWindow
// 返回类型：HEXDUI
// 函数说明：绑定窗口,成功返回引擎句柄,失败返回0.
// 参数<1>：hWnd, HWND, 窗口句柄
// 参数<2>：hTheme, int, 主题句柄.(值可为0)
// 参数<3>：dwStyle, DWORD, 相关常量:#EWS_
//======================================================
EX_DEFINE_API(Ex_DUIBindWindow, HEXDUI, (HWND hWnd, int hTheme, DWORD dwStyle));

//======================================================
// 函数名称：Ex_ObjGetFromID
// 返回类型：HEXOBJ
// 函数说明：获取组件句柄自ID
// 参数<1>：hExDuiOrhObj, EXHANDLE, 如果指定引擎句柄,则全部搜索;如果指定组件句柄,则从该组件的子组件开始搜索.
// 参数<2>：nID, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromID, HEXOBJ, (EXHANDLE hExDuiOrhObj, int nID));

//======================================================
// 函数名称：Ex_ObjGetFromName
// 返回类型：int
// 函数说明：获取组件句柄自NAME
// 参数<1>：hExDuiOrhObj, EXHANDLE, 如果指定引擎句柄,则全部搜索;如果指定组件句柄,则从该组件的子组件开始搜索.
// 参数<2>：lpwzName, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromName, int, (EXHANDLE hExDuiOrhObj, LPCWSTR lpwzName));

//======================================================
// 函数名称：Ex_ObjHandleEvent
// 返回类型：BOOL
// 函数说明：挂接组件事件回调
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nEvent, int, #NM_
// 参数<3>：pfnCallback, ExObjEventHandler, (Bool) Handler(hObj,nID,nCode,wParam,lParam) 返回假继续分发事件,返回真则停止继续分发事件
//======================================================
EX_DEFINE_API(Ex_ObjHandleEvent, BOOL, (HEXOBJ hObj, int nEvent, ExObjEventHandler pfnCallback));

//======================================================
// 函数名称：Ex_ThemeGetColor
// 返回类型：int
// 函数说明：获取主题相关颜色值
// 参数<1>：hTheme, int, 主题句柄
// 参数<2>：nIndex, int, #COLOR_EX_
//======================================================
EX_DEFINE_API(Ex_ThemeGetColor, int, (int hTheme, int nIndex));

//======================================================
// 函数名称：Ex_ObjGetUIState
// 返回类型：int
// 函数说明：获取组件状态
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetUIState, int, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjSetColor
// 返回类型：int
// 函数说明：设置组件相关颜色,返回修改前相关颜色
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nIndex, int, 相关常量 COLOR_EX_
// 参数<3>：dwColor, int, 
// 参数<4>：fRedraw, BOOL, 是否重画
//======================================================
EX_DEFINE_API(Ex_ObjSetColor, int, (HEXOBJ hObj, int nIndex, int dwColor, BOOL fRedraw));

//======================================================
// 函数名称：Ex_ObjGetColor
// 返回类型：int
// 函数说明：获取组件相关颜色
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nIndex, int, 相关常量 COLOR_EX_
//======================================================
EX_DEFINE_API(Ex_ObjGetColor, int, (HEXOBJ hObj, int nIndex));

//======================================================
// 函数名称：_res_pack
// 返回类型：void
// 函数说明：打包
// 参数<1>：root, LPCSTR, 文件根目录
// 参数<2>：file, LPCSTR, 目标文件
// 参数<3>：fSubDir, BOOL, 是否扫描子目录
// 参数<4>：byteHeader, int, 目标文件头
// 参数<5>：bPntBits, BOOL, 预处理PNG
//======================================================
EX_DEFINE_API(_res_pack, void, (LPCSTR root, LPCSTR file, BOOL fSubDir, int byteHeader, BOOL bPntBits));

//======================================================
// 函数名称：Ex_ResLoadFromFile
// 返回类型：int
// 函数说明：从文件加载资源
// 参数<1>：lpwzFile, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ResLoadFromFile, int, (LPCWSTR lpwzFile));

//======================================================
// 函数名称：Ex_ResLoadFromMemory
// 返回类型：int
// 函数说明：从内存加载资源
// 参数<1>：lpData, LPBYTE, 
// 参数<2>：dwDataLen, int, 
//======================================================
EX_DEFINE_API(Ex_ResLoadFromMemory, int, (LPBYTE lpData, int dwDataLen));

//======================================================
// 函数名称：Ex_I18NGetString
// 返回类型：BOOL
// 函数说明：语言包_获取文本
// 参数<1>：lpwzID, LPCWSTR, 
// 参数<2>：lpString, LPCWSTR, [out]指向字符串指针.如果已被格式化,用户需调用 Ex_I18NFreeString() 进行释放.
// 参数<3>：bFormat, BOOL, [in/out]是否需要格式化
//======================================================
EX_DEFINE_API(Ex_I18NGetString, BOOL, (LPCWSTR lpwzID, LPCWSTR lpString, BOOL bFormat));

//======================================================
// 函数名称：Ex_I18NGetStringFromAtom
// 返回类型：BOOL
// 函数说明：语言包_获取文本
// 参数<1>：atomID, int, 
// 参数<2>：lpString, LPCWSTR, [out]指向字符串指针.如果已被格式化,用户需调用 Ex_FreeBuffer() 进行释放.
// 参数<3>：bFormat, BOOL, [in/out]是否需要格式化
//======================================================
EX_DEFINE_API(Ex_I18NGetStringFromAtom, BOOL, (int atomID, LPCWSTR lpString, BOOL bFormat));

//======================================================
// 函数名称：Ex_ResGetFile
// 返回类型：BOOL
// 函数说明：获取资源文件
// 参数<1>：hRes, int, 
// 参数<2>：lpwzPath, LPCWSTR, 
// 参数<3>：lpFile, int, [out]文件数据指针.用户不应该释放该内存.
// 参数<4>：dwFileLen, int, [out]文件尺寸.
//======================================================
EX_DEFINE_API(Ex_ResGetFile, BOOL, (int hRes, LPCWSTR lpwzPath, int lpFile, int dwFileLen));

//======================================================
// 函数名称：Ex_ResGetFileFromAtom
// 返回类型：BOOL
// 函数说明：获取资源文件
// 参数<1>：hRes, int, 
// 参数<2>：atomPath, int, 
// 参数<3>：lpFile, int, [out]文件数据指针.用户不应该释放该内存.
// 参数<4>：dwFileLen, int, [out]文件尺寸.
//======================================================
EX_DEFINE_API(Ex_ResGetFileFromAtom, BOOL, (int hRes, int atomPath, int lpFile, int dwFileLen));

//======================================================
// 函数名称：Ex_ResFree
// 返回类型：void
// 函数说明：释放资源
// 参数<1>：hRes, int, 
//======================================================
EX_DEFINE_API(Ex_ResFree, void, (int hRes));

//======================================================
// 函数名称：Ex_ObjDispatchNotify
// 返回类型：int
// 函数说明：分发事件
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nCode, int, 
// 参数<3>：wParam, WPARAM, 
// 参数<4>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(Ex_ObjDispatchNotify, int, (HEXOBJ hObj, int nCode, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：Ex_I18NStringFormat
// 返回类型：void
// 函数说明：语言包_文本格式化
// 参数<1>：lppStringSrc, int, 
// 参数<2>：lpStringFormated, int, 
//======================================================
EX_DEFINE_API(Ex_I18NStringFormat, void, (int lppStringSrc, int lpStringFormated));

//======================================================
// 函数名称：Ex_I18NRegisterCallback
// 返回类型：void
// 函数说明：语言包_注册回调
// 参数<1>：pfnStringFormatCallback, int, [bool]callback(atomID,lppString)
//======================================================
EX_DEFINE_API(Ex_I18NRegisterCallback, void, (int pfnStringFormatCallback));

//======================================================
// 函数名称：Ex_DUITrayIconSet
// 返回类型：BOOL
// 函数说明：设置托盘图标
// 参数<1>：hExdui, int, 引擎句柄
// 参数<2>：hIcon, int, 图标句柄
// 参数<3>：lpwzTips, LPCWSTR, 提示文本指针
//======================================================
EX_DEFINE_API(Ex_DUITrayIconSet, BOOL, (int hExdui, int hIcon, LPCWSTR lpwzTips));

//======================================================
// 函数名称：Ex_DUITrayIconPopup
// 返回类型：BOOL
// 函数说明：弹出托盘图标
// 参数<1>：hExDui, HEXDUI, 引擎句柄
// 参数<2>：lpwzInfo, LPCWSTR, 弹出文本内容
// 参数<3>：lpwzInfoTitle, LPCWSTR, 弹出标题文本
// 参数<4>：dwInfoFlags, int, 相关常量 #NIIF_
//======================================================
EX_DEFINE_API(Ex_DUITrayIconPopup, BOOL, (HEXDUI hExDui, LPCWSTR lpwzInfo, LPCWSTR lpwzInfoTitle, int dwInfoFlags));

//======================================================
// 函数名称：Ex_FreeBuffer
// 返回类型：void
// 函数说明：释放内存
// 参数<1>：lpBuffer, LPBYTE, 
//======================================================
EX_DEFINE_API(Ex_FreeBuffer, void, (LPBYTE lpBuffer));

//======================================================
// 函数名称：Ex_ObjDrawBackgroundProc
// 返回类型：BOOL
// 函数说明：默认绘制背景过程
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：hCanvas, HEXCANVAS, 
// 参数<3>：lprcPaint, int, 
//======================================================
EX_DEFINE_API(Ex_ObjDrawBackgroundProc, BOOL, (HEXOBJ hObj, HEXCANVAS hCanvas, int lprcPaint));

//======================================================
// 函数名称：Ex_ObjGetFocus
// 返回类型：HEXOBJ
// 函数说明：获取焦点组件
// 参数<1>：hExDuiOrhObj, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFocus, HEXOBJ, (EXHANDLE hExDuiOrhObj));

//======================================================
// 函数名称：_canvas_settransform
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：pMatrix, int, 0.则重置
//======================================================
EX_DEFINE_API(_canvas_settransform, BOOL, (HEXCANVAS hCanvas, int pMatrix));

//======================================================
// 函数名称：_matrix_create
// 返回类型：int
// 函数说明：
//======================================================
EX_DEFINE_API(_matrix_create, int, ());

//======================================================
// 函数名称：_matrix_destroy
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pMatrix, int, 
//======================================================
EX_DEFINE_API(_matrix_destroy, BOOL, (int pMatrix));

//======================================================
// 函数名称：_matrix_reset
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pMatrix, int, 
//======================================================
EX_DEFINE_API(_matrix_reset, BOOL, (int pMatrix));

//======================================================
// 函数名称：_matrix_translate
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pMatrix, int, 
// 参数<2>：offsetX, float, 
// 参数<3>：offsetY, float, 
//======================================================
EX_DEFINE_API(_matrix_translate, BOOL, (int pMatrix, float offsetX, float offsetY));

//======================================================
// 函数名称：_matrix_rotate
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pMatrix, int, 
// 参数<2>：fAngle, float, 
//======================================================
EX_DEFINE_API(_matrix_rotate, BOOL, (int pMatrix, float fAngle));

//======================================================
// 函数名称：_matrix_scale
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pMatrix, int, 
// 参数<2>：scaleX, float, 
// 参数<3>：scaleY, float, 
//======================================================
EX_DEFINE_API(_matrix_scale, BOOL, (int pMatrix, float scaleX, float scaleY));

//======================================================
// 函数名称：_img_createfromres
// 返回类型：int
// 函数说明：创建图像自资源包。成功返回0。
// 参数<1>：hRes, int, 
// 参数<2>：atomPath, int, 
// 参数<3>：hImg, HEXIMAGE*, 返回图像指针
//======================================================
EX_DEFINE_API(_img_createfromres, int, (int hRes, int atomPath, HEXIMAGE* hImg));

//======================================================
// 函数名称：_brush_setcolor
// 返回类型：int
// 函数说明：
// 参数<1>：hBrush, HEXBRUSH, 
// 参数<2>：argb, int, 
//======================================================
EX_DEFINE_API(_brush_setcolor, int, (HEXBRUSH hBrush, int argb));

//======================================================
// 函数名称：Ex_ThemeDrawControl
// 返回类型：BOOL
// 函数说明：绘制主题数据
// 参数<1>：hTheme, int, 主题句柄
// 参数<2>：hCanvas, HEXCANVAS, 画板句柄
// 参数<3>：dstLeft, float, 目标左边
// 参数<4>：dstTop, float, 目标顶边
// 参数<5>：dstRight, float, 目标右边
// 参数<6>：dstBottom, float, 目标底边
// 参数<7>：atomClass, int, 
// 参数<8>：atomSrcRect, int, 
// 参数<9>：dwAlpha, int, 透明度(0-255)
//======================================================
EX_DEFINE_API(Ex_ThemeDrawControl, BOOL, (int hTheme, HEXCANVAS hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom, int atomClass, int atomSrcRect, int dwAlpha));

//======================================================
// 函数名称：_brush_createfromimg
// 返回类型：HEXBRUSH
// 函数说明：
// 参数<1>：hImg, HEXIMAGE*, 
//======================================================
EX_DEFINE_API(_brush_createfromimg, HEXBRUSH, (HEXIMAGE* hImg));

//======================================================
// 函数名称：_path_create
// 返回类型：int
// 函数说明：创建路径
// 参数<1>：brushmode, int, 
// 参数<2>：dwFlags, int, EPF_
// 参数<3>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_create, int, (int brushmode, int dwFlags, HEXPATH* hPath));

//======================================================
// 函数名称：_path_destroy
// 返回类型：int
// 函数说明：销毁路径
// 参数<1>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_destroy, int, (HEXPATH* hPath));

//======================================================
// 函数名称：_path_addline
// 返回类型：int
// 函数说明：添加线
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：x1, float, 
// 参数<3>：y1, float, 
// 参数<4>：x2, float, 
// 参数<5>：y2, float, 
//======================================================
EX_DEFINE_API(_path_addline, int, (HEXPATH* hPath, float x1, float y1, float x2, float y2));

//======================================================
// 函数名称：_path_beginfigure
// 返回类型：int
// 函数说明：开始新图形
// 参数<1>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_beginfigure, int, (HEXPATH* hPath));

//======================================================
// 函数名称：_path_endfigure
// 返回类型：int
// 函数说明：结束当前图形
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：fCloseFigure, BOOL, 是否需要闭合图形
//======================================================
EX_DEFINE_API(_path_endfigure, int, (HEXPATH* hPath, BOOL fCloseFigure));

//======================================================
// 函数名称：Ex_AllocBuffer
// 返回类型：int
// 函数说明：申请内存
// 参数<1>：dwLen, size_t, 
//======================================================
EX_DEFINE_API(Ex_AllocBuffer, int, (size_t dwLen));

//======================================================
// 函数名称：_img_scale
// 返回类型：int
// 函数说明：缩放图像.成功返回0
// 参数<1>：hImage, HEXIMAGE, 
// 参数<2>：dstWidth, int, 
// 参数<3>：dstHeight, int, 
// 参数<4>：dstImg, HEXIMAGE, 返回新图像
//======================================================
EX_DEFINE_API(_img_scale, int, (HEXIMAGE hImage, int dstWidth, int dstHeight, HEXIMAGE dstImg));

//======================================================
// 函数名称：_fmt_int
// 返回类型：int
// 函数说明：格式化_文本到整数
// 参数<1>：lpValue, int, 字符串指针
// 参数<2>：lpdwPercentFlags, int, (out)返回是否为百分比单位
//======================================================
EX_DEFINE_API(_fmt_int, int, (int lpValue, int lpdwPercentFlags));

//======================================================
// 函数名称：_fmt_intary
// 返回类型：int
// 函数说明：格式化_文本到整数数组
// 参数<1>：lpValue, int, 字符串指针
// 参数<2>：lpAry, int, 数组指针
// 参数<3>：nMaxCount, int, 最大数量
// 参数<4>：fZero, BOOL, 是否清空
// 参数<5>：lpdwPercentFlags, int, (out)返回百分比标记位(0-31位)
//======================================================
EX_DEFINE_API(_fmt_intary, int, (int lpValue, int lpAry, int nMaxCount, BOOL fZero, int lpdwPercentFlags));

//======================================================
// 函数名称：_fmt_rect
// 返回类型：BOOL
// 函数说明：格式化_文本到矩形
// 参数<1>：lpValue, int, 字符串指针
// 参数<2>：lpRect, RECT*, 矩形指针
// 参数<3>：lpdwPercentFlags, int, (out)返回百分比标记位(0-31位)
//======================================================
EX_DEFINE_API(_fmt_rect, BOOL, (int lpValue, RECT* lpRect, int lpdwPercentFlags));

//======================================================
// 函数名称：_fmt_string
// 返回类型：BOOL
// 函数说明：格式化_文本到文本_语言包
// 参数<1>：hRes, int, 资源句柄.(值可为0)
// 参数<2>：lpValue, int, 字符串指针
// 参数<3>：lpString, LPCWSTR, (out)
// 参数<4>：bDispatchI18NCallback, BOOL, (in/out)
//======================================================
EX_DEFINE_API(_fmt_string, BOOL, (int hRes, int lpValue, LPCWSTR lpString, BOOL bDispatchI18NCallback));

//======================================================
// 函数名称：_fmt_color
// 返回类型：BOOL
// 函数说明：格式化_文本到颜色
// 参数<1>：lpValue, int, 字符串指针
// 参数<2>：lpColor, int, (out)返回颜色
//======================================================
EX_DEFINE_API(_fmt_color, BOOL, (int lpValue, int lpColor));

//======================================================
// 函数名称：_fmt_bin
// 返回类型：BOOL
// 函数说明：格式化_二进制数据
// 参数<1>：hRes, int, 资源句柄
// 参数<2>：lpValue, int, 数据指针
// 参数<3>：lpBin, int, (out)返回二进制数据指针
// 参数<4>：lpLen, int, (out)返回数据长度
// 参数<5>：lpFreeBuffer, BOOL, (out)返回是否需要释放数据
//======================================================
EX_DEFINE_API(_fmt_bin, BOOL, (int hRes, int lpValue, int lpBin, int lpLen, BOOL lpFreeBuffer));

//======================================================
// 函数名称：_fmt_getvalue
// 返回类型：BOOL
// 函数说明：格式化_获取数据偏移地址
// 参数<1>：lpValue, int, 
// 参数<2>：atomDest, int, 
//======================================================
EX_DEFINE_API(_fmt_getvalue, BOOL, (int lpValue, int atomDest));

//======================================================
// 函数名称：_fmt_getatom
// 返回类型：int
// 函数说明：格式化_获取数据偏移地址
// 参数<1>：lpValue, int, 
// 参数<2>：lpValueOffset, int, 
//======================================================
EX_DEFINE_API(_fmt_getatom, int, (int lpValue, int lpValueOffset));

//======================================================
// 函数名称：_layout_register
// 返回类型：BOOL
// 函数说明：
// 参数<1>：nType, int, 布局类型
// 参数<2>：lpfnLayoutProc, int, 布局管理器回调函数(lpLayout[有可能是NULL],nEevent,wParam,lParam)返回整数
//======================================================
EX_DEFINE_API(_layout_register, BOOL, (int nType, int lpfnLayoutProc));

//======================================================
// 函数名称：_layout_unregister
// 返回类型：BOOL
// 函数说明：
// 参数<1>：nType, int, 布局类型
//======================================================
EX_DEFINE_API(_layout_unregister, BOOL, (int nType));

//======================================================
// 函数名称：_layout_create
// 返回类型：HEXLAYOUT
// 函数说明：hLayout
// 参数<1>：nType, int, #ELT_ 布局类型
// 参数<2>：hObjBind, EXHANDLE, 所绑定的HOBJ或HEXDUI
//======================================================
EX_DEFINE_API(_layout_create, HEXLAYOUT, (int nType, EXHANDLE hObjBind));

//======================================================
// 函数名称：_layout_destroy
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_destroy, BOOL, (HEXLAYOUT hLayout));

//======================================================
// 函数名称：_layout_addchild
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(_layout_addchild, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj));

//======================================================
// 函数名称：_layout_addchildren
// 返回类型：BOOL
// 函数说明：已被加入的不会重复添加(系统按钮不加入)
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：fDesc, BOOL, 是否倒序
// 参数<3>：dwObjClassATOM, int, 0或空为所有
// 参数<4>：nCount, int, 加入的个数
//======================================================
EX_DEFINE_API(_layout_addchildren, BOOL, (HEXLAYOUT hLayout, BOOL fDesc, int dwObjClassATOM, int nCount));

//======================================================
// 函数名称：_layout_deletechild
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(_layout_deletechild, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj));

//======================================================
// 函数名称：_layout_deletechildren
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：dwObjClassATOM, int, 0或空为所有
//======================================================
EX_DEFINE_API(_layout_deletechildren, BOOL, (HEXLAYOUT hLayout, int dwObjClassATOM));

//======================================================
// 函数名称：_layout_setchildprop
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObj, HEXOBJ, 
// 参数<3>：dwPropID, int, 
// 参数<4>：pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_setchildprop, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int dwPropID, int pvValue));

//======================================================
// 函数名称：_layout_getchildprop
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObj, HEXOBJ, 
// 参数<3>：dwPropID, int, 
// 参数<4>：pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_getchildprop, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int dwPropID, int pvValue));

//======================================================
// 函数名称：_layout_getchildproplist
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObj, HEXOBJ, 
// 参数<3>：lpProps, int, 不释放
//======================================================
EX_DEFINE_API(_layout_getchildproplist, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObj, int lpProps));

//======================================================
// 函数名称：_layout_getprop
// 返回类型：int
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：dwPropID, int, 
//======================================================
EX_DEFINE_API(_layout_getprop, int, (HEXLAYOUT hLayout, int dwPropID));

//======================================================
// 函数名称：_layout_setprop
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：dwPropID, int, 
// 参数<3>：pvValue, int, 
//======================================================
EX_DEFINE_API(_layout_setprop, BOOL, (HEXLAYOUT hLayout, int dwPropID, int pvValue));

//======================================================
// 函数名称：_layout_getproplist
// 返回类型：int
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_getproplist, int, (HEXLAYOUT hLayout));

//======================================================
// 函数名称：_layout_update
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_update, BOOL, (HEXLAYOUT hLayout));

//======================================================
// 函数名称：_layout_gettype
// 返回类型：int
// 函数说明：重新设置type应当重新创建LM
// 参数<1>：hLayout, HEXLAYOUT, 
//======================================================
EX_DEFINE_API(_layout_gettype, int, (HEXLAYOUT hLayout));

//======================================================
// 函数名称：_layout_enableupdate
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：fUpdateable, BOOL, 
//======================================================
EX_DEFINE_API(_layout_enableupdate, BOOL, (HEXLAYOUT hLayout, BOOL fUpdateable));

//======================================================
// 函数名称：_layout_notify
// 返回类型：int
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：nEvent, int, 
// 参数<3>：wParam, WPARAM, 
// 参数<4>：lParam, LPARAM, 
//======================================================
EX_DEFINE_API(_layout_notify, int, (HEXLAYOUT hLayout, int nEvent, WPARAM wParam, LPARAM lParam));

//======================================================
// 函数名称：Ex_ObjGetParentEx
// 返回类型：int
// 函数说明：获取父组件和EXDUI句柄
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：phExDUI, HEXDUI*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetParentEx, int, (HEXOBJ hObj, HEXDUI* phExDUI));

//======================================================
// 函数名称：Ex_ObjGetTextRect
// 返回类型：BOOL
// 函数说明：获取组件文本矩形
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpRect, RECT*, 
//======================================================
EX_DEFINE_API(Ex_ObjGetTextRect, BOOL, (HEXOBJ hObj, RECT* lpRect));

//======================================================
// 函数名称：Ex_ThemeDrawControlEx
// 返回类型：BOOL
// 函数说明：绘制主题数据加强版
// 参数<1>：hTheme, int, 主题句柄
// 参数<2>：hCanvas, HEXCANVAS, 画板句柄
// 参数<3>：dstLeft, float, 目标左边
// 参数<4>：dstTop, float, 目标顶边
// 参数<5>：dstRight, float, 目标右边
// 参数<6>：dstBottom, float, 目标底边
// 参数<7>：atomClass, int, 
// 参数<8>：atomSrcRect, int, 
// 参数<9>：atomBackgroundRepeat, int, 
// 参数<10>：atomBackgroundPositon, int, 
// 参数<11>：atomBackgroundGrid, int, 
// 参数<12>：atomBackgroundFlags, int, 
// 参数<13>：dwAlpha, int, 透明度(0-255)
//======================================================
EX_DEFINE_API(Ex_ThemeDrawControlEx, BOOL, (int hTheme, HEXCANVAS hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom, int atomClass, int atomSrcRect, int atomBackgroundRepeat, int atomBackgroundPositon, int atomBackgroundGrid, int atomBackgroundFlags, int dwAlpha));

//======================================================
// 函数名称：_font_getcontext
// 返回类型：int
// 函数说明：
// 参数<1>：hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_getcontext, int, (HEXFONT hFont));

//======================================================
// 函数名称：Ex_ObjTooltipsSetText
// 返回类型：BOOL
// 函数说明：设置提示文本
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpString, LPCWSTR, 
//======================================================
EX_DEFINE_API(Ex_ObjTooltipsSetText, BOOL, (HEXOBJ hObj, LPCWSTR lpString));

//======================================================
// 函数名称：Ex_TrackPopupMenu
// 返回类型：BOOL
// 函数说明：弹出菜单
// 参数<1>：hMenu, int, 菜单句柄
// 参数<2>：uFlags, int, 相关常量 TPM_
// 参数<3>：x, int, 弹出坐标X(屏幕坐标)
// 参数<4>：y, int, 弹出坐标Y(屏幕坐标)
// 参数<5>：nReserved, int, 0.备用
// 参数<6>：handle, EXHANDLE, 组件句柄/引擎句柄/窗口句柄.(如果该值为窗口句柄且窗口未使用引擎渲染,则以默认菜单弹出)
// 参数<7>：lpRc, int, 0.忽略
// 参数<8>：pfnCallback, ExObjEventHandler, (BOOL)MsgProc(hWnd,hExDui,uMsg,wParam,lParam,lpResult).
// 参数<9>：dwFlags, int, 相关常量 EMNF_
//======================================================
EX_DEFINE_API(Ex_TrackPopupMenu, BOOL, (int hMenu, int uFlags, int x, int y, int nReserved, EXHANDLE handle, int lpRc, ExObjEventHandler pfnCallback, int dwFlags));

//======================================================
// 函数名称：Ex_DUIFromWindow
// 返回类型：int
// 函数说明：从窗口句柄获取引擎句柄
// 参数<1>：hWnd, HWND, 
//======================================================
EX_DEFINE_API(Ex_DUIFromWindow, int, (HWND hWnd));

//======================================================
// 函数名称：Ex_ObjScrollGetRange
// 返回类型：BOOL
// 函数说明：获取滚动条范围
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, 
// 参数<3>：lpnMinPos, int, 
// 参数<4>：lpnMaxPos, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetRange, BOOL, (HEXOBJ hObj, int nBar, int lpnMinPos, int lpnMaxPos));

//======================================================
// 函数名称：Ex_ObjScrollGetTrackPos
// 返回类型：int
// 函数说明：获取滚动条拖动位置
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nBar, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetTrackPos, int, (HEXOBJ hObj, int nBar));

//======================================================
// 函数名称：Ex_ObjScrollGetInfo
// 返回类型：BOOL
// 函数说明：获取滚动条信息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fnBar, int, 
// 参数<3>：lpnMin, int, 
// 参数<4>：lpnMax, int, 
// 参数<5>：lpnPos, int, 
// 参数<6>：lpnTrackPos, int, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollGetInfo, BOOL, (HEXOBJ hObj, int fnBar, int lpnMin, int lpnMax, int lpnPos, int lpnTrackPos));

//======================================================
// 函数名称：Ex_ObjLoadFromLayout
// 返回类型：BOOL
// 函数说明：加载XML布局
// 参数<1>：handle, EXHANDLE, 窗口句柄/引擎句柄/组件句柄
// 参数<2>：hRes, int, 资源句柄.(值可为0)
// 参数<3>：lpLayout, int, 布局资源指针
// 参数<4>：cbLayout, int, 布局资源长度
//======================================================
EX_DEFINE_API(Ex_ObjLoadFromLayout, BOOL, (EXHANDLE handle, int hRes, int lpLayout, int cbLayout));

//======================================================
// 函数名称：Ex_ObjGetFromNodeID
// 返回类型：int
// 函数说明：
// 参数<1>：hExDUIOrObj, int, 
// 参数<2>：nNodeID, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFromNodeID, int, (int hExDUIOrObj, int nNodeID));

//======================================================
// 函数名称：_fmt_const
// 返回类型：BOOL
// 函数说明：
// 参数<1>：const, int, in/out
// 参数<2>：consts, int, atom
// 参数<3>：values, int, value
// 参数<4>：nCount, int, 
//======================================================
EX_DEFINE_API(_fmt_const, BOOL, (int const, int consts, int values, int nCount));

//======================================================
// 函数名称：Ex_JSBindObject
// 返回类型：int
// 函数说明：绑定自己的JS对象
// 参数<1>：hExDUI_hObj, int, 作用域为DUI
// 参数<2>：szObjName, int, 
// 参数<3>：lpfnDispatch, int, HRESULT DispatchFunc (this,atomName,hExDUI,pvParam,wFlags,pDispParams,pVarResult,lpDispInfo)
// 参数<4>：pvParam, int, 
//======================================================
EX_DEFINE_API(Ex_JSBindObject, int, (int hExDUI_hObj, int szObjName, int lpfnDispatch, int pvParam));

//======================================================
// 函数名称：Ex_JSEval
// 返回类型：int
// 函数说明：
// 参数<1>：hExDUI_hObj, int, 
// 参数<2>：szExpression, int, 
// 参数<3>：fUseThis, BOOL, 为真时表达式中this代表参数1对应的JS对象
// 参数<4>：pVarResult, int, 不为NULL时会将返回值写入,注意释放
//======================================================
EX_DEFINE_API(Ex_JSEval, int, (int hExDUI_hObj, int szExpression, BOOL fUseThis, int pVarResult));

//======================================================
// 函数名称：Ex_JSAddCode
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hExDUI_hObj, int, 
// 参数<2>：szCode, LPCSTR, 
//======================================================
EX_DEFINE_API(Ex_JSAddCode, BOOL, (int hExDUI_hObj, LPCSTR szCode));

//======================================================
// 函数名称：Ex_JSGetLastError
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hExDUI_hObj, int, 
// 参数<2>：nErrCode, int, 
// 参数<3>：nErrLine, int, 
// 参数<4>：szErrMsg, int, char[1024]
//======================================================
EX_DEFINE_API(Ex_JSGetLastError, BOOL, (int hExDUI_hObj, int nErrCode, int nErrLine, int szErrMsg));

//======================================================
// 函数名称：Ex_JSRegisterFunction
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：notyfiCode, int, 
// 参数<3>：szFuncName, int, 
//======================================================
EX_DEFINE_API(Ex_JSRegisterFunction, BOOL, (HEXOBJ hObj, int notyfiCode, int szFuncName));

//======================================================
// 函数名称：Ex_JSSetVariant
// 返回类型：void
// 函数说明：
// 参数<1>：pVariant, int, 
// 参数<2>：nType, int, 
// 参数<3>：dwValue, int, 
//======================================================
EX_DEFINE_API(Ex_JSSetVariant, void, (int pVariant, int nType, int dwValue));

//======================================================
// 函数名称：Ex_JSSetVariantPtr
// 返回类型：void
// 函数说明：
// 参数<1>：pVariant, int, 
// 参数<2>：nType, int, 
// 参数<3>：pValue, int, 
// 参数<4>：cbSize, int, 1,2,4,8
//======================================================
EX_DEFINE_API(Ex_JSSetVariantPtr, void, (int pVariant, int nType, int pValue, int cbSize));

//======================================================
// 函数名称：Ex_JSGetParamCount
// 返回类型：int
// 函数说明：
// 参数<1>：lpParams, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamCount, int, (int lpParams));

//======================================================
// 函数名称：Ex_JSGetParamType
// 返回类型：int
// 函数说明：
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamType, int, (int lpParams, int nIndex));

//======================================================
// 函数名称：Ex_JSGetParam
// 返回类型：int
// 函数说明：返回pVar
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParam, int, (int lpParams, int nIndex));

//======================================================
// 函数名称：Ex_JSGetParamNumber
// 返回类型：double
// 函数说明：
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
// 参数<3>：nDefault, double, 
// 参数<4>：pType, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamNumber, double, (int lpParams, int nIndex, double nDefault, int pType));

//======================================================
// 函数名称：Ex_JSGetParamInt
// 返回类型：int
// 函数说明：
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
// 参数<3>：nDefault, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamInt, int, (int lpParams, int nIndex, int nDefault));

//======================================================
// 函数名称：Ex_JSGetParamFloat
// 返回类型：float
// 函数说明：
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
// 参数<3>：nDefault, float, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamFloat, float, (int lpParams, int nIndex, float nDefault));

//======================================================
// 函数名称：Ex_JSGetParamDouble
// 返回类型：double
// 函数说明：
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
// 参数<3>：nDefault, double, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamDouble, double, (int lpParams, int nIndex, double nDefault));

//======================================================
// 函数名称：Ex_JSGetParamString
// 返回类型：int
// 函数说明：wchar_t* 不要释放
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamString, int, (int lpParams, int nIndex));

//======================================================
// 函数名称：Ex_JSGetParamToString
// 返回类型：int
// 函数说明：wchar_t* 需要自己释放
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
// 参数<3>：wzDefault, int, 
// 参数<4>：pType, int, 
// 参数<5>：fFormat, BOOL, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamToString, int, (int lpParams, int nIndex, int wzDefault, int pType, BOOL fFormat));

//======================================================
// 函数名称：Ex_JSGetParamFormatString
// 返回类型：int
// 函数说明：wchar_t* 需要自己释放
// 参数<1>：lpParams, int, 
// 参数<2>：nIndex, int, 
//======================================================
EX_DEFINE_API(Ex_JSGetParamFormatString, int, (int lpParams, int nIndex));

//======================================================
// 函数名称：Ex_ObjGetRectEx
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpRect, RECT*, 
// 参数<3>：nType, int, 
//======================================================
EX_DEFINE_API(Ex_ObjGetRectEx, BOOL, (HEXOBJ hObj, RECT* lpRect, int nType));

//======================================================
// 函数名称：Ex_ObjLayoutGet
// 返回类型：int
// 函数说明：获取布局对象句柄
// 参数<1>：handle, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutGet, int, (EXHANDLE handle));

//======================================================
// 函数名称：Ex_ObjLayoutSet
// 返回类型：BOOL
// 函数说明：设置布局对象句柄
// 参数<1>：handle, EXHANDLE, 
// 参数<2>：hLayout, HEXLAYOUT, 
// 参数<3>：fUpdate, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutSet, BOOL, (EXHANDLE handle, HEXLAYOUT hLayout, BOOL fUpdate));

//======================================================
// 函数名称：Ex_ObjLayoutUpdate
// 返回类型：BOOL
// 函数说明：更新对象布局
// 参数<1>：handle, EXHANDLE, 
//======================================================
EX_DEFINE_API(Ex_ObjLayoutUpdate, BOOL, (EXHANDLE handle));

//======================================================
// 函数名称：Ex_ObjLayoutClear
// 返回类型：BOOL
// 函数说明：清空对象布局信息
// 参数<1>：handle, EXHANDLE, 
// 参数<2>：bChildren, BOOL, 是否清空所有子组件,否则为当前组件.
//======================================================
EX_DEFINE_API(Ex_ObjLayoutClear, BOOL, (EXHANDLE handle, BOOL bChildren));

//======================================================
// 函数名称：_layout_table_setinfo
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：aRowHeight, int, 
// 参数<3>：cRows, int, 
// 参数<4>：aCellWidth, int, 
// 参数<5>：cCells, int, 
//======================================================
EX_DEFINE_API(_layout_table_setinfo, BOOL, (HEXLAYOUT hLayout, int aRowHeight, int cRows, int aCellWidth, int cCells));

//======================================================
// 函数名称：Ex_ObjSetPadding
// 返回类型：BOOL
// 函数说明：设置组件偏移矩形
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nPaddingType, int, EOPT_TEXT=0
// 参数<3>：left, int, 
// 参数<4>：top, int, 
// 参数<5>：right, int, 
// 参数<6>：bottom, int, 
// 参数<7>：fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetPadding, BOOL, (HEXOBJ hObj, int nPaddingType, int left, int top, int right, int bottom, BOOL fRedraw));

//======================================================
// 函数名称：Ex_ObjSetFontFromFamily
// 返回类型：BOOL
// 函数说明：设置组件文本字体
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpszFontfamily, LPCWSTR, -1 为默认字体
// 参数<3>：dwFontsize, int, -1 为默认尺寸
// 参数<4>：dwFontstyle, int, -1 为默认风格
// 参数<5>：fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFontFromFamily, BOOL, (HEXOBJ hObj, LPCWSTR lpszFontfamily, int dwFontsize, int dwFontstyle, BOOL fRedraw));

//======================================================
// 函数名称：Ex_ObjGetFont
// 返回类型：HEXFONT
// 函数说明：获取字体。用户不应该销毁该字体对象
// 参数<1>：hObj, HEXOBJ, 
//======================================================
EX_DEFINE_API(Ex_ObjGetFont, HEXFONT, (HEXOBJ hObj));

//======================================================
// 函数名称：Ex_ObjPointTransform
// 返回类型：void
// 函数说明：
// 参数<1>：hObjSrc, int, 
// 参数<2>：hObjDst, int, 0为所属窗口
// 参数<3>：ptX, int, in/out
// 参数<4>：ptY, int, in/out
//======================================================
EX_DEFINE_API(Ex_ObjPointTransform, void, (int hObjSrc, int hObjDst, int ptX, int ptY));

//======================================================
// 函数名称：Ex_ObjEnableEventBubble
// 返回类型：BOOL
// 函数说明：设置该控件是否启用事件冒泡
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fEnable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjEnableEventBubble, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// 函数名称：Ex_ObjGetClassInfo
// 返回类型：BOOL
// 函数说明：获取组件类信息
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpClassInfo, int, 相关结构 EX_CLASSINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetClassInfo, BOOL, (HEXOBJ hObj, int lpClassInfo));

//======================================================
// 函数名称：Ex_ObjGetClassInfoEx
// 返回类型：BOOL
// 函数说明：通过类名/类ATOM获取类信息
// 参数<1>：wzClassName, int, wzClassName/AtomClassName
// 参数<2>：lpClassInfo, int, 相关结构 EX_CLASSINFO
//======================================================
EX_DEFINE_API(Ex_ObjGetClassInfoEx, BOOL, (int wzClassName, int lpClassInfo));

//======================================================
// 函数名称：_easing_curve_load
// 返回类型：int
// 函数说明：
// 参数<1>：lpCurveInfo, int, 
// 参数<2>：cbCurveInfo, int, 
//======================================================
EX_DEFINE_API(_easing_curve_load, int, (int lpCurveInfo, int cbCurveInfo));

//======================================================
// 函数名称：_easing_curve_free
// 返回类型：void
// 函数说明：
// 参数<1>：pCurveInfo, int, 
//======================================================
EX_DEFINE_API(_easing_curve_free, void, (int pCurveInfo));

//======================================================
// 函数名称：_easing_create
// 返回类型：int
// 函数说明：
// 参数<1>：dwType, int, #缓动类型_
// 参数<2>：pEasingContext, int, 
// 参数<3>：dwMode, int, #缓动模式_ 的组合
// 参数<4>：pContext, int, 
// 参数<5>：nTotalTime, int, ms
// 参数<6>：nInterval, int, ms
// 参数<7>：nState, int, #EES_
// 参数<8>：nStart, int, 
// 参数<9>：nStop, int, 
// 参数<10>：param1, int, 
// 参数<11>：param2, int, 
// 参数<12>：param3, int, 
// 参数<13>：param4, int, 
//======================================================
EX_DEFINE_API(_easing_create, int, (int dwType, int pEasingContext, int dwMode, int pContext, int nTotalTime, int nInterval, int nState, int nStart, int nStop, int param1, int param2, int param3, int param4));

//======================================================
// 函数名称：_easing_setstate
// 返回类型：BOOL
// 函数说明：
// 参数<1>：pEasing, HEXEASING, 
// 参数<2>：nState, int, #EES_
//======================================================
EX_DEFINE_API(_easing_setstate, BOOL, (HEXEASING pEasing, int nState));

//======================================================
// 函数名称：Ex_Sleep
// 返回类型：void
// 函数说明：
// 参数<1>：us, int, 
//======================================================
EX_DEFINE_API(Ex_Sleep, void, (int us));

//======================================================
// 函数名称：_easing_getstate
// 返回类型：int
// 函数说明：
// 参数<1>：pEasing, HEXEASING, 
//======================================================
EX_DEFINE_API(_easing_getstate, int, (HEXEASING pEasing));

//======================================================
// 函数名称：_layout_absolute_setedge
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObjChild, HEXOBJ, 
// 参数<3>：dwEdge, int, #ELCP_ABSOLUTE_XXX
// 参数<4>：dwType, int, 
// 参数<5>：nValue, int, 
//======================================================
EX_DEFINE_API(_layout_absolute_setedge, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObjChild, int dwEdge, int dwType, int nValue));

//======================================================
// 函数名称：_layout_absolute_lock
// 返回类型：BOOL
// 函数说明：按当前位置锁定
// 参数<1>：hLayout, HEXLAYOUT, 
// 参数<2>：hObjChild, HEXOBJ, 
// 参数<3>：tLeft, int, #ELCP_ABSOLUTE_XXX_TYPE 下同
// 参数<4>：tTop, int, 
// 参数<5>：tRight, int, 
// 参数<6>：tBottom, int, 
// 参数<7>：tWidth, int, 
// 参数<8>：tHeight, int, 
//======================================================
EX_DEFINE_API(_layout_absolute_lock, BOOL, (HEXLAYOUT hLayout, HEXOBJ hObjChild, int tLeft, int tTop, int tRight, int tBottom, int tWidth, int tHeight));

//======================================================
// 函数名称：Ex_ObjInitPropList
// 返回类型：BOOL
// 函数说明：要注意每次初始化都会清空之前存储的内容,若存储的是指针需要自己先行释放
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：nPropCount, int, -1为哈希表模式,0为不存储属性,正数为属性个数(每个4字节)
//======================================================
EX_DEFINE_API(Ex_ObjInitPropList, BOOL, (HEXOBJ hObj, int nPropCount));

//======================================================
// 函数名称：Ex_ObjRemoveProp
// 返回类型：int
// 函数说明：移除属性
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：dwKey, int, 
//======================================================
EX_DEFINE_API(Ex_ObjRemoveProp, int, (HEXOBJ hObj, int dwKey));

//======================================================
// 函数名称：Ex_ObjEnumProps
// 返回类型：int
// 函数说明：返回个数.枚举属性表
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：lpfnCbk, int, bool enum(hObj,dwKey,dwValue,param)
// 参数<3>：param, int, 
//======================================================
EX_DEFINE_API(Ex_ObjEnumProps, int, (HEXOBJ hObj, int lpfnCbk, int param));

//======================================================
// 函数名称：_brush_createfromcanvas
// 返回类型：HEXBRUSH
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
//======================================================
EX_DEFINE_API(_brush_createfromcanvas, HEXBRUSH, (HEXCANVAS hCanvas));

//======================================================
// 函数名称：Ex_ObjSetRadius
// 返回类型：BOOL
// 函数说明：设置组件圆角度
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：topleft, float, 左上角
// 参数<3>：topright, float, 右上角
// 参数<4>：bottomright, float, 右下角
// 参数<5>：bottomleft, float, 左下角
// 参数<6>：fUpdate, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetRadius, BOOL, (HEXOBJ hObj, float topleft, float topright, float bottomright, float bottomleft, BOOL fUpdate));

//======================================================
// 函数名称：_path_reset
// 返回类型：int
// 函数说明：重置路径
// 参数<1>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_reset, int, (HEXPATH* hPath));

//======================================================
// 函数名称：_path_getbounds
// 返回类型：int
// 函数说明：取路径边界矩形
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：lpBounds, int, RECTF
//======================================================
EX_DEFINE_API(_path_getbounds, int, (HEXPATH* hPath, int lpBounds));

//======================================================
// 函数名称：_path_close
// 返回类型：int
// 函数说明：关闭路径
// 参数<1>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_close, int, (HEXPATH* hPath));

//======================================================
// 函数名称：_path_open
// 返回类型：int
// 函数说明：打开路径
// 参数<1>：hPath, HEXPATH*, 
//======================================================
EX_DEFINE_API(_path_open, int, (HEXPATH* hPath));

//======================================================
// 函数名称：_path_addarc
// 返回类型：int
// 函数说明：添加弧 (已过时,不推荐使用)
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：x1, float, 起始坐标X
// 参数<3>：y1, float, 起始坐标Y
// 参数<4>：x2, float, 终点坐标X
// 参数<5>：y2, float, 终点坐标Y
// 参数<6>：radiusX, float, 半径X
// 参数<7>：radiusY, float, 半径Y
// 参数<8>：fClockwise, BOOL, 是否顺时针
//======================================================
EX_DEFINE_API(_path_addarc, int, (HEXPATH* hPath, float x1, float y1, float x2, float y2, float radiusX, float radiusY, BOOL fClockwise));

//======================================================
// 函数名称：_path_addarc2
// 返回类型：int
// 函数说明：添加弧 v2
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：x, float, 
// 参数<3>：y, float, 
// 参数<4>：width, float, 宽度
// 参数<5>：height, float, 高度
// 参数<6>：startAngle, float, 开始角度
// 参数<7>：sweepAngle, float, 扫描角度
//======================================================
EX_DEFINE_API(_path_addarc2, int, (HEXPATH* hPath, float x, float y, float width, float height, float startAngle, float sweepAngle));

//======================================================
// 函数名称：_canvas_drawpath
// 返回类型：int
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hPath, HEXPATH*, 
// 参数<3>：hBrush, HEXBRUSH, 
// 参数<4>：strokeWidth, float, 
// 参数<5>：strokeStyle, int, 
//======================================================
EX_DEFINE_API(_canvas_drawpath, int, (HEXCANVAS hCanvas, HEXPATH* hPath, HEXBRUSH hBrush, float strokeWidth, int strokeStyle));

//======================================================
// 函数名称：_canvas_fillpath
// 返回类型：int
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：hPath, HEXPATH*, 
// 参数<3>：hBrush, HEXBRUSH, 
//======================================================
EX_DEFINE_API(_canvas_fillpath, int, (HEXCANVAS hCanvas, HEXPATH* hPath, HEXBRUSH hBrush));

//======================================================
// 函数名称：_path_addrect
// 返回类型：int
// 函数说明：添加矩形
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：left, float, 
// 参数<3>：top, float, 
// 参数<4>：right, float, 
// 参数<5>：bottom, float, 
//======================================================
EX_DEFINE_API(_path_addrect, int, (HEXPATH* hPath, float left, float top, float right, float bottom));

//======================================================
// 函数名称：_path_addroundedrect
// 返回类型：int
// 函数说明：添加圆角矩形
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：left, float, 
// 参数<3>：top, float, 
// 参数<4>：right, float, 
// 参数<5>：bottom, float, 
// 参数<6>：radiusTopLeft, float, 
// 参数<7>：radiusTopRight, float, 
// 参数<8>：radiusBottomLeft, float, 
// 参数<9>：radiusBottomRight, float, 
// 参数<10>：unit, int, 
//======================================================
EX_DEFINE_API(_path_addroundedrect, int, (HEXPATH* hPath, float left, float top, float right, float bottom, float radiusTopLeft, float radiusTopRight, float radiusBottomLeft, float radiusBottomRight, int unit));

//======================================================
// 函数名称：_path_hittest
// 返回类型：BOOL
// 函数说明：测试坐标是否在可见路径内
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：x, float, 
// 参数<3>：y, float, 
//======================================================
EX_DEFINE_API(_path_hittest, BOOL, (HEXPATH* hPath, float x, float y));

//======================================================
// 函数名称：_brush_settransform
// 返回类型：int
// 函数说明：
// 参数<1>：hBrush, HEXBRUSH, 
// 参数<2>：matrix, int, 
//======================================================
EX_DEFINE_API(_brush_settransform, int, (HEXBRUSH hBrush, int matrix));

//======================================================
// 函数名称：Ex_ObjScrollShow
// 返回类型：BOOL
// 函数说明：显示/隐藏滚动条
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：wBar, int, 支持SB_BOTH
// 参数<3>：fShow, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjScrollShow, BOOL, (HEXOBJ hObj, int wBar, BOOL fShow));

//======================================================
// 函数名称：Ex_ObjScrollEnable
// 返回类型：BOOL
// 函数说明：禁用/启用滚动条
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：wSB, int, 支持SB_BOTH
// 参数<3>：wArrows, int, 相关常量 ESB_
//======================================================
EX_DEFINE_API(Ex_ObjScrollEnable, BOOL, (HEXOBJ hObj, int wSB, int wArrows));

//======================================================
// 函数名称：_font_copy
// 返回类型：int
// 函数说明：
// 参数<1>：hFont, HEXFONT, 
//======================================================
EX_DEFINE_API(_font_copy, int, (HEXFONT hFont));

//======================================================
// 函数名称：Ex_JSLoadConst
// 返回类型：void
// 函数说明：加载JS常量
// 参数<1>：szConst, LPCSTR, 
//======================================================
EX_DEFINE_API(Ex_JSLoadConst, void, (LPCSTR szConst));

//======================================================
// 函数名称：Ex_ObjSetFont
// 返回类型：BOOL
// 函数说明：设置组件文本字体
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：hFont, HEXFONT, _font_createxxx
// 参数<3>：fRedraw, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetFont, BOOL, (HEXOBJ hObj, HEXFONT hFont, BOOL fRedraw));

//======================================================
// 函数名称：_imglist_create
// 返回类型：int
// 函数说明：创建图片组
// 参数<1>：nWidth, int, 宽度
// 参数<2>：nHeight, int, 高度
//======================================================
EX_DEFINE_API(_imglist_create, int, (int nWidth, int nHeight));

//======================================================
// 函数名称：_imglist_destroy
// 返回类型：void
// 函数说明：销毁图片组
// 参数<1>：hImageList, int, 图片组句柄
//======================================================
EX_DEFINE_API(_imglist_destroy, void, (int hImageList));

//======================================================
// 函数名称：_imglist_add
// 返回类型：int
// 函数说明：添加图片
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：lpImage, int, 图像数据指针
// 参数<3>：cbImage, int, 图像数据长度
// 参数<4>：nIndexInsert, int, 插入位置(0为最后)
//======================================================
EX_DEFINE_API(_imglist_add, int, (int hImageList, int lpImage, int cbImage, int nIndexInsert));

//======================================================
// 函数名称：_imglist_addimage
// 返回类型：int
// 函数说明：添加图片
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：hImage, HEXIMAGE, 图像对象句柄
// 参数<3>：nIndexInsert, int, 插入位置(0为最后)
//======================================================
EX_DEFINE_API(_imglist_addimage, int, (int hImageList, HEXIMAGE hImage, int nIndexInsert));

//======================================================
// 函数名称：_imglist_del
// 返回类型：int
// 函数说明：删除图片
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：nIndex, int, 图片索引
//======================================================
EX_DEFINE_API(_imglist_del, int, (int hImageList, int nIndex));

//======================================================
// 函数名称：_imglist_get
// 返回类型：int
// 函数说明：获取图片句柄
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：nIndex, int, 图片索引
//======================================================
EX_DEFINE_API(_imglist_get, int, (int hImageList, int nIndex));

//======================================================
// 函数名称：_imglist_set
// 返回类型：int
// 函数说明：设置图片
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：nIndex, int, 图片索引
// 参数<3>：lpImage, int, 图片数据指针
// 参数<4>：cbImage, int, 图片数据长度
//======================================================
EX_DEFINE_API(_imglist_set, int, (int hImageList, int nIndex, int lpImage, int cbImage));

//======================================================
// 函数名称：_imglist_setimage
// 返回类型：int
// 函数说明：设置图片
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：nIndex, int, 图片索引
// 参数<3>：hImage, HEXIMAGE, 图像对象句柄
//======================================================
EX_DEFINE_API(_imglist_setimage, int, (int hImageList, int nIndex, HEXIMAGE hImage));

//======================================================
// 函数名称：_imglist_count
// 返回类型：int
// 函数说明：获取图片组图片数量
// 参数<1>：hImageList, int, 图片组句柄
//======================================================
EX_DEFINE_API(_imglist_count, int, (int hImageList));

//======================================================
// 函数名称：_imglist_size
// 返回类型：void
// 函数说明：获取图片组图片尺寸
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：pWidth, int, 图片宽度
// 参数<3>：pHeight, int, 图片高度
//======================================================
EX_DEFINE_API(_imglist_size, void, (int hImageList, int pWidth, int pHeight));

//======================================================
// 函数名称：_imglist_draw
// 返回类型：BOOL
// 函数说明：绘制图片(图片将被居中绘制到提供的矩形中)
// 参数<1>：hImageList, int, 图片组句柄
// 参数<2>：nIndex, int, 图片索引
// 参数<3>：hCanvas, HEXCANVAS, 画布句柄
// 参数<4>：nLeft, int, 左边
// 参数<5>：nTop, int, 顶边
// 参数<6>：nRight, int, 右边
// 参数<7>：nBottom, int, 底边
// 参数<8>：nAlpha, int, 透明度0-255
//======================================================
EX_DEFINE_API(_imglist_draw, BOOL, (int hImageList, int nIndex, HEXCANVAS hCanvas, int nLeft, int nTop, int nRight, int nBottom, int nAlpha));

//======================================================
// 函数名称：Ex_ObjEnableIME
// 返回类型：BOOL
// 函数说明：是否允许启用输入法
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fEnable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjEnableIME, BOOL, (HEXOBJ hObj, BOOL fEnable));

//======================================================
// 函数名称：Ex_ObjSetIMEState
// 返回类型：BOOL
// 函数说明：设置窗口的输入法状态
// 参数<1>：hObjOrExDui, int, 
// 参数<2>：fOpen, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjSetIMEState, BOOL, (int hObjOrExDui, BOOL fOpen));

//======================================================
// 函数名称：Ex_ObjDisableTranslateSpaceAndEnterToClick
// 返回类型：BOOL
// 函数说明：设置控件是否禁止转换空格和回车为单击事件
// 参数<1>：hObj, HEXOBJ, 
// 参数<2>：fDisable, BOOL, 
//======================================================
EX_DEFINE_API(Ex_ObjDisableTranslateSpaceAndEnterToClick, BOOL, (HEXOBJ hObj, BOOL fDisable));

//======================================================
// 函数名称：_canvas_settextantialiasmode
// 返回类型：BOOL
// 函数说明：设置画布文本抗锯齿模式
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：textAntialiasMode, int, 0.不抗锯齿 1.抗锯齿 2.ClearType
//======================================================
EX_DEFINE_API(_canvas_settextantialiasmode, BOOL, (HEXCANVAS hCanvas, int textAntialiasMode));

//======================================================
// 函数名称：_canvas_setantialias
// 返回类型：BOOL
// 函数说明：设置画布图形抗锯齿
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：antialias, BOOL, 是否抗锯齿
//======================================================
EX_DEFINE_API(_canvas_setantialias, BOOL, (HEXCANVAS hCanvas, BOOL antialias));

//======================================================
// 函数名称：_canvas_setimageantialias
// 返回类型：BOOL
// 函数说明：设置画布图像抗锯齿
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：antialias, BOOL, 是否抗锯齿
//======================================================
EX_DEFINE_API(_canvas_setimageantialias, BOOL, (HEXCANVAS hCanvas, BOOL antialias));

//======================================================
// 函数名称：Ex_ObjSetParent
// 返回类型：int
// 函数说明：置父
// 参数<1>：hObj, HEXOBJ, 被置父的子控件
// 参数<2>：hParent, EXHANDLE, 新的父控件/皮肤/窗口 句柄
//======================================================
EX_DEFINE_API(Ex_ObjSetParent, int, (HEXOBJ hObj, EXHANDLE hParent));

//======================================================
// 函数名称：_brush_createlinear
// 返回类型：HEXBRUSH
// 函数说明：创建线性渐变画刷
// 参数<1>：xs, float, 起点X
// 参数<2>：ys, float, 起点Y
// 参数<3>：xe, float, 终点X
// 参数<4>：ye, float, 终点Y
// 参数<5>：crBegin, int, 起点颜色ARGB
// 参数<6>：crEnd, int, 终点颜色ARGB
//======================================================
EX_DEFINE_API(_brush_createlinear, HEXBRUSH, (float xs, float ys, float xe, float ye, int crBegin, int crEnd));

//======================================================
// 函数名称：_brush_createlinear_ex
// 返回类型：HEXBRUSH
// 函数说明：创建线性渐变画刷2
// 参数<1>：xs, float, 起点X
// 参数<2>：ys, float, 起点Y
// 参数<3>：xe, float, 终点X
// 参数<4>：ye, float, 终点Y
// 参数<5>：arrStopPts, int, 停止点指针,{位置(0-100),颜色(ARGB),位置,颜色,...}
// 参数<6>：cStopPts, int, 停止点个数
//======================================================
EX_DEFINE_API(_brush_createlinear_ex, HEXBRUSH, (float xs, float ys, float xe, float ye, int arrStopPts, int cStopPts));

//======================================================
// 函数名称：_path_beginfigure2
// 返回类型：int
// 函数说明：开始图形(可设置起始点,D2D有效,GDI模式和beginfigure一样)
// 参数<1>：hPath, HEXPATH*, 
// 参数<2>：x, float, 起始坐标
// 参数<3>：y, float, 起始坐标
//======================================================
EX_DEFINE_API(_path_beginfigure2, int, (HEXPATH* hPath, float x, float y));

//======================================================
// 函数名称：Ex_LoadImageFromMemory
// 返回类型：int
// 函数说明：加载图像对象自内存(返回位图句柄或图标句柄)
// 参数<1>：lpData, LPBYTE, 图像数据指针
// 参数<2>：dwLen, size_t, 图像数据长度
// 参数<3>：uType, int, 图像类型 #IMAGE_
// 参数<4>：nIndex, int, 索引
//======================================================
EX_DEFINE_API(Ex_LoadImageFromMemory, int, (LPBYTE lpData, size_t dwLen, int uType, int nIndex));

//======================================================
// 函数名称：_brush_createfromcanvas2
// 返回类型：HEXBRUSH
// 函数说明：画刷_创建自画布2
// 参数<1>：hCanvas, HEXCANVAS, 画布句柄
// 参数<2>：nAlpha, int, 透明度
//======================================================
EX_DEFINE_API(_brush_createfromcanvas2, HEXBRUSH, (HEXCANVAS hCanvas, int nAlpha));

//======================================================
// 函数名称：_img_savetofile
// 返回类型：int
// 函数说明：图像_保存文件
// 参数<1>：hImg, HEXIMAGE, 图像句柄
// 参数<2>：wzFileName, LPCWSTR, 保存的文件名
//======================================================
EX_DEFINE_API(_img_savetofile, int, (HEXIMAGE hImg, LPCWSTR wzFileName));

//======================================================
// 函数名称：_img_savetomemory
// 返回类型：int
// 函数说明：返回长度
// 参数<1>：hImg, HEXIMAGE, 图像句柄
// 参数<2>：lpBuffer, LPBYTE, 填充保存的缓冲区(0则只是返回长度)
//======================================================
EX_DEFINE_API(_img_savetomemory, int, (HEXIMAGE hImg, LPBYTE lpBuffer));

//======================================================
// 函数名称：_canvas_drawcanvas
// 返回类型：BOOL
// 函数说明：
// 参数<1>：hCanvas, HEXCANVAS, 
// 参数<2>：sCanvas, int, 
// 参数<3>：dstLeft, int, 
// 参数<4>：dstTop, int, 
// 参数<5>：dstRight, int, 
// 参数<6>：dstBottom, int, 
// 参数<7>：srcLeft, int, 
// 参数<8>：srcTop, int, 
// 参数<9>：dwAlpha, int, 
// 参数<10>：dwCompositeMode, int, #CV_COMPOSITE_MODE_
//======================================================
EX_DEFINE_API(_canvas_drawcanvas, BOOL, (HEXCANVAS hCanvas, int sCanvas, int dstLeft, int dstTop, int dstRight, int dstBottom, int srcLeft, int srcTop, int dwAlpha, int dwCompositeMode));

