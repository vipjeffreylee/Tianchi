// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享资源库
// =====================================================================================================================
// 允许为空的日期选择控件
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
/// @file tcv_DateEdit.h 允许为空的日期选择控件
// *********************************************************************************************************************
#ifndef TIANCHI_DATEEDIT_H
#define TIANCHI_DATEEDIT_H

#include "tc_qglobal.h"

#include <QtWidgets/QComboBox>
#include <QCalendarWidget>

#if defined(TIANCHI_LIBRARY)
    class Q_DECL_EXPORT TCDateEdit : public QComboBox
#else
    class TCDateEdit : public QComboBox
#endif
//class TIANCHI_EXPORT JSKDateEdit : public QComboBox
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
    TCDateEdit(QWidget *parent = 0);
    virtual ~TCDateEdit();

    QDate date() const;
    void setDate(QDate value);
    void unsetDate();

    inline void setDate(QDateTime value) { setDate(value.date()); }
};

#endif
