#ifndef JSKDATEEDIT_H
#define JSKDATEEDIT_H

#include "jsk_qglobal.h"

#include <QtWidgets/QComboBox>
#include <QCalendarWidget>

#if defined(JSK_LIBRARY)
    class Q_DECL_EXPORT JSKDateEdit : public QComboBox
#else
    class JSKDateEdit : public QComboBox
#endif
//class JSK_EXPORT JSKDateEdit : public QComboBox
{
    Q_OBJECT

    Q_PROPERTY(QDate date READ date WRITE setDate RESET unsetDate)

private slots:
    void calendarClicked(QDate);

private:
    QCalendarWidget *m_calendar;

protected:
    void focusInEvent(QFocusEvent *e);
//    void focusOutEvent(QFocusEvent *e);
    void mousePressEvent(QMouseEvent *e);

public:
    JSKDateEdit(QWidget *parent = 0);
    virtual ~JSKDateEdit();

    QDate date() const;
    void setDate(QDate value);
    void unsetDate();

    inline void setDate(QDateTime value) { setDate(value.date()); }
};

#endif
