#include "mytreeitem.h"

MyTreeItem::MyTreeItem(QString nomalImage,QString selectImage,QString text) :
    QWidget(0),
    m_nomalImage(nomalImage),
    m_selectImage(selectImage),
    m_text(text)
{
    this->setStyleSheet("MyTreeItem{border:1px;background-color:rgb(217,217,217)}");
}
