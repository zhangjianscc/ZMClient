#include "mysearchedit.h"
#include "stable.h"

MySearchEdit::MySearchEdit(QWidget* parent) :
    QLineEdit(parent)
{
    initUI();
}

void MySearchEdit::initUI()
{
    this->setTextMargins(5, 0, 20, 0);
    this->setStyleSheet("MySearchEdit{border:1px solid rgb(180,180,180);background-color:rgb(255,255,255)}");

    // 搜索按钮
    QPushButton* pSearchBtn = new QPushButton();
    pSearchBtn->setFixedSize(20,20);
    pSearchBtn->setStyleSheet("QPushButton{border:none;border-image:url(://images//search-01.png);background-color:rgb(255,255,255);}"
                              "QPushButton:hover{border-image:url(://images//search-02.png)}"
                              "QPushButton:pressed{border-image:url(://images//search-02.png)}");
    connect(pSearchBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotSearchBtnBlicked()));


    QHBoxLayout *layout = new QHBoxLayout();
    layout->addStretch();
    layout->addWidget(pSearchBtn,0,Qt::AlignCenter);
    this->setLayout(layout);
}

void MySearchEdit::onSlotSearchBtnBlicked()
{
    emit searchBtnClicked();
}

void MySearchEdit::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
