#include "editmonitorareadlg.h"
#include "ui_editmonitorareadlg.h"

EditMonitorAreaDlg::EditMonitorAreaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMonitorAreaDlg)
{
    ui->setupUi(this);
}

EditMonitorAreaDlg::~EditMonitorAreaDlg()
{
    delete ui;
}