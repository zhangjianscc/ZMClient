#include "mytablewidget.h"
#include "ui_mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTableWidget)
{
    ui->setupUi(this);
    initUI();
}

MyTableWidget::~MyTableWidget()
{
    delete ui;
}

void MyTableWidget::initUI()
{}

void MyTableWidget::updateTableData(int page)
{}

void MyTableWidget::initColumHeader(QStringList list)
{}
void MyTableWidget::bindData(QList<QList<QString>> list)
{}
void MyTableWidget::setHorizatalHeaderVisible(bool visible)
{}
void MyTableWidget::setVerticalHeaderVisible(bool visible)
{}
void MyTableWidget::setOperatorColumVisible(bool visible)
{}
void MyTableWidget::setPageRowCount(int count)
{}
void MyTableWidget::setCellWidget(int rowNumber,int columNumber,QWidget* pwid)
{}
void MyTableWidget::updateNaviBtn()
{}
void MyTableWidget::onBtnSelectAll()
{}
void MyTableWidget::onBtnReSelectAll()
{}
void MyTableWidget::onBtnDelete()
{}
void MyTableWidget::onBtnPageFirst()
{}
void MyTableWidget::onBtnPagePre()
{}
void MyTableWidget::onBtnPage1()
{}
void MyTableWidget::onBtnPage2()
{}
void MyTableWidget::onBtnPage3()
{}
void MyTableWidget::onBtnPage4()
{}
void MyTableWidget::onBtnPage5()
{}
void MyTableWidget::onBtnPageNext()
{}
void MyTableWidget::onBtnPageLast()
{}
void MyTableWidget::onBtnEdit()
{}
