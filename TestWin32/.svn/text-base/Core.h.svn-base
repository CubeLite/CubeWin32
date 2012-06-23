#pragma once

#include "Definition.h"

/// <summary>
/// 提供一组方法，用于封装句柄的通用操作。
/// </summary>
class WINEXT_MODULE_EXPIMP Core
{
protected:
	/// <summary>
	/// 实际的内核对象的句柄。
	/// </summary>
	HANDLE mHandle;

protected:
	/// <summary>
	/// 初始化一个无效的内核句柄。
	/// </summary>
	/// <remarks></remarks>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   12:15"/>
	Core();

	/// <summary>
	/// 使用系统的 HANDLE 初始化一个内核对象。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="handle">[I] 输入内核对象的句柄。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:27"/>
	Core(HANDLE handle);

	/// <summary>
	/// 将包含句柄信息的字符串解析为句柄。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="strHandle">[I] 输入包含句柄信息的字符串。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:28"/>
	Core(const CString &strHandle);

	/// <summary>
	/// 复制内核对象的句柄，指向同一个内核对象。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="src">[I] 输入要拷贝的内核对象句柄。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:28"/>
	Core(const Core& src);

	/// <summary>
	/// 赋值运算符
	/// </summary>
	/// <remarks></remarks>
	/// <param name="src">[I] 输入要拷贝的内核对象句柄。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:29"/>
	virtual Core& operator = (const Core& src);
	
	
public:
	/// <summary>
	/// 将包含核心对象句柄的字符串解析为核心对象的指针。
	/// </summary>
	/// <remarks>该方法无法确定具体的核心对象的类型。</remarks>
	/// <param name="strHandle">[I] 输入包含核心对象句柄的字符串。</param>
	/// <returns>若解析成功，则返回核心对象的指针，否则返回 NULL。</returns>
	/// <author name="hps" date="2012.6.22   13:01"/>
	static Core* Parse(const CString &strHandle);

	/// <summary>
	/// 释放在堆上分配的核心对象句柄的资源。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="pCore">[I] 指定要释放资源的核心对象句柄的指针。</param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   13:02"/>
	static void Dispose(Core *&pCore);
	
	/// <summary>
	/// 析构函数
	/// </summary>
	/// <remarks></remarks>
	/// <param name=""></param>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.22   1:30"/>
	~Core(void);

	/// <summary>
	/// 关闭内核对象。
	/// </summary>
	/// <remarks></remarks>
	/// <returns></returns>
	/// <author name="hps" date="2012.6.18   15:05"/>
	virtual void Close();

	/// <summary>
	/// 打开或关闭指定句柄的可继承性。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="isInherit">[I] true 则打开句柄的继承性；false 则关闭句柄的继承性。</param>
	/// <returns>若执行成功，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:06"/>
	bool SetInherit(bool isInherit);

	/// <summary>
	/// 获取一个值，指示句柄是否具有可继承性。
	/// </summary>
	/// <remarks></remarks>
	/// <returns>若句柄具有可继承性，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:08"/>
	bool IsInherit();

	/// <summary>
	/// 设置句柄是否不能被关闭。
	/// </summary>
	/// <remarks>若调用：SetStopClose(true); 后再调用 Core.Close(); 将会引发异常。</remarks>
	/// <param name="isStopClose">[I] true 表示指定的句柄不能被关闭；false 则取消不能被关闭的限制。</param>
	/// <returns>若执行成功，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:09"/>
	bool SetStopClose(bool isStopClose);

	/// <summary>
	/// 获取一个值，指示句柄是否是不能被关闭。
	/// </summary>
	/// <remarks></remarks>
	/// <returns>若指定的句柄不能被关闭，则返回 true；否则返回 false。</returns>
	/// <author name="hps" date="2012.6.18   15:21"/>
	bool IsStopClose();

	/// <summary>
	/// 将句柄转换为字符串形式。
	/// </summary>
	/// <remarks></remarks>
	/// <returns>返回转换后的字符串。</returns>
	/// <author name="hps" date="2012.6.18   15:33"/>
	virtual CString ToString();
};