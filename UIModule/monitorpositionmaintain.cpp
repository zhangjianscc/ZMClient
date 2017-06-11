#include "monitorpositionmaintain.h"
#include "ui_monitorpositionmaintain.h"

MonitorPositionMaintain::MonitorPositionMaintain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorPositionMaintain)
{
    ui->setupUi(this);
}

MonitorPositionMaintain::~MonitorPositionMaintain()
{
    delete ui;
}
