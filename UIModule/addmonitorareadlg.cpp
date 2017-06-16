#include "addmonitorareadlg.h"
#include "ui_addmonitorareadlg.h"

AddMonitorAreaDlg::AddMonitorAreaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMonitorAreaDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    initUi();
}

AddMonitorAreaDlg::~AddMonitorAreaDlg()
{
    delete ui;
}

void AddMonitorAreaDlg::initUi()
{
    QString string = "QPushButton{color:rgb(0,0,0); border:1px solid rgb(200,200,200); border-radius:5px;background-color:rgb(255,255,255)}"
                     "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                     "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}";
    ui->savePushButton->setStyleSheet(string);
    ui->cancelPushButton->setStyleSheet(string);
}

void AddMonitorAreaDlg::slot_saveButClicked()
{}

void AddMonitorAreaDlg::slot_cancelButClicked()
{}
