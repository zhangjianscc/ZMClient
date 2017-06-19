#include "addtargetpersondlg.h"
#include "ui_addtargetperson.h"

AddTargetPersonDlg::AddTargetPersonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTargetPerson)
{
    ui->setupUi(this);
    initUI();
}

AddTargetPersonDlg::~AddTargetPersonDlg()
{
    delete ui;
}

void AddTargetPersonDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    //
    QString btnStyle = "QPushButton{font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{color:rgb(255,255,255);background-color:rgb(4,119,182)}"
                       "QPushButton:pressed{color:rgb(255,255,255);background-color:rgb(4,119,182)}";
    ui->m_btnSave->setStyleSheet(btnStyle);
    ui->m_btnCancel->setStyleSheet(btnStyle);

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

}

void AddTargetPersonDlg::onSlotClose()
{
    this->close();
}







