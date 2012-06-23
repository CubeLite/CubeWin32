#pragma once

#include "Definition.h"

/// <summary>
/// 表示互斥量的访问权限。
/// </summary>
class WINEXT_MODULE_EXPIMP EMutexRight
{
public:
	enum Enums
	{
		/// <summary>
		/// 允许修改状态
		/// </summary>
		ModifyState,

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