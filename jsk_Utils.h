// =====================================================================================================================
// JSK Share library for Qt5
//    Frame: Qt5.0.1
// Compiler: VC2010
// ---------------------------------------------------------------------------------------------------------------------
//  Date       Author   Description
//  2013.03.27 齐天小圣   初版
// =====================================================================================================================

#ifndef JSK4QT_UTILS_H
#define JSK4QT_UTILS_H

#include "jsk_qglobal.h"

#include <QTextCodec>
#include <QMessageBox>
#include <QVariant>

#include <QDateTime>

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QtWidgets/QComboBox>

#include <QThread>

#include <iostream>
using namespace std;

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

namespace JSK
{
namespace OperMode
{
const int Append = 1; // 添加或新建
const int Change = 2; // 修改
const int Delete = 4; // 删除
};

// 取操作系统名称，仅支持 Windows
JSK_EXPORT QString GetOSName();
// 取操作系统的语言，仅支持 Windows
JSK_EXPORT QString GetOSLanguage();
// 取执行文件的版本，仅支持 Windows
JSK_EXPORT QString GetFileVersion(const QString& exeFile);
// Windows 域用户登录，仅支持 Windows
JSK_EXPORT bool UserLogin(const QString& Domain, const QString& UserID, const QString& Password);

// 把 k/v 结构的文本转换为 map 结构
JSK_EXPORT QHash<QString, QString> StringToMap(const QString& mapStrings);
JSK_EXPORT QHash<QString, QString> StringToMap(const QStringList& mapStrings);
// 返回当前时间字符串：yyyy-MM-dd HH:mm:ss.zzz
JSK_EXPORT QString NowText();
// 返回当前时间字符串：yyyy-MM-dd HH:mm:ss
JSK_EXPORT QString NowText2();

// 返回18位身位证的最后一位校验码
JSK_EXPORT char getIDCardVerifyCode(const QByteArray& id);

// 转换字符串为日期时间
JSK_EXPORT QDateTime DateTimefrom(const QString& s);

JSK_EXPORT char        typeFrom(QVariant::Type type);
inline char typeFrom(const QVariant& v)
{
    return typeFrom(v.type());
}
inline void addField(QByteArray& fieldBytes, const QString& name, const QVariant& value)
{
    QByteArray bytes = value.toByteArray();
    fieldBytes.append(name).append('\0')
            .append(JSK::typeFrom(value.type())).append('\0')
            .append(QByteArray::number(bytes.length())).append('\0')
            .append(bytes);
}
JSK_EXPORT QHash<QString, QByteArray> getFields(const QByteArray& fieldBytes);

JSK_EXPORT int find(const QStringList& ss, const QString& s);

JSK_EXPORT QString uniqueFileName(const QString& dir, const QString& fileTemplate, const QString& suffix="");

JSK_EXPORT int findOf(const QStringList& list, const QString& key);

JSK_EXPORT bool filter(const QString& text, const QStringList& filters);

JSK_EXPORT QDateTime GetComplieDateTime();

JSK_EXPORT QDateTime toDateTime(const QString& text);
JSK_EXPORT int       splitHumanName(QString full, QString& sur, QString& real, QString& english);
JSK_EXPORT QString   getTextByIndex(const char* strings, int index);
JSK_EXPORT bool      loadFromFile(QString& context, const QString& filename);

}; // namespace JSK;

class JSK_EXPORT DBFields
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


// 字符集转换
inline QString QS(const char* s)
{
    return QTextCodec::codecForLocale()->toUnicode(s);
}
// 显示文本对话框
inline void MsgBox(const QString& s)
{
    QMessageBox::information(NULL, "", s);
}
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


#endif // JSK4QT_UTILS_H
