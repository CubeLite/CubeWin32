#include "stdafx.h"
#include "CommonEnums.h"

DWORD EInherit::Get(Enums va)
{
	switch (va)
	{
	case Yes:
		return 1;

	case No:
		return 0;
	}
	return -1;
}

DWORD ECopyOption::Get(Enums va)
{
	switch (va)
	{
	case None:
		return 0;

	case AsSameAccess:
		return DUPLICATE_SAME_ACCESS;

	case CloseSource:
		return DUPLICATE_CLOSE_SOURCE;
	}
	return -1;
}