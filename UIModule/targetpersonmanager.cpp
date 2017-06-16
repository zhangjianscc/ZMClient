#include "targetpersonmanager.h"
#include "ui_targetpersonmanager.h"
#include "UIModule/Comm/mytablewidget.h"

TargetPersonManager::TargetPersonManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetPersonManager)
{
    ui->setupUi(this);
}

TargetPersonManager::~TargetPersonManager()
{
    delete ui;
}
