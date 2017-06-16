#include "mytwoimagecomparepane.h"
#include "ui_mytwoimagecomparepane.h"
#include "stable.h"

MyTwoImageComparePane::MyTwoImageComparePane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTwoImageComparePane)
{
    ui->setupUi(this);
}

MyTwoImageComparePane::~MyTwoImageComparePane()
{
    delete ui;
}

void MyTwoImageComparePane::setData(QPixmap pix1,QPixmap pix2,QString imageSource,double similar)
{
    ui->m_labelImage1->setPixmap(pix1);
    ui->m_labelImage2->setPixmap(pix2);
    ui->m_labelTitle->setText(imageSource);

    double value = similar * 100;
    value = value < 0?0:value;
    value = value > 100?100:value;
    ui->m_progressBar->setValue((int)value);

    ui->m_labelSimilar->setText(QString("%1%").arg(similar * 100));
}
