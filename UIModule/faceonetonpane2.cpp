#include "faceonetonpane2.h"
#include "ui_faceonetonpane2.h"

FaceOneToNPane2::FaceOneToNPane2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceOneToNPane2)
{
    ui->setupUi(this);
}

FaceOneToNPane2::~FaceOneToNPane2()
{
    delete ui;
}
