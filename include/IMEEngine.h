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
// 混合字符时，转换中不过滤英数符号等
JSK_EXPORT QString chineseToChars(const QString& Str, bool Tonality=false);
// 取得多个汉字的全拼音
JSK_EXPORT QString chineseToPinyin(const QString& Str, bool Tonality=false);
// 取得多个汉字的首字母
JSK_EXPORT QString firstPinyins(const QString& HzString);
// 取首字母
//wchar_t GetFirstPinyin(QString HzString);
//// 取首字母
//QString FirstPinyin(QString HzString);
#endif

#endif // Qt_IMEEngineH

