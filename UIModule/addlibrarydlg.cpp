#include "addlibrarydlg.h"
#include "ui_addlibrary.h"

AddLibraryDlg::AddLibraryDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLibrary)
{
    ui->setupUi(this);
}

AddLibraryDlg::~AddLibraryDlg()
{
    delete ui;
}
