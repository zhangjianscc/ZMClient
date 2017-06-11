#include "librarymanager.h"
#include "ui_librarymanager.h"

LibraryManager::LibraryManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibraryManager)
{
    ui->setupUi(this);
}

LibraryManager::~LibraryManager()
{
    delete ui;
}
