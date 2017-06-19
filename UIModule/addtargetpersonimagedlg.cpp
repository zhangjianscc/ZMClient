#include "addtargetpersonimagedlg.h"
#include "ui_addtargetpersonimage.h"

AddTargetPersonImageDlg::AddTargetPersonImageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTargetPersonImage)
{
    ui->setupUi(this);
    initUI();
}

AddTargetPersonImageDlg::~AddTargetPersonImageDlg()
{
    delete ui;
}

void AddTargetPersonImageDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}
