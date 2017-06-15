#include "facehistoryimageitem.h"
#include "ui_facehistoryimageitem.h"
#include "stable.h"

FaceHistoryImageItem::FaceHistoryImageItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceHistoryImageItem)
{
    ui->setupUi(this);
    initUI();
}

FaceHistoryImageItem::~FaceHistoryImageItem()
{
    delete ui;
}

void FaceHistoryImageItem::initUI()
{
    ui->m_progressBar->setRange(0,100);
}

void FaceHistoryImageItem::setData(QPixmap pix,QString address,QString dateTime,double similar)
{
    ui->m_labelImage->setPixmap(pix);
    ui->m_labelAddress->setText(address);
    ui->m_labelDateTime->setText(dateTime);

    double value = similar * 100;
    ui->m_progressBar->setValue((int)value);

    ui->m_labelSimilar->setText(QString("%1%").arg(similar * 100));

}
