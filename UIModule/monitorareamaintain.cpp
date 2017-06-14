#include "monitorareamaintain.h"
#include "ui_monitorareamaintain.h"

MonitorAreaMaintain::MonitorAreaMaintain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorAreaMaintain)
{
    ui->setupUi(this);
}

MonitorAreaMaintain::~MonitorAreaMaintain()
{
    delete ui;
}
