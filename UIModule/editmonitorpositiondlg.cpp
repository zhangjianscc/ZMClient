#include "editmonitorpositiondlg.h"
#include "ui_editmonitorpositiondlg.h"

EditMonitorPositionDlg::EditMonitorPositionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMonitorPositionDlg)
{
    ui->setupUi(this);
}

EditMonitorPositionDlg::~EditMonitorPositionDlg()
{
    delete ui;
}
