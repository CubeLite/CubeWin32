#include "stdafx.h"
#include "ProcessRight.h"

DWORD EProcessRight::Get(Enums va)
{
	switch (va)
	{
	case Terminate:
		return PROCESS_TERMINATE;
	case CreateThread:
		return PROCESS_CREATE_THREAD;
	case SetSessionID:
		return PROCESS_SET_SESSIONID;
	case OperateVirtualMemory:
		return PROCESS_VM_OPERATION;
	case ReadVirtualMemory:
		return PROCESS_VM_READ;
	case WriteVirtualMemory:
		return PROCESS_VM_WRITE;
	case CopyAsProcessHandle:
		return PROCESS_DUP_HANDLE;
	case CreateProcess:
		return PROCESS_CREATE_PROCESS;
	case SetQuota:
		return PROCESS_SET_QUOTA;
	case SetInformation:
		return PROCESS_SET_INFORMATION;
	case QueryInformation:
		return PROCESS_QUERY_INFORMATION;
	case SuspendAndResume:
		return PROCESS_SUSPEND_RESUME;
	case All:
		return PROCESS_ALL_ACCESS;
	}
	return -1;
}