#include "addmonitorareadlg.h"
#include "ui_addmonitorareadlg.h"

AddMonitorAreaDlg::AddMonitorAreaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMonitorAreaDlg)
{
    ui->setupUi(this);
}

AddMonitorAreaDlg::~AddMonitorAreaDlg()
{
    delete ui;
}
