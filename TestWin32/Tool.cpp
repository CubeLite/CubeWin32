#include "stdafx.h"
#include "Tool.h"
#include <Windows.h>
#include <WinError.h>
#include <tchar.h>

CString CTool::GetErrorMessageByNum(int errorNum)
{
	//strcmp();
	//wcscmp();
	//_tcscmp();
	//lstrcmp();
	//StrCmp();
	//CompareString();
	//GetThreadLocale();

	TCHAR s[] = _T("1 I love you, Hello World");
	DWORD dw1 = CharLowerBuff(s, 13);
	DWORD dw2 = CharUpperBuff(s, 10);

	BOOL isA = IsCharAlpha(s[2]);
	BOOL isN = IsCharAlphaNumeric(s[0]);

	char sText[20] = {"¶à×Ö½Ú×Ö·û´®!OK!"};
	int count = MultiByteToWideChar(CP_ACP, 0, sText, -1, NULL, 0);
	TCHAR *pText = new TCHAR[count];
	int count2 = MultiByteToWideChar(CP_ACP, 0, sText, -1, pText, count);
	delete []pText;

	int lpi[5] = {IS_TEXT_UNICODE_ASCII16};
	BOOL isUnicode = IsTextUnicode(s, 15, lpi);

	HLOCAL hlocal = NULL;
	HANDLE hThread = GetCurrentThread();
	BOOL isOk = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, errorNum, 
		MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), 
		(LPTSTR)&hlocal, 0, NULL);

	PCTSTR str = (PCTSTR)LocalLock(hlocal);

	CString result = str;
	

	LocalFree(hlocal);
	
	return result;
}