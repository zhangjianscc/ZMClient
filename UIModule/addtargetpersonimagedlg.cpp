#include "addtargetpersonimagedlg.h"
#include "ui_addtargetpersonimage.h"

AddTargetPersonImageDlg::AddTargetPersonImageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTargetPersonImage)
{
    ui->setupUi(this);
}

AddTargetPersonImageDlg::~AddTargetPersonImageDlg()
{
    delete ui;
}
