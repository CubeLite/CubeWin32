#include "stdafx.h"
#include "ProcessExt.h"
#include "Tool.h"

CProcessExt::~CProcessExt()
{

}

void CProcessExt::Dispose(CProcessExt *&pProcess)
{
	if (pProcess != NULL)
	{
		delete pProcess;
		pProcess = NULL;
	}
}

CProcessExt* CProcessExt::Current()
{
	HANDLE handle = GetCurrentProcess();
	DWORD num = GetLastError();
	if (num != 0)
	{
		//CString message = CTool::GetErrorMessageByNum(num);
		return NULL;
	}
	
	CProcessExt *p = new CProcessExt();
	p->mHandle = handle;
	return p;
}

CProcessExt* CProcessExt::Open(EProcessRight::Enums accessRight, BOOL bInheritHandle, DWORD dwProcessId)
{
	DWORD desiredAccess = EProcessRight::Get(accessRight);
	HANDLE handle = OpenProcess(desiredAccess, bInheritHandle, dwProcessId);

	CProcessExt *p = new CProcessExt();
	p->mHandle = handle;
	return p;
}