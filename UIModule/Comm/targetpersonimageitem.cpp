#include "targetpersonimageitem.h"
#include "ui_targetpersonimageitem.h"

TargetPersonImageItem::TargetPersonImageItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetPersonImageItem)
{
    ui->setupUi(this);
}

TargetPersonImageItem::~TargetPersonImageItem()
{
    delete ui;
}

void TargetPersonImageItem::setData(QPixmap pix,QString name)
{
    m_pixmap = pix;
    m_imageName = name;
    ui->m_labelImage->setPixmap(pix);
    ui->m_labelImageName->setText(name);
}
