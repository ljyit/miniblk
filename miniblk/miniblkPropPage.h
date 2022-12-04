#pragma once

// miniblkPropPage.h : CminiblkPropPage 属性页类的声明。


// CminiblkPropPage : 有关实现的信息，请参阅 miniblkPropPage.cpp。

class CminiblkPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CminiblkPropPage)
	DECLARE_OLECREATE_EX(CminiblkPropPage)

// 构造函数
public:
	CminiblkPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MINIBLK };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

