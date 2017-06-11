#include "realwarningmanager.h"
#include "ui_realwarningmanager.h"

RealWarningManager::RealWarningManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealWarningManager)
{
    ui->setupUi(this);
}

RealWarningManager::~RealWarningManager()
{
    delete ui;
}
