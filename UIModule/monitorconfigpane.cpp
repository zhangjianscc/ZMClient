#include "monitorconfigpane.h"
#include "ui_monitorconfigpane.h"

MonitorConfigPane::MonitorConfigPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorConfigPane)
{
    ui->setupUi(this);
}

MonitorConfigPane::~MonitorConfigPane()
{
    delete ui;
}
