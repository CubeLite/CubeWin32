#pragma once

#include "Definition.h"
#include "Core.h"
#include "MutexRight.h"
#include "CommonEnums.h"

class CProcessExt;

/// <summary>
/// 创建互斥量时的信息。
/// </summary>
struct WINEXT_MODULE_EXPIMP SMutexInfo
{
	/// <summary>
	/// 互斥量的名称，若指定为 NULL，表示创建匿名互斥量。
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
	/// 指定创建互斥量后返回的句柄是否可被子进程继承。
	/// </summary>
	BOOL IsInherit;
};

/// <summary>
/// 提供一组方法，用于封装互斥量的通用操作。
/// </summary>
class WINEXT_MODULE_EXPIMP CMutexExt : public Core
{
public:

	/// <summary>
	/// 析构函数
	/// </summary>
	/// <remarks></remarks>
	/// <param name=""></param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:55"/>
	~CMutexExt(void);

public:
	/// <summary>
	/// 创建一个匿名的、不可被子进程继承的互斥量。
	/// </summary>
	/// <remarks>每次调用 CMutexExt::Create(...) 方法以后，必须调用 CMutexExt::Dispose(...) 方法释放资源。</remarks>
	/// <returns>返回创建的 CMutexExt 对象的指针。</returns>
	/// <author name="hps" date="2012.6.22   12:36"/>
	static CMutexExt* Create();

	/// <summary>
	/// 以指定的信息，创建一个互斥量。
	/// </summary>
	/// <remarks>每次调用 CMutexExt::Create(...) 方法以后，必须调用 CMutexExt::Dispose(...) 方法释放资源。</remarks>
	/// <param name="info">[I] 指定创建互斥量的相关信息。</param>
	/// <returns>返回 CMutexExt 对象的指针。若系统中已经存在指定的信息中同名的互斥量，则不会创建新的互斥量，仅当系统中不存在同名的互斥量时，才创建新的互斥量。</returns>
	/// <author name="hps" date="2012.6.22   12:38"/>
	static CMutexExt* Create(const SMutexInfo &info);

	/// <summary>
	/// 将一个互斥量从一个进程拷贝到另一个进程。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="pSource">[I] 指定要拷贝的互斥量的所在进程。</param>
	/// <param name="pMutex">[I] 指定要拷贝的互斥量。</param>
	/// <param name="pTarget">[I] 指定拷贝的目标进程。</param>
	/// <param name="accessRight">[I] 指定拷贝以后的互斥量所具有的访问权限。</param>
	/// <param name="inheritable">[I] 指定拷贝以后的互斥量是否具有可继承性。</param>
	/// <param name="option">[I] 指定拷贝的选项。若指定 ECopyOption::AsSameAccess，那么 accessRight 将会被忽略。</param>
	/// <returns>返回拷贝以后的互斥量，该互斥量与 pTarget 进程相关。</returns>
	/// <author name="hps" date="2012.6.22   13:51"/>
	static CMutexExt* CopyFrom(CProcessExt *pSource, CMutexExt *pMutex, CProcessExt *pTarget, EMutexRight::Enums accessRight, EInherit::Enums inheritable, ECopyOption::Enums option);

	/// <summary>
	/// 释放在堆上分配的互斥量的资源。
	/// </summary>
	/// <param name="pMutex">[I] 指定要释放资源的互斥量的指针。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   2:07"/>
	static void Dispose(CMutexExt *&pMutex);
};