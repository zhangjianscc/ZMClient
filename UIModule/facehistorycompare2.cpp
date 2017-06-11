#include "facehistorycompare2.h"
#include "ui_facehistorycompare2.h"

FaceHistoryCompare2::FaceHistoryCompare2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceHistoryCompare2)
{
    ui->setupUi(this);
}

FaceHistoryCompare2::~FaceHistoryCompare2()
{
    delete ui;
}
