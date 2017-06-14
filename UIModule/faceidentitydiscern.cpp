#include "faceidentitydiscern.h"
#include "ui_faceidentitydiscern.h"

FaceIdentityDiscern::FaceIdentityDiscern(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceIdentityDiscern)
{
    ui->setupUi(this);
    initUI();
}

FaceIdentityDiscern::~FaceIdentityDiscern()
{
    delete ui;
}

void FaceIdentityDiscern::initUI()
{
    ui->btnBeginCompare->setText("");

    // 搜索框
    ui->m_editSearch->setTextMargins(5, 0, 40, 0);
    ui->m_editSearch->setStyleSheet("QLineEdit{border:1px solid rgb(180,180,180);background-color:rgb(255,255,255)}");
    QPushButton* pSearchBtn = new QPushButton();
    pSearchBtn->setFixedSize(20,20);
    pSearchBtn->setStyleSheet("QPushButton{border:none;border-image:url(://images//search-02.png);background-color:rgb(255,255,255);}"
                              "QPushButton:hover{border-image:url(://images//search-01.png)}"
                              "QPushButton:pressed{border-image:url(://images//search-02.png)}");
    connect(pSearchBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotSearchBtnClicked()));
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,10,0);
    layout->addStretch();
    layout->addWidget(pSearchBtn,0,Qt::AlignCenter);
    ui->m_editSearch->setLayout(layout);
}

void FaceIdentityDiscern::onSlotSearchBtnClicked()
{}
