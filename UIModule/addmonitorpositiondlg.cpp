#include "addmonitorpositiondlg.h"
#include "ui_addmonitorpositiondlg.h"

AddMonitorPositionDlg::AddMonitorPositionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMonitorPositionDlg)
{
    ui->setupUi(this);
}

AddMonitorPositionDlg::~AddMonitorPositionDlg()
{
    delete ui;
}
