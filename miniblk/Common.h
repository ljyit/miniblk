#pragma once
 
class CCommon
{
public:
	CCommon(void);
	~CCommon(void);
};
char * utf16ToUtf8(LPCWSTR lpszSrc);
wchar_t*  utf8ToUtf16(const char* utf8String);