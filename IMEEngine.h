// ********************************************************************************************************************
// Copyright(c) 1994,1997-2007,2010-2011 By Jonix Fu (Shanghai China), all rights reserved.
// Author: Jonix Fu (huibo@online.sh.cn, fs.lanchat@gmail.com)
// Compiler: Borland/CodeGear/Embarcadero C++Builder 6.0/2007-2010
// --------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// ====================================================================================================================
#ifndef Qt_IMEEngineH
#define Qt_IMEEngineH

#include "jsk_qglobal.h"

#include <QString>

#if defined(_WIN32) || defined(__WINNT__)
// ����ַ�ʱ��ת���в�����Ӣ�����ŵ�
JSK_EXPORT QString chineseToChars(const QString& Str, bool Tonality=false);
// ȡ�ö�����ֵ�ȫƴ��
JSK_EXPORT QString chineseToPinyin(const QString& Str, bool Tonality=false);
// ȡ�ö�����ֵ�����ĸ
JSK_EXPORT QString firstPinyins(const QString& HzString);
// ȡ����ĸ
//wchar_t GetFirstPinyin(QString HzString);
//// ȡ����ĸ
//QString FirstPinyin(QString HzString);
#endif

#endif // Qt_IMEEngineH

