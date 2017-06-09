#include "myimagelabel.h"
#include <QLabel>
#include "stable.h"

MyImageLabel::MyImageLabel(QWidget* parent) : QLabel(parent)
{


}


void MyImageLabel::resizeEvent(QResizeEvent *event)
{
    if(event->oldSize() == this->size()) return;

    if(this->pixmap() == Q_NULLPTR)return;

    int wid = this->pixmap()->width();
    int hei = this->pixmap()->height();

    int step = hei / event->size().height();

    int newWid = wid / step;

    resize(newWid,event->size().height());
    QWidget::resizeEvent(event);
}
