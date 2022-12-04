// miniblkPropPage.cpp : CminiblkPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "miniblk.h"
#include "miniblkPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CminiblkPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CminiblkPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CminiblkPropPage, "MINIBLK.miniblkPropPage.1",
	0xf1d12dc5, 0x957f, 0x417c, 0xbb, 0x61, 0x37, 0x33, 0x5, 0x72, 0xb4, 0x71)



// CminiblkPropPage::CminiblkPropPageFactory::UpdateRegistry -
// ���ӻ��Ƴ� CminiblkPropPage ��ϵͳע�����

BOOL CminiblkPropPage::CminiblkPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MINIBLK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CminiblkPropPage::CminiblkPropPage - ���캯��

CminiblkPropPage::CminiblkPropPage() :
	COlePropertyPage(IDD, IDS_MINIBLK_PPG_CAPTION)
{
}



// CminiblkPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CminiblkPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CminiblkPropPage ��Ϣ��������