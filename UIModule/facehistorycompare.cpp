#include "facehistorycompare.h"
#include "ui_facehistorycompare.h"
#include "UIModule/Comm/facehistoryimageitem.h"
#include "UIModule/maptrackpane.h"

FaceHistoryCompare::FaceHistoryCompare(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceHistoryCompare)
{
    ui->setupUi(this);
    initUI();
}

FaceHistoryCompare::~FaceHistoryCompare()
{
    delete ui;
}

void FaceHistoryCompare::initUI()
{
    // 选择图片按钮
    ui->m_btnSelectImage->setStyleSheet("QPushButton{border-image:url(://images//选择照片.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//选择照片-01.png);}"
                                              "QPushButton:pressed{border-image:url(://images//选择照片-02.png);}");
    connect(ui->m_btnSelectImage,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectImage()));

    // 开始比对按钮
    ui->m_btnBeginCompare->setStyleSheet("QPushButton{border-image:url(://images//btnBeginCompare-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//btnBeginCompare-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//btnBeginCompare-03.png);}");
    connect(ui->m_btnBeginCompare,SIGNAL(clicked(bool)),this,SLOT(onSlotBeginCompare()));

    // 生成行动轨迹按钮
    ui->m_btnRunTrack->setStyleSheet("QPushButton{border-image:url(://images//生成行动轨迹图-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//生成行动轨迹图-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//生成行动轨迹图-03.png);}");
    connect(ui->m_btnRunTrack,SIGNAL(clicked(bool)),this,SLOT(onSlotRunTrack()));

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

}

void FaceHistoryCompare::onSlotSelectImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择照片"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        QPixmap pix(fileName);
        ui->m_laelImage->setPixmap(pix);
    }
}
void FaceHistoryCompare::onSlotBeginCompare()
{
    // by ly
    QList<FaceHistoryCompareData> list;
    for(int i = 0 ;i < 4 ; ++i)
    {
        FaceHistoryCompareData data;
        data.pix = QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1));
        data.address = "乌鲁木齐市";
        data.dateTime = "2017-05-05 12:12:59";
        data.similar = 0.18 * (i+1);
        list.append(data);
    }
    initCompareResultTable(list);
}
void FaceHistoryCompare::onSlotRunTrack()
{
    MapTrackPane* pane = new MapTrackPane(NULL);
    pane->show();
}
void FaceHistoryCompare::initCompareResultTable(QList<FaceHistoryCompareData> list)
{
    // 初始化表格
    ui->m_tableCompareResult->clearContents();
    ui->m_tableCompareResult->setColumnCount(2);
    ui->m_tableCompareResult->setColumnWidth(0,ui->m_tableCompareResult->width()/2);
    ui->m_tableCompareResult->setColumnWidth(1,ui->m_tableCompareResult->width()/2);
    ui->m_tableCompareResult->setRowCount(list.size()/2 + list.size()%2);

    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        FaceHistoryImageItem* pItem = new FaceHistoryImageItem();
        pItem->setData(list[i].pix,list[i].address,list[i].dateTime,list[i].similar);
        int hei = pItem->height() + 10;
        ui->m_tableCompareResult->setRowHeight(i/2,hei);
        ui->m_tableCompareResult->setCellWidget(i/2,i%2,pItem);
    }
}










