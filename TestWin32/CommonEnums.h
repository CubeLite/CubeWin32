#pragma once

#include "Definition.h"

/// <summary>
/// 表示继承型。
/// </summary>
class WINEXT_MODULE_EXPIMP EInherit
{
public:
	enum Enums
	{
		/// <summary>
		/// 允许继承
		/// </summary>
		Yes,

		/// <summary>
		/// 不允许继承
		/// </summary>
		No
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


/// <summary>
/// 表示 CXXX::CopyFrom(...) 的选项。
/// </summary>
class WINEXT_MODULE_EXPIMP ECopyOption
{
public:
	enum Enums
	{
		/// <summary>
		/// 不使用选项
		/// </summary>
		None,

		/// <summary>
		/// 复制后的核心对象和源核心对象具有通用的访问权限
		/// </summary>
		AsSameAccess,

		/// <summary>
		/// 复制以后关闭源对象
		/// </summary>
		CloseSource
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