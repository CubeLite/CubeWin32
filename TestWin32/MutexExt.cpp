#include "stdafx.h"
#include "MutexExt.h"
#include "ProcessExt.h"

CMutexExt::~CMutexExt(void)
{
}

CMutexExt* CMutexExt::Create()
{
	HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
	
	CMutexExt *p = new CMutexExt();
	p->mHandle = hMutex;
	return p;
}

CMutexExt* CMutexExt::Create(const SMutexInfo &info)
{
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = info.lpSecurityDescriptor;
	sa.bInheritHandle = info.IsInherit;

	HANDLE hMutex = CreateMutex(&sa, info.IsInitialOwner, info.Name);
	CMutexExt *p = new CMutexExt();
	p->mHandle = hMutex;
	return p;
}

void CMutexExt::Dispose(CMutexExt *&pMutex)
{
	if (pMutex != NULL)
	{
		delete pMutex;
		pMutex = NULL;
	}
}

CMutexExt* CMutexExt::CopyFrom(CProcessExt *pSource, CMutexExt *pMutex, CProcessExt *pTarget, EMutexRight::Enums accessRight, EInherit::Enums inheritable, ECopyOption::Enums option)
{
	HANDLE hSourceProcessHandle = pSource->mHandle;
	HANDLE hSourceHandle = pMutex->mHandle;
	HANDLE hTargetProcessHandle = pTarget;
	
	DWORD dwDesiredAccess = EMutexRight::Get(accessRight);
	BOOL bInheritHandle = EInherit::Get(inheritable);
	DWORD dwOptions = ECopyOption::Get(option);

	HANDLE hTargetHandle;

	BOOL ok = DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, &hTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions);
	if (ok == FALSE)
		return NULL;

	CMutexExt *p = new CMutexExt();
	p->mHandle = hTargetHandle;
	return p;
}