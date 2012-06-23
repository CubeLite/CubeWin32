#pragma once

#include "Definition.h"
#include "Core.h"
#include "ProcessRight.h"

/// <summary>
/// ���̵���������Ϣ
/// </summary>
struct WINEXT_MODULE_EXPIMP SProcessInfo
{
	
};

/// <summary>
/// �ṩһ�鷽�������ڷ�װ���̵�ͨ�ò�����
/// ��õ����е� CProcessExt �����ָ�룬��ʹ�����Ժ󣬱������ CProcessExt::Dispose(...) �ͷ���Դ
/// �� ���� CProcessExt::Dispose(...) �Ժ��������ں˶�����Ӱ�졣
/// </summary>
class WINEXT_MODULE_EXPIMP CProcessExt : public Core
{
public:
	friend class CMutexExt;

public:
	~CProcessExt();

public:
	/// <summary>
	/// ��ȡ��ǰ���̵ľ����
	/// </summary>
	/// <remarks></remarks>
	/// <returns>���ص�ǰ���̵ľ����</returns>
	/// <author name="hps" date="2012.6.22   0:05"/>
	static CProcessExt* Current();

	/// <summary>
	/// ��һ��ָ���Ľ��̡�
	/// </summary>
	/// <remarks></remarks>
	/// <param name="accessRight">[I] ָ�����صĽ��̾��ӵ�еķ���Ȩ��</param>
	/// <param name="bInheritHandle">[I] ָ�����صĽ��̾���Ƿ�ɱ��̳С�</param>
	/// <param name="dwProcessId">[I] ָ��Ҫ�򿪵Ľ��̵Ľ��� ID������ GetWindowThreadProcessId() ��ȡ��</param>
	/// <returns>���ش򿪽��̵ľ����</returns>
	/// <author name="hps" date="2012.6.22   1:10"/>
	static CProcessExt* Open(EProcessRight::Enums accessRight, BOOL bInheritHandle, DWORD dwProcessId);

	/// <summary>
	/// �ͷ��ڶ��Ϸ���Ľ��̵���Դ��
	/// </summary>
	/// <remarks></remarks>
	/// <param name="pProcess">[I] ָ��Ҫ�ͷ���Դ�Ľ��̵�ָ�롣</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   12:45"/>
	static void Dispose(CProcessExt *&pProcess);
};