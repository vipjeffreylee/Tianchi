// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// ���ù��ܺ���
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
/// @file tc_Utils.h ���ù��ܺ���
// *********************************************************************************************************************
#ifndef TIANCHI_UTILS_H
#define TIANCHI_UTILS_H

#include "tc_qglobal.h"

#ifdef QT_WIDGETS_LIB
    #include <QMessageBox>
#endif

#include <QTextCodec>
#include <QVariant>

#include <QDateTime>

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QComboBox>

#include <QThread>

#include <iostream>
using namespace std;

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

namespace Tianchi
{
namespace OperMode
{
const int Append = 1; // ��ӻ��½�
const int Change = 2; // �޸�
const int Delete = 4; // ɾ��
};

// ȡ����ϵͳ���ƣ���֧�� Windows
TIANCHI_EXPORT QString GetOSName();
// ȡ����ϵͳ�����ԣ���֧�� Windows
TIANCHI_EXPORT QString GetOSLanguage();
// ȡִ���ļ��İ汾����֧�� Windows
TIANCHI_EXPORT QString GetFileVersion(const QString& exeFile);
// Windows ���û���¼����֧�� Windows
TIANCHI_EXPORT bool UserLogin(const QString& Domain, const QString& UserID, const QString& Password);

// �� k/v �ṹ���ı�ת��Ϊ map �ṹ
TIANCHI_EXPORT QHash<QString, QString> StringToMap(const QString& mapStrings);
TIANCHI_EXPORT QHash<QString, QString> StringToMap(const QStringList& mapStrings);
// ���ص�ǰʱ���ַ�����yyyy-MM-dd HH:mm:ss.zzz
TIANCHI_EXPORT QString NowText();
// ���ص�ǰʱ���ַ�����yyyy-MM-dd HH:mm:ss
TIANCHI_EXPORT QString NowText2();

// ����18λ��λ֤�����һλУ����
TIANCHI_EXPORT char getIDCardVerifyCode(const QByteArray& id);

// ת���ַ���Ϊ����ʱ��
TIANCHI_EXPORT QDateTime DateTimefrom(const QString& s);

TIANCHI_EXPORT char        typeFrom(QVariant::Type type);
inline char typeFrom(const QVariant& v)
{
    return typeFrom(v.type());
}
inline void addField(QByteArray& fieldBytes, const QString& name, const QVariant& value)
{
    QByteArray bytes = value.toByteArray();
    fieldBytes.append(name).append('\0')
            .append(Tianchi::typeFrom(value.type())).append('\0')
            .append(QByteArray::number(bytes.length())).append('\0')
            .append(bytes);
}
TIANCHI_EXPORT QHash<QString, QByteArray> getFields(const QByteArray& fieldBytes);

TIANCHI_EXPORT int find(const QStringList& ss, const QString& s);

TIANCHI_EXPORT QString uniqueFileName(const QString& dir, const QString& fileTemplate, const QString& suffix="");

TIANCHI_EXPORT int findOf(const QStringList& list, const QString& key);

TIANCHI_EXPORT bool filter(const QString& text, const QStringList& filters);

TIANCHI_EXPORT QDateTime GetComplieDateTime();

TIANCHI_EXPORT QDateTime toDateTime(const QString& text);
TIANCHI_EXPORT int       splitHumanName(QString full, QString& sur, QString& real, QString& english);
TIANCHI_EXPORT QString   getTextByIndex(const char* strings, int index);
TIANCHI_EXPORT bool      loadFromFile(QString& context, const QString& filename);

}; // namespace Tianchi;

class TIANCHI_EXPORT DBFields
{
public:
    DBFields() {}
    inline DBFields(QHash<QString, QByteArray> fields)
                    { setFields(fields); }

    void    setFields(QHash<QString, QByteArray> fields)
    {
        m_fields.clear();
        m_keys.clear();

        m_fields = fields;
        m_keys = m_fields.keys();
    }
    inline QByteArray value(const QString& key) const
    {
        return m_fields.value(key.trimmed().toLower());
    }

private:
    QHash<QString, QByteArray>  m_fields;
    QStringList m_keys;
};


// �ַ���ת��
inline QString QS(const char* s)
{
    return QTextCodec::codecForLocale()->toUnicode(s);
}

#ifdef QT_WIDGETS_LIB
// ��ʾ�ı��Ի���
inline void MsgBox(const QString& s)
{
    QMessageBox::information(NULL, "", s);
}
#endif

inline int     iif(bool logic, int v1, int v2=0) { return logic ? v1 : v2; }
inline QString iif(bool logic, const QString& v1, const QString& v2="") { return logic ? v1 : v2; }

inline void printLocal(const char* file, int line, const QString& text="")
{
    cout<<QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss->").toLocal8Bit().data()<<file<<"("<<line<<"): "<<text.toLocal8Bit().data()<<endl;
}
inline void printLocal(const char* file, int line, int v)
{
    printLocal(file, line, QString::number(v));
}

#define PRINT_STEP     printLocal(__FILE__, __LINE__);
#define PRINT_TEXT(x)  printLocal(__FILE__, __LINE__, x);


#endif // TIANCHI_UTILS_H
