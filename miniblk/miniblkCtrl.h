#pragma once
#include "wke.h"
#include "headers.h"
// miniblkCtrl.h : CminiblkCtrl ActiveX 控件类的声明。


// CminiblkCtrl : 有关实现的信息，请参阅 miniblkCtrl.cpp。

class CminiblkCtrl : public COleControl
{
	DECLARE_DYNCREATE(CminiblkCtrl)

// 构造函数
public:
	CminiblkCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CminiblkCtrl();

	DECLARE_OLECREATE_EX(CminiblkCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CminiblkCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CminiblkCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CminiblkCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidCookiePath = 41,
		dispidCookieEnabled = 40,
		dispidContentHeight = 39,
		dispidContentWidth = 38,
		dispidTitle = 37,
		dispidAlign = 36,
		dispidZoomFactor = 35,
		dispidFireKeyPressEvent = 34L,
		dispidFireKeyDownEvent = 33L,
		dispidFireKeyUpEvent = 32L,
		dispidFireMouseWheelEvent = 31L,
		dispidFireMouseEvent = 30L,
		dispidLocalStorageFullPath = 29,
		dispidIsDocumentReady = 28,
		dispidHeadlessEnabled = 27,
		eventidOnLoadUrlEnd = 10L,
		eventidOnLoadUrlFinish = 9L,
		dispidAdd = 9L,
		dispidHeaders = 26,
		dispidSetCookie = 25L,
		dispidStopLoading = 24L,
		eventidOnConsole = 8L,

		dispidResourceGc = 23,
		dispidLoadHTML = 22L,
		eventidOnAlertBox = 7L,
		dispidRunJS = 21L,
		dispidSetFocus = 20L,
		dispidUserAgent = 19,
		dispidSetProxy = 18L,
		dispidVersion = 17,
		dispidLoadFile = 16L,

		dispidNetSetData = 14L,
		dispidNetSetMIMEType = 13L,
		dispidMouseEnabled = 11,
		dispidContextMenuEnabled = 10,
		dispidTouchEnabled = 9,
		dispidReload = 8L,
		dispidGoForward = 7L,
		dispidGoBack = 6L,
		dispidCanGoForward = 5L,
		dispidCanGoBack = 4L,
		dispidGetCookie = 3L,
		dispidwkeHandle = 2,
		dispidLoadUrl = 1L,

		eventidOnLoadingFinish = 6L,
		eventidOnDocumentReady = 5L,
		eventidOnNavigation = 4L,
		eventidOnURLChanged = 3L,
		eventidOnTitleChanged = 2L,
		eventidOnLoadUrlBegin = 1L
	};
protected:
	wkeWebView web;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();

protected:
	void OnLoadUrlBegin(ULONG web, ULONG parm, LPCTSTR url, ULONG job,VARIANT* cancel)
	{
		FireEvent(eventidOnLoadUrlBegin, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_PVARIANT), web, parm, url, job,cancel);
	}

	void OnTitleChanged(ULONG web, ULONG parm, LPCTSTR title)
	{
		FireEvent(eventidOnTitleChanged, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_BSTR), web, parm, title);
	}
	void OnURLChanged(ULONG web, ULONG parm, ULONG frameId, LPCTSTR url)
	{
		FireEvent(eventidOnURLChanged, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR), web, parm, frameId, url);
	}
	void OnNavigation(ULONG web, ULONG parm, ULONG type, LPCTSTR url ,VARIANT* cancel)
	{
		FireEvent(eventidOnNavigation, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_PVARIANT), web, parm, type, url, cancel);
	}	
	void OnDocumentReady(ULONG web, ULONG parm, ULONG frameID)
	{
		FireEvent(eventidOnDocumentReady, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_UI4), web, parm, frameID);
	}

	void OnLoadingFinish(ULONG web, ULONG parm, LPCTSTR url, ULONG result, LPCTSTR failedReason)
	{
		FireEvent(eventidOnLoadingFinish, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_BSTR), web, parm, url, result, failedReason);
	}
	void OnAlertBox(LPCTSTR message)
	{
		FireEvent(eventidOnAlertBox, EVENT_PARAM(VTS_BSTR), message);
	}
	void OnConsole(ULONG web, ULONG param, ULONG level, LPCTSTR message, LPCTSTR sourceName, ULONG sourceLine, LPCTSTR stackTrace)
	{
		FireEvent(eventidOnConsole, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_BSTR VTS_UI4 VTS_BSTR), web, param, level, message, sourceName, sourceLine, stackTrace);
	}
	void OnLoadUrlFinish(ULONG web, ULONG parm, LPCTSTR url, ULONG job, ULONG len)
	{
		FireEvent(eventidOnLoadUrlFinish, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_UI4), web, parm, url, job, len);
	}
	void OnLoadUrlEnd(ULONG web, ULONG parm, LPCTSTR url, ULONG job, BYTE* data, ULONG len)
	{
		FireEvent(eventidOnLoadUrlEnd, EVENT_PARAM(VTS_UI4 VTS_UI4 VTS_BSTR VTS_UI4 VTS_PUI1 VTS_UI4), web, parm, url, job, data, len);
	}
public:
	static bool OnLoadUrlBegin_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job);
	static void OnTitleChanged_(wkeWebView webView, void* param, const wkeString title);
	static void OnURLChanged_(wkeWebView webView, void* param, wkeWebFrameHandle frameId, const wkeString url);
	static bool OnNavigation_(wkeWebView webView, void* param, wkeNavigationType type, const wkeString urlStr);
	static void OnDocumentReady_(wkeWebView webView, void* param, wkeWebFrameHandle frameId);
	static void OnLoadingFinish_(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason);
	static void OnAlertBox_(wkeWebView webView, void* param, const wkeString msg);
	static void OnLoadUrlFinish_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job, int len);
	static void OnLoadUrlEnd_(wkeWebView webView, void* param, const utf8* url, wkeNetJob job, void* buf, int len);
	static void OnConsole_(
		wkeWebView webView, 
		void* param, 
		wkeConsoleLevel level, 
		const wkeString message, 
		const wkeString sourceName, 
		unsigned sourceLine, 
		const wkeString stackTrace
		);

protected:
	ULONG GetwkeHandle(void);
	VARIANT_BOOL GetCanGoBack(void);
	VARIANT_BOOL GetCanGoForward(void);

	BSTR GetVersion(void);

	BSTR GetUserAgent(void);
	void SetUserAgent(LPCTSTR newVal);

	void OnTouchEnabledChanged(void);
	VARIANT_BOOL m_TouchEnabled;

	void OnContextMenuEnabledChanged(void);
	VARIANT_BOOL m_ContextMenuEnabled;

	void OnMouseEnabledChanged(void);
	VARIANT_BOOL m_MouseEnabled;

	void OnResourceGcChanged(void);
	ULONG m_ResourceGc;

protected:
	void LoadUrl(LPCTSTR url);
	void LoadHTML(LPCTSTR html);
	void LoadFile(LPCTSTR filename);
	void Reload(void);
	VARIANT_BOOL GoBack(void);
	VARIANT_BOOL GoForward(void);
	BSTR GetCookie(void);
	void NetSetMIMEType(ULONG job, LPCTSTR type);
	void NetSetData(ULONG job, LPCTSTR data, ULONG datalen);

	void SetProxy(ULONG type, LPCTSTR hostname, SHORT port, LPCTSTR username, LPCTSTR password);
	void SetFocus(void);
	IDispatch* RunJS(LPCTSTR script);
	void StopLoading(void);
	void SetCookie(LPCTSTR url, LPCTSTR cookies);

	IDispatch* GetHeaders(); 
public:
	CHeaders m_Headers;

protected:
	void OnHeadlessEnabledChanged(void);
	VARIANT_BOOL m_HeadlessEnabled;
	VARIANT_BOOL GetIsDocumentReady(void);
	void OnLocalStorageFullPathChanged(void);
	CString m_LocalStorageFullPath;
	void FireMouseEvent(ULONG msg, LONG x, LONG y, ULONG flags);
	void FireMouseWheelEvent(LONG x, LONG y, LONG delta, LONG flag);
	void FireKeyUpEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey);
	void FireKeyDownEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey);
	void FireKeyPressEvent(ULONG charCode, ULONG flags, VARIANT_BOOL systemKey);

	
	FLOAT GetZoomFactor(void);
	void SetZoomFactor(FLOAT newVal);
	ULONG GetAlign(void);
	void SetAlign(ULONG newVal);
	BSTR GetTitle(void);
	ULONG GetContentWidth(void);
	ULONG GetContentHeight(void);
	VARIANT_BOOL GetCookieEnabled(void);
	void SetCookieEnabled(VARIANT_BOOL newVal);
	void OnCookiePathChanged(void);
	CString m_CookiePath;
};

