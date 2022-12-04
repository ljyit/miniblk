// miniblkCtrl.cpp : CminiblkCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "miniblk.h"
#include "miniblkCtrl.h"
#include "miniblkPropPage.h"
#include "JSValue.h"
#include "Common.h"
#include "miniblkidl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



IMPLEMENT_DYNCREATE(CminiblkCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CminiblkCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CminiblkCtrl, COleControl)
	DISP_FUNCTION_ID(CminiblkCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CminiblkCtrl, "LoadUrl", dispidLoadUrl, LoadUrl, VT_EMPTY, VTS_BSTR)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "wkeHandle", dispidwkeHandle, GetwkeHandle, SetNotSupported, VT_UI4)
	DISP_FUNCTION_ID(CminiblkCtrl, "GetCookie", dispidGetCookie, GetCookie, VT_BSTR, VTS_NONE)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "CanGoBack", dispidCanGoBack, GetCanGoBack, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "CanGoForward", dispidCanGoForward, GetCanGoForward, SetNotSupported, VT_BOOL)
	DISP_FUNCTION_ID(CminiblkCtrl, "GoBack", dispidGoBack, GoBack, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CminiblkCtrl, "GoForward", dispidGoForward, GoForward, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CminiblkCtrl, "Reload", dispidReload, Reload, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "TouchEnabled", dispidTouchEnabled, m_TouchEnabled, OnTouchEnabledChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "ContextMenuEnabled", dispidContextMenuEnabled, m_ContextMenuEnabled, OnContextMenuEnabledChanged, VT_BOOL)
	DISP_DEFVALUE(CminiblkCtrl, "ContextMenuEnabled")
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "MouseEnabled", dispidMouseEnabled, m_MouseEnabled, OnMouseEnabledChanged, VT_BOOL)
	DISP_FUNCTION_ID(CminiblkCtrl, "NetSetMIMEType", dispidNetSetMIMEType, NetSetMIMEType, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(CminiblkCtrl, "NetSetData", dispidNetSetData, NetSetData, VT_EMPTY, VTS_UI4 VTS_BSTR VTS_UI4)
	
	DISP_FUNCTION_ID(CminiblkCtrl, "LoadFile", dispidLoadFile, LoadFile, VT_EMPTY, VTS_BSTR)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "Version", dispidVersion, GetVersion, SetNotSupported, VT_BSTR)
	DISP_FUNCTION_ID(CminiblkCtrl, "SetProxy", dispidSetProxy, SetProxy, VT_EMPTY, VTS_UI4 VTS_BSTR VTS_I2 VTS_BSTR VTS_BSTR)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "UserAgent", dispidUserAgent, GetUserAgent, SetUserAgent, VT_BSTR)
	DISP_FUNCTION_ID(CminiblkCtrl, "SetFocus", dispidSetFocus, SetFocus, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CminiblkCtrl, "RunJS", dispidRunJS, RunJS, VT_DISPATCH, VTS_BSTR)
	DISP_FUNCTION_ID(CminiblkCtrl, "LoadHTML", dispidLoadHTML, LoadHTML, VT_EMPTY, VTS_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "ResourceGc", dispidResourceGc, m_ResourceGc, OnResourceGcChanged, VT_UI4)
	DISP_FUNCTION_ID(CminiblkCtrl, "StopLoading", dispidStopLoading, StopLoading, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CminiblkCtrl, "SetCookie", dispidSetCookie, SetCookie, VT_EMPTY, VTS_BSTR VTS_BSTR)
	DISP_PROPERTY_PARAM_ID(CminiblkCtrl, "Headers", dispidHeaders, GetHeaders, SetNotSupported, VT_DISPATCH, VTS_UI4)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "HeadlessEnabled", dispidHeadlessEnabled, m_HeadlessEnabled, OnHeadlessEnabledChanged, VT_BOOL)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "IsDocumentReady", dispidIsDocumentReady, GetIsDocumentReady, SetNotSupported, VT_BOOL)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "LocalStorageFullPath", dispidLocalStorageFullPath, m_LocalStorageFullPath, OnLocalStorageFullPathChanged, VT_BSTR)
	DISP_FUNCTION_ID(CminiblkCtrl, "FireMouseEvent", dispidFireMouseEvent, FireMouseEvent, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4 VTS_UI4)
	DISP_FUNCTION_ID(CminiblkCtrl, "FireMouseWheelEvent", dispidFireMouseWheelEvent, FireMouseWheelEvent, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CminiblkCtrl, "FireKeyUpEvent", dispidFireKeyUpEvent, FireKeyUpEvent, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BOOL)
	DISP_FUNCTION_ID(CminiblkCtrl, "FireKeyDownEvent", dispidFireKeyDownEvent, FireKeyDownEvent, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BOOL)
	DISP_FUNCTION_ID(CminiblkCtrl, "FireKeyPressEvent", dispidFireKeyPressEvent, FireKeyPressEvent, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_BOOL)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "ZoomFactor", dispidZoomFactor, GetZoomFactor, SetZoomFactor, VT_R4)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "Align", dispidAlign, GetAlign, SetAlign, VT_UI4)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "Title", dispidTitle, GetTitle, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "ContentWidth", dispidContentWidth, GetContentWidth, SetNotSupported, VT_UI4)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "ContentHeight", dispidContentHeight, GetContentHeight, SetNotSupported, VT_UI4)
	DISP_PROPERTY_EX_ID(CminiblkCtrl, "CookieEnabled", dispidCookieEnabled, GetCookieEnabled, SetCookieEnabled, VT_BOOL)
	DISP_PROPERTY_NOTIFY_ID(CminiblkCtrl, "CookiePath", dispidCookiePath, m_CookiePath, OnCookiePathChanged, VT_BSTR)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CminiblkCtrl, COleControl)
	EVENT_CUSTOM_ID("OnLoadUrlBegin", eventidOnLoadUrlBegin, OnLoadUrlBegin, VTS_UI4 VTS_UI4 VTS_BSTR VTS_PBOOL)
	EVENT_CUSTOM_ID("OnTitleChanged", eventidOnTitleChanged, OnTitleChanged, VTS_UI4 VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("OnURLChanged", eventidOnURLChanged, OnURLChanged, VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("OnNavigation", eventidOnNavigation, OnNavigation, VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("OnDocumentReady", eventidOnDocumentReady, OnDocumentReady, VTS_UI4 VTS_UI4 VTS_UI4)
	EVENT_CUSTOM_ID("OnLoadingFinish", eventidOnLoadingFinish, OnLoadingFinish, VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("OnAlertBox", eventidOnAlertBox, OnAlertBox, VTS_BSTR)

	EVENT_CUSTOM_ID("OnConsole", eventidOnConsole, OnConsole, VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_BSTR VTS_UI4 VTS_BSTR)
	EVENT_CUSTOM_ID("OnLoadUrlFinish", eventidOnLoadUrlFinish, OnLoadUrlFinish, VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_UI4)
	EVENT_CUSTOM_ID("OnLoadUrlEnd", eventidOnLoadUrlEnd, OnLoadUrlEnd, VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_PUI1 VTS_UI4)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CminiblkCtrl, 1)
	PROPPAGEID(CminiblkPropPage::guid)
END_PROPPAGEIDS(CminiblkCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CminiblkCtrl, "MINIBLK.miniblkCtrl.1",
	0x24354416, 0x5082, 0x41e6, 0xae, 0x4, 0xd0, 0x1a, 0x23, 0xbb, 0x56, 0x7b)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CminiblkCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID BASED_CODE IID_Dminiblk =
		{ 0xC063C610, 0x2D3, 0x4893, { 0xBF, 0x59, 0x7A, 0x82, 0x6, 0xED, 0x66, 0x8E } };
const IID BASED_CODE IID_DminiblkEvents =
		{ 0x13340B10, 0x871F, 0x4023, { 0x98, 0x43, 0xB7, 0x55, 0x83, 0xFA, 0x16, 0xB } };



// 控件类型信息

static const DWORD BASED_CODE _dwminiblkOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CminiblkCtrl, IDS_MINIBLK, _dwminiblkOleMisc)



// CminiblkCtrl::CminiblkCtrlFactory::UpdateRegistry -
// 添加或移除 CminiblkCtrl 的系统注册表项

BOOL CminiblkCtrl::CminiblkCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MINIBLK,
			IDB_MINIBLK,
			afxRegApartmentThreading,
			_dwminiblkOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CminiblkCtrl::CminiblkCtrl - 构造函数

CminiblkCtrl::CminiblkCtrl()
{
	InitializeIIDs(&IID_Dminiblk, &IID_DminiblkEvents);
	// TODO: 在此初始化控件的实例数据。
}



// CminiblkCtrl::~CminiblkCtrl - 析构函数

CminiblkCtrl::~CminiblkCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CminiblkCtrl::OnDraw - 绘图函数

void CminiblkCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc) return;
	// TODO: 用您自己的绘图代码替换下面的代码。
	CRect rc(rcBounds);
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	CString msg("minibilink ocx control\r\nby mugua 2022\r\nVersion 1.0");
	pdc->SetBkMode(0);
	pdc->DrawText(msg,rc,0);  
}



// CminiblkCtrl::DoPropExchange - 持久性支持

void CminiblkCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CminiblkCtrl::OnResetState - 将控件重置为默认状态

void CminiblkCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CminiblkCtrl::AboutBox - 向用户显示“关于”框

void CminiblkCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MINIBLK);
	dlgAbout.DoModal();
}



// CminiblkCtrl 消息处理程序

void CminiblkCtrl::LoadUrl(LPCTSTR url)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	wkeLoadURLW(web,url); 
}

void CminiblkCtrl::OnDestroy()
{
	COleControl::OnDestroy();
	wkeDestroyWebWindow(web);
	// TODO: 在此处添加消息处理程序代码
}


int CminiblkCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  在此添加您专用的创建代码
	wkeSetWkeDllPath(L"node.dll");
	wkeInitialize();

	RECT rect;
	GetWindowRect(&rect);
	web = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL,m_hWnd,0,0,200,200);
	wkeShowWindow(web, true);
	wkeOnLoadUrlBegin(web,&CminiblkCtrl::OnLoadUrlBegin_,this);
	wkeOnTitleChanged(web,&CminiblkCtrl::OnTitleChanged_,this);
	wkeOnURLChanged2 (web,&CminiblkCtrl::OnURLChanged_,this);
	wkeOnNavigation(web, &CminiblkCtrl::OnNavigation_, this);
	wkeOnDocumentReady2(web,&CminiblkCtrl::OnDocumentReady_, this);
	wkeOnLoadingFinish(web,&CminiblkCtrl::OnLoadingFinish_, this);
	wkeOnAlertBox(web,&CminiblkCtrl::OnAlertBox_, this);
	wkeOnConsole(web,&CminiblkCtrl::OnConsole_,this);
	wkeOnLoadUrlFinish(web,&CminiblkCtrl::OnLoadUrlFinish_,this);
	wkeOnLoadUrlEnd(web,&CminiblkCtrl::OnLoadUrlEnd_,this);
	return 0;
}

void CminiblkCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);
	wkeResizeWindow(web,cx,cy);
}



bool CminiblkCtrl::OnLoadUrlBegin_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	wchar_t* str=utf8ToUtf16(url);

	wkeNetHookRequest(job);

	//不能使用VARIANT_BOOL，在其他语言中真和假不一定是0和-1，而且也不一定长度2个字节，
	//会造成溢出提示
	VARIANT cancel;
	cancel.vt=VT_BOOL;
	cancel.boolVal=VARIANT_FALSE;

	me->OnLoadUrlBegin(*(ULONG*)&webView,*(ULONG*)&param,str,*(ULONG*)&job,&cancel);

	delete []str;

	//加入http 头
	CString key,value;
	ULONG x=0;
	POSITION ps=me->m_Headers.m_Map.GetStartPosition();
	while (ps)
	{
		me->m_Headers.m_Map.GetNextAssoc(ps,key,value);
		wkeNetSetHTTPHeaderField(job,key,value,false);
	}


	//无论返回真假，loadUrl过程不会停止，是不是BUG？
	return cancel.boolVal!=0;
}

void CminiblkCtrl::OnTitleChanged_(wkeWebView webView, void* param, const wkeString title)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnTitleChanged(*(ULONG*)&webView,*(ULONG*)&param,wkeGetStringW(title));
}

void CminiblkCtrl::OnURLChanged_(wkeWebView webView, void* param, wkeWebFrameHandle frameId, const wkeString url)
{
	wchar_t* str=(wchar_t*)wkeGetStringW(url);

	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnURLChanged(*(ULONG*)&webView,*(ULONG*)&param,*(ULONG*)&frameId,str);
}

ULONG CminiblkCtrl::GetwkeHandle(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return *(ULONG*)&web;
}

BSTR CminiblkCtrl::GetCookie(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult=utf8ToUtf16(wkeGetCookie(web));

	return strResult.AllocSysString();
}

bool CminiblkCtrl::OnNavigation_(wkeWebView webView, void* param, wkeNavigationType type, const wkeString url)
{
	VARIANT cancel;
	cancel.vt=VT_BOOL;
	cancel.boolVal=VARIANT_FALSE;

	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnNavigation(*(ULONG*)&webView,*(ULONG*)&param,type,(wchar_t*)wkeGetStringW(url),&cancel);

	return (cancel.boolVal==VARIANT_FALSE);
}

VARIANT_BOOL CminiblkCtrl::GetCanGoBack(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	
	return wkeCanGoBack(web)==FALSE?VARIANT_FALSE:VARIANT_TRUE;
}

VARIANT_BOOL CminiblkCtrl::GetCanGoForward(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return wkeCanGoForward(web)==FALSE?VARIANT_FALSE:VARIANT_TRUE;
}

VARIANT_BOOL CminiblkCtrl::GoBack(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return wkeGoBack(web)==FALSE?VARIANT_FALSE:VARIANT_TRUE;
}

VARIANT_BOOL CminiblkCtrl::GoForward(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return wkeGoForward(web)==FALSE?VARIANT_FALSE:VARIANT_TRUE; 
}

void CminiblkCtrl::Reload(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	wkeReload(web);
}
 
void CminiblkCtrl::OnTouchEnabledChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetTouchEnabled(web,m_TouchEnabled);

	SetModifiedFlag();
}

void CminiblkCtrl::OnContextMenuEnabledChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetContextMenuEnabled(web,m_ContextMenuEnabled);
	SetModifiedFlag();
}

void CminiblkCtrl::OnMouseEnabledChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetMouseEnabled(web,m_MouseEnabled);
	SetModifiedFlag();
}

void CminiblkCtrl::OnDocumentReady_(wkeWebView webView, void* param, wkeWebFrameHandle frameId)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnDocumentReady(*(ULONG*)&webView,*(ULONG*)&param,*(ULONG*)&frameId);
}

void CminiblkCtrl::OnLoadingFinish_(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnLoadingFinish(*(ULONG*)&webView,*(ULONG*)&param,wkeGetStringW(url),result,wkeGetStringW(failedReason) );

}


void CminiblkCtrl::NetSetMIMEType(ULONG job, LPCTSTR type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	char* str=utf16ToUtf8(type);
	wkeNetSetMIMEType(*(wkeNetJob*)&job,str);
	delete []str;
}

void CminiblkCtrl::NetSetData(ULONG job, LPCTSTR data, ULONG datalen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int len=*(int*)((char*)data)-4;
	wkeNetSetData(*(wkeNetJob*)&job,(char*)data,datalen);
	
}


void CminiblkCtrl::LoadFile(LPCTSTR filename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeLoadFileW(web,filename);
	
}

BSTR CminiblkCtrl::GetVersion(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	wchar_t* str=utf8ToUtf16(wkeGetVersionString());
	CString strResult(str);
	delete []str;

	return strResult.AllocSysString();
}

void CminiblkCtrl::SetProxy(ULONG type, LPCTSTR hostname, SHORT port, LPCTSTR username, LPCTSTR password)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	char* host=utf16ToUtf8(hostname);
	char* user=utf16ToUtf8(username);
	char* pwd=utf16ToUtf8(password);
	wkeProxy px;

	CopyMemory(px.hostname,host,sizeof(px.hostname));
	CopyMemory(px.username,user,sizeof(px.username));
	CopyMemory(px.password,pwd,sizeof(px.password));
	px.port=port;
	px.type=(wkeProxyType)type;
	wkeSetProxy(&px);

	delete []host;
	delete []user;
	delete []pwd;
}

BSTR CminiblkCtrl::GetUserAgent(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wchar_t* str=utf8ToUtf16(wkeGetUserAgent(web));
	CString strResult(str);
	delete []str;
	

	return strResult.AllocSysString();
}

void CminiblkCtrl::SetUserAgent(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetUserAgentW(web,newVal);
	SetModifiedFlag();
}

void CminiblkCtrl::SetFocus(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	wkeSetFocus(web);
}

IDispatch* CminiblkCtrl::RunJS(LPCTSTR script)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState());
	jsValue val=wkeRunJSW(web,script);
/*

【群主】miniblink作者（唯一官方）(93527630) 2022/5/9 13:40:25
C++的生命周期管理起来太费劲

【群主】miniblink作者（唯一官方）(93527630) 2022/5/9 13:40:34
用c++操作dom很容易搞的内存泄漏

【群主】miniblink作者（唯一官方）(93527630)  13:41:14
所以我不想让jsValue 可以长时间访问

【群主】miniblink作者（唯一官方）(93527630)  13:46:08
别搞那些花里胡哨的

【群主】miniblink作者（唯一官方）(93527630)  13:46:37
dom以后会在别的线程甚至进程

【群主】miniblink作者（唯一官方）(93527630)  13:46:51
这个就不好封装了

*/
// 	jsExecState es=wkeGlobalExec(web);
// 	jsValue val=jsEmptyObject(wkeGlobalExec(web));
// 	jsValue strval=jsString(wkeGlobalExec(web),"test");
// 
// 	jsSet(wkeGlobalExec(web),val,"name",strval);
// 
// 	int x=jsTypeOf(val);
// 	x=jsTypeOf(strval);
// 	x=jsIsObject(val);

	CJSValue* tmp=new CJSValue(web,val);
	return tmp->GetSelf();
}

void CminiblkCtrl::OnAlertBox_(wkeWebView webView, void* param, const wkeString msg)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnAlertBox(wkeGetStringW(msg));
}

void CminiblkCtrl::LoadHTML(LPCTSTR html)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeLoadHTMLW(web,html);
	
}

void CminiblkCtrl::OnResourceGcChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetResourceGc(web,m_ResourceGc);

	SetModifiedFlag();
}

void CminiblkCtrl::OnConsole_(
							  wkeWebView webView, 
							  void* param, 
							  wkeConsoleLevel level, 
							  const wkeString message, 
							  const wkeString sourceName, 
							  unsigned sourceLine, 
							  const wkeString stackTrace
							  ) 
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	me->OnConsole(*(ULONG*)&webView
		,*(ULONG*)&param
		,level
		,wkeGetStringW(message)
		,wkeGetStringW(sourceName)
		,sourceLine
		,wkeGetStringW(stackTrace)
		);

}

void CminiblkCtrl::StopLoading(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	wkeStopLoading(web);
}

void CminiblkCtrl::SetCookie(LPCTSTR url, LPCTSTR cookies)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	

	char* pUrl=utf16ToUtf8(url);
	char* pCookies=utf16ToUtf8(cookies);
	wkeSetCookie(web,pUrl,pCookies);
	delete []pUrl;
	delete []pCookies;

}

IDispatch* CminiblkCtrl::GetHeaders()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return this->m_Headers.GetIDispatch(TRUE);
} 
 

void CminiblkCtrl::OnLoadUrlFinish_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job, int len)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	wchar_t* str=utf8ToUtf16(url);
	const wkeSlist * list=wkeNetGetRawResponseHead(job);
	me->OnLoadUrlFinish(*(ULONG*)&webView,*(ULONG*)&param,str,*(ULONG*)&job,len);
	delete []str;

}

void CminiblkCtrl::OnLoadUrlEnd_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job, void* buf, int len)
{
	CminiblkCtrl* me=(CminiblkCtrl*)param;
	wchar_t* str=utf8ToUtf16(url);
	me->OnLoadUrlEnd(*(ULONG*)&webView,*(ULONG*)&param,str,*(ULONG*)&job,(BYTE*)buf,len);
	delete []str;
}

void CminiblkCtrl::OnHeadlessEnabledChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetHeadlessEnabled(web,m_HeadlessEnabled);
	SetModifiedFlag();
}

VARIANT_BOOL CminiblkCtrl::GetIsDocumentReady(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return wkeIsDocumentReady(web)==FALSE?VARIANT_FALSE:VARIANT_TRUE;	
	return VARIANT_TRUE;
}

void CminiblkCtrl::OnLocalStorageFullPathChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetLocalStorageFullPath(web,m_LocalStorageFullPath);
	SetModifiedFlag();
}

void CminiblkCtrl::FireMouseEvent(ULONG msg, LONG x, LONG y, ULONG flags)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeFireMouseEvent(web,msg,x,y,flags);
	
}

void CminiblkCtrl::FireMouseWheelEvent(LONG x, LONG y, LONG delta, LONG flag)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeFireMouseWheelEvent(web,x,y,delta,flag);
	
}

void CminiblkCtrl::FireKeyUpEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeFireKeyUpEvent(web,virtualKeyCode,flags,systemKey);
	
}
void CminiblkCtrl::FireKeyDownEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeFireKeyDownEvent(web,virtualKeyCode,flags,systemKey);
	
}
void CminiblkCtrl::FireKeyPressEvent(ULONG charCode, ULONG flags, VARIANT_BOOL systemKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeFireKeyPressEvent(web,charCode,flags,systemKey);
	
}


FLOAT CminiblkCtrl::GetZoomFactor(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	
	return wkeGetZoomFactor(web); 
}

void CminiblkCtrl::SetZoomFactor(FLOAT newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	wkeSetZoomFactor(web,newVal);
	SetModifiedFlag();
}

ULONG CminiblkCtrl::GetAlign(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	return 0;
}

void CminiblkCtrl::SetAlign(ULONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	SetModifiedFlag();
}

BSTR CminiblkCtrl::GetTitle(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult=wkeGetTitleW(web);
	return strResult.AllocSysString();
}

ULONG CminiblkCtrl::GetContentWidth(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return wkeGetContentWidth(web);
}

ULONG CminiblkCtrl::GetContentHeight(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return wkeGetContentHeight(web);
}

VARIANT_BOOL CminiblkCtrl::GetCookieEnabled(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if(wkeIsCookieEnabled(web))
	{
		return VARIANT_TRUE;
	}
	else
	{
		return VARIANT_FALSE;
	}

}

void CminiblkCtrl::SetCookieEnabled(VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeSetCookieEnabled(web,newVal==VARIANT_TRUE?true:false);
	SetModifiedFlag();
}

void CminiblkCtrl::OnCookiePathChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wkeSetCookieJarFullPath(web,m_CookiePath);
	SetModifiedFlag();
}
