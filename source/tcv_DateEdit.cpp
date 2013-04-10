#include "tcv_DateEdit.h"

#include <QMouseEvent>

TCDateEdit::TCDateEdit(QWidget *parent)
    : QComboBox(parent)
{
    setEditable(true);

    m_calendar = new QCalendarWidget(this);
    QFont _font;
    _font.setPixelSize(12);
    m_calendar->setFont(_font);
    m_calendar->setContentsMargins(0, 0, 0, 0);
    m_calendar->resize(350, 170);
    m_calendar->hide();

    connect(m_calendar, SIGNAL(clicked(QDate)), this, SLOT(calendarClicked(QDate)));
}

TCDateEdit::~TCDateEdit()
{
    delete m_calendar;
}

void TCDateEdit::focusInEvent(QFocusEvent *e)
{
    //屏蔽基类事件
}
/*
void JSKDateEdit::focusOutEvent(QFocusEvent *e)
{
    QString dateStr = currentText().trimmed();
    if ( ! dateStr.isEmpty() )
    {
        QDate date = QDate::currentDate();
        int year  = date.year();
        int month = date.month();
        int day   = date.day();
        switch(dateStr.length())
        {
        case 23:
        case 19:
            year    = dateStr.mid( 0, 4).toInt();
            month   = dateStr.mid( 5, 2).toInt();
            day     = dateStr.mid( 8, 2).toInt();
            break;
        case 14:
            year    = dateStr.mid( 0, 4).toInt();
            month   = dateStr.mid( 4, 2).toInt();
            day     = dateStr.mid( 6, 2).toInt();
            break;
        case 10:
            year    = dateStr.mid( 0, 4).toInt();
            month   = dateStr.mid( 5, 2).toInt();
            day     = dateStr.mid( 8, 2).toInt();
            break;
        case 8:
            year    = dateStr.mid( 0, 2).toInt();
            month   = dateStr.mid( 3, 2).toInt();
            day     = dateStr.mid( 6, 2).toInt();
            break;
        case 5:
            month   = dateStr.mid( 0, 2).toInt();
            day     = dateStr.mid( 3, 2).toInt();
            break;
        case 4:
            year    = dateStr.toInt();
            break;
        case 2:
        case 1:
            day     = dateStr.toInt();
            break;
        }
        date = QDate(year, month, day);
        setEditText(date.year() > 1900 ? date.toString("yyyy-MM-dd") : "");
    }
}
*/
void TCDateEdit::mousePressEvent(QMouseEvent *e)
{
    //获取鼠标当前坐标及全局坐标
    int x = e->x();
    int y = e->y();
    int globx = e->globalX();
    int globy = e->globalY();

    //把日历移动到对应屏幕坐标位置、显示
    //即（屏幕x - 当前控件x）= 当前控件左端x
    //y坐标类似
    m_calendar->move(globx - x, globy + this->height() - y);
    m_calendar->setWindowFlags(Qt::Popup);
    m_calendar->setSelectedDate(this->date());
    m_calendar->show();
}

void TCDateEdit::calendarClicked(QDate _date)
{
    //日历的单击信号处理函数

    //判断combox中记录数量
    //保证其中只有一条数据
    if ( this->count() == 0 )
    {
        this->addItem(_date.toString("yyyy-MM-dd"));
    }
    else
    {
        this->setItemData(0, QVariant::fromValue(_date.toString("yyyy-MM-dd")), Qt::DisplayRole);
    }
    this->setCurrentIndex(0);
    m_calendar->hide();
}

QDate TCDateEdit::date() const
{
    QString str = currentText().trimmed();

    QDate date = QDate::currentDate();
    int year  = date.year();
    int month = date.month();
    int day   = date.day();
    switch(str.length())
    {
    case 23:
    case 19:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 5, 2).toInt();
        day     = str.mid( 8, 2).toInt();
        break;
    case 14:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 4, 2).toInt();
        day     = str.mid( 6, 2).toInt();
        break;
    case 10:
        year    = str.mid( 0, 4).toInt();
        month   = str.mid( 5, 2).toInt();
        day     = str.mid( 8, 2).toInt();
        break;
    case 8:
        year    = str.mid( 0, 2).toInt();
        month   = str.mid( 3, 2).toInt();
        day     = str.mid( 6, 2).toInt();
        break;
    case 5:
        month   = str.mid( 0, 2).toInt();
        day     = str.mid( 3, 2).toInt();
        break;
    case 4:
        year    = str.toInt();
        break;
    case 2:
    case 1:
        day     = str.toInt();
        break;
    }
    return QDate(year, month, day);
}

void TCDateEdit::setDate(QDate value)
{
    setEditText(value.year() > 1900 ? value.toString("yyyy-MM-dd") : "");
}

void TCDateEdit::unsetDate()
{
    setEditText("");
}
