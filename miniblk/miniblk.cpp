// miniblk.cpp : CminiblkApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "miniblk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CminiblkApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x775B09F0, 0x2D0C, 0x4E6F, { 0x80, 0xD0, 0x2, 0x45, 0x6A, 0xAE, 0x45, 0x68 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CminiblkApp::InitInstance - DLL 初始化

BOOL CminiblkApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CminiblkApp::ExitInstance - DLL 终止

int CminiblkApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
