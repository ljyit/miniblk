#pragma once

// miniblkPropPage.h : CminiblkPropPage ����ҳ���������


// CminiblkPropPage : �й�ʵ�ֵ���Ϣ������� miniblkPropPage.cpp��

class CminiblkPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CminiblkPropPage)
	DECLARE_OLECREATE_EX(CminiblkPropPage)

// ���캯��
public:
	CminiblkPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MINIBLK };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

