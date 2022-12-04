// Headers.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "miniblk.h"
#include "Headers.h"
#include "miniblkidl.h"

// CHeaders

IMPLEMENT_DYNAMIC(CHeaders, CCmdTarget)


CHeaders::CHeaders()
{
	EnableAutomation();
	

}

CHeaders::~CHeaders()
{
}


void CHeaders::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CHeaders, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CHeaders, CCmdTarget)
	DISP_FUNCTION_ID(CHeaders, "Count", dispidCount, Count, VT_UI4, VTS_NONE)
	DISP_FUNCTION_ID(CHeaders, "Clear", dispidClear, Clear, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHeaders, "Add", dispidAdd, Add, VT_EMPTY, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CHeaders, "item", dispiditem, item, VT_BSTR, VTS_UI4)
END_DISPATCH_MAP()

// ע��: ������� IID_IHeaders ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {4AE5F4F4-D042-4D45-B530-AC83A0FF287A}
static const IID IID_IHeaders =
{ 0x4AE5F4F4, 0xD042, 0x4D45, { 0xB5, 0x30, 0xAC, 0x83, 0xA0, 0xFF, 0x28, 0x7A } };

BEGIN_INTERFACE_MAP(CHeaders, CCmdTarget)
	INTERFACE_PART(CHeaders, IID_IHeaders, Dispatch)
END_INTERFACE_MAP()


// CHeaders ��Ϣ�������

ULONG CHeaders::Count(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	return m_Map.GetCount();
}

void CHeaders::Clear(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); 
	m_Map.RemoveAll();
}

void CHeaders::Add(LPCTSTR key, LPCTSTR value)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_Map.SetAt(key,value); 
}


BSTR CHeaders::item(ULONG idx)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); 

	CString key,value;
	ULONG x=0;
	POSITION ps=m_Map.GetStartPosition();
	while (ps)
	{
		m_Map.GetNextAssoc(ps,key,value);

		if (x==idx)
		{
			break;
		}
		x++;
		
	}

	return value.AllocSysString();
}
