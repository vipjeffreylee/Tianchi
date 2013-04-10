#include "tc_Smtp.h"

#include <QtNetwork>

Tianchi::Smtp::Smtp(const QString& host, int port)
{
    setHost(host, port);
}

void readWelcome(QTcpSocket& socket)
{
    char data[1024];
    int len;
    if ( socket.waitForReadyRead(-1) == true )
    {
        memset(data, '\0', sizeof(data));
        len = socket.readLine(data, 1024);
        qDebug() << data << endl;;
    }
}

void communication(QTcpSocket & socket, const char *msg)
{
        char data[1024];

        if (socket.write(msg, qstrlen(msg)) == -1)
                qDebug() << "@@@@@@@@@@@@@@ socket.write failed";
        socket.flush();

        if (socket.waitForReadyRead(-1) == true)
        {
            memset(data, '\0', sizeof(data));
            socket.readLine(data, 1024);
            qDebug() << data;
        }
}

void smtpCommunication(QTcpSocket & socket)
{
    communication(socket, "helo sina.com\r\n");
    communication(socket, "auth login\r\n");
    communication(socket, QByteArray("fs_sender@sina.com").toBase64()+"\r\n");
    communication(socket, QByteArray("1qazse4rfv").toBase64()+"\r\n");
    communication(socket, "mail from: <fengqing.fu@achievo.com>\r\n");
    communication(socket, "rcpt to: <fs.lanchat@gmail.com>\r\n");
    communication(socket, "data\r\n");
    communication(socket, "From: fs_sender@sina.com\r\nTo: fs.lanchat@gmail.com\r\n"
                          "Subject: QT EMAIL\r\n\r\n"
                          "QT EMail Test!"
                          "\r\n.\r\n");
    communication(socket, "quit\r\n");

    qDebug() << "send email ok." << endl;
}

bool Tianchi::Smtp::send()
{
    //bool ret = false;
    QTcpSocket socket;
    socket.connectToHost("smtp.sina.com", 25);
    if ( socket.waitForConnected(25000) )
    {
        qDebug() << "smtp server connected success.";
        readWelcome(socket);
        smtpCommunication(socket);
        socket.close();
    }else
    {
        qDebug() << "connection failed.";
    }
    return true;
}
