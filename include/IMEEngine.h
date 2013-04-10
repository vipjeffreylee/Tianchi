// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享资源库
// =====================================================================================================================
// Windows 下汉字转拼音库
// 注意：此库不支持 Windows 以外的操作系统。
// =====================================================================================================================
// 创建/更新/维护人员:
// Date         Name        IM              Email               Description
// ---------------------------------------------------------------------------------------------------------------------
// 2013.04.10   Jonix Fu    QQ:23552351     jonix@qtcn.org      初创
//
// =====================================================================================================================
// Confirmation/确认:
// Date         Name        OS/Compiler     Description
// ---------------------------------------------------------------------------------------------------------------------
// 2013.04.10   Jonix Fu    Win8/VC2010     仅编译通过
//
// *********************************************************************************************************************
/// @file IMEEngine.h Windows 下汉字转拼音库(Windows only)
// *********************************************************************************************************************
#ifndef Tianchi_IMEEngineH
#define Tianchi_IMEEngineH
#include "tc_qglobal.h"

#include <QString>

#ifdef _WIN32
// 混合字符时，转换中不过滤英数符号等
TIANCHI_EXPORT QString chineseToChars(const QString& Str, bool Tonality=false);
// 取得多个汉字的全拼音
TIANCHI_EXPORT QString chineseToPinyin(const QString& Str, bool Tonality=false);
// 取得多个汉字的首字母
TIANCHI_EXPORT QString firstPinyins(const QString& HzString);
// 取首字母
//wchar_t GetFirstPinyin(QString HzString);
//// 取首字母
//QString FirstPinyin(QString HzString);
#endif

#endif // Tianchi_IMEEngineH

