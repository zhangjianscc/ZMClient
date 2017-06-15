#include "maptrackitem.h"
#include "ui_maptrackitem.h"

MapTrackItem::MapTrackItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTrackItem)
{
    ui->setupUi(this);
}

MapTrackItem::~MapTrackItem()
{
    delete ui;
}

void MapTrackItem::setData(QPixmap pix,QString position,QString dateTime)
{
    ui->m_labelImage->setPixmap(pix);
    ui->m_labelPosition->setText(position);
    ui->m_labelDateTime->setText(dateTime);
}
