// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// ����Ϊ�յ�����ѡ��ؼ�
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
/// @file tcv_DateEdit.h ����Ϊ�յ�����ѡ��ؼ�
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
