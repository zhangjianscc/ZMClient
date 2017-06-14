#include "targetpersonmanager.h"
#include "ui_targetpersonmanager.h"

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
