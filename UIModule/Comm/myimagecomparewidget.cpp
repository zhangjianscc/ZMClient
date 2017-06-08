#include "myimagecomparewidget.h"

MyImageCompareWidget::MyImageCompareWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("MyImageCompareWidget{border:0px;border-radius:2px;background-color:rgb(178,178,178)}");
    this->setFixedSize(100,200);
}
