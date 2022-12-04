# miniblk
miniblink 的OCX封装

已完成的：

属性：

    BSTR          Version            miniblink版本
    ULONG         wkeHandle          miniblink的句柄，可直接用于API
    VARIANT_BOOL  CanGoBack          是否可以后退
    VARIANT_BOOL  CanGoForward       是否可以前进
    VARIANT_BOOL  TouchEnabled       是否启用触摸屏模式，默认否
    VARIANT_BOOL  ContextMenuEnabled 是否允许快捷菜单,默认是
    VARIANT_BOOL  MouseEnabled       是否允许鼠标，默认是
    VARIANT_BOOL  CookieEnabled      设置或读取Cookies是否启用，但不影响CURL的cookies设置
    VARIANT_BOOL  HeadlessEnabled    开启无头模式，默认关。开启后页面不会被渲染上屏，直接内存运行，大幅提升性能。
    VARIANT_BOOL  IsDocumentReady    DOM文档结构是否加载完成。
    FLOAT         ZoomFactor         设置页面缩放系数，默认是1.0。
    BSTR          Title              当前窗口标题
    ULONG         ContentWidth       获取网页排版出来的宽度
    ULONG         ContentHeight      网页排版出来的高度
    BSTR          CookiePath         读取或设置cookie的本地文件路径
    BSTR          UserAgent          浏览器的UA
    ULONG         ResourceGc         设置自动回收系统资源时间间隔，单位秒，默认秒。
    BSTR          LocalStorageFullPath   设置localstorage的全路径。必须且只能是目录，默认是当前目录。

方法：

    void          LoadUrl(BSTR url)      打开网址   
    void          LoadFile(BSTR filename 打开文件  
    void          LoadHTML(BSTR html)    加载HTML代码  
    BSTR          GetCookie(void)        获取cookies   
    VARIANT_BOOL GoBack(void)            后退   
    VARIANT_BOOL GoForward(void)         前进  
    void          Reload(void)           刷新网页  
    void          NetSetMIMEType(ULONG job, BSTR type)                   在OnLoadUrlBegin回调里调用，设置http请求的MIME类型 
    void          NetSetData(ULONG job, BSTR data, ULONG datalen);       在此接口后会触发OnLoadUrlEnd事件。   
    void          SetProxy(ULONG type, BSTR hostname, SHORT port, BSTR username, BSTR password);  设置代理服务器  
    void          SetFocus(void)               设置焦点  
    IJSValue      RunJS(BSTR script)           执行JS代码
    void          StopLoading(void)            停止当前页面加载  
    void          SetCookie(BSTR url, BSTR cookies)  设置Cookie，必须符合curl的标准写022 03:04:55 GMT; domain=.fidelity.com; path=/; secure 
    void          FireMouseEvent(ULONG msg, LONG x, LONG y, ULONG flags                        触发一个鼠标事件  
    void          FireMouseWheelEvent(LONG x, LONG y, LONG delta, LONG flag)                   向webView发送滚轮消息。  
    void          FireKeyUpEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey)    向webView发送WM_KEYUP消息。  
    void          FireKeyDownEvent(ULONG virtualKeyCode, ULONG flags, VARIANT_BOOL systemKey)  向webView发送WM_KEYDOWN消息。   
    void          FireKeyPressEvent(ULONG charCode, ULONG flags, VARIANT_BOOL systemKey)       向webView发送WM_KEYPRESS消息。   

事件:

OnLoadUrlBegin(ULONG web, ULONG parm, BSTR url,ULONG job, VARIANT_BOOL* cancel)    当开始加载时发生
OnTitleChanged(ULONG web, ULONG parm, BSTR title)                                  当浏览器标题改变时发生
OnURLChanged(ULONG web, ULONG parm, ULONG frameId, BSTR url)                       当URL改变时发生
OnNavigation(ULONG web, ULONG parm, ULONG type, BSTR url,VARIANT_BOOL* cancel)     当页面导航时发生
OnDocumentReady(ULONG web, ULONG parm, ULONG frameID)                              当文档加载完成时发生
OnLoadingFinish(ULONG web, ULONG parm, BSTR url, ULONG result, BSTR failedReason)  当页面加载完成时发生
OnAlertBox(BSTR message)                                                           当网页弹出alert时发生
OnConsole(ULONG web, ULONG param, ULONG level, BSTR message, BSTR sourceName, ULONG sourceLine, BSTR stackTrace);当有控制台输出时发生
OnLoadUrlFinish(ULONG web, ULONG parm, BSTR url, ULONG job, ULONG len)             当URL完成时
OnLoadUrlEnd(ULONG web, ULONG parm, BSTR url, ULONG job, BYTE* data, ULONG len)    当URL加载完成时

      
