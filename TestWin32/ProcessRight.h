#pragma once

#include "Definition.h"

/// <summary>
/// 表示进程的访问权限。
/// </summary>
class WINEXT_MODULE_EXPIMP EProcessRight
{
public:
	enum Enums
	{
		/// <summary>
		/// 允许 TerminateProcess 使用进程句柄来关闭进程
		/// </summary>
		Terminate,

		/// <summary>
		/// 允许 CreateRemoteThread 使用进程句柄来创建线程
		/// </summary>
		CreateThread,

		/// <summary>
		/// 
		/// </summary>
		SetSessionID,

		/// <summary>
		/// 允许 VirtualProtectEx 使用进程句柄来改变进程的虚拟内存
		/// </summary>
		OperateVirtualMemory,

		/// <summary>
		/// 允许 ReadProcessMemory 使用进程句柄从进程的虚拟内存中读取数据
		/// </summary>
		ReadVirtualMemory,

		/// <summary>
		/// 允许 WriteProcessMemory 使用进程句柄向进程的虚拟内存中写入数据
		/// </summary>
		WriteVirtualMemory,

		/// <summary>
		/// 允许 DuplicateHandle 把进程句柄当作源句柄或目标句柄进行复制
		/// </summary>
		CopyAsProcessHandle,

		/// <summary>
		/// 默认值
		/// </summary>
		CreateProcess,

		/// <summary>
		/// 允许 SetProcessWorkingSetSize 使用进程句柄来来设置虚拟内存的上限值
		/// </summary>
		SetQuota,

		/// <summary>
		/// 允许 SetPriorityClass 使用进程句柄来设置进程优先级
		/// </summary>
		SetInformation,

		/// <summary>
		/// 允许 GetExitCodeProcess 或 GetPriorityClass 通过进程句柄读取进程信息
		/// </summary>
		QueryInformation,

		/// <summary>
		/// 允许任何等待的函数使用进程句柄
		/// </summary>
		SuspendAndResume,

		/// <summary>
		/// 允许所有权限
		/// </summary>
		All
	};

	/// <summary>
	/// 将枚举值转换为系统预定义的值。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="va"></param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:03"/>
	static DWORD Get(Enums va);	
};