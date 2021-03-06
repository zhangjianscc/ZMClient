#include "mytargetbutton.h"

MyButton::MyButton() :
    QPushButton()
{}

MyTargetButton::MyTargetButton(QString text) :
    QPushButton(0)
{
    this->setCheckable(true);
    this->setFixedSize(180, 40);
    this->setStyleSheet("MyTargetButton{border:1px solid rgb(200,200,200);background-color:rgb(255,255,255)}"
                        "MyTargetButton:hover{background-color:rgb(255,255,255)}"
                        "MyTargetButton:pressed{background-color:rgb(76,76,76)}");


    m_pNameLabel = new QLabel;
    m_pNameLabel->setStyleSheet("QLabel{border:none;color:rgb(0,0,0);background-color:rgb(255,255,255)}");
    QFont font;
    font.setPointSize(12);
    m_pNameLabel->setFont(font);
    m_pNameLabel->setText(tr("%1").arg(text));

    m_pStatusLabel = new QLabel;
    m_pStatusLabel->setText(tr("已选"));
    m_pStatusLabel->setVisible(false);

    m_pCloseButton = new MyButton;
    m_pCloseButton->setCheckable(true);
    m_pCloseButton->setIcon(QIcon("://images//X选小图标.png"));
    m_pCloseButton->setVisible(false);

    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pVBoxLayout->addWidget(m_pCloseButton, 0, Qt::AlignTop);
    pVBoxLayout->addWidget(m_pStatusLabel);

    /// 主布局
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);
    pHBoxLayout->addWidget(m_pNameLabel, 0, Qt::AlignHCenter);
    pHBoxLayout->addLayout(pVBoxLayout);
}

void MyTargetButton::select()
{
    m_pStatusLabel->setVisible(true);
    m_pCloseButton->setVisible(false);

    this->setStyleSheet("QPushButton{border:2px;background-color:rgb(76,76,76)}");
    m_pNameLabel->setStyleSheet("QLabel{border:none;color:rgb(255,255,255);background-color:rgb(76,76,76)}");
    m_pStatusLabel->setStyleSheet("QLabel{border:none;color:rgb(18,132,194);background-color:rgb(76,76,76)}");
}

void MyTargetButton::selected()
{
    m_pStatusLabel->setVisible(false);
    m_pCloseButton->setVisible(true);

    this->setStyleSheet("QPushButton{border:2px;background-color:rgb(76,76,76)}");
    m_pNameLabel->setStyleSheet("QLabel{border:none;color:rgb(255,255,255);background-color:rgb(76,76,76)}");
    m_pCloseButton->setStyleSheet("QPushButton{border:none;color:rgb(76,76,76);background-color:rgb(76,76,76)}");
}

void MyTargetButton::unSelect()
{
    m_pStatusLabel->setVisible(false);
    m_pCloseButton->setVisible(false);

    /*m_pNameLabel->setObjectName("123");
    this->setStyleSheet("QPushButton#123{border:2px solid rgb();background-color:rgb(255,255,255)}");*/
    this->setStyleSheet("QPushButton{border:1px solid rgb(200,200,200);background-color:rgb(255,255,255)}");
    m_pNameLabel->setStyleSheet("QLabel{border:none;color:rgb(0,0,0);background-color:rgb(255,255,255)}");
}

void MyTargetButton::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
