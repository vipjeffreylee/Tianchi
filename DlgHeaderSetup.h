#ifndef DLGHEADERSETUP_H
#define DLGHEADERSETUP_H

#include "jsk_qglobal.h"

#include <QDialog>
#include <QTreeWidget>

namespace Ui {
class DlgHeaderSetup;
}

#if defined(JSK_LIBRARY)
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

#endif // DLGHEADERSETUP_H
