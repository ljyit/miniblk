// miniblk.cpp : CminiblkApp �� DLL ע���ʵ�֡�

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



// CminiblkApp::InitInstance - DLL ��ʼ��

BOOL CminiblkApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CminiblkApp::ExitInstance - DLL ��ֹ

int CminiblkApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
