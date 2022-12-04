
#pragma once
#include "wke.h"
#include "Common.h"

// CJSValue ÃüÁîÄ¿±ê

class CJSValue : public CCmdTarget
{
	DECLARE_DYNCREATE(CJSValue)

public:
	CJSValue(){	EnableAutomation();	AfxOleLockApp();m_value=NULL;m_web=NULL;};
	CJSValue(wkeWebView web,jsValue val);
	virtual ~CJSValue();

	virtual void OnFinalRelease();
	IDispatch* GetSelf();
protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CJSValue)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	CHAR Type(void);

	enum 
	{
		dispidItem = 11L,
		dispidCount = 10L,
		dispidValue = 9,
		dispidKey = 8,
		dispidisNull = 7L,
		dispidisLogical = 6L,
		dispidisNumber = 5L,
		dispidisString = 4L,
		dispidisArray = 3L,
		dispidisObject = 2L,
		dispidType = 1L
	};
	VARIANT_BOOL isObject(void);
	VARIANT_BOOL isArray(void);
	VARIANT_BOOL isString(void);
	VARIANT_BOOL isNumber(void);
	VARIANT_BOOL isLogical(void);
	VARIANT_BOOL isNull(void);
	BSTR GetKey(void);
	VARIANT GetValue(void);
	void SetValue(VARIANT newVal);
	ULONG Count(void);


protected:
	wkeWebView m_web;
	jsValue m_value;


	IDispatch* Item(VARIANT &idx);
};


