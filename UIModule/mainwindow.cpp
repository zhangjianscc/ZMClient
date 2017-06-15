#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UIModule/Comm/mytoolbutton.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"
#include "UIModule/Comm/myimagewidget.h"
#include "UIModule/Comm/mytargetbutton.h"
#include "warningwidget.h"
#include "realtimemonitorpane.h"
#include "faceonetoonepane.h"
#include "facehistorycompare.h"
#include "faceonetonpane.h"
#include "faceidentitydiscern.h"
#include "faceonetonpane.h"
#include "facehistorycompare.h"
#include "monitorconfigpane.h"
#include "targetpersonmanager.h"
#include "templatemanager.h"
#include "librarymanager.h"
#include "realwarningmanager.h"
#include "monitorareamaintain.h"
#include "monitorpositionmaintain.h"
#include "monitordevicemaintain.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    m_bIsMoveing(false)
{
    initUserInfo();
    initMainFrame();
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}

void MainWindow::initMainFrame()
{
    // 主框架初始化
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 标题栏
    QWidget* pTitleWid = new QWidget();
    pTitleWid->setFixedHeight(g_topMenuPaneHei);
    //pTitleWid->setStyleSheet("QWidget{color: rgb(238, 238, 238);border: 1px solid rgb(228,228,228);}");
    pTitleWid->setStyleSheet("QWidget{border-radius:0px;"
                                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(235, 235, 235), stop:1 rgb(170, 170, 170));}");

    QLabel* pLogLabel = new QLabel();
    pLogLabel->setStyleSheet("QLabel{border: none}");
    pLogLabel->setFixedSize(103,32);
    pLogLabel->setPixmap(QPixmap("://images//左上角logo.png"));
    pLogLabel->setScaledContents(true);

    QPushButton* pBtnMinimize = new QPushButton();
    pBtnMinimize->setFixedSize(30,26);
    pBtnMinimize->setStyleSheet("QPushButton{background-image:url(://images//shutdown-02.png);border: none;border-top-left-radius: 0px;"
                                "border-top-right-radius: 0px;border-bottom-left-radius: 5px;border-bottom-right-radius: 0px;}"
                                              "QPushButton:hover{background-image:url(://images//shutdown.png);}"
                                              "QPushButton:pressed{background-image:url(://images//shutdown.png);}");
    connect(pBtnMinimize,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMinimize()));

    QPushButton* pBtnClose = new QPushButton();
    pBtnClose->setFixedSize(33,26);
    pBtnClose->setStyleSheet("QPushButton{border-image:url(://images//shutdown-04.png);border: none;border-top-left-radius: 0px;"
                                  "border-top-right-radius: 0px;border-bottom-left-radius: 0px;border-bottom-right-radius: 5px;}"
                                              "QPushButton:hover{border-image:url(://images//shutdown-03.png);}"
                                              "QPushButton:pressed{border-image:url(://images//shutdown-03.png);}");
    connect(pBtnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnClose()));

    QHBoxLayout* playout = new QHBoxLayout(pTitleWid);
    playout->setContentsMargins(10,0,2,0);
    playout->setSpacing(0);
    playout->addWidget(pLogLabel,0,Qt::AlignVCenter);
    playout->addStretch();
    playout->addWidget(pBtnMinimize,0,Qt::AlignTop);
    playout->addWidget(pBtnClose,0,Qt::AlignTop);

    // 内容区域
    QWidget* pContentWid = new QWidget();
    QWidget* pNaviPane = initNavePane();

    m_pContentPane = new QStackedWidget();
    m_pContentPane->addWidget(initBackGroundImagePane());     // 0

    m_pRealTimeMonitorPane = new RealTimeMonitorPane();
    m_pContentPane->addWidget(m_pRealTimeMonitorPane);        // 1

    m_pMonitorConfigPane = new MonitorConfigPane();
    m_pContentPane->addWidget(m_pMonitorConfigPane);       // 2

    m_pFaceOneToOnePane = new FaceOneToOnePane();
    m_pContentPane->addWidget(m_pFaceOneToOnePane);     // 3

    m_pFaceOneToNPane = new FaceOneToNPane();
    m_pContentPane->addWidget(m_pFaceOneToNPane);       // 4

    m_pFaceIdentityDiscern = new FaceIdentityDiscern();
    m_pContentPane->addWidget(m_pFaceIdentityDiscern);      // 5

    m_pFaceHistoryCompare = new FaceHistoryCompare();
    m_pContentPane->addWidget(m_pFaceHistoryCompare);  // 6

    m_pTargetPersonManager = new TargetPersonManager();
    m_pContentPane->addWidget(m_pTargetPersonManager);  // 7

    m_pTemplateManager = new TemplateManager();
    m_pContentPane->addWidget(m_pTemplateManager);  // 8

    m_pLibraryManager = new LibraryManager();
    m_pContentPane->addWidget(m_pLibraryManager);  // 9

    m_pRealWarningManager = new RealWarningManager();
    m_pContentPane->addWidget(m_pRealWarningManager);  // 10

    m_pMonitorAreaMaintain = new MonitorAreaMaintain;
    m_pContentPane->addWidget(m_pMonitorAreaMaintain);  // 11

    m_pMonitorPositionMaintain = new MonitorPositionMaintain();
    m_pContentPane->addWidget(m_pMonitorPositionMaintain);  // 12

    m_pMonitorDeviceMaintain = new MonitorDeviceMaintain();
    m_pContentPane->addWidget(m_pMonitorDeviceMaintain);  // 13

    QHBoxLayout* playout2 = new QHBoxLayout(pContentWid);
    playout2->setMargin(0);
    playout2->setSpacing(0);
    playout2->addWidget(pNaviPane,1);
    playout2->addWidget(m_pContentPane,7);

    // 主布局
    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setMargin(0);
    pMainLayout->setSpacing(0);
    pMainLayout->addWidget(pTitleWid);
    pMainLayout->addWidget(pContentWid);

}

void MainWindow::onSlotBtnMinimize()
{
    this->showMinimized();
}

void MainWindow::onSlotBtnClose()
{
    this->close();
}

QWidget* MainWindow::initNavePane()
{
    int leftWid = g_leftNaviPaneWid;

    QWidget* pWid = new QWidget();
    pWid->setMinimumWidth(leftWid);
    pWid->setStyleSheet("QWidget{background-color:rgb(217,217,217);border: 1px solid rgb(180,180,180)}");
    QVBoxLayout* playout = new QVBoxLayout(pWid);
    playout->setMargin(0);
    playout->setSpacing(0);

    QWidget* pWidTitle = new QWidget();
    pWidTitle->setFixedHeight(80);
    initUserPane(pWidTitle);
    playout->addWidget(pWidTitle);


    m_pBtnNaviCtr = new MyToolButton("布控","://images//左侧图标01.png","://images//左侧图标01-02.png");
    playout->addWidget(m_pBtnNaviCtr);
    connect(m_pBtnNaviCtr,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    m_pBtnRealTimeMonitor = new MyToolButton("实时监控");
    playout->addWidget(m_pBtnRealTimeMonitor);
    m_pBtnRealTimeMonitor->setVisible(false);
    connect(m_pBtnRealTimeMonitor,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnRealTimeMonitor()));

    m_pBtnMonitorConfig = new MyToolButton("布控设置");
    playout->addWidget(m_pBtnMonitorConfig);
    m_pBtnMonitorConfig->setVisible(false);
    connect(m_pBtnMonitorConfig,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMonitorConfig()));

    m_pBtnFaceDetection = new MyToolButton("人脸识别","://images//左侧图标02.png","://images//左侧图标02-02.png");
    playout->addWidget(m_pBtnFaceDetection);
    connect(m_pBtnFaceDetection,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnFaceDetection()));

    m_pBtnFaceOneToOne = new MyToolButton("1:1对比");
    playout->addWidget(m_pBtnFaceOneToOne);
    m_pBtnFaceOneToOne->setVisible(false);
    connect(m_pBtnFaceOneToOne,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnFaceOneToOne()));

    m_pBtnFaceOneToN = new MyToolButton("1:N对比");
    playout->addWidget(m_pBtnFaceOneToN);
    m_pBtnFaceOneToN->setVisible(false);
    connect(m_pBtnFaceOneToN,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnFaceOneToN()));

    m_pBtnIndentify = new MyToolButton("身份验证");
    playout->addWidget(m_pBtnIndentify);
    m_pBtnIndentify->setVisible(false);
    connect(m_pBtnIndentify,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnIndentify()));

    m_pBtnHistoryFace = new MyToolButton("历史人脸库对比");
    playout->addWidget(m_pBtnHistoryFace);
    m_pBtnHistoryFace->setVisible(false);
    connect(m_pBtnHistoryFace,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnHistoryFace()));

    m_pBtnModeManage = new MyToolButton("模板库管理","://images//左侧图标03.png","://images//左侧图标03-01.png");
    playout->addWidget(m_pBtnModeManage);
    connect(m_pBtnModeManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnModeManage()));

    m_pBtnTargetPersonManager = new MyToolButton("目标人管理");
    playout->addWidget(m_pBtnTargetPersonManager);
    m_pBtnTargetPersonManager->setVisible(false);
    connect(m_pBtnTargetPersonManager,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnTargetPersonManager()));

    m_pBtnTemplateManager = new MyToolButton("模板管理");
    playout->addWidget(m_pBtnTemplateManager);
    m_pBtnTemplateManager->setVisible(false);
    connect(m_pBtnTemplateManager,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnTemplateManager()));

    m_pBtnLibraryManager = new MyToolButton("库管理");
    playout->addWidget(m_pBtnLibraryManager);
    m_pBtnLibraryManager->setVisible(false);
    connect(m_pBtnLibraryManager,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnLibraryManager()));

    m_pBtnWarningManage = new MyToolButton("告警管理","://images//左侧图标04.png","://images//左侧图标04-01.png");
    playout->addWidget(m_pBtnWarningManage);
    connect(m_pBtnWarningManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnWarningManage()));

    m_pBtnRealWarningManager = new MyToolButton("实时告警管理");
    playout->addWidget(m_pBtnRealWarningManager);
    m_pBtnRealWarningManager->setVisible(false);
    connect(m_pBtnRealWarningManager,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnRealWarningManager()));

    m_pBtnInfoManage = new MyToolButton("基础信息维护","://images//左侧图标05.png","://images//左侧图标05-01.png");
    playout->addWidget(m_pBtnInfoManage);
    connect(m_pBtnInfoManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnInfoManage()));

    m_pBtnMonitorAreaMaintain = new MyToolButton("监控区域信息维护");
    playout->addWidget(m_pBtnMonitorAreaMaintain);
    m_pBtnMonitorAreaMaintain->setVisible(false);
    connect(m_pBtnMonitorAreaMaintain,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMonitorAreaMaintain()));

    m_pBtnMonitorPositionMaintain = new MyToolButton("监控位置信息维护");
    playout->addWidget(m_pBtnMonitorPositionMaintain);
    m_pBtnMonitorPositionMaintain->setVisible(false);
    connect(m_pBtnMonitorPositionMaintain,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMonitorPositionMaintain()));

    m_pBtnMonitorDeviceMaintain = new MyToolButton("人脸采集设备信息维护");
    playout->addWidget(m_pBtnMonitorDeviceMaintain);
    m_pBtnMonitorDeviceMaintain->setVisible(false);
    connect(m_pBtnMonitorDeviceMaintain,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnDeviceMaintain()));

    playout->addStretch();

    return pWid;
}

QWidget* MainWindow::initBackGroundImagePane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel();
    pLabel->setScaledContents(true);
    pLabel->setPixmap(QPixmap("://images//01主界面.png"));
    QHBoxLayout* playout = new QHBoxLayout(pWid);
    playout->setMargin(0);
    playout->addWidget(pLabel);
    return pWid;
}

void MainWindow::onSlotBtnNaviCtr()
{
    if(m_pBtnNaviCtr->isChecked())
    {
        m_pBtnNaviCtr->select();
        m_pBtnRealTimeMonitor->setVisible(true);
        m_pBtnMonitorConfig->setVisible(true);
    }
    else
    {
        m_pBtnNaviCtr->unSelect();
        m_pBtnRealTimeMonitor->setVisible(false);
        m_pBtnMonitorConfig->setVisible(false);
    }
}

void MainWindow::onSlotBtnFaceDetection()
{
    if(m_pBtnFaceDetection->isChecked())
    {
        m_pBtnFaceDetection->select();
        m_pBtnFaceOneToOne->setVisible(true);
        m_pBtnFaceOneToN->setVisible(true);
        m_pBtnIndentify->setVisible(true);
        m_pBtnHistoryFace->setVisible(true);
    }
    else
    {
        m_pBtnFaceDetection->unSelect();
        m_pBtnFaceOneToOne->setVisible(false);
        m_pBtnFaceOneToN->setVisible(false);
        m_pBtnIndentify->setVisible(false);
        m_pBtnHistoryFace->setVisible(false);
    }
}
void MainWindow::onSlotBtnRealTimeMonitor()
{
    m_pContentPane->setCurrentIndex(1);

    checkPane(m_pBtnRealTimeMonitor);

    updateRealTimeMonitorData();
}
void MainWindow::onSlotBtnMonitorConfig()
{
    m_pContentPane->setCurrentIndex(2);

    checkPane(m_pBtnMonitorConfig);

    test();
}
void MainWindow::onSlotBtnFaceOneToOne()
{
    m_pContentPane->setCurrentIndex(3);
    checkPane(m_pBtnFaceOneToOne);
}
void MainWindow::onSlotBtnFaceOneToN()
{
    m_pContentPane->setCurrentIndex(4);
    checkPane(m_pBtnFaceOneToN);
}
void MainWindow::onSlotBtnIndentify()
{
    m_pContentPane->setCurrentIndex(5);
    checkPane(m_pBtnIndentify);
}
void MainWindow::onSlotBtnHistoryFace()
{
    m_pContentPane->setCurrentIndex(6);
    checkPane(m_pBtnHistoryFace);
}
void MainWindow::onSlotBtnTargetPersonManager()
{
    m_pContentPane->setCurrentIndex(7);
    checkPane(m_pBtnTargetPersonManager);
}
void MainWindow::onSlotBtnTemplateManager()
{
    m_pContentPane->setCurrentIndex(8);
    checkPane(m_pBtnTemplateManager);
}
void MainWindow::onSlotBtnLibraryManager()
{
    m_pContentPane->setCurrentIndex(9);
    checkPane(m_pBtnLibraryManager);
}
void MainWindow::onSlotBtnRealWarningManager()
{
    m_pContentPane->setCurrentIndex(10);
    checkPane(m_pBtnRealWarningManager);
}
void MainWindow::onSlotBtnMonitorAreaMaintain()
{
    m_pContentPane->setCurrentIndex(11);
    checkPane(m_pBtnMonitorAreaMaintain);
}
void MainWindow::onSlotBtnMonitorPositionMaintain()
{
    m_pContentPane->setCurrentIndex(12);
    checkPane(m_pBtnMonitorPositionMaintain);
}
void MainWindow::onSlotBtnDeviceMaintain()
{
    m_pContentPane->setCurrentIndex(13);
    checkPane(m_pBtnMonitorDeviceMaintain);
}
void MainWindow::onSlotBtnModeManage()
{
    if(m_pBtnModeManage->isChecked())
    {
        m_pBtnModeManage->select();
        m_pBtnTargetPersonManager->setVisible(true);
        m_pBtnTemplateManager->setVisible(true);
        m_pBtnLibraryManager->setVisible(true);
    }
    else
    {
        m_pBtnModeManage->unSelect();
        m_pBtnTargetPersonManager->setVisible(false);
        m_pBtnTemplateManager->setVisible(false);
        m_pBtnLibraryManager->setVisible(false);
    }
}
void MainWindow::onSlotBtnWarningManage()
{
    if(m_pBtnWarningManage->isChecked())
    {
        m_pBtnWarningManage->select();
        m_pBtnRealWarningManager->setVisible(true);
    }
    else
    {
        m_pBtnWarningManage->unSelect();
        m_pBtnRealWarningManager->setVisible(false);
    }
}
void MainWindow::onSlotBtnInfoManage()
{
    if(m_pBtnInfoManage->isChecked())
    {
        m_pBtnInfoManage->select();
        m_pBtnMonitorAreaMaintain->setVisible(true);
        m_pBtnMonitorPositionMaintain->setVisible(true);
        m_pBtnMonitorDeviceMaintain->setVisible(true);
    }
    else
    {
        m_pBtnInfoManage->unSelect();
        m_pBtnMonitorAreaMaintain->setVisible(false);
        m_pBtnMonitorPositionMaintain->setVisible(false);
        m_pBtnMonitorDeviceMaintain->setVisible(false);
    }
}

void MainWindow::initUserPane(QWidget* pWid)
{
    // 用户图标
    QLabel* pLabelUserIcon = new QLabel();
    pLabelUserIcon->setPixmap(QPixmap("://images//用户小图标.png"));
    pLabelUserIcon->setStyleSheet("QLabel{border:none;}");

    //  欢迎 语
    QLabel* pLabelWelcome = new QLabel();
    pLabelWelcome->setText(QString("欢迎%1").arg(m_strUserType));
    pLabelWelcome->setStyleSheet("QLabel{border:none;font: 10pt}");

    // 注销按钮
    QPushButton* pBtnLogout = new QPushButton();
    pBtnLogout->setStyleSheet("QPushButton{border-image:url(://images//注销按钮.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//注销按钮.png);}"
                                              "QPushButton:pressed{border-image:url(://images//注销按钮.png);}");
    // 用户名
    QLabel* pLabelUserName = new QLabel();
    pLabelUserName->setText(m_strUserName);
    pLabelUserName->setStyleSheet("QLabel{border:none;font: 16pt Arial Black;}");

    // 日期时间
    QLabel* pLabelDateTime = new QLabel();
    QDateTime time = QDateTime::currentDateTime();
    pLabelDateTime->setText(time.toString("yyyy年MM月dd日 hh:mm:ss"));
    pLabelDateTime->setStyleSheet("QLabel{border:none;font: 10pt}");

    QHBoxLayout* playout = new QHBoxLayout();
    playout->addStretch();
    playout->addWidget(pLabelUserIcon);
    playout->addWidget(pLabelWelcome);
    playout->addWidget(pBtnLogout);
    playout->addStretch();

    QVBoxLayout* pMainLayout = new QVBoxLayout(pWid);
    pMainLayout->addLayout(playout);
    pMainLayout->addWidget(pLabelUserName,0,Qt::AlignHCenter);
    pMainLayout->addWidget(pLabelDateTime,0,Qt::AlignHCenter);
}

void MainWindow::initUserInfo()
{
    // by ly
    m_strUserName = "administrator";
    m_strUserType = "管理员";
}

void MainWindow::updateRealTimeMonitorData()
{
    // by ly
    // 获取图片数据

    QList<RealTimeMonitorPane::stImageData> list;
    for(int i = 0 ; i < 9 ; i++)
    {
        RealTimeMonitorPane::stImageData data;
        data.name = QString("image%1").arg(i);
        QString str = QString("://images//head%1.jpg").arg(qrand()%7 + 1);
        //qDebug()<<str;
        data.pix = QPixmap(str);
        data.date = "2017-06-05";
        data.time = "12:59:59";
        data.position = "成都市.高新区.天府二街";
        list.append(data);
    }
    m_pRealTimeMonitorPane->updateImageData(list);
}




void MainWindow::checkPane(MyToolButton* pBtn)
{
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnMonitorConfig->setChecked(false);

    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnIndentify->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);

    m_pBtnRealWarningManager->setChecked(false);

    m_pBtnTargetPersonManager->setChecked(false);
    m_pBtnTemplateManager->setChecked(false);
    m_pBtnLibraryManager->setChecked(false);

    m_pBtnMonitorAreaMaintain->setChecked(false);
    m_pBtnMonitorPositionMaintain->setChecked(false);
    m_pBtnMonitorDeviceMaintain->setChecked(false);

    pBtn->setChecked(true);
}



void MainWindow::test()
{
    QList<QString> listString;
    for(int i=0; i<5; ++i)
    {
        listString.append(tr("全国失踪人口库A"));
        listString.append(tr("全国失踪人口库B"));
        listString.append(tr("全国失踪人口库C"));
        listString.append(tr("全国失踪人口库D"));
        listString.append(tr("全国失踪人口库E"));
    }

    m_pMonitorConfigPane->loadInfo(listString);
}
