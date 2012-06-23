#pragma once

#include "Definition.h"

class WINEXT_MODULE_EXPIMP CTool
{
public:
	/// <summary>
	/// 根据指定的系统错误码获取关联的错误信息。
	/// </summary>
	/// <remarks></remarks>
	/// <param name="errorNum">[I] 指定错误码。</param>
	/// <returns>返回对应错误码的错误信息。</returns>
	/// <author name="hps" date="2012.6.18   15:31"/>
	static CString GetErrorMessageByNum(int errorNum);
};