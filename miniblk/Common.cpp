#include "StdAfx.h"
#include "Common.h"

CCommon::CCommon(void)
{
}

CCommon::~CCommon(void)
{
}

char * utf16ToUtf8(LPCWSTR lpszSrc)
{
	int  nUTF8Len = WideCharToMultiByte(CP_UTF8, 0, lpszSrc, -1, NULL, 0, NULL, NULL);
	char* pUTF8 = new char[nUTF8Len + 1];
	ZeroMemory(pUTF8, nUTF8Len + 1);
	WideCharToMultiByte(CP_UTF8, 0, lpszSrc, -1, pUTF8, nUTF8Len, NULL, NULL);
	return pUTF8;
}

wchar_t*  utf8ToUtf16(const char* utf8String)
{
	int nUTF8Len = MultiByteToWideChar(CP_UTF8, 0, utf8String, -1, NULL, NULL);
	wchar_t* pUTF8 = new wchar_t[nUTF8Len + 1];
	ZeroMemory(pUTF8, nUTF8Len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8String, -1, pUTF8, nUTF8Len);
	return pUTF8;
}

