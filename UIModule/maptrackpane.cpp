#include "maptrackpane.h"
#include "ui_maptrackpane.h"
#include "UIModule/Comm/maptrackitem.h"

MapTrackPane::MapTrackPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTrackPane)
{
    ui->setupUi(this);
    initUI();

    // by ly
    QList<MapTrackData> list;
    for(int i = 0 ; i < 5 ; ++i)
    {
        MapTrackData data;
        data.pixmap = QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1));
        data.postion = QString("中国新疆博览中心%1").arg(i);
        data.dateTime = QString("2017-5-15 12:35:3%1").arg(i);
        list.append(data);
        initTable(list);
    }
}

MapTrackPane::~MapTrackPane()
{
    delete ui;
}

void MapTrackPane::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    QPixmap pix("://images//1080-680.png");
    this->setMask(pix.mask());

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotReturn()));

    // 目标库table
    ui->m_table->horizontalHeader()->setVisible(false);
    ui->m_table->verticalHeader()->setVisible(false);
    ui->m_table->setColumnCount(1);
    ui->m_table->setShowGrid(false);
    ui->m_table->horizontalHeader()->setStretchLastSection(true);
    ui->m_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->m_table->setSelectionMode(QAbstractItemView::NoSelection);
    ui->m_table->setFocusPolicy(Qt::NoFocus);
    ui->m_table->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");
}

void MapTrackPane::initTable(QList<MapTrackData> list)
{
    ui->m_table->clearContents();
    ui->m_table->setColumnCount(1);
    ui->m_table->setRowCount(list.size());


    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MapTrackItem* pItem = new MapTrackItem();
        pItem->setData(list[i].pixmap,list[i].postion,list[i].dateTime);
        //QWidget* pWid = new QWidget();
        //QHBoxLayout* pLayout = new QHBoxLayout(pWid);
        //pLayout->setMargin(0);
        //pLayout->addWidget(pItem,0,Qt::AlignHCenter);

        ui->m_table->setRowHeight(i,pItem->height() + 3);
        ui->m_table->setCellWidget(i,0,pItem);
    }
}

void MapTrackPane::onSlotReturn()
{
    this->close();
}
