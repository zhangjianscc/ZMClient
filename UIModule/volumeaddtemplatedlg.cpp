#include "volumeaddtemplatedlg.h"
#include "ui_volumeaddtemplate.h"

VolumeAddTemplateDlg::VolumeAddTemplateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeAddTemplate)
{
    ui->setupUi(this);
}

VolumeAddTemplateDlg::~VolumeAddTemplateDlg()
{
    delete ui;
}
