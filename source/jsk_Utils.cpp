#include "jsk_Utils.h"

#include <QTextStream>
#include <QTextCodec>
#include <QDateTime>
#include <QFileInfo>
#include <QDir>

#include <QSettings>

#if defined(__WIN32__) || defined(_WIN32)
  #include <windows.h>
#endif

#include <QMessageBox>

#include <iostream>
using namespace std;

QString JSK::GetOSName()
{
    QString ret;
  #if defined(__WIN32__) || defined(_WIN32)
    const QString RegPath = "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows NT\\CurrentVersion";
    QSettings reg(RegPath, QSettings::NativeFormat);
    ret = reg.value("ProductName").toString();
  #endif
    return ret;
}

QString JSK::GetOSLanguage()
{
    QString ret;
  #if defined(__WIN32__) || defined(_WIN32)
    LANGID  LangID = GetSystemDefaultLangID();
    wchar_t LanguageName[100];
    VerLanguageName(LangID, LanguageName, 100);
    ret = QString::fromWCharArray(LanguageName);
  #endif
    return ret;
}

QString JSK::GetFileVersion(const QString& exeFile)
{
    QString ret = "";

  #if defined(__WIN32__) || defined(_WIN32)
    int size = GetFileVersionInfoSize(exeFile.toStdWString().c_str(), NULL);
    if ( size >0 )
    {
        char* data = new char[size +1];
        if ( GetFileVersionInfo(exeFile.toStdWString().c_str(), 0, size, data) )
        {
            VS_FIXEDFILEINFO* fileInfo;
            unsigned int      fileInfoSize = 0;
            if ( VerQueryValue(data, L"\\", (void**)&fileInfo, &fileInfoSize) )
            {
                int vMajor  = HIWORD(fileInfo->dwFileVersionMS);
                int vMinor  = LOWORD(fileInfo->dwFileVersionMS);
                int Release = HIWORD(fileInfo->dwFileVersionLS);
                int vBuild  = LOWORD(fileInfo->dwFileVersionLS);
                ret.append(QString::number(vMajor)).append(".")
                        .append(QString::number(vMinor)).append(".")
                        .append(QString::number(Release)).append(".")
                        .append(QString::number(vBuild));
            }
        }
        delete data;
    }
  #endif
    return ret;
}

bool JSK::UserLogin(const QString& Domain, const QString& UserID, const QString& Password)
{
    bool ret = false;
  #if defined(__WIN32__) || defined(_WIN32)
    wchar_t* domain = new wchar_t[Domain.length()+1];
    wmemset(domain, L'\0', sizeof(domain));
    Domain.toWCharArray(domain);

    wchar_t* userID = new wchar_t[UserID.length()+1];
    wmemset(userID, L'\0', sizeof(userID));
    UserID.toWCharArray(userID);

    wchar_t* password = new wchar_t[Password.length()+1];
    wmemset(password, L'\0', sizeof(password));
    Password.toWCharArray(password);

    HANDLE hUser;
    ret = LogonUser(userID,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &hUser);
    delete domain;
    delete userID;
    delete password;
  #endif
    return ret;
}

QHash<QString, QString> JSK::StringToMap(const QString& mapStrings)
{
    QStringList strings = mapStrings.split("\n", QString::SkipEmptyParts);

    return JSK::StringToMap(strings);
}

QHash<QString, QString> JSK::StringToMap(const QStringList& mapStrings)
{
    QHash<QString, QString> ret;

    foreach(QString s, mapStrings)
    {
        QString key;
        QString value;
        int pos = s.indexOf("=");
        if ( pos >= 0 )
        {
            key = s.mid(0, pos).trimmed();
            value = s.mid(pos+1).trimmed();
            if ( ! key.isEmpty() && ! value.isEmpty() )
            {
                ret[key] = value;
            }
        }
    }
    return ret;
}

QString JSK::NowText()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");
}

QString JSK::NowText2()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
}

char JSK::getIDCardVerifyCode(const QByteArray& id)
{
    char ret = '\0';
    if ( id.length() >= 17 )
    {
        // 加权乘积求和除以11的余数所对应的校验数
        const char verifyMap[] = "10X98765432";
        // 加权因子
        const int factor[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1 };

        int Sum = 0;  //加权乘积求和
        for( int i=0;i<17;i++ )
        {
            char c = id[i];

            Sum += (c-'0') * factor[i]; // 加权乘积求和
        }
        ret = verifyMap[Sum % 11]; // 取模
    }
    return ret;
}

QDateTime JSK::DateTimefrom(const QString& s)
{
    QString str = s.trimmed();

    int year    = 1899;
    int month   =   12;
    int day     =   30;
    int hour    =    0;
    int minute  =    0;
    int second  =    0;
    int msecond =    0;
    switch(str.length())
    {
    case 23:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 5, 2).toInt();
        day     = str.mid( 8, 2).toInt();
        hour    = str.mid(11, 2).toInt();
        minute  = str.mid(14, 2).toInt();
        second  = str.mid(17, 2).toInt();
        msecond = str.mid(20, 3).toInt();
        break;
    case 19:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 5, 2).toInt();
        day     = str.mid( 8, 2).toInt();
        hour    = str.mid(11, 2).toInt();
        minute  = str.mid(14, 2).toInt();
        second  = str.mid(17, 2).toInt();
        break;
    case 14:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 4, 2).toInt();
        day     = str.mid( 6, 2).toInt();
        hour    = str.mid( 8, 2).toInt();
        minute  = str.mid(10, 2).toInt();
        second  = str.mid(12, 2).toInt();
        break;
    case 10:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 5, 2).toInt();
        day     = str.mid( 8, 2).toInt();
        break;
    case 8:
        hour    = str.mid(0, 2).toInt();
        minute  = str.mid(3, 2).toInt();
        second  = str.mid(6, 2).toInt();
        break;
    }
    return QDateTime(QDate(year, month, day), QTime(hour, minute, second, msecond));
}

char JSK::typeFrom(QVariant::Type type)
{
    char c = '\0';
    if ( type == QVariant::Int
      || type == QVariant::UInt
      || type == QVariant::LongLong
      || type == QVariant::ULongLong )
    {
        c = 'i';
    }else
    if ( type == QVariant::Double )
    {
        c = 'n';
    }else
    if ( type == QVariant::String )
    {
        c = 's';
    }else
    if ( type == QVariant::Date
      || type == QVariant::Time
      || type == QVariant::DateTime )
    {
        c = 't';
    }else
    if ( type == QVariant::Date
      || type == QVariant::Time
      || type == QVariant::DateTime )
    {
        c = 't';
    }else
    if ( type == QVariant::ByteArray )
    {
         c = 'm';
    }else
    {

    }
    return c;
}

QHash<QString, QByteArray> JSK::getFields(const QByteArray& fieldBytes)
{
    QHash<QString, QByteArray>  ret;

    int pos1 = 0;
    int pos2 = fieldBytes.indexOf('\0');
    while(pos2>=0)
    {
        QString key = fieldBytes.mid(pos1, pos2);
        pos1 = fieldBytes.indexOf('\0', ++pos2);
        QString type = fieldBytes.mid(pos2, pos1-pos2);
        pos2 = fieldBytes.indexOf('\0', ++pos1);
        int len = fieldBytes.mid(pos1, pos2-pos1).toInt();
        QByteArray value = fieldBytes.mid(++pos2, len);
        pos1 = pos2+len;
        ret[key] = value;
        pos2 = fieldBytes.indexOf('\0', pos1);
    }
    return ret;
}

int JSK::find(const QStringList& ss, const QString& s)
{
    int ret = -1;
    for( int i=0;i<ss.count();i++ )
    {
        if ( ss.at(i).compare(s) == 0 )
        {
            ret = i;
            break;
        }
    }
    return ret;
}

QString JSK::uniqueFileName(const QString& dir, const QString& fileTemplate, const QString& suffix)
{
    QString fileDir    = dir;
    QString filePrefix = fileTemplate;
    QString fileSuffix = suffix;

    QFileInfo f;
    if ( fileDir == "" )
    {
        f.setFile(fileTemplate);
        fileDir    = f.absoluteDir().absolutePath();
        fileSuffix = f.suffix();
        if ( ! fileSuffix.isEmpty() )
        {
            filePrefix = filePrefix.mid(0, filePrefix.length()-fileSuffix.length()-1);
        }
    }
    if ( fileSuffix == "" )
    {
        f.setFile(fileTemplate);
        fileSuffix = f.suffix();
        if ( ! fileSuffix.isEmpty() )
        {
            filePrefix = filePrefix.mid(0, filePrefix.length()-fileSuffix.length()-1);
        }
    }
    QString ret = fileDir + QDir::separator() + filePrefix + "." + fileSuffix;
    f.setFile(ret);
    int index = 2;
    while(f.exists())
    {
        ret = fileDir + QDir::separator() + filePrefix + "("+QString::number(index++)+")."+fileSuffix;
        f.setFile(ret);
    }
    return ret;
}

int JSK::findOf(const QStringList& list, const QString& key)
{
    int ret = -1;
    for( int i=0;i<list.count();i++ )
    {
        if ( list.at(i).trimmed().compare(key.trimmed(), Qt::CaseInsensitive)==0 )
        {
            ret = i;
            break;
        }
    }
    return ret;
}

bool JSK::filter(const QString& text, const QStringList& filters)
{
    bool ret = filters.count() <= 0;
    foreach(QString s, filters)
    {
        s = s.trimmed();
        if ( ! s.isEmpty() )
        {
            if ( text.indexOf(s, Qt::CaseInsensitive) >= 0 )
            {
                ret = true;
                break;
            }
        }
    }
    return ret;
}

QDateTime JSK::GetComplieDateTime()
{
    QString DateString = __DATE__;
    QString Year  = DateString.right(4);
    QString Month = DateString.left(3).toUpper();
    QString Day   = DateString.mid(4, 2);
    QString TimeString = __TIME__;
    QString Hour   = TimeString.left(2);
    QString Minute = TimeString.mid(3, 2);
    QString Second = TimeString.right(2);
    const QString MonthString[12] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                                      "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    unsigned int MonthValue;
    for( MonthValue=0;MonthValue<sizeof(MonthString);MonthValue++ )
    {
        if ( Month == MonthString[MonthValue] )
        {
            MonthValue++;
            break;
        }
    }
    return QDateTime(QDate(Year.toInt(), MonthValue, Day.toInt()),
                     QTime(Hour.toInt(), Minute.toInt(), Second.toInt()));
}

QDateTime JSK::toDateTime(const QString& text)
{
    QDateTime ret = QDateTime();
    switch(text.length())
    {
    case 23:
        ret.fromString(text, "yyyy-MM-dd HH:mm:ss.zzz");
        break;
    case 19:
        ret.fromString(text, "yyyy-MM-dd HH:mm:ss");
        break;
    case 16:
        ret.fromString(text, "yyyy-MM-dd HH:mm");
        break;
    case 14:
        ret.fromString(text, "yyyyMMddHHmmss");
        break;
    case 10:
        ret.fromString(text, "yyyy-MM-dd");
        break;
    case  8:
        ret.fromString(text, "HH:mm:ss");
        break;
    case  7:
        ret.fromString(text, "yyyy/MM");
        break;
    case  5:
        if ( text.at(2) == '/'
          || text.at(2) == '-' )
        {
            ret.fromString(text, "MM/dd");
        }else
        if ( text.at(2) == ':' )
        {
            ret.fromString(text, "HH:mm");
        }
        break;
    case  4:
        ret.fromString(text, "yyyy");
        break;
    }
    return ret;
}

/// 分解姓名（单、复姓、英文）
int JSK::splitHumanName(QString full, QString& sur, QString& real, QString& english)
{
    QString surs = QTextCodec::codecForLocale()->toUnicode(
                               "欧阳\n太史\n端木\n上官\n司马\n东方\n独孤\n南宫\n万俟\n"
                               "闻人\n夏侯\n诸葛\n尉迟\n公羊\n赫连\n澹台\n皇甫\n宗政\n"
                               "濮阳\n公冶\n太叔\n申屠\n公孙\n慕容\n仲孙\n钟离\n长孙\n"
                               "宇文\n司徒\n鲜于\n司空\n闾丘\n子车\n亓官\n司寇\n巫马\n"
                               "公西\n颛孙\n壤驷\n公良\n漆雕\n乐正\n宰父\n谷梁\n拓跋\n"
                               "夹谷\n轩辕\n令狐\n段干\n百里\n呼延\n东郭\n南门\n羊舌\n"
                               "微生\n公户\n公玉\n公仪\n梁丘\n公仲\n公上\n公门\n公山\n"
                               "公坚\n左丘\n公伯\n西门\n公祖\n第五\n公乘\n贯丘\n公皙\n"
                               "南荣\n东里\n东宫\n仲长\n子书\n子桑\n即墨\n达奚\n褚师\n");
    QStringList doubleSurnames = surs.split("\n");

    full = full.trimmed();

    int ret = 0;
    if ( ! full.isEmpty() )
    {
        if ( full.length() != full.toLocal8Bit().length() )
        {// 汉字
            foreach(QString s, doubleSurnames)
            {
                if ( ! s.isEmpty() && full.startsWith(s) )
                {
                    sur = s;
                    ret = 2;
                    break;
                }
            }
            if ( ret != 2 )
            {
                sur = full.mid(0, 1);
                ret = 1;
            }
            real = full.mid(sur.length());
        }else
        {// 英文名
            QStringList ss = full.split(" ", QString::SkipEmptyParts);
            english = "";
            for( int i=0;i<ss.count();i++ )
            {
                QString t = ss.at(i);
                if ( i == ss.count()-1 )
                {
                    sur = t;
                }else
                {
                    english += t + " ";
                }
            }
            english = english.trimmed();

            ret = 3;
        }
    }
    return ret;
}

QString JSK::getTextByIndex(const char* strings, int index)
{
    QStringList ss = QTextCodec::codecForLocale()->toUnicode(strings).split("\n", QString::SkipEmptyParts);
    return ss.at(index);
}
bool JSK::loadFromFile(QString& context, const QString& filename)
{
    bool ret = false;
    QFile file(filename);
    if ( file.open(QIODevice::ReadOnly) )
    {
       QTextStream in(&file);
       context = in.readAll();
       ret = true;
       file.close();
    }
    return ret;
}
// ---------------------------------------------------------------------------------------------------------------------

