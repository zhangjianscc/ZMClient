#include "noticedlg.h"
#include "ui_noticedlg.h"

NoticeDlg::NoticeDlg(QString info1,QString info2) :
    QDialog(0),
    ui(new Ui::NoticeDlg)
{
    ui->setupUi(this);
    initUI();
    ui->m_labelInfo1->setText(info1);
    ui->m_labelInfo2->setText(info2);
}

NoticeDlg::~NoticeDlg()
{
    delete ui;
}
void NoticeDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(:/images/弹窗X选-02.png)}"
                                  "QPushButton:hover{border-image:url(:/images/弹窗X选.png)}"
                                  "QPushButton:pressed{border-image:url(:/images/弹窗X选.png)}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    //ok按钮
    ui->m_btnOk->setStyleSheet("QPushButton{background-color:rgb(255,0,0);color:rgb(255,255,255)}"
                                   "QPushButton:hover{background-color:rgb(83,83,83);color:rgb(255,255,255)}"
                                   "QPushButton:pressed{background-color:rgb(83,83,83);color:rgb(255,255,255)}");
    connect(ui->m_btnOk,SIGNAL(clicked(bool)),this,SLOT(onSlotOk()));

}

void NoticeDlg::onSlotClose()
{
    this->reject();
}

void NoticeDlg::onSlotOk()
{
    this->accept();
}


void NoticeDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void NoticeDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void NoticeDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}
