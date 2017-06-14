#include "monitordevicemaintain.h"
#include "ui_monitordevicemaintain.h"

MonitorDeviceMaintain::MonitorDeviceMaintain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorDeviceMaintain)
{
    ui->setupUi(this);
}

MonitorDeviceMaintain::~MonitorDeviceMaintain()
{
    delete ui;
}
