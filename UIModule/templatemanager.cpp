#include "templatemanager.h"
#include "ui_templatemanager.h"

TemplateManager::TemplateManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateManager)
{
    ui->setupUi(this);
}

TemplateManager::~TemplateManager()
{
    delete ui;
}
