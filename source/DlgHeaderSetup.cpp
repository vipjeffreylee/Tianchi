#include "DlgHeaderSetup.h"
#include "ui_DlgHeaderSetup.h"

DlgHeaderSetup::DlgHeaderSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgHeaderSetup)
{
    ui->setupUi(this);

    m_view = NULL;
}

DlgHeaderSetup::~DlgHeaderSetup()
{
    delete ui;
}

void DlgHeaderSetup::setHeader(QTreeWidget* view, int max)
{
    m_view = view;

    QTreeWidgetItem* header = view->headerItem();
    for( int i=0;i<header->columnCount();i++ )
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->MasterView);
        item->setText(0, header->text(i));
        item->setTextAlignment(0, header->textAlignment(i));
        item->setCheckState(0, view->isColumnHidden(i) ? Qt::Unchecked : Qt::Checked);
    }
}

void DlgHeaderSetup::on_MasterView_itemClicked(QTreeWidgetItem *item, int column)
{
    int index = ui->MasterView->indexOfTopLevelItem(item);
    m_view->setColumnHidden(index, item->checkState(0) == Qt::Unchecked);
}

void DlgHeaderSetup::on_bnUpward_clicked()
{
    foreach(QTreeWidgetItem* item, ui->MasterView->selectedItems())
    {
        int index1 = ui->MasterView->indexOfTopLevelItem(item);
        if ( index1 >0 )
        {
            int index2 = index1-1;
            item = ui->MasterView->takeTopLevelItem(index1);
            ui->MasterView->insertTopLevelItem(index2, item);
            item->setSelected(true);

            m_view->header()->swapSections(index1, index2);
        }
    }
}

void DlgHeaderSetup::on_bnDownawrd_clicked()
{
    foreach(QTreeWidgetItem* item, ui->MasterView->selectedItems())
    {
        int index1 = ui->MasterView->indexOfTopLevelItem(item);
        if ( index1 < (ui->MasterView->topLevelItemCount()-1) )
        {
            int index2 = index1+1;
            item = ui->MasterView->takeTopLevelItem(index1);
            ui->MasterView->insertTopLevelItem(index2, item);
            item->setSelected(true);

            m_view->header()->swapSections(index1, index2);
        }
    }
}

void DlgHeaderSetup::on_bnLeft_clicked()
{
    foreach(QTreeWidgetItem* item, ui->MasterView->selectedItems())
    {
        item->setTextAlignment(0, Qt::AlignLeft | Qt::AlignVCenter);

        int index = ui->MasterView->indexOfTopLevelItem(item);

        QTreeWidgetItem* header = m_view->headerItem();
        header->setTextAlignment(index, Qt::AlignLeft | Qt::AlignVCenter);
    }
}

void DlgHeaderSetup::on_bnCenter_clicked()
{
    foreach(QTreeWidgetItem* item, ui->MasterView->selectedItems())
    {
        item->setTextAlignment(0, Qt::AlignHCenter | Qt::AlignVCenter);

        int index = ui->MasterView->indexOfTopLevelItem(item);

        QTreeWidgetItem* header = m_view->headerItem();
        header->setTextAlignment(index, Qt::AlignHCenter | Qt::AlignVCenter);
    }
}

void DlgHeaderSetup::on_bnRight_clicked()
{
    foreach(QTreeWidgetItem* item, ui->MasterView->selectedItems())
    {
        item->setTextAlignment(0, Qt::AlignRight | Qt::AlignVCenter);

        int index = ui->MasterView->indexOfTopLevelItem(item);

        QTreeWidgetItem* header = m_view->headerItem();
        header->setTextAlignment(index, Qt::AlignRight | Qt::AlignVCenter);
    }
}
