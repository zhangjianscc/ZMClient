#include "faceidentitydiscern.h"
#include "ui_faceidentitydiscern.h"

FaceIdentityDiscern::FaceIdentityDiscern(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceIdentityDiscern)
{
    ui->setupUi(this);
}

FaceIdentityDiscern::~FaceIdentityDiscern()
{
    delete ui;
}
