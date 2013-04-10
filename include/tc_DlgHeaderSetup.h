// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع�����Դ��
// =====================================================================================================================
// �޸� QTreeWidget �����õĶԻ���
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
/// @file tc_DlgHeaderSetup.h �޸� QTreeWidget �����õĶԻ���
// *********************************************************************************************************************
#ifndef TIANCHI_DLGHEADERSETUP_H
#define TIANCHI_DLGHEADERSETUP_H

#include "tc_qglobal.h"

#include <QDialog>
#include <QTreeWidget>

namespace Ui {
class DlgHeaderSetup;
}

#if defined(TIANCHI_LIBRARY)
    class Q_DECL_EXPORT DlgHeaderSetup : public QDialog
#else
    class DlgHeaderSetup : public QDialog
#endif
{
    Q_OBJECT
    
public:
    explicit DlgHeaderSetup(QWidget *parent = 0);
    ~DlgHeaderSetup();

    void setHeader(QTreeWidget* view, int max=-1);
    
private slots:
    void on_bnUpward_clicked();
    void on_bnDownawrd_clicked();

    void on_MasterView_itemClicked(QTreeWidgetItem *item, int column);

    void on_bnLeft_clicked();

    void on_bnCenter_clicked();

    void on_bnRight_clicked();

private:
    Ui::DlgHeaderSetup *ui;

    QTreeWidget* m_view;
};

#endif // TIANCHI_DLGHEADERSETUP_H
