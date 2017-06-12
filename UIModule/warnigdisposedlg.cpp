#include "warnigdisposedlg.h"
#include "ui_warnigdisposedlg.h"

WarnigDisposeDlg::WarnigDisposeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarnigDisposeDlg)
{
    ui->setupUi(this);
}

WarnigDisposeDlg::~WarnigDisposeDlg()
{
    delete ui;
}
