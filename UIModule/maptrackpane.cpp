#include "maptrackpane.h"
#include "ui_maptrackpane.h"

MapTrackPane::MapTrackPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTrackPane)
{
    ui->setupUi(this);
}

MapTrackPane::~MapTrackPane()
{
    delete ui;
}
