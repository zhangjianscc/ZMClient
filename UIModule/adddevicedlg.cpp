#include "adddevicedlg.h"
#include "ui_adddevicedlg.h"

AddDeviceDlg::AddDeviceDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDeviceDlg)
{
    ui->setupUi(this);
}

AddDeviceDlg::~AddDeviceDlg()
{
    delete ui;
}
