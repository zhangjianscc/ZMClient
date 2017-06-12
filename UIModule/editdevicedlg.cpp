#include "editdevicedlg.h"
#include "ui_editdevicedlg.h"

EditDeviceDlg::EditDeviceDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeviceDlg)
{
    ui->setupUi(this);
}

EditDeviceDlg::~EditDeviceDlg()
{
    delete ui;
}
