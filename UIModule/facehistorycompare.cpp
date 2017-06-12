#include "facehistorycompare.h"
#include "ui_facehistorycompare.h"

FaceHistoryCompare::FaceHistoryCompare(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceHistoryCompare)
{
    ui->setupUi(this);
}

FaceHistoryCompare::~FaceHistoryCompare()
{
    delete ui;
}
