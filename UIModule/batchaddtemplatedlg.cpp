#include "batchaddtemplatedlg.h"
#include "ui_batchaddtemplatedlg.h"

BatchAddTemplateDlg::BatchAddTemplateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatchAddTemplateDlg)
{
    ui->setupUi(this);
}

BatchAddTemplateDlg::~BatchAddTemplateDlg()
{
    delete ui;
}
