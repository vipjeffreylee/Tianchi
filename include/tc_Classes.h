// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享资源库
// =====================================================================================================================
// 一些常用的小类
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
/// @file tc_Classes.h 一些常用的小类
// *********************************************************************************************************************
#ifndef TIANCHI_CLASSES_H
#define TIANCHI_CLASSES_H

#include "tc_qglobal.h"

#ifdef QT_WIDGETS_LIB
    #include <QWidget>
    #include <QCursor>
#endif

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QElapsedTimer>
#include <QHash>

namespace Tianchi
{
#if defined(TIANCHI_LIBRARY)
    class Q_DECL_EXPORT Player : public QObject
#else
    class Player : public QObject
#endif
{
    Q_OBJECT

    Q_PROPERTY(int       userNo    READ userNo    WRITE setUserNo   )
    Q_PROPERTY(QString   userID    READ userID    WRITE setUserID   )
    Q_PROPERTY(QString   username  READ username  WRITE setUsername )
    Q_PROPERTY(bool      loggedIn  READ loggedIn  WRITE setLoggedIn )
    Q_PROPERTY(QDateTime loginTime READ loginTime WRITE setLoginTime)

public:
    /** 用户权限 */
    typedef enum AuthLevel
    {
        AUTH_SYSADMIN = 999,  /**< 最高系统级管理员权限 */
        AUTH_ADMIN    = 888,  /**< 最高用户级管理员权限 */
        AUTH_MANAGER  =  99,  /**< 用户级：管理权限    */
        AUTH_USER     =   9,  /**< 用户级：普通用户权限 */
        AUTH_GUEST    =   1,  /**< 用户级：访客级权限   */
    };


    Player();
    Player &operator=(const Player&);

    inline int          userNo() const { return m_userNo; }
    inline void         setUserNo(int value) { m_userNo = value; }
    inline QString      userID() const { return m_userID; }
    inline void         setUserID(const QString& value) { m_userID = value.trimmed(); }
    inline QString      username() const { return m_username; }
    inline void         setUsername(const QString& value) { m_username = value.trimmed(); }
    inline int          userLevel() const { return m_userLevel; }
    inline void         setUserLevel(int value) { m_userLevel = value; }

    int                 authority(const QString& key) const;
    inline void         setAuthority(const QString& key, int auth) { m_authority[key] = auth; }
    void                setAuthorityText(const QString& value);
    void                setAuthorityText(const QStringList& value);

    inline QString      loginID() const { return m_loginID; }
    inline void         setLoginID(const QString& value) { m_loginID = value.trimmed(); }
    inline QString      password() const { return m_password; }
    inline void         setPassword(const QString& value) { m_password = value.trimmed(); }

    inline bool         loggedIn() const { return m_loggedIn; }
           void         setLoggedIn(bool value);
    inline void         setLoggedIn() { setLoggedIn(true); }
    inline QDateTime    loginTime() const { return m_loginTime; }
    inline void         setLoginTime(QDateTime value) { m_loginTime = value; m_loggedIn = true; }

    inline int          noLoginTime() { return m_loggedIn ? 0 : m_noLoginTimer.elapsed()/1000; }

    void clear();

private:
    int                 m_userNo;
    QString             m_userID;
    QString             m_username;
    int                 m_userLevel;
    QHash<QString, int> m_authority;

    QString             m_loginID;
    QString             m_password;

    bool                m_loggedIn;
    QDateTime           m_loginTime;
    QElapsedTimer       m_noLoginTimer;
};

class Q_DECL_EXPORT CInvokeObject
{
public:
    CInvokeObject(QObject* o=NULL, QByteArray m="")
            { init(o, m); }
    CInvokeObject &operator=(const CInvokeObject& from)
    {
        if ( this != &from )
        {
            this->m_object = from.m_object;
            this->m_method = from.m_method;
        }
        return *this;
    }
    inline void init(QObject* o, QByteArray m)
            { m_object = o; m_method = m; }


    inline bool queued(QGenericArgument val0 = QGenericArgument(0),
                       QGenericArgument val1 = QGenericArgument(),
                       QGenericArgument val2 = QGenericArgument(),
                       QGenericArgument val3 = QGenericArgument(),
                       QGenericArgument val4 = QGenericArgument(),
                       QGenericArgument val5 = QGenericArgument(),
                       QGenericArgument val6 = QGenericArgument(),
                       QGenericArgument val7 = QGenericArgument(),
                       QGenericArgument val8 = QGenericArgument(),
                       QGenericArgument val9 = QGenericArgument())
    {
        try {
            return m_object != NULL ? m_object->metaObject()->invokeMethod(m_object, m_method,
                                                                           Qt::QueuedConnection,
                                                                           val0, val1, val2, val3, val4,
                                                                           val5, val6, val7, val8, val9)
                                    : false;
        }catch(...)
        {
            return false;
        }
    }
    bool invoke(QGenericArgument val0 = QGenericArgument(0),
                       QGenericArgument val1 = QGenericArgument(),
                       QGenericArgument val2 = QGenericArgument(),
                       QGenericArgument val3 = QGenericArgument(),
                       QGenericArgument val4 = QGenericArgument(),
                       QGenericArgument val5 = QGenericArgument(),
                       QGenericArgument val6 = QGenericArgument(),
                       QGenericArgument val7 = QGenericArgument(),
                       QGenericArgument val8 = QGenericArgument(),
                       QGenericArgument val9 = QGenericArgument());

    inline bool isValid() const { return m_object != NULL && ! m_method.isEmpty(); }
private:
    QObject*    m_object;
    QByteArray  m_method;
};

#if defined(TIANCHI_LIBRARY)
    class Q_DECL_EXPORT Climax : public QObject
#else
    class Climax : public QObject
#endif
{
    Q_OBJECT
public:
    explicit Climax(QObject *parent = 0);


};

#ifdef QT_WIDGETS_LIB
class Q_DECL_EXPORT CursorCustom
{
protected:
    CursorCustom(QWidget* parent, Qt::CursorShape shape)
    {
        m_parent = parent;
        m_cursor = m_parent->cursor();
        m_parent->setCursor(QCursor(shape));
    }
    virtual ~CursorCustom()
    {
        m_parent->setCursor(m_cursor);
    }
    QWidget* m_parent;
    QCursor  m_cursor;

};

class Q_DECL_EXPORT CursorWait : public CursorCustom
{
public:
    CursorWait(QWidget* parent)
        : CursorCustom(parent, Qt::WaitCursor)
    {
    }
};

class Q_DECL_EXPORT CursorBusy : public CursorCustom
{
public:
    CursorBusy(QWidget* parent)
        : CursorCustom(parent, Qt::BusyCursor)
    {
    }
};
#endif
} // namespace Tianchi

#endif // TIANCHI_CLASSES_H
