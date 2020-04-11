#pragma once

// ����DPI����
#define EXGF_DPI_ENABLE	2
// ����_�������
#define EXGF_RENDER_CANVAS_ALIAS	64
// ʹ��GDI/GDI+��Ⱦ
#define EXGF_RENDER_METHOD_GDI	128
// ʹ��D2D��Ⱦ
#define EXGF_RENDER_METHOD_D2D	256
// ʹ��֧��GDI������D2D��Ⱦ
#define EXGF_RENDER_METHOD_D2D_GDI_COMPATIBLE	768
// �ı���Ⱦ_ʹ��ClearType�����
#define EXGF_TEXT_CLEARTYPE	1024
// �ı���Ⱦ_�����
#define EXGF_TEXT_ANTIALIAS	2048
// ͼ����Ⱦ_�����
#define EXGF_IMAGE_ANTIALIAS	4096
// ���ö���Ч��
#define EXGF_OBJECT_DISABLEANIMATION	65536
// ��ʾ����߽�
#define EXGF_OBJECT_SHOWRECTBORDER	131072
// ��ʾ���λ��
#define EXGF_OBJECT_SHOWPOSTION	262144
// ����JSȫ�ֶ�������ļ�
#define EXGF_JS_FILE	524288
// ����JSȫ�ֶ�������ڴ�
#define EXGF_JS_MEMORY	1048576
// ����JSȫ�ֶ��������ڴ�
#define EXGF_JS_MEMORY_ALLOC	2097152
// ����JSȫ�ֶ��󴴽����̡�������򡢼���DLL
#define EXGF_JS_PROCESS	4194304
// ����JSȫ�ֶ������������Դ
#define EXGF_JS_ALL	7864320
// ��Ⱦ���в˵�
#define EXGF_MENU_ALL	8388608
// ����ע��
#define EXR_DEFAULT	0
// ����ע��
#define EXR_STRING	1
// ����ע��
#define EXR_LAYOUT	2
// ����ʾ�˵���Ӱ
#define EMNF_NOSHADOW	-2147483648
// ��ʾ����ͼ��
#define EMBF_WINDOWICON	-2147483648
// ��Ϣ��Ӹ������м�
#define EMBF_CENTEWINDOW	1073741824
// ��ʾ����ʱ
#define EMBF_SHOWTIMEOUT	536870912
// ������_�رհ�ť
#define EWS_BUTTON_CLOSE	1
// ������_��󻯰�ť
#define EWS_BUTTON_MAX	2
// ������_��С����ť
#define EWS_BUTTON_MIN	4
// ������_�˵���ť
#define EWS_BUTTON_MENU	8
// ������_Ƥ����ť
#define EWS_BUTTON_SKIN	16
// ������_���ð�ť
#define EWS_BUTTON_SETTING	32
// ������_������ť
#define EWS_BUTTON_HELP	64
// ������_ͼ��
#define EWS_HASICON	128
// ������_����
#define EWS_TITLE	256
// ������_ȫ��ģʽ.���øñ�Ǵ������ʱ,�����������ڵ�.
#define EWS_FULLSCREEN	512
// ������_��������ߴ�
#define EWS_SIZEABLE	1024
// ������_���������ƶ�
#define EWS_MOVEABLE	2048
// ������_����ʾ������Ӱ
#define EWS_NOSHADOW	4096
// ������_���̳и����ڱ�������
#define EWS_NOINHERITBKG	8192
// ������_����ʾTAB����߿�
#define EWS_NOTABBORDER	16384
// ������_ESC�رմ���
#define EWS_ESCEXIT	32768
// ������_������(ӵ�и÷��ʱ,�����ڱ��ر�,�����PostQuitMessage()�˳���Ϣѭ��)
#define EWS_MAINWINDOW	65536
// ������_���ھ���(����и�����,���ڸ������м�,����Ϊ��Ļ�м�)
#define EWS_CENTERWINDOW	131072
// ������_������ȡ���ö�
#define EWS_NOCAPTIONTOPMOST	262144
// ������_����ʽ����
#define EWS_POPUPWINDOW	524288
// ����ģ��
#define EWL_BLUR	-2
// ������Ϣ����
#define EWL_MSGPROC	-4
// ����͸����
#define EWL_ALPHA	-5
// �Զ������
#define EWL_LPARAM	-7
// �߿���ɫ
#define EWL_CRBORDER	-30
// ������ɫ
#define EWL_CRBKG	-31
// ��С�߶�
#define EWL_MINHEIGHT	-33
// ��С���
#define EWL_MINWIDTH	-34
// ����������
#define EWL_OBJFOCUS	-53
// ������������
#define EWL_OBJCAPTION	-54
// XML���Էַ��ص�(wParam->atomPropName,lParam->lpwzPropValue>)
#define WM_EX_XML_PROPDISPATCH	-1
// JS�ű��ַ��ص�(wParam->atomPropName,lParam->dispIdMember>)
#define WM_EX_JS_DISPATCH	-2
// ����������
#define WM_EX_LCLICK	-3
// �Ҽ��������
#define WM_EX_RCLICK	-4
// �м��������
#define WM_EX_MCLICK	-5
// ����ʽ�����Ѿ���ʼ�����
#define WM_EX_INITPOPUP	-6
// ����ʽ���ڼ������� (wParam=0:��������.wParam=1:�Ƿ������,����1��ȡ������)
#define WM_EX_EXITPOPUP	-7
// �����ؼ������,������EMT_EASINGתNM_EASING
#define WM_EX_EASING	-8
// ��Ҫ��GDI����
#define ECF_D2D_GDI_COMPATIBLE	1
// ����ڵ�ID
#define EOL_NODEID	-1
// ���ģ��ϵ��
#define EOL_BLUR	-2
// ����ص�
#define EOL_OBJPROC	-4
// ���͸����
#define EOL_ALPHA	-5
// �Զ������
#define EOL_LPARAM	-7
// �����
#define EOL_OBJPARENT	-8
// ����ı���ʽ
#define EOL_TEXTFORMAT	-11
// ���ID
#define EOL_ID	-12
// ����������
#define EOL_STYLE	-16
// ���������
#define EOL_HFONT	-19
// �����չ���
#define EOL_EXSTYLE	-20
// �û�����
#define EOL_USERDATA	-21
// �����������Ҫ�Ҹģ�
#define EOL_HCANVAS	-22
// �ؼ����ݣ���Ҫ�Ҹģ�
#define EOL_OWNER	-23
// ���״̬
#define EOL_STATE	-24
// �����������ָ��
#define EOL_LPWZTITLE	-28
// �����
#define EOL_CURSOR	-17
// ����ע��
#define ״̬_����	0
// ����ע��
#define ״̬_��ֹ	1
// ����ע��
#define ״̬_ѡ��	2
// ����ע��
#define ״̬_����	4
// ����ע��
#define ״̬_����	8
// ����ע��
#define ״̬_ѡ��	16
// ����ע��
#define ״̬_��ѡ��	32
// ����ע��
#define ״̬_ֻ��	64
// ����ע��
#define ״̬_��ȼ	128
// ����ע��
#define ״̬_Ĭ��	256
// ����ע��
#define ״̬_����Ŀ_����	512
// ����ע��
#define ״̬_����Ŀ_����	1024
// ����ע��
#define ״̬_��æ��	2048
// ����ע��
#define ״̬_������	8192
// ����ע��
#define ״̬_������	16384
// ����ע��
#define ״̬_����	32768
// ����ע��
#define ״̬_�����޸ĳߴ�	131072
// ����ע��
#define ״̬_�����϶�	262144
// ����ע��
#define ״̬_������	1048576
// ����ע��
#define ״̬_����ѡ��	2097152
// ����ע��
#define ״̬_������_��ȼ	4194304
// ����ע��
#define ״̬_������_�ѷ���	8388608
// ����ע��
#define ״̬_�����ѡ	16777216
// ����ע��
#define ״̬_����ģʽ	536870912
// ������_������������ʱ��ʾ��ֹ״̬
#define EOS_DISABLENOSCROLL	33554432
// ������_�ɵ����ߴ�
#define EOS_SIZEBOX	67108864
// ������_��ֹ
#define EOS_DISABLED	134217728
// ������_����
#define EOS_VISIBLE	268435456
// ������_�߿�
#define EOS_BORDER	536870912
// ������_ˮƽ������
#define EOS_VSCROLL	1073741824
// ������_��ֱ������
#define EOS_HSCROLL	-2147483648
// ������_��չ_����Ӧ�ߴ�
#define EOS_EX_AUTOSIZE	4194304
// ������_��չ_��괩͸
#define EOS_EX_TRANSPARENT	8388608
// ������_��չ_������ק
#define EOS_EX_DRAGDROP	33554432
// ������_��չ_�����ļ��Ϸ�
#define EOS_EX_ACCEPTFILES	67108864
// ������_��չ_������
#define EOS_EX_FOCUSABLE	134217728
// ������_��չ_����TAB����
#define EOS_EX_TABSTOP	268435456
// ������_��չ_������ǰ
#define EOS_EX_TOPMOST	536870912
// ������_��չ_�������
#define EOS_EX_COMPOSITED	1073741824
// ������_��չ_�Զ������
#define EOS_EX_CUSTOMDRAW	-2147483648
// ����ע��
#define SB_HORZ	0
// ����ע��
#define SB_VERT	1
// ����ע��
#define SB_CTL	2
// ����ע��
#define SB_BOTH	3
// ����ע��
#define ��ť���_��ѡ��ť	1
// ����ע��
#define ��ť���_��ѡ��ť	2
// ���°�ťʱƫ���ı�
#define ��ť���_�ı�ƫ��	4
// ����ע��
#define ��ť���_ͼ������	8
// ����ע��
#define ���������_ˮƽ������	0
// ����ע��
#define ���������_��ֱ������	1
// ����ע��
#define ���������_�󶥶���	2
// ����ע��
#define ���������_�ҵ׶���	4
// ����ע��
#define ���������_���ư�ť	8
// ����ע��
#define �༭����_������ק	1
// ����ע��
#define �༭����_��������	2
// ����ע��
#define �༭����_��ʾѡ���ı�	4
// ����ע��
#define �༭����_�ḻ�ı�	8
// ����ע��
#define �༭����_��������	16
// ����ע��
#define �༭����_ֻ��	32
// ����ע��
#define �༭����_�س�����	64
// ����ע��
#define �༭����_��ֵ����	128
// ����ע��
#define �༭����_�Զ�ѡ���ַ�	256
// ����ע��
#define �༭����_�����Ҽ�Ĭ�ϲ˵�	512
// ����ע��
#define �༭����_����URL	1024
// ����ע��
#define �༭����_����TAB�ַ�	2048
// ����ע��
#define �༭����_������ʾ��ʾ�ı�	4096
// ����ע��
#define �༭����_���ز����	8192
// ������ʾ�ı�(wParam:��ʾ�ı���ɫ,lParam:�ı�ָ��)
#define EM_SETCUEBANNER	5377
// ����ע��
#define �б���_�����б�	0
// ����ע��
#define �б���_�����б�	1
// ����ע��
#define �б���_�����ѡ	8
// ����ע��
#define �б���_�������	16
// ����ע��
#define �б���_ʼ����ʾѡ����	32
// δ����
#define LVHT_NOWHERE	1
// ���б���
#define LVHT_ONITEM	14
// ����ѡ����ı�
#define LVN_ITEMCHANGED	-101
// �ȵ����
#define LVN_HOTTRACK	-121
// ���в���
#define LVM_HITTEST	4114
// �����Ŀ
#define LVM_DELETEALLITEMS	4015
// ɾ����Ŀ
#define LVM_DELETEITEM	4104
// ��֤��ʾ��Ŀ
#define LVM_ENSUREVISIBLE	4115
// ȡ���ӷ�Χ�ڵ���Ŀ����
#define LVM_GETCOUNTPERPAGE	4136
// ȡ��Ŀ����
#define LVM_GETITEMCOUNT	4100
// ȡָ����Ŀ�ľ��η�Χ
#define LVM_GETITEMRECT	4110
// ȡ��ѡ����Ŀ��
#define LVM_GETSELECTEDCOUNT	4146
// ȡ����ѡ����Ŀ
#define LVM_GETSELECTIONMARK	4162
// ������ѡ����Ŀ
#define LVM_SETSELECTIONMARK	4163
// ȡ�ڿ��ӷ�Χ�е�һ����Ŀ������
#define LVM_GETTOPINDEX	4135
// ������Ŀ
#define LVM_INSERTITEM	4103
// �ػ���Ŀ
#define LVM_REDRAWITEMS	4117
// �����б���Ŀ����
#define LVM_SETITEMCOUNT	4143
// ȡ��Ŀ״̬
#define LVM_GETITEMSTATE	4140
// ����Ŀ״̬
#define LVM_SETITEMSTATE	4139
// ȡ���ָ��ָ����Ŀ������
#define LVM_GETHOTITEM	4157
// ���������������ߴ�
#define LVM_CALCITEMSIZE	5150
// ��Ҫ��GDI����
#define CVF_GDI_COMPATIBLE	1
// ID2D1DeviceContext
#define CVC_DX_D2DCONTEXT	1
// ID2D1Bitmap
#define CVC_DX_D2DBITMAP	2
// Grahpics*
#define CVC_GDIP_GRAPHICS	1
// ���ģʽ-����
#define CV_COMPOSITE_MODE_SRCOVER	0
// ���ģʽ-����
#define CV_COMPOSITE_MODE_SRCCOPY	1
// ������ɫ
#define COLOR_EX_BACKGROUND	0
// �߿���ɫ
#define COLOR_EX_BORDER	1
// �ı���ɫ.����
#define COLOR_EX_TEXT_NORMAL	2
// �ı���ɫ.��ȼ
#define COLOR_EX_TEXT_HOVER	3
// �ı���ɫ.����
#define COLOR_EX_TEXT_DOWN	4
// �ı���ɫ.����
#define COLOR_EX_TEXT_FOCUS	5
// �ı���ɫ.ѡ��
#define COLOR_EX_TEXT_CHECKED	6
// �ı���ɫ.ѡ��
#define COLOR_EX_TEXT_SELECT	7
// �ı���ɫ.�ȵ�
#define COLOR_EX_TEXT_HOT	8
// �ı���ɫ.�ѷ���
#define COLOR_EX_TEXT_VISTED	9
// �ı���ɫ.��Ӱ
#define COLOR_EX_TEXT_SHADOW	10
// �༭��.���ԭɫ
#define COLOR_EX_EDIT_CARET	30
// �༭��.��ʾ�ı���ɫ
#define COLOR_EX_EDIT_BANNER	31
// ���Ŷ���
#define BIF_PLAYIMAGE	1
// ��������
#define BIF_DISABLESCALE	2
// �Ź�����-�ų��м�����
#define BIF_GRID_EXCLUSION_CENTER	4
// Xʹ�ðٷֱȵ�λ
#define BIF_POSITION_Y_PERCENT	8
// Yʹ�ðٷֱȵ�λ
#define BIF_POSITION_X_PERCENT	16
// Ĭ��(����)
#define BIR_DEFALUT	0
// ƽ�̲��ظ�
#define BIR_NO_REPEAT	1
// ˮƽ����ֱ�ظ�ƽ��
#define BIR_REPEAT	2
// ˮƽ�ظ�ƽ��
#define BIR_REPEAT_X	3
// ��ֱ�ظ�ƽ��
#define BIR_REPEAT_Y	4
// ����ע��
#define EPF_DISABLESCALE	1
// ����.������������Ĳ������ϲ�����������
#define RGN_COMBINE_UNION	0
// ����.������������Ľ������ϲ�����������
#define RGN_COMBINE_INTERSECT	1
// ���.������������Ĳ�������ȥ���ص�����
#define RGN_COMBINE_XOR	2
// �ų�.�ӵ�һ���������ų��ڶ�������
#define RGN_COMBINE_EXCLUDE	3
// ��λ:����
#define UNIT_PIXEL	0
// ��λ:�ٷֱ�
#define UNIT_PERCENT	1
// �¼�_����
#define NM_CREATE	-99
// �¼�_����
#define NM_DESTROY	-98
// �¼�_����ߴ�
#define NM_CALCSIZE	-97
// �¼�_�ؼ��ƶ�
#define NM_MOVE	-96
// �¼�_�ߴ类�ı�
#define NM_SIZE	-95
// �¼�_��ֹ״̬���ı�
#define NM_ENABLE	-94
// �¼�_����״̬���ı�
#define NM_SHOW	-93
// �¼�_������ſ�
#define NM_LUP	-92
// �¼�_�뿪���
#define NM_LEAVE	-91
// �¼�_ʱ��
#define NM_TIMER	-90
// �¼�_ѡ��
#define NM_CHECK	-89
// �¼�_����ͼ��
#define NM_TRAYICON	-88
// �¼�_�Ի����ʼ�����
#define NM_INTDLG	-87
// �¼�_����
#define NM_EASING	-86
// �¼�_���������
#define NM_CLICK	-2
// �¼�_�����˫��
#define NM_DBLCLK	-3
// �¼�_�س���������
#define NM_RETURN	-4
// �¼�_�Ҽ�������
#define NM_RCLICK	-5
// �¼�_�Ҽ���˫��
#define NM_RDBLCLK	-6
// �¼�_���ý���
#define NM_SETFOCUS	-7
// �¼�_ʧȥ����
#define NM_KILLFOCUS	-8
// �¼�_�Զ������
#define NM_CUSTOMDRAW	-12
// �¼�_�������
#define NM_HOVER	-13
// �¼�_�������
#define NM_NCHITTEST	-14
// �¼�_����ĳ��
#define NM_KEYDOWN	-15
// �¼�_ȡ����겶��
#define NM_RELEASEDCAPTURE	-16
// �¼�_�ַ�����
#define NM_CHAR	-18
// �¼�_��ʾ�򼴽�����
#define NM_TOOLTIPSCREATED	-19
// �¼�_���������
#define NM_LDOWN	-20
// �¼�_�Ҽ�������
#define NM_RDOWN	-21
// �¼�_���屻�ı�
#define NM_FONTCHANGED	-23
// ��ȡ���ָ����Ը���
#define ELN_GETPROPSCOUNT	1
// ��ȡ���������Ը���
#define ELN_GETCHILDPROPCOUNT	2
// ��ʼ���������б�
#define ELN_INITPROPS	3
// �ͷŸ������б�
#define ELN_UNINITPROPS	4
// ��ʼ���������б�
#define ELN_INITCHILDPROPS	5
// �ͷ��������б�
#define ELN_UNINITCHILDPROPS	6
// �������ֵ�Ƿ���ȷ,wParamΪpropID��lParamΪֵ
#define ELN_CHECKPROPVALUE	7
// ���������ֵ�Ƿ���ȷ,wParam��λΪnIndex����λΪpropID��lParamΪֵ
#define ELN_CHECKCHILDPROPVALUE	8
// ��XML���Ա���䵽������Ϣ��
#define ELN_FILL_XML_PROPS	9
// ��XML���Ա���䵽��������Ϣ��
#define ELN_FILL_XML_CHILD_PROPS	10
// ���²���
#define ELN_UPDATE	15
// ��������_��
#define ELT_NULL	0
// ��������_����
#define ELT_LINEAR	1
// ��������_��ʽ
#define ELT_FLOW	2
// ��������_ҳ��
#define ELT_PAGE	3
// ��������_���
#define ELT_TABLE	4
// ��������_���
#define ELT_RELATIVE	5
// ��������_����
#define ELT_ABSOLUTE	6
// ��������_ͨ��_�ڼ��_��
#define ELP_PADDING_LEFT	-1
// ��������_ͨ��_�ڼ��_��
#define ELP_PADDING_TOP	-2
// ��������_ͨ��_�ڼ��_��
#define ELP_PADDING_RIGHT	-3
// ��������_ͨ��_�ڼ��_��
#define ELP_PADDING_BOTTOM	-4
// ��������_ͨ��_����_��
#define ELCP_MARGIN_LEFT	-1
// ��������_ͨ��_����_��
#define ELCP_MARGIN_TOP	-2
// ��������_ͨ��_����_��
#define ELCP_MARGIN_RIGHT	-3
// ��������_ͨ��_����_��
#define ELCP_MARGIN_BOTTOM	-4
// ��������:����
#define ELP_LINEAR_DIRECTION	1
// ����������:�ߴ�[-1��δ��дΪ�����ǰ�ߴ�]
#define ELCP_LINEAR_SIZE	1
// ����������:����һ������Ķ��뷽ʽ
#define ELCP_LINEAR_ALIGN	2
// ��������:���ַ�����뷽ʽ
#define ELP_LINEAR_DALIGN	2
// ����ע��
#define ELP_LINEAR_DALIGN_LEFT_TOP	0
// ����ע��
#define ELP_LINEAR_DALIGN_CENTER	1
// ����ע��
#define ELP_LINEAR_DALIGN_RIGHT_BOTTOM	2
// ����ע��
#define ELCP_LINEAR_ALGIN_FILL	0
// ����ע��
#define ELCP_LINEAR_ALIGN_LEFT_TOP	1
// ����ע��
#define ELCP_LINEAR_ALIGN_CENTER	2
// ����ע��
#define ELCP_LINEAR_ALIGN_RIGHT_BOTTOM	3
// ����:ˮƽ
#define ELP_DIRECTION_H	0
// ����:��ֱ
#define ELP_DIRECTION_V	1
// ��������:����
#define ELP_FLOW_DIRECTION	1
// ����������:�ߴ�[-1��δ��дΪ�����ǰ�ߴ�]
#define ELCP_FLOW_SIZE	1
// ����������:���ǿ�ƻ���
#define ELCP_FLOW_NEW_LINE	2
// ��������:��ǰ��ʾҳ������
#define ELP_PAGE_CURRENT	1
// ����������:�Ƿ������������
#define ELCP_PAGE_FILL	1
// ��������_���_������
#define ELCP_TABLE_ROW	1
// ��������_���_������
#define ELCP_TABLE_CELL	2
// ��������_���_������
#define ELCP_TABLE_ROW_SPAN	3
// ��������_���_������
#define ELCP_TABLE_CELL_SPAN	4
// ��������_���_�Ƿ�����
#define ELCP_TABLE_FILL	5
// ��������_���_�����(���)
#define ELCP_RELATIVE_LEFT_OF	1
// ��������_���_֮����(���)
#define ELCP_RELATIVE_TOP_OF	2
// ��������_���_�Ҳ���(���)
#define ELCP_RELATIVE_RIGHT_OF	3
// ��������_���_֮����(���)
#define ELCP_RELATIVE_BOTTOM_OF	4
// ��������_���_�������(���)
#define ELCP_RELATIVE_LEFT_ALIGN_OF	5
// ��������_���_��������(���)
#define ELCP_RELATIVE_TOP_ALIGN_OF	6
// ��������_���_�Ҷ�����(���)
#define ELCP_RELATIVE_RIGHT_ALIGN_OF	7
// ��������_���_�׶�����(���)
#define ELCP_RELATIVE_BOTTOM_ALIGN_OF	8
// ��������_���_ˮƽ�����ڸ�
#define ELCP_RELATIVE_CENTER_PARENT_H	9
// ��������_���_��ֱ�����ڸ�
#define ELCP_RELATIVE_CENTER_PARENT_V	10
// ��������_����_���
#define ELCP_ABSOLUTE_LEFT	1
// ��������_����_�������
#define ELCP_ABSOLUTE_LEFT_TYPE	2
// ��������_����_����
#define ELCP_ABSOLUTE_TOP	3
// ��������_����_��������
#define ELCP_ABSOLUTE_TOP_TYPE	4
// ��������_����_�Ҳ�
#define ELCP_ABSOLUTE_RIGHT	5
// ��������_����_�Ҳ�����
#define ELCP_ABSOLUTE_RIGHT_TYPE	6
// ��������_����_�ײ�
#define ELCP_ABSOLUTE_BOTTOM	7
// ��������_����_�ײ�����
#define ELCP_ABSOLUTE_BOTTOM_TYPE	8
// ��������_����_��ȣ����ȼ������Ҳࣩ
#define ELCP_ABSOLUTE_WIDTH	9
// ��������_����_�������
#define ELCP_ABSOLUTE_WIDTH_TYPE	10
// ��������_����_�߶ȣ����ȼ����ڵײ���
#define ELCP_ABSOLUTE_HEIGHT	11
// ��������_����_�߶�����
#define ELCP_ABSOLUTE_HEIGHT_TYPE	12
// ��������_����_ˮƽƫ����
#define ELCP_ABSOLUTE_OFFSET_H	13
// ��������_����_ˮƽƫ��������
#define ELCP_ABSOLUTE_OFFSET_H_TYPE	14
// ��������_����_��ֱƫ����
#define ELCP_ABSOLUTE_OFFSET_V	15
// ��������_����_��ֱƫ��������
#define ELCP_ABSOLUTE_OFFSET_V_TYPE	16
// ��������_����_����_δ֪(δ���û򱣳ֲ���)
#define ELCP_ABSOLUTE_TYPE_UNKNOWN	0
// ��������_����_����_����
#define ELCP_ABSOLUTE_TYPE_PX	1
// ��������_����_����_�ٷֱ�
#define ELCP_ABSOLUTE_TYPE_PS	2
// ��������_����_����_����ߴ�ٷֱȣ���OFFSET����
#define ELCP_ABSOLUTE_TYPE_OBJPS	3
// ���λ��Ĭ��ֵ
#define EOP_DEFAULT	-2147483648
// ����ע��
#define ��Ͽ���_����༭	1
// ��Ͽ��¼�_�б���ı�
#define CBN_SELCHANGE	1
// ��Ͽ��¼�_�༭���ݱ��ı�
#define CBN_EDITCHANGE	5
// ��Ͽ��¼�_���������б�
#define CBN_DROPDOWN	7
// ��Ͽ��¼�_�����ر��б�
#define CBN_CLOSEUP	8
// ��Ͽ��¼�_���������б�
#define CBN_POPUPLISTWINDOW	2001
// ����ע��
#define ��������_Linear	1
// ����ע��
#define ��������_Clerp	2
// ����ע��
#define ��������_Spring	3
// ����ע��
#define ��������_Punch	4
// ����ע��
#define ��������_InQuad	5
// ����ע��
#define ��������_OutQuad	6
// ����ע��
#define ��������_InOutQuad	7
// ����ע��
#define ��������_InCubic	8
// ����ע��
#define ��������_OutCubic	9
// ����ע��
#define ��������_InOutCubic	10
// ����ע��
#define ��������_InQuart	11
// ����ע��
#define ��������_OutQuart	12
// ����ע��
#define ��������_InOutQuart	13
// ����ע��
#define ��������_InQuint	14
// ����ע��
#define ��������_OutQuint	15
// ����ע��
#define ��������_InOutQuint	16
// ����ע��
#define ��������_InSine	17
// ����ע��
#define ��������_OutSine	18
// ����ע��
#define ��������_InOutSine	19
// ����ע��
#define ��������_InExpo	20
// ����ע��
#define ��������_OutExpo	21
// ����ע��
#define ��������_InOutExpo	22
// ����ע��
#define ��������_InCirc	23
// ����ע��
#define ��������_OutCirc	24
// ����ע��
#define ��������_InOutCirc	25
// ����ע��
#define ��������_InBounce	26
// ����ע��
#define ��������_OutBounce	27
// ����ע��
#define ��������_InOutBounce	28
// ����ע��
#define ��������_InBack	29
// ����ע��
#define ��������_OutBack	30
// ����ע��
#define ��������_InOutBack	31
// ����ע��
#define ��������_InElastic	32
// ����ע��
#define ��������_OutElastic	33
// ����ע��
#define ��������_InOutElastic	34
// pEasingContextΪ�Զ���ص�����(nProcess,nStart,nStop,nCurrent*,pEasingContext)
#define ��������_�Զ���	50
// pEasingContextΪpCurveInfo(_easing_load_curve)
#define ��������_����	51
// ����ע��
#define ����ģʽ_����	1
// ע������ֹͣ
#define ����ģʽ_ѭ��	2
// ��λ��Ϊ����
#define ����ģʽ_���	4
// ����ע��
#define ����ģʽ_˳��	8
// ����ע��
#define ����ģʽ_����	16
// ����ע��
#define ����ģʽ_����	32
// pContextΪ�ص�����,bool isStop Cbk(pEasingProgress,double nProgress,double nCurrent,pEasingContext,nTimesSurplus,Param1,Param2,Param3,Param4)
#define ����ģʽ_���ú���	0
// pContextΪhObj��hExDUI, wParam:pEasing,lParam:lpEasingInfo,result:isStop
#define ����ģʽ_�ַ���Ϣ	128
// ʹ���̴߳���,������UI�̴߳���(�����л���������)
#define ����ģʽ_ʹ���߳�	256
// ��ʹ����������ʱ��Ч,�ڽ���ʱ���Զ��ͷ�����ָ��
#define ����ģʽ_�ͷ�����	512
// ����
#define EES_PLAY	0
// ��ͣ
#define EES_PAUSE	1
// ֹͣ
#define EES_STOP	2
// ����ע��
#define sizeof_ex_nmhdr	20
// ����ע��
#define sizeof_ex_easing	44
// ����ע��
#define sizeof_ex_jsdispatchinfo	20
// ����ע��
#define sizeof_ex_customdraw	40
// ����ע��
#define TVI_FIRST	-65535
// ����ע��
#define TVI_LAST	-65534
// ����ע��
#define TVI_ROOT	-65536
// ����ע��
#define TVI_SORT	-65533
// ɾ���ڵ㼰��������(lParamΪ�ڵ���,0��TVI_ROOTΪɾ������)
#define TVM_DELETEITEM	4353
// ��֤��ʾ(lParamΪ��ʾ�Ľڵ���)
#define TVM_ENSUREVISIBLE	4372
// չ������(wParamΪ�Ƿ�չ��,lParamΪ���õĽڵ���)
#define TVM_EXPAND	4354
// ȡ�ڵ���
#define TVM_GETCOUNT	4357
// ȡ���׿��
#define TVM_GETINDENT	4358
// ȡ�ڵ���Ϣ(wParamΪ�ڵ���,lParamΪ EX_TREEVIEW_ITEMINFO ָ�룬tzTextΪUnicode)
#define TVM_GETITEMW	4414
// ȡ�ڵ����(wParamΪ�ڵ���,lParamΪ EX_RECT ָ��,ע��ýڵ���봦�ڿɼ���Χ,������Ϣ�޷���ȡ������0)
#define TVM_GETITEMRECT	4356
// ȡ��ؽڵ�(wParamΪ TVGN_ ��ͷ�ĳ���,lParamΪ�ڵ���)
#define TVM_GETNEXTITEM	4362
// ȡչ�����ӽڵ����
#define TVM_GETVISIBLECOUNT	4368
// ���в���(wParam��λΪx��λΪy[��Կؼ�],lParamΪ ����#TVHT_��ͷ���� ��ָ��,��Ϣ����ֵΪ���еĽڵ���)
#define TVM_HITTEST	4369
// ����ڵ�(lParamΪ EX_TREEVIEW_ITEMINFO ָ�룬tzTextΪUnicode)
#define TVM_INSERTITEMW	4402
// ��ѡ����(lParamΪѡ�еĽڵ���)
#define TVM_SELECTITEM	4363
// �������׿��(wParamΪ���׿��)
#define TVM_SETINDENT	4359
// ���ýڵ����(wParamΪ�ڵ���,lParamΪ EX_TREEVIEW_ITEMINFO ָ��)
#define TVM_SETITEMW	4415
// �������ο�
#define TVM_UPDATE	4499
// �����и�(lParamΪ���и�)
#define TVM_SETITEMHEIGHT	5091
// ��ȡ�и�
#define TVM_GETITEMHEIGHT	5092
// ��������ȡ�ڵ���(wParamΪ����,�ڵ����ɼ����򷵻�0)
#define TVM_GETNODEFROMINDEX	5093
// ���ýڵ����(wParamΪ�ڵ���,lParamΪ �ı�ָ��,Unicode)
#define TVM_SETITEMTEXTW	14414
// ��ȡ�ڵ����(wParamΪ�ڵ���,����ֵΪ����Unicode�ַ���,��Ҫ�����ͷ�)
#define TVM_GETITEMTEXTW	14415
// ��ȡ���ڵ�
#define TVGN_ROOT	0
// ��ȡ��һ���ڵ�
#define TVGN_NEXT	1
// ��ȡ��һ���ڵ�
#define TVGN_PREVIOUS	2
// ��ȡ���ڵ�
#define TVGN_PARENT	3
// ��ȡ�ӽڵ�
#define TVGN_CHILD	4
// ��ȡ��һ���ɼ��ڵ�
#define TVGN_NEXTVISIBLE	6
// û������
#define TVHT_NOWHERE	1
// ����ͼ��
#define TVHT_ONITEMICON	2
// ���б���
#define TVHT_ONITEMLABEL	4
// ��������
#define TVHT_ONITEMINDENT	8
// ���мӼ���
#define TVHT_ONITEMSTATEICON	64
// ɾ���ڵ�
#define TVN_DELETEITEM	391
// �ڵ�չ��
#define TVN_ITEMEXPANDED	394
// �ڵ�չ����
#define TVN_ITEMEXPANDING	395
// ���ƽڵ�
#define TVN_DRAWITEM	3099
// ����ע��
#define sizeof_ex_treeview_insertinfo	40
// ����ע��
#define sizeof_ex_treeview_iteminfo	28
// ����ע��
#define �����_���ƺ���	256
// ����ע��
#define �����_��������	512
// ����ע��
#define �����_�ޱ�ͷ	1024
// ��ͷ���_�ɵ��
#define ERLV_CS_CLICKABLE	1
// ��ͷ���_�������
#define ERLV_CS_LOCKWIDTH	2
// ��ͷ���_������(ǰ���ǵÿɵ��)
#define ERLV_CS_SORTABLE	4
// ��ȡ����(lParamΪEX_REPORTLIST_ITEMINFOָ��)
#define LVM_GETITEM	4101
// ���ñ���(lParamΪEX_REPORTLIST_ITEMINFOָ��)
#define LVM_SETITEM	4102
// ��ȡ�����ı�(wParam����Ϊ0��Ϊ��������,lParamΪEX_REPORTLIST_ITEMINFOָ��)
#define LVM_GETITEMTEXT	4141
// ���ñ����ı�(wParam����Ϊ0��Ϊ��������,lParamΪEX_REPORTLIST_ITEMINFOָ��)
#define LVM_SETITEMTEXT	4142
// ������(wParmΪ�Ƿ���������,lParamΪEX_REPORTLIST_COLUMNINFOָ��)
#define LVM_INSERTCOLUMN	4123
// ɾ����(wParmΪ�Ƿ���������,lParamΪ������)
#define LVM_DELETECOLUMN	4124
// ����(lParamΪEX_REPORTLIST_SORTINFOָ��)
#define LVM_SORTITEMS	4144
// �����б��
#define LVM_UPDATE	4138
// ɾ��������
#define LVM_DELETEALLCOLUMN	4900
// ��ȡ����
#define LVM_GETCOLUMNCOUNT	4901
// ��ȡ����Ϣ(wParamΪ������,lParamΪ EX_REPORTLIST_COLUMNINFO ָ��)
#define LVM_GETCOLUMN	4902
// ��������Ϣ(wParam��λΪ������,��λΪ�Ƿ�����ˢ��,lParamΪ EX_REPORTLIST_COLUMNINFO ָ��)
#define LVM_SETCOLUMN	4903
// �����б���(wParam��λΪ������,��λΪ�Ƿ�����ˢ��,lParamΪ ���ı�ָ��)
#define LVM_SETCOLUMNTEXT	4904
// ��ȡ�б���(wParamΪ������,lParamΪ ���ı�ָ��)
#define LVM_GETCOLUMNTEXT	4905
// ��ȡ�п�
#define LVM_GETCOLUMNWIDTH	4906
// �����п�(wParamΪ������,lParamΪ �п�)
#define LVM_SETCOLUMNWIDTH	4907
// ���ñ���߶�
#define LVM_SETITEMHEIGHT	4908
// ��ȡ����߶�(lParamΪ���и�)
#define LVM_GETITEMHEIGHT	4909
// ��ȡͼƬ��
#define LVM_GETIMAGELIST	4098
// ����ͼƬ��(wParamΪ�Ƿ���±�����,lParamΪͼƬ����)
#define LVM_SETIMAGELIST	4099
// ��ͷ������
#define RLVN_COLUMNCLICK	97000
// ���Ʊ���
#define RLVN_DRAW_TR	97001
// ���Ʊ���
#define RLVN_DRAW_TD	97002
// �������¼�
#define RLVN_CHECK	97003
// ��������Ϣ
#define RLVM_CHECK	99001
// ���ü���״̬
#define RLVM_SETCHECK	99002
// ��ȡ����״̬
#define RLVM_GETCHECK	99003
// ���������
#define ERLV_RS_CHECKBOX	1
// ����Ϊѡ��״̬
#define ERLV_RS_CHECKBOX_CHECK	2
// ����ע��
#define sizeof_ex_reportlist_columninfo	24
// ����ע��
#define sizeof_ex_reportlist_rowinfo	16
// ����ע��
#define sizeof_ex_reportlist_iteminfo	28
// ����ע��
#define sizeof_ex_reportlist_sortinfo	20
// ����ͼƬ��(wParamΪ�Ƿ���±�����,lParamΪͼƬ����)
#define TVM_SETIMAGELIST	4361
// ��ȡͼƬ��
#define TVM_GETIMAGELIST	4360
// ����ע��
#define ���ο���_��ʾ�Ӽ���	64
// ����ע��
#define ���ο���_��ʾ������	128
// ��ʾ
#define SW_SHOW	5
// ����
#define SW_HIDE	0
// ���
#define SW_SHOWMAXIMIZED	3
// ��С��
#define SW_SHOWMINIMIZED	2
// ������
#define SW_SHOWNOACTIVATE	4
// �ӿؼ�
#define GW_CHILD	5
// ��һ���ֵ�
#define GW_HWNDPREV	3
// ��һ���ֵ�
#define GW_HWNDNEXT	2
// ����ע��
#define IDYES	6
// ����ע��
#define IDNO	7
// ����ע��
#define IDCANCEL	2
// ����ע��
#define IDOK	1
// ����ע��
#define IDCLOSE	8
// ����ע��
#define NULL	0
// ���ý�������Χ
#define PBM_SETRANGE	1025
// ���ý�����λ��
#define PBM_SETPOS	1026
// ��ȡ������λ��
#define PBM_GETPOS	1032
// ��ȡ��������Χ
#define PBM_GETRANGE	1031
// �����ͷ
#define EPDF_THEME	254
// ��Դ��ͷ
#define EPDF_FILES	255
// �ò˵���ť�����˵�(wParam:�˵���,lParam:�˵����)
#define MBM_POPUP	103001
// �˵������¼�(wParam:�˵���,lParam:�˵����)
#define MBN_POPUP	102401
// λͼ
#define IMAGE_BITMAP	0
// ͼ��
#define IMAGE_ICON	1
