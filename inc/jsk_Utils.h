#ifndef UTILS_H
#define UTILS_H

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

namespace JSK
{
namespace OperMode
{
const int Append = 1; // 添加
const int Change = 2; // 修改
const int Delete = 4; // 删除
};

// 取操作系统名称，仅支持 Windows
QString GetOSName();
// 取操作系统的语言，仅支持 Windows
QString GetOSLanguage();
// 取执行文件的版本，仅支持 Windows
QString GetFileVersion(const QString& exeFile);
// Windows 域用户登录，仅支持 Windows
bool UserLogin(const QString& Domain, const QString& UserID, const QString& Password);

// 把 k/v 结构的文本转换为 map 结构
QHash<QString, QString> StringToMap(const QString& mapStrings);
QHash<QString, QString> StringToMap(const QStringList& mapStrings);
// 返回当前时间字符串：yyyy-MM-dd HH:mm:ss.zzz
QString NowText();
// 返回当前时间字符串：yyyy-MM-dd HH:mm:ss
QString NowText2();

// 返回18位身位证的最后一位校验码
char getIDCardVerifyCode(const QByteArray& id);

// 转换字符串为日期时间
QDateTime DateTimefrom(const QString& s);

char        typeFrom(QVariant::Type type);
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
QHash<QString, QByteArray> getFields(const QByteArray& fieldBytes);

int find(const QStringList& ss, const QString& s);

QString uniqueFileName(const QString& dir, const QString& fileTemplate, const QString& suffix="");

int findOf(const QStringList& list, const QString& key);

bool filter(const QString& text, const QStringList& filters);

QDateTime GetComplieDateTime();

QDateTime   toDateTime(const QString& text);
int         splitHumanName(QString full, QString& sur, QString& real, QString& english);
QString     getTextByIndex(const char* strings, int index);
bool        loadFromFile(QString& context, const QString& filename);

}; // namespace JSK;

inline int     iif(bool logic, int v1, int v2=0) { return logic ? v1 : v2; }
inline QString iif(bool logic, const QString& v1, const QString& v2="") { return logic ? v1 : v2; }

class DBFields
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


#endif // UTILS_H
