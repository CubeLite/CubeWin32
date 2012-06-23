#pragma once

#include "Definition.h"

class WINEXT_MODULE_EXPIMP CEnvironment
{
public:
	/// <summary>
	/// 在线程所在的进程设置指定环境变量的值。
	/// </summary>
	/// <remarks>若指定的环境变量的键在当前进程的环境变量中不存在，则会新增加一个环境变量。</remarks>
	/// <param name="key">[I] 指定环境变量的名称。</param>
	/// <param name="value">[I] 指定环境变量的值。</param>
	/// <returns>若设置成功，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:26"/>
	static bool SetVariable(const CString &key, const CString &value);

	/// <summary>
	/// 获取指定键名的环境变量的值。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="key">[I] 指定要获取值的环境变量的键名。</param>
	/// <returns>返回对应的键名的环境变量的值。</returns>
	/// <author name="hps" date="2012.6.18   15:28"/>
	static CString GetVariable(const CString &key);

	/// <summary>
	/// 从当前线程所在的进程环境变量中清除指定键名的环境变量。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="key">[I] 指定要清除的环境变量的键名。</param>
	/// <returns>若执行成功，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:29"/>
	static bool ClearVariable(const CString &key);
};