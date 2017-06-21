#include "deleteconfirmationdlg.h"
#include "ui_deletetargetperson.h"

DeleteConfirmationDlg::DeleteConfirmationDlg(QString info1,QString redInfo,QString info3) :
    QDialog(0),
    ui(new Ui::DeleteTargetPerson)
{
    ui->setupUi(this);
    initUI();
    ui->m_labelInfo1->setText(info1);
    ui->m_labelInfo2->setText(redInfo);
    ui->m_labelInfo3->setText(info3);
}

DeleteConfirmationDlg::~DeleteConfirmationDlg()
{
    delete ui;
}
void DeleteConfirmationDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(:/images/弹窗X选-02.png)}"
                                  "QPushButton:hover{border-image:url(:/images/弹窗X选.png)}"
                                  "QPushButton:pressed{border-image:url(:/images/弹窗X选.png)}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    //删除按钮
    ui->m_btnDelete->setStyleSheet("QPushButton{background-color:rgb(255,0,0);color:rgb(255,255,255)}"
                                   "QPushButton:hover{background-color:rgb(83,83,83);color:rgb(255,255,255)}"
                                   "QPushButton:pressed{background-color:rgb(83,83,83);color:rgb(255,255,255)}");
    connect(ui->m_btnDelete,SIGNAL(clicked(bool)),this,SLOT(onSlotDelete()));

    // 取消按钮
    ui->m_btnCancel->setStyleSheet("QPushButton{background-color:rgb(83,83,83);color:rgb(255,255,255)}"
                                   "QPushButton:hover{background-color:rgb(255,0,0);color:rgb(255,255,255)}"
                                   "QPushButton:pressed{background-color:rgb(255,0,0);color:rgb(255,255,255)}");
    connect(ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onSlotCancel()));

}

void DeleteConfirmationDlg::onSlotClose()
{
    this->reject();
}

void DeleteConfirmationDlg::onSlotDelete()
{
    this->accept();
}

void DeleteConfirmationDlg::onSlotCancel()
{
    this->reject();
}

void DeleteConfirmationDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void DeleteConfirmationDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void DeleteConfirmationDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}






