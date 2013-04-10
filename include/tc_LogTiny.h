// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享资源库
// =====================================================================================================================
// 简单的 Log 输出类
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
/// @file tc_LogTiny.h 简单的 Log 输出类
// *********************************************************************************************************************
#ifndef TIANCHI_LOG_H
#define TIANCHI_LOG_H

#include "tc_qglobal.h"

#include <QString>

///@file tc_Log.h 简单文件日志输出类

namespace Tianchi
{
class TIANCHI_EXPORT LogTiny
{
public:
    /**
     * 指定全路径的执行文件名，自动设置与执行文件同目录、同名，且后缀为 .log 的日志文件。
     * @param [in] AppFile 执行文件名。
     * @par 示例:
     * @code
     QApplication app(argc, argv);

     LogTiny log;

     // 建议把执行文件名作为参数
     log.setAppFile(app.applicationFilePath());
     * @endcode
     * @see setLogFile
     */
    void setAppFile(const QString& AppFile);
    /**
     * 指定全路径的日志文件名。
     * @param [in] LogFile 日志文件名。
     * @par 示例:
     * @code
     log.setLogFile("C:\\Temp\\app.log");
     * @endcode
     * @see setAppFile
     */
    void setLogFile(const QString& LogFile);
    /**
     * 写日志
     * @param [in] S 日志内容。
     * @param [in] SourceName 源文件名，建议用__FILE__作为参数。
     * @param [in] SourceLine 源文件行，建议用__LINE__作为参数。
     */
    void write(const QString& S, const QString& SourceName="", int SourceLine=0);
    /**
     * 调试模式(Debug)下输出日志，在 Release 模式下没有作用。
     * @param [in] S 日志内容。
     * @param [in] SourceName 源文件名，建议用__FILE__作为参数。
     * @param [in] SourceLine 源文件行，建议用__LINE__作为参数。
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
