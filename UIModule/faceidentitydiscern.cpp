#include "faceidentitydiscern.h"
#include "ui_faceidentitydiscern.h"
#include "UIModule/Comm/mytwoimagecomparepane.h"

FaceIdentityDiscern::FaceIdentityDiscern(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceIdentityDiscern)
{
    ui->setupUi(this);
    initUI();
    initCameraImage(QPixmap("://images//head3.jpg"));
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

    // 比对结果table
    ui->m_tableCompareResult->horizontalHeader()->setVisible(false);
    ui->m_tableCompareResult->verticalHeader()->setVisible(false);
    ui->m_tableCompareResult->setColumnCount(2);
    ui->m_tableCompareResult->setShowGrid(false);
    ui->m_tableCompareResult->horizontalHeader()->setStretchLastSection(true);
    ui->m_tableCompareResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_tableCompareResult->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->m_tableCompareResult->setSelectionMode(QAbstractItemView::NoSelection);
    ui->m_tableCompareResult->setFocusPolicy(Qt::NoFocus);
    ui->m_tableCompareResult->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");

    // 对比按钮
    connect(ui->btnBeginCompare,SIGNAL(clicked(bool)),this,SLOT(onSlotBeginCompare()));

}

void FaceIdentityDiscern::onSlotSearchBtnClicked()
{
    QString name = ui->m_editSearch->text();
    ui->m_labelTargetPerson->setText(name);
    // by ly
    QList<QPixmap> list;
    for(int i = 0 ; i < 6 ; ++i)
    {
        list.append(QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1)));
    }
    initTargetPerson(list);
}

void FaceIdentityDiscern::initCameraImage(QPixmap pix)
{
    ui->m_labelCameraImage->setPixmap(pix);
}

void FaceIdentityDiscern::initTargetPerson(QList<QPixmap> list)
{
    if(list.size() > 0)
    {
        ui->m_labelTargetImage1->setPixmap(list[0]);
    }
    else
    {
        ui->m_labelTargetImage1->setPixmap(QPixmap());
    }

    if(list.size() > 1)
    {
        ui->m_labelTargetImage2->setPixmap(list[1]);
    }
    else
    {
        ui->m_labelTargetImage2->setPixmap(QPixmap());
    }

    if(list.size() > 2)
    {
        ui->m_labelTargetImage3->setPixmap(list[2]);
    }
    else
    {
        ui->m_labelTargetImage3->setPixmap(QPixmap());
    }

    if(list.size() > 3)
    {
        ui->m_labelTargetImage4->setPixmap(list[3]);
    }
    else
    {
        ui->m_labelTargetImage4->setPixmap(QPixmap());
    }

    if(list.size() > 4)
    {
        ui->m_labelTargetImage5->setPixmap(list[4]);
    }
    else
    {
        ui->m_labelTargetImage5->setPixmap(QPixmap());
    }

    if(list.size() > 5)
    {
        ui->m_labelTargetImage6->setPixmap(list[5]);
    }
    else
    {
        ui->m_labelTargetImage6->setPixmap(QPixmap());
    }

}

void FaceIdentityDiscern::initCompareResultTable(QList<CompareResultData> list)
{
    ui->m_tableCompareResult->clearContents();
    ui->m_tableCompareResult->setColumnCount(1);
    ui->m_tableCompareResult->setRowCount(list.size());


    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MyTwoImageComparePane* pBtn = new MyTwoImageComparePane();
        pBtn->setData(list[i].pix1,list[i].pix2,list[i].imageSource,list[i].similar);
        ui->m_tableCompareResult->setCellWidget(i,0,pBtn);
        ui->m_tableCompareResult->setRowHeight(i,pBtn->height() + 3);
    }
}

void FaceIdentityDiscern::onSlotBeginCompare()
{
    // by ly
    QList<CompareResultData> list;
    for(int i = 1 ;i < 6 ; ++i)
    {
        CompareResultData da;
        da.pix1 = QPixmap(QString("://images//head%1.jpg").arg(i));
        da.pix2 = QPixmap(QString("://images//head%1.jpg").arg(i+1));
        da.imageSource = QString("全国失踪人口库%1").arg(i+1);
        da.similar = 0.18 * i;
        list.append(da);
    }
    initCompareResultTable(list);
}






