// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// Windows �º���תƴ����
// ע�⣺�˿ⲻ֧�� Windows ����Ĳ���ϵͳ��
// =====================================================================================================================
// ����/����/ά����Ա:
// Date         Name        IM              Email               Description
// ---------------------------------------------------------------------------------------------------------------------
// 2013.04.10   Jonix Fu    QQ:23552351     jonix@qtcn.org      ����
//
// =====================================================================================================================
// Confirmation/ȷ��:
// Date         Name        OS/Compiler     Description
// ---------------------------------------------------------------------------------------------------------------------
// 2013.04.10   Jonix Fu    Win8/VC2010     ������ͨ��
//
// *********************************************************************************************************************
/// @file IMEEngine.h Windows �º���תƴ����(Windows only)
// *********************************************************************************************************************
#ifndef Tianchi_IMEEngineH
#define Tianchi_IMEEngineH
#include "tc_qglobal.h"

#include <QString>

#ifdef _WIN32
// ����ַ�ʱ��ת���в�����Ӣ�����ŵ�
TIANCHI_EXPORT QString chineseToChars(const QString& Str, bool Tonality=false);
// ȡ�ö�����ֵ�ȫƴ��
TIANCHI_EXPORT QString chineseToPinyin(const QString& Str, bool Tonality=false);
// ȡ�ö�����ֵ�����ĸ
TIANCHI_EXPORT QString firstPinyins(const QString& HzString);
// ȡ����ĸ
//wchar_t GetFirstPinyin(QString HzString);
//// ȡ����ĸ
//QString FirstPinyin(QString HzString);
#endif

#endif // Tianchi_IMEEngineH

