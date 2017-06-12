#include "edittargetpersondlg.h"
#include "ui_edittargetperson.h"

EditTargetPersonDlg::EditTargetPersonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTargetPerson)
{
    ui->setupUi(this);
}

EditTargetPersonDlg::~EditTargetPersonDlg()
{
    delete ui;
}
