#pragma once

#include "Definition.h"

class WINEXT_MODULE_EXPIMP CTool
{
public:
	/// <summary>
	/// ����ָ����ϵͳ�������ȡ�����Ĵ�����Ϣ��
	/// </summary>
	/// <remarks></remarks>
	/// <param name="errorNum">[I] ָ�������롣</param>
	/// <returns>���ض�Ӧ������Ĵ�����Ϣ��</returns>
	/// <author name="hps" date="2012.6.18   15:31"/>
	static CString GetErrorMessageByNum(int errorNum);
};