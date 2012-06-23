#pragma once

#include "Definition.h"
#include "Core.h"
#include "MutexRight.h"
#include "CommonEnums.h"

class CProcessExt;

/// <summary>
/// ����������ʱ����Ϣ��
/// </summary>
struct WINEXT_MODULE_EXPIMP SMutexInfo
{
	/// <summary>
	/// �����������ƣ���ָ��Ϊ NULL����ʾ����������������
	/// </summary>
	LPCWSTR Name;

	/// <summary>
	/// 
	/// </summary>
	BOOL IsInitialOwner;

	/// <summary>
	/// 
	/// </summary>
	LPVOID lpSecurityDescriptor;

	/// <summary>
	/// ָ�������������󷵻صľ���Ƿ�ɱ��ӽ��̼̳С�
	/// </summary>
	BOOL IsInherit;
};

/// <summary>
/// �ṩһ�鷽�������ڷ�װ��������ͨ�ò�����
/// </summary>
class WINEXT_MODULE_EXPIMP CMutexExt : public Core
{
public:

	/// <summary>
	/// ��������
	/// </summary>
	/// <remarks></remarks>
	/// <param name=""></param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:55"/>
	~CMutexExt(void);

public:
	/// <summary>
	/// ����һ�������ġ����ɱ��ӽ��̼̳еĻ�������
	/// </summary>
	/// <remarks>ÿ�ε��� CMutexExt::Create(...) �����Ժ󣬱������ CMutexExt::Dispose(...) �����ͷ���Դ��</remarks>
	/// <returns>���ش����� CMutexExt �����ָ�롣</returns>
	/// <author name="hps" date="2012.6.22   12:36"/>
	static CMutexExt* Create();

	/// <summary>
	/// ��ָ������Ϣ������һ����������
	/// </summary>
	/// <remarks>ÿ�ε��� CMutexExt::Create(...) �����Ժ󣬱������ CMutexExt::Dispose(...) �����ͷ���Դ��</remarks>
	/// <param name="info">[I] ָ�������������������Ϣ��</param>
	/// <returns>���� CMutexExt �����ָ�롣��ϵͳ���Ѿ�����ָ������Ϣ��ͬ���Ļ��������򲻻ᴴ���µĻ�����������ϵͳ�в�����ͬ���Ļ�����ʱ���Ŵ����µĻ�������</returns>
	/// <author name="hps" date="2012.6.22   12:38"/>
	static CMutexExt* Create(const SMutexInfo &info);

	/// <summary>
	/// ��һ����������һ�����̿�������һ�����̡�
	/// </summary>
	/// <remarks></remarks>
	/// <param name="pSource">[I] ָ��Ҫ�����Ļ����������ڽ��̡�</param>
	/// <param name="pMutex">[I] ָ��Ҫ�����Ļ�������</param>
	/// <param name="pTarget">[I] ָ��������Ŀ����̡�</param>
	/// <param name="accessRight">[I] ָ�������Ժ�Ļ����������еķ���Ȩ�ޡ�</param>
	/// <param name="inheritable">[I] ָ�������Ժ�Ļ������Ƿ���пɼ̳��ԡ�</param>
	/// <param name="option">[I] ָ��������ѡ���ָ�� ECopyOption::AsSameAccess����ô accessRight ���ᱻ���ԡ�</param>
	/// <returns>���ؿ����Ժ�Ļ��������û������� pTarget ������ء�</returns>
	/// <author name="hps" date="2012.6.22   13:51"/>
	static CMutexExt* CopyFrom(CProcessExt *pSource, CMutexExt *pMutex, CProcessExt *pTarget, EMutexRight::Enums accessRight, EInherit::Enums inheritable, ECopyOption::Enums option);

	/// <summary>
	/// �ͷ��ڶ��Ϸ���Ļ���������Դ��
	/// </summary>
	/// <param name="pMutex">[I] ָ��Ҫ�ͷ���Դ�Ļ�������ָ�롣</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   2:07"/>
	static void Dispose(CMutexExt *&pMutex);
};