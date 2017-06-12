#include "faceonetonpane.h"
#include "ui_faceonetonpane.h"

FaceOneToNPane::FaceOneToNPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceOneToNPane)
{
    ui->setupUi(this);
}

FaceOneToNPane::~FaceOneToNPane()
{
    delete ui;
}
