// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// JSON �����ͽ�����
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
/// @file tc_Json.h JSON �����ͽ�����
// *********************************************************************************************************************
#ifndef TIANCHI_JSON_H
#define TIANCHI_JSON_H

#include "tc_qglobal.h"

#include <QDateTime>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QString>
#include <QStringList>

namespace Tianchi
{
class TIANCHI_EXPORT JSONObject
{
public:
    enum ValueTypeFlag { vtfObject=0, vtfString=1, vtfInt=2, vtfDouble=3, vtfBool=4, vtfDateTime=5, vtfNull=6, vtfArray=99 };

    JSONObject(const QString& key="");
    virtual ~JSONObject();

    static QString quote(const QString& Text);
    static QString dequote(const QString& S);

protected:
    JSONObject* parent;

    int m_index;
    QMap<QString, JSONObject*>  m_list;

    ValueTypeFlag   m_type;
    QString         m_key;
    QVariant        m_value;

    QString jsonKey() const;
    QString jsonValue() const;

    void init();
    const wchar_t* fromObject(const QString& Key, const wchar_t* ptr);
    const wchar_t* fromArray(const wchar_t* ptr);

    inline QString newKey(const QString& key)
                         { return key.trimmed().isEmpty() ? QString::number(m_index++) : key.trimmed(); }

    const wchar_t* parseKey(QString& Value, const wchar_t* ptr);
    const wchar_t* parseValue(QString Key, const wchar_t* ptr);
    const wchar_t* parseNumber(QString& Value, const wchar_t* ptr);
    static inline const wchar_t* skip(const wchar_t* in)
    {
        while(in && *in && *in<=32)
        {
            in++;
        }
        return in;
    }

public:
    int     type() const { return m_type; }
    void    setType(int value) { m_type = (ValueTypeFlag) value; }

    QString     key() const;
    void        setKey(const QString& value);
    QVariant    value() const;
    inline QVariant value(const QString& key) const
                         { QVariant ret; value(key, ret); return ret; }
    bool        value(const QString& key, QVariant& v) const;
    inline bool exists(const QString& key) const
    {
        QMap<QString, JSONObject*>::const_iterator child = m_list.find(key);
        return child != m_list.constEnd() && child.key() == key;
    }
    inline int count() const { return m_list.count(); }
    inline JSONObject* get(const QString& key) const
                          { return m_list[key]; }
    QList<JSONObject*> children() const;


    JSONObject*  addObject(const QString& key="");
    JSONObject*  addArray(const QString& key);
    JSONObject*  addNull(const QString& key);
    inline JSONObject*  add(const QString& key, const char*    value) { return add(key, QString(value)); }
    JSONObject*  add(const QString& key, const QString& value);
    JSONObject*  add(const QString& key, int            value);
    JSONObject*  add(const QString& key, double         value);
    JSONObject*  add(const QString& key, bool           value);
    JSONObject*  add(const QString& key, QDateTime      value);

    JSONObject*  addNull();
    inline JSONObject*  add(const char*    value) { return add(QString(value)); }
    inline JSONObject*  add(const QString& value) { return add(QString::number(m_index++), value); }
    inline JSONObject*  add(int            value) { return add(QString::number(m_index++), value); }
    inline JSONObject*  add(double         value) { return add(QString::number(m_index++), value); }
    inline JSONObject*  add(bool           value) { return add(QString::number(m_index++), value); }
    inline JSONObject*  add(QDateTime      value) { return add(QString::number(m_index++), value); }

    void    deleteChildren(const QString& key);
    void    clearChildren();
    void    clear();

    virtual QString toString() const; // 取得

    bool    fromString(QString jsonText);
};
// =====================================================================================================================
}; // End of namespace Tianchi;

#endif // TIANCHI_JSON_H
