#include "mytreeitem.h"

MyTreeItem::MyTreeItem(QString nomalImage,QString selectImage,QString text) :
    QWidget(0),
    m_nomalImage(nomalImage),
    m_selectImage(selectImage),
    m_text(text)
{
    //this->setStyleSheet("MyTreeItem{border: 1px solid rgb(180,180,180);background-color:rgb(76,76,76)}");
    //m_pLabelImage = new QLabel();
    //m_pLabelImage->setPixmap(QPixmap(m_nomalImage));
    //m_pLabelText = new QLabel();
   // m_pLabelText->setStyleSheet("QLabel{color:rgb(0,0,0);font: 24pt Arial Black;}");
    //m_pLabelText->setText(text);
    QToolButton* pTBtn = new QToolButton();
    pTBtn->setText("text");
    pTBtn->setIcon(QIcon(QPixmap(m_nomalImage)));
    pTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    pTBtn->setCheckable(true);
    pTBtn->setStyleSheet("QToolButton{background-color:rgb(217,217,217);border: 2px solid rgb(180,180,180);}"
                         "QPushButton:hover{background-color:rgb(76,76,76);}"
                         "QPushButton:pressed{background-color:rgb(76,76,76);}");
    QHBoxLayout* pLayout = new QHBoxLayout(this);
    pLayout->addWidget(pTBtn);
    //pLayout->addWidget(m_pLabelImage);
    //pLayout->addWidget(m_pLabelText);
    //pLayout->addStretch();Qt::ToolButtonTextBesideIcon
}

void MyTreeItem::select()
{
    this->setStyleSheet("MyTreeItem{border: 1px solid rgb(180,180,180);background-color:rgb(76,76,76)}");
    m_pLabelImage->setPixmap(QPixmap(m_selectImage));
    m_pLabelText->setStyleSheet("QLabel{color:rgb(255,255,255);font: 14pt Arial Black;}");

}
void MyTreeItem::unSelect()
{
    this->setStyleSheet("MyTreeItem{border: 1px solid rgb(180,180,180);background-color:rgb(217,217,217)}");
    m_pLabelImage->setPixmap(QPixmap(m_nomalImage));
    m_pLabelText->setStyleSheet("QLabel{color:rgb(0,0,0);font: 14pt Arial Black;}");
}
