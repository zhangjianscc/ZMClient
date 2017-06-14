#include "monitorconfigpane.h"
#include "ui_monitorconfigpane.h"
#include "Comm/mytargetbutton.h"

MonitorConfigPane::MonitorConfigPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorConfigPane)
{
    ui->setupUi(this);

    initUi();
}

MonitorConfigPane::~MonitorConfigPane()
{
    delete ui;
}

void MonitorConfigPane::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void MonitorConfigPane::initUi()
{}

void MonitorConfigPane::updateData(QList<QString> &listString)
{
    ui->selectTarConTableWidget->setRowCount(listString.count()/3 + listString.count()%3);

    for(int i=0; i<listString.count(); ++i)
    {
        MyTargetButton *pButton = new MyTargetButton(listString[i]);
        ui->selectTarConTableWidget->setCellWidget(i/3, i%3, pButton);
    }
}
