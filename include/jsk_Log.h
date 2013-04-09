#ifndef JSK4QT_LOG_H
#define JSK4QT_LOG_H

#include "jsk_qglobal.h"

#include <QString>

///@file jsk_Log.h 简单文件日志输出类

namespace JSK
{
class JSK_EXPORT Log4Qt
{
public:
    /**
     * 指定全路径的执行文件名，自动设置与执行文件同目录、同名，且后缀为 .log 的日志文件。
     * @param [in] AppFile 执行文件名。
     *  @par 示例:
     *  @code
     QApplication app(argc, argv);

     Log4Qt log;

     // 建议把执行文件名作为参数
     log.setAppFile(app.applicationFilePath());
     *  @endcode
     *  @see setLogFile
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
/**
 * @brief JSK::Log 全局 Log4Qt 实例，可在应用程序中直接使用。
 */
extern Log4Qt Log;
};
#define _LOG_STEP_ JSK::Log.write("<<STEP>>", __FILE__, __LINE__);

#ifdef _DEBUG
    #define Debug_Log(s)    JSK::Log.write(s, __FILE__, __LINE__);
#else
    #define Debug_Log(s)
#endif

#endif // JSK4QT_LOG_H
