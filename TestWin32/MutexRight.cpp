#include "stdafx.h"
#include "MutexRight.h"

DWORD EMutexRight::Get(Enums va)
{
	switch (va)
	{
	case ModifyState:
		return MUTEX_MODIFY_STATE;

	case All:
		return MUTEX_ALL_ACCESS;
	}
	return -1;
}