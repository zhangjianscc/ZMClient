#include "addtemplatedlg.h"
#include "ui_addtemplate.h"

AddTemplateDlg::AddTemplateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTemplate)
{
    ui->setupUi(this);
}

AddTemplateDlg::~AddTemplateDlg()
{
    delete ui;
}
