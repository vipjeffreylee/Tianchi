#ifndef JSK_MSEXCEL_H
#define JSK_MSEXCEL_H

#include "jsk_qglobal.h"

#include <QString>
#include <QStringList>

#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>

#include <QTreeWidget>

///@file jsk_MSExcel.h 通过 OLE 接口对 Microsoft Excel 进行读写。

namespace JSK
{
class JSK_EXPORT MSExcel
{
public:
    MSExcel();
    virtual ~MSExcel();

private:
    QAxWidget*  m_excel;
    QAxObject*  m_books;
    QAxObject*  m_book;
    QAxObject*  m_sheets;
    QAxObject*  m_sheet;
    QString     m_filename;
    QString     m_sheetName;

    int m_rowStart;
    int m_colStart;
    int m_rowEnd;
    int m_colEnd;

public:
    enum Alignment
    {
        xlTop    = -4160,
        xlLeft   = -4131,
        xlRight  = -4152,
        xlCenter = -4108,
        xlBottom = -4107,
    };

    bool        create(const QString& filename="");
    bool        open(const QString& filename="");
    void        save(const QString& filename="");
    void        close();
    void        kick();

    void        setVisible(bool value);
    void        setCaption(const QString& value);

    QAxObject*  addBook();

    void        cellFormat(int row, int col, const QString& format);
    void        cellAlign(int row, int col, Alignment hAlign, Alignment vAlign);

    QVariant    read(int row, int col);
    void        write(int row, int col, const QVariant& value);

    int         sheetCount();
    QAxObject*  currentSheet();

    QAxObject*  sheet(int index);

    bool        usedRange();

    QStringList sheetNames();
    QString     sheetName() const { return m_sheetName; }

    inline int rowStart() const { return m_rowStart; }
    inline int colStart() const { return m_colStart; }
    inline int rowEnd() const { return m_rowEnd; }
    inline int colEnd() const { return m_colEnd; }

    class JSK_EXPORT Exporter
    {
    public:
        Exporter(QTreeWidget* view, int mode, JSK::MSExcel* excel, int row=1, int col=1);

        void setStart(int row, int col) { m_row = row; m_col = col; }
        void setExcel(JSK::MSExcel* excel) { m_excel = excel; }
        void setMode(int mode) { m_mode = mode; } // 0:all, 1:selected

        int  exec();

        QStringList     formats;
        QStringList     cellTypes;

    private:
        QTreeWidget*    m_view;
        JSK::MSExcel*   m_excel;
        int             m_row;
        int             m_col;
        int             m_mode;
    };
};

} // namespace JSK

#endif // JSK_MSEXCEL_H
