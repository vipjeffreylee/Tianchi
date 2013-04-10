#include <QCoreApplication>
#include <tianchi.h>
#include <qDebug>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec*pCodec=QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(pCodec);

    qDebug()<<QTextCodec::codecForLocale()->toUnicode("�й�");
    qDebug()<<chineseToPinyin(QTextCodec::codecForLocale()->toUnicode("�й�"));
    qDebug()<<"end of China.";

    return a.exec();
}
