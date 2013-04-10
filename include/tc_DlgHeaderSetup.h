// *********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享资源库
// =====================================================================================================================
// 修改 QTreeWidget 列设置的对话框
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
/// @file tc_DlgHeaderSetup.h 修改 QTreeWidget 列设置的对话框
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
