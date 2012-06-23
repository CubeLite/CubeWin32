#include "stdafx.h"
#include "Core.h"
#include "Tool.h"

Core::Core()
{
	this->mHandle = NULL;
}

Core::Core(HANDLE handle)
{
	this->mHandle = handle;
}

Core::Core(const CString &strHandle)
{
	__int64 pv = _tstol(strHandle);
	void *p = (void*)pv;
	mHandle = p;
}

Core::Core(const Core& src)
{
	*this = src;
}

Core& Core::operator=(const Core& src)
{
	if (this == &src)
	{
		return *this;
	}

	this->mHandle = src.mHandle;
	return *this;
}

Core::~Core(void)
{
}

void Core::Close()
{
	CloseHandle(this->mHandle);
	this->mHandle = NULL;
}

bool Core::SetInherit(bool isInherit)
{
	BOOL ok = FALSE;
	if (isInherit == true)
		ok = SetHandleInformation(mHandle, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
	else
		ok = SetHandleInformation(mHandle, HANDLE_FLAG_INHERIT, 0);

	if (ok == TRUE)
		return true;

	return false;
}

bool Core::IsInherit()
{
	DWORD dwFlags;
	BOOL ok = GetHandleInformation(mHandle, &dwFlags);
	if (ok == FALSE)
		return false;

	if ((dwFlags & HANDLE_FLAG_INHERIT) != 0)
		return true;
	return false;
}

bool Core::SetStopClose(bool isStopClose)
{
	BOOL ok = FALSE;
	if (isStopClose == true)
		ok = SetHandleInformation(mHandle, HANDLE_FLAG_PROTECT_FROM_CLOSE, HANDLE_FLAG_PROTECT_FROM_CLOSE);
	else
		ok = SetHandleInformation(mHandle, HANDLE_FLAG_PROTECT_FROM_CLOSE, 0);

	if (ok == TRUE)
		return true;
	return false;
	//CloseHandle(handle); // 若调用关闭句柄的方法，将抛出异常
}

bool Core::IsStopClose()
{
	DWORD dwFlags;
	BOOL ok = GetHandleInformation(mHandle, &dwFlags);
	if (ok == FALSE)
		return false;

	if ((dwFlags & HANDLE_FLAG_PROTECT_FROM_CLOSE) != 0)
		return true;
	return false;
}


CString Core::ToString()
{
	CString temp;
	temp.Format(_T("%d"), mHandle);
	return temp;
}

Core* Core::Parse(const CString &strHandle)
{
	__int64 pv = _tstol(strHandle);
	void *p = (void*)pv;
	HANDLE temp = p;

	Core *pCore = new Core();
	pCore->mHandle = temp;
	return pCore;
}

void Core::Dispose(Core *&pCore)
{
	if (pCore != NULL)
	{
		delete pCore;
		pCore = NULL;
	}
}