#include "selectmonitorpositiondlg.h"
#include "ui_selectmonitorpositiondlg.h"

SelectMonitorPositionDlg::SelectMonitorPositionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectMonitorPositionDlg)
{
    ui->setupUi(this);
}

SelectMonitorPositionDlg::~SelectMonitorPositionDlg()
{
    delete ui;
}
