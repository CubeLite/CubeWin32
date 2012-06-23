#pragma once

#include "Definition.h"
#include "Core.h"
#include "ProcessRight.h"

/// <summary>
/// 进程的上下文信息
/// </summary>
struct WINEXT_MODULE_EXPIMP SProcessInfo
{
	
};

/// <summary>
/// 提供一组方法，用于封装进程的通用操作。
/// 获得的所有的 CProcessExt 对象的指针，在使用完以后，必须调用 CProcessExt::Dispose(...) 释放资源
/// 在 调用 CProcessExt::Dispose(...) 以后，真正的内核对象不受影响。
/// </summary>
class WINEXT_MODULE_EXPIMP CProcessExt : public Core
{
public:
	friend class CMutexExt;

public:
	~CProcessExt();

public:
	/// <summary>
	/// 获取当前进程的句柄。
	/// </summary>
	/// <remarks></remarks>
	/// <returns>返回当前进程的句柄。</returns>
	/// <author name="hps" date="2012.6.22   0:05"/>
	static CProcessExt* Current();

	/// <summary>
	/// 打开一个指定的进程。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="accessRight">[I] 指定返回的进程句柄拥有的访问权限</param>
	/// <param name="bInheritHandle">[I] 指定返回的进程句柄是否可被继承。</param>
	/// <param name="dwProcessId">[I] 指定要打开的进程的进程 ID。可由 GetWindowThreadProcessId() 获取。</param>
	/// <returns>返回打开进程的句柄。</returns>
	/// <author name="hps" date="2012.6.22   1:10"/>
	static CProcessExt* Open(EProcessRight::Enums accessRight, BOOL bInheritHandle, DWORD dwProcessId);

	/// <summary>
	/// 释放在堆上分配的进程的资源。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="pProcess">[I] 指定要释放资源的进程的指针。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   12:45"/>
	static void Dispose(CProcessExt *&pProcess);
};