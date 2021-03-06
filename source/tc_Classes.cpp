#include "tc_Classes.h"
#include "tc_Utils.h"


namespace Tianchi
{

Player::Player()
    : QObject()
{
    m_loggedIn  = false;
    m_userNo    = 0;
    m_userLevel = 0;
    m_noLoginTimer.start();
}

Player& Player::operator=(const Player & from)
{
    if ( this != &from )
    {
        m_userNo    = from.m_userNo;
        m_userID    = from.m_userID;
        m_username  = from.m_username;
        m_userLevel = from.m_userLevel;

        m_authority = from.m_authority;

        m_loginID   = from.m_loginID;
        m_password  = from.m_password;

        m_loggedIn  = from.m_loggedIn;
        m_loginTime = from.m_loginTime;
    }
    return *this;
}

void Player::setLoggedIn(bool value)
{
    m_loggedIn = value;
    m_loginTime = QDateTime::currentDateTime();
    if ( ! value )
    {
        m_noLoginTimer.restart();
    }
}

void Player::clear()
{
    m_userNo    = 0;
    m_userID    = "";
    m_username  = "";
    m_userLevel = 0;

    m_loginID  = "";
    m_password = "";

    m_loggedIn  = false;
    m_loginTime = QDateTime();

    m_noLoginTimer.restart();
}

int Player::authority(const QString& key) const
{
    int ret  = 0;
    if ( m_userLevel >= AUTH_ADMIN )
    {
        ret = m_userLevel;
    }else
    if ( m_userLevel >= AUTH_GUEST )
    {
        ret = m_authority.value(key);
    }
    return ret;
}

void Player::setAuthorityText(const QString& value)
{
    QHash<QString, QString> map = Tianchi::StringToMap(value);

    m_authority.clear();

    QStringList keys = map.keys();
    foreach(QString key, keys)
    {
        int value = map.value(key).toInt();
        if ( value >0 )
        {
            m_authority[key] = value;
        }
    }
}

void Player::setAuthorityText(const QStringList& value)
{
    QHash<QString, QString> map = Tianchi::StringToMap(value);

    m_authority.clear();

    QStringList keys = map.keys();
    foreach(QString key, keys)
    {
        int value = map.value(key).toInt();
        if ( value >0 )
        {
            m_authority[key] = value;
        }
    }
}

// =====================================================================================================================

Climax::Climax(QObject *parent) :
    QObject(parent)
{
}

bool CInvokeObject::invoke(QGenericArgument val0,
                           QGenericArgument val1,
                           QGenericArgument val2,
                           QGenericArgument val3,
                           QGenericArgument val4,
                           QGenericArgument val5,
                           QGenericArgument val6,
                           QGenericArgument val7,
                           QGenericArgument val8,
                           QGenericArgument val9)
{
    try {
        return m_object != NULL ? m_object->metaObject()->invokeMethod(m_object, m_method,
                                                                       val0, val1, val2, val3, val4,
                                                                       val5, val6, val7, val8, val9)
                                : false;
    }catch(...)
    {
        return false;
    }
}

} // namespace Tianchi
