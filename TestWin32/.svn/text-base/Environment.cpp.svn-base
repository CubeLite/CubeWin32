#include "stdafx.h"
#include "Environment.h"

bool CEnvironment::SetVariable(const CString &key, const CString &value)
{
	BOOL ok = SetEnvironmentVariable(key, value);
	if (ok == TRUE)
		return true;
	return false;
}

CString CEnvironment::GetVariable(const CString &key)
{
	DWORD size = 1024;
	TCHAR buf[1024];
	
	GetEnvironmentVariable(key, buf, size);
	CString temp = buf;

	return temp;
}

bool CEnvironment::ClearVariable(const CString &key)
{
	BOOL ok = SetEnvironmentVariable(key, NULL);
	if (ok == TRUE)
		return true;
	return false;
}