#include "maptrackpane.h"
#include "ui_maptrackpane.h"
#include "UIModule/Comm/maptrackitem.h"
#include <QVariant>
#include <QAbstractEventDispatcher>
#include <QUrl>
#include <QAxObject>
#include <QDateTime>
#include <QThread>

MapTrackPane::MapTrackPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTrackPane)
{
    ui->setupUi(this);
    initUI();

    // by ly

    //1
    MapTrackData data1;
    data1.pixmap = QPixmap("://images//head1.jpg");
    data1.postion = "中国新疆博览中心1";
    data1.dateTime = "2017-5-15 12:35:31";
    data1.latitude = 39.910;
    data1.longitude = 116.41;
    m_mapData.insert(QDateTime::fromString(data1.dateTime,"yyyy-MM-dd hh:mm:ss"),data1);

    //2
    MapTrackData data2;
    data2.pixmap = QPixmap("://images//head2.jpg");
    data2.postion = "中国新疆博览中心2";
    data2.dateTime = "2017-5-15 12:35:32";
    data2.latitude = 39.930;
    data2.longitude = 116.42;
    m_mapData.insert(QDateTime::fromString(data2.dateTime,"yyyy-MM-dd hh:mm:ss"),data2);

    //3
    MapTrackData data3;
    data3.pixmap = QPixmap("://images//head3.jpg");
    data3.postion = "中国新疆博览中心3";
    data3.dateTime = "2017-5-15 12:35:33";
    data3.latitude = 39.920;
    data3.longitude = 116.43;
    m_mapData.insert(QDateTime::fromString(data3.dateTime,"yyyy-MM-dd hh:mm:ss"),data3);

    //4
    MapTrackData data4;
    data4.pixmap = QPixmap("://images//head4.jpg");
    data4.postion = "中国新疆博览中心4";
    data4.dateTime = "2017-5-15 12:35:34";
    data4.latitude = 39.960;
    data4.longitude = 116.44;
    m_mapData.insert(QDateTime::fromString(data4.dateTime,"yyyy-MM-dd hh:mm:ss"),data4);

    //5
    MapTrackData data5;
    data5.pixmap = QPixmap("://images//head5.jpg");
    data5.postion = "中国新疆博览中心5";
    data5.dateTime = "2017-5-15 12:35:35";
    data5.latitude = 39.950;
    data5.longitude = 116.45;
    m_mapData.insert(QDateTime::fromString(data5.dateTime,"yyyy-MM-dd hh:mm:ss"),data5);

    //
    initTableData();
    loadMap();
    //QThread::sleep(5);
    //initMapData();
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
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    ui->m_btnReturn->setStyleSheet("QPushButton{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}"
                                   "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                                   "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}");
    connect(ui->m_btnReturn,SIGNAL(clicked(bool)),this,SLOT(onSlotReturn()));

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
    // 地图
    ui->webWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));
    ui->webWidget->setObjectName(QString::fromUtf8("webWidget"));
    //ui->webWidget->setFocusPolicy(Qt::StrongFocus);
    ui->webWidget->setProperty("DisplayAlerts",false);  //不显示任何警告信息。
    ui->webWidget->setProperty("DisplayScrollBars",false); // 显示滚动条
}

void MapTrackPane::loadMap()
{
    QString mapHtml=QDir::currentPath()+"/MapFile/BaiduMap.html";
    ui->webWidget->dynamicCall("Navigate(const QString&)",mapHtml);
}
void MapTrackPane::initMapData()
{
    QAxObject *document = ui->webWidget->querySubObject("Document");
    QAxObject *parentWindow = document->querySubObject("parentWindow");

    double x1,x2,x3,x4;
    double totalX = 0;
    double totalY = 0;
    QMap<QDateTime,MapTrackData>::const_iterator it = m_mapData.begin();
    for( ; it != m_mapData.end() ; ++it)
    {
        // 位置点 一个一个的加
        QString AddMarker = QString("AddMarker(\"%1\", \"%2\")").arg(it.value().longitude).arg(it.value().latitude);
        parentWindow->dynamicCall("execScript(QString,QString)",AddMarker,"JavaScript");

        // 绘制折线
        x1 = x3;
        x2 = x4;
        x3 = it.value().longitude;
        x4 = it.value().latitude;
        totalX += x3;
        totalY += x4;
        if(it != m_mapData.begin())
        {
            QString AddLine = QString("AddLine(\"%1\", \"%2\", \"%3\", \"%4\")").arg(x1).arg(x2).arg(x3).arg(x4);
            parentWindow->dynamicCall("execScript(QString,QString)",AddLine,"JavaScript");
        }
    }

    // 计算中心点
    double centerX = totalX/m_mapData.size();
    double centerY = totalY/m_mapData.size();
    QString SetViewCenter = QString("SetViewCenter(\"%1\", \"%2\")").arg(centerX).arg(centerY);
    parentWindow->dynamicCall("execScript(QString,QString)",SetViewCenter,"JavaScript");
}

void MapTrackPane::initTableData()
{
    ui->m_table->clearContents();
    ui->m_table->setColumnCount(1);
    ui->m_table->setRowCount(m_mapData.size());

    // 添加数据
    QMap<QDateTime,MapTrackData>::const_iterator it = m_mapData.begin();
    for(int i = 0 ; it != m_mapData.end() ; ++it,++i)
    {
        MapTrackItem* pItem = new MapTrackItem();
        pItem->setData(it.value().pixmap,it.value().postion,it.value().dateTime);

        ui->m_table->setRowHeight(i,pItem->height() + 3);
        ui->m_table->setCellWidget(i,0,pItem);
    }
}

void MapTrackPane::onSlotClose()
{
    this->close();
}
void MapTrackPane::onSlotReturn()
{
    initMapData();
}
