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
}
