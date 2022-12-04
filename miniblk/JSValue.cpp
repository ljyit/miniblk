// JSValue.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "miniblk.h"
#include "JSValue.h"
#include "miniblkidl.h"

// CJSValue

IMPLEMENT_DYNCREATE(CJSValue, CCmdTarget)


CJSValue::CJSValue(wkeWebView web, jsValue val)
{
	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	m_value=val;
	m_web=web;
	AfxOleLockApp();
}

CJSValue::~CJSValue()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	//::MessageBox(0,L"jsvalue destroy",0,0);
	AfxOleUnlockApp();
}


void CJSValue::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣
	//::MessageBox(0,L"OnFinalRelease",0,0);
	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CJSValue, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CJSValue, CCmdTarget)
	DISP_FUNCTION_ID(CJSValue, "Type", dispidType, Type, VT_I1, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isObject", dispidisObject, isObject, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isArray", dispidisArray, isArray, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isString", dispidisString, isString, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isNumber", dispidisNumber, isNumber, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isLogical", dispidisLogical, isLogical, VT_BOOL, VTS_NONE)
	DISP_FUNCTION_ID(CJSValue, "isNull", dispidisNull, isNull, VT_BOOL, VTS_NONE)
	DISP_PROPERTY_EX_ID(CJSValue, "Key", dispidKey, GetKey, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX_ID(CJSValue, "Value", dispidValue, GetValue, SetValue, VT_VARIANT)
	DISP_FUNCTION_ID(CJSValue, "Count", dispidCount, Count, VT_UI4, VTS_NONE)
	DISP_DEFVALUE(CJSValue, "Value")
	DISP_FUNCTION_ID(CJSValue, "Item", dispidItem, Item, VT_DISPATCH, VTS_VARIANT)
END_DISPATCH_MAP()

// ע��: ������� IID_IJSValue ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {B4AE6DFE-0137-4CEA-9AAF-D925DC41CD73}
static const IID IID_IJSValue =
{ 0xB4AE6DFE, 0x137, 0x4CEA, { 0x9A, 0xAF, 0xD9, 0x25, 0xDC, 0x41, 0xCD, 0x73 } };

BEGIN_INTERFACE_MAP(CJSValue, CCmdTarget)
	INTERFACE_PART(CJSValue, IID_IJSValue, Dispatch)
END_INTERFACE_MAP()

// {04ED7311-AE2A-4E80-8D62-EA408724D070}
//IMPLEMENT_OLECREATE_FLAGS(CJSValue, "miniblk.JSValue", afxRegApartmentThreading, 0x4ed7311, 0xae2a, 0x4e80, 0x8d, 0x62, 0xea, 0x40, 0x87, 0x24, 0xd0, 0x70)


// CJSValue ��Ϣ�������

CHAR CJSValue::Type(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	char type='N';

	// TODO: �ڴ���ӵ��ȴ���������
	switch (jsTypeOf(m_value))
	{
	case JSTYPE_NUMBER:
		type='D';
		break;
	case JSTYPE_STRING:
		type='C';
		break;
	case JSTYPE_BOOLEAN:
		type='L';
		break;
	case JSTYPE_OBJECT:
		type='O';
		break;
	case JSTYPE_FUNCTION:
		type='F';
		break;
	case JSTYPE_UNDEFINED:
		type='U';
		break;
	case JSTYPE_ARRAY:
		type='A';
		break;
	case JSTYPE_NULL:
		type='N';
		break;
	}
	
	return type;
}

VARIANT_BOOL CJSValue::isObject(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: �ڴ���ӵ��ȴ���������
	int x=jsIsObject(m_value);
	x=jsTypeOf(m_value);


	jsValue val=jsEmptyObject(wkeGlobalExec(m_web));
	x=jsIsObject(val);
	return x? VARIANT_TRUE:VARIANT_FALSE;
}

VARIANT_BOOL CJSValue::isArray(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return jsIsArray(m_value)? VARIANT_TRUE:VARIANT_FALSE;
}

VARIANT_BOOL CJSValue::isString(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return jsIsString(m_value)? VARIANT_TRUE:VARIANT_FALSE;
}

VARIANT_BOOL CJSValue::isNumber(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return jsIsNumber(m_value)? VARIANT_TRUE:VARIANT_FALSE;
}

VARIANT_BOOL CJSValue::isLogical(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return jsIsBoolean(m_value)? VARIANT_TRUE:VARIANT_FALSE;
}

VARIANT_BOOL CJSValue::isNull(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������

	return jsIsNull(m_value)? VARIANT_TRUE:VARIANT_FALSE;
}

BSTR CJSValue::GetKey(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	jsKeys* keys=jsGetKeys(wkeGlobalExec(m_web),m_value);

	return strResult.AllocSysString();
}

VARIANT CJSValue::GetValue(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	VARIANT vaResult;
	VariantInit(&vaResult);

	wchar_t* str;
 
	switch (jsTypeOf(m_value))
	{
	case JSTYPE_NUMBER:
		vaResult.vt= VT_R8;
		vaResult.dblVal=jsToDouble(wkeGlobalExec(m_web),m_value);
		break;
	case JSTYPE_STRING:
		vaResult.vt=VT_BSTR;
		str=utf8ToUtf16(jsToTempString(wkeGlobalExec(m_web),m_value));
		vaResult.bstrVal=::SysAllocString(str);
		break;
	case JSTYPE_BOOLEAN:
		vaResult.vt=VT_BOOL;
		vaResult.boolVal=jsToBoolean(wkeGlobalExec(m_web),m_value)?VARIANT_TRUE:VARIANT_FALSE;
		break;
	case JSTYPE_OBJECT:
	case JSTYPE_ARRAY:
		vaResult.vt=VT_DISPATCH;
		vaResult.pdispVal=(IDispatch*) CJSValue(m_web,m_value).GetInterface(&IID_IJSValue);
		//vaResult.pdispVal=tmpVal->GetIDispatch(FALSE);
		break;
	case JSTYPE_FUNCTION:
	case JSTYPE_UNDEFINED:
	case JSTYPE_NULL:
	default:
		vaResult.vt=VT_NULL;
		break;
	}

	return vaResult;
}

void CJSValue::SetValue(VARIANT newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ�������Դ���������
}



ULONG CJSValue::Count(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	return jsGetLength(wkeGlobalExec(m_web),m_value);
}

IDispatch* CJSValue::Item(VARIANT &idx)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (!(isArray() || isObject()))
	{
		return NULL;
	}

	if (isArray())
	{
		int nIndex;

		switch (idx.vt)
		{

		case VT_UI1:
		case VT_I1:
			nIndex=idx.bVal;
			break;
		case VT_I2:
		case VT_UI2:
		case VT_BOOL:
			nIndex=idx.iVal;
			break;
		case VT_I4:
		case VT_UI4:
		case VT_R4:
		case VT_INT:
		case VT_UINT:
			nIndex=idx.uintVal;
			break;
		default:
			ERROR(L"params error");
		}
		 jsValue tmpVal = jsGetAt(wkeGlobalExec(m_web),m_value,nIndex);
		
		 return CJSValue(m_web,tmpVal).GetIDispatch(FALSE);
	}

	return NULL;
}
IDispatch* CJSValue::GetSelf()
{
	return (IDispatch*)GetInterface(&IID_IJSValue);
}