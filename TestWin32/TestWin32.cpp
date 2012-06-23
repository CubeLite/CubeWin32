// TestWin32.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Win32All.h"

//int _tmain(int argc, _TCHAR* argv[])
//void main()
//int WINAPI _tWinMain(HINSTANCE hinstExe, HINSTANCE, PTSTR pszCmdLine, int)
int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	CProcessExt *pCurrent = CProcessExt::Current();
	CString str = pCurrent->ToString();
	bool c1 = pCurrent->IsStopClose();
	pCurrent->SetInherit(true);
	bool c2 = pCurrent->IsInherit(); 
	pCurrent->Close();
	CProcessExt::Dispose(pCurrent);

	CString msg = CTool::GetErrorMessageByNum(2);

	SMutexInfo minfo;
	minfo.Name = _T("myinstance");
	minfo.IsInherit = FALSE;
	minfo.IsInitialOwner = FALSE;
	minfo.lpSecurityDescriptor = NULL;
	CMutexExt *pMutex = CMutexExt::Create(minfo);

	bool isInherit1 = pMutex->IsInherit();
	bool ok = pMutex->SetInherit(true);
	bool isInherit2 = pMutex->IsInherit();
	
	CString temp = pMutex->ToString();
	CMutexExt::Dispose(pMutex);

	CString key = _T("ExtHandle");
	bool flag = CEnvironment::SetVariable(key, temp);
	CString temp2 = CEnvironment::GetVariable(key);

	Core *pCore = Core::Parse(temp2);
	pCore->Close();
	Core::Dispose(pCore);

	CEnvironment::SetVariable(key, _T("haha"));
	CEnvironment::ClearVariable(key);

	return 0;
}

