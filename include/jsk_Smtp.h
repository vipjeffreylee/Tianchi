#ifndef JSK_SMTP_H
#define JSK_SMTP_H

#include "jsk_qglobal.h"

#include <QString>

namespace JSK
{
class Q_DECL_EXPORT Smtp
{
public:
    Smtp(const QString& host="", int port=25);

private:
    QString m_Host;
    int     m_Port;

public:
    inline void setHost(const QString& host, int port=25)
    {
        m_Host = host;
        m_Port = port;
    }

    bool send();
};
};

#endif // JSK_SMTP_H
