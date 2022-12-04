
#pragma once


// CHeaders

class CHeaders : public CCmdTarget
{
	DECLARE_DYNAMIC(CHeaders)

public:
	CHeaders();
	virtual ~CHeaders();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	ULONG Count(void);

	enum 
	{
		dispiditem = 4L,
		dispidItem = 4L,
		dispidAdd = 3L,
		dispidClear = 2L,
		dispidCount = 1L
	};
	void Clear(void);
	void Add(LPCTSTR key, LPCTSTR value);

public:
	CMap<CString, LPCTSTR, CString, LPCTSTR> m_Map;
 
protected:
	BSTR item(ULONG idx);
};


