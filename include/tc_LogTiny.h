// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// �򵥵� Log �����
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
/// @file tc_LogTiny.h �򵥵� Log �����
// *********************************************************************************************************************
#ifndef TIANCHI_LOG_H
#define TIANCHI_LOG_H

#include "tc_qglobal.h"

#include <QString>

///@file tc_Log.h ���ļ���־�����

namespace Tianchi
{
class TIANCHI_EXPORT LogTiny
{
public:
    /**
     * ָ��ȫ·����ִ���ļ������Զ�������ִ���ļ�ͬĿ¼��ͬ�����Һ�׺Ϊ .log ����־�ļ���
     * @param [in] AppFile ִ���ļ�����
     * @par ʾ��:
     * @code
     QApplication app(argc, argv);

     LogTiny log;

     // �����ִ���ļ�����Ϊ����
     log.setAppFile(app.applicationFilePath());
     * @endcode
     * @see setLogFile
     */
    void setAppFile(const QString& AppFile);
    /**
     * ָ��ȫ·������־�ļ�����
     * @param [in] LogFile ��־�ļ�����
     * @par ʾ��:
     * @code
     log.setLogFile("C:\\Temp\\app.log");
     * @endcode
     * @see setAppFile
     */
    void setLogFile(const QString& LogFile);
    /**
     * д��־
     * @param [in] S ��־���ݡ�
     * @param [in] SourceName Դ�ļ�����������__FILE__��Ϊ������
     * @param [in] SourceLine Դ�ļ��У�������__LINE__��Ϊ������
     */
    void write(const QString& S, const QString& SourceName="", int SourceLine=0);
    /**
     * ����ģʽ(Debug)�������־���� Release ģʽ��û�����á�
     * @param [in] S ��־���ݡ�
     * @param [in] SourceName Դ�ļ�����������__FILE__��Ϊ������
     * @param [in] SourceLine Դ�ļ��У�������__LINE__��Ϊ������
     */
    inline void debug(const QString& S, const QString& SourceName="", int SourceLine=0)
    {
      #ifdef _DEBUG
        write(S, SourceName, SourceLine);
      #endif
    }

private:
    QString m_FileName;
};
};
//#define _LOG_STEP_ Tianchi::Log.write("<<STEP>>", __FILE__, __LINE__);

//#ifdef _DEBUG
//    #define Debug_Log(s)    Tianchi::Log.write(s, __FILE__, __LINE__);
//#else
//    #define Debug_Log(s)
//#endif

#endif // TIANCHI_LOG_H
