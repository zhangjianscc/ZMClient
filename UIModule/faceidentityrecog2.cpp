#include "faceidentityrecog2.h"
#include "ui_faceidentityrecog2.h"

FaceIdentityRecog2::FaceIdentityRecog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceIdentityRecog2)
{
    ui->setupUi(this);
}

FaceIdentityRecog2::~FaceIdentityRecog2()
{
    delete ui;
}
