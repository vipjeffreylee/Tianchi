#ifndef JSK4QT_LOG_H
#define JSK4QT_LOG_H

#include "jsk_qglobal.h"

#include <QString>

///@file jsk_Log.h ���ļ���־�����

namespace JSK
{
class JSK_EXPORT Log4Qt
{
public:
    /**
     * ָ��ȫ·����ִ���ļ������Զ�������ִ���ļ�ͬĿ¼��ͬ�����Һ�׺Ϊ .log ����־�ļ���
     * @param [in] AppFile ִ���ļ�����
     *  @par ʾ��:
     *  @code
     QApplication app(argc, argv);

     Log4Qt log;

     // �����ִ���ļ�����Ϊ����
     log.setAppFile(app.applicationFilePath());
     *  @endcode
     *  @see setLogFile
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
/**
 * @brief JSK::Log ȫ�� Log4Qt ʵ��������Ӧ�ó�����ֱ��ʹ�á�
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
