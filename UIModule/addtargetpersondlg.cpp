#include "addtargetpersondlg.h"
#include "ui_addtargetperson.h"

AddTargetPersonDlg::AddTargetPersonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTargetPerson)
{
    ui->setupUi(this);
}

AddTargetPersonDlg::~AddTargetPersonDlg()
{
    delete ui;
}
