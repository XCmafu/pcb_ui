#include "globalui.h"
#include <QMouseEvent>

QDoubleClickebleLabel::QDoubleClickebleLabel(QWidget *parent)
    :QLabel(parent)
{

}

void QDoubleClickebleLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() ==Qt::LeftButton)
    {
        //触发信号
        emit sig_labelDoubleClicked();
    }

    QLabel::mouseDoubleClickEvent(event);
}
