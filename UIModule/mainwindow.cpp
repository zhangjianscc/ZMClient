#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UIModule/Comm/mytoolbutton.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"
#include "UIModule/Comm/myimagewidget.h"
<<<<<<< HEAD
#include "realtimemonitorpane.h"
#include "UIModule/logindialog.h"
#include "Common/singleton.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "InterFaceToService/sysuser.h"
#include <vector>
#include "InterFaceToService/objformat.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
=======
#include "UIModule/Comm/mytargetbutton.h"
#include "warningwidget.h"
#include "realtimemonitorpane.h"
#include "faceonetoonepane.h"
#include "facehistorycompare.h"
#include "faceonetonpane.h"
#include "faceidentityrecog.h"
#include "faceonetonpane2.h"
#include "faceidentityrecog2.h"
#include "facehistorycompare2.h"
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
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
{
    initUserInfo();
    initMainFrame();
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
<<<<<<< HEAD
     //this->m_curWindowPos = this->pos();
     //this->m_curMousePos = event->globalPos();
     //this->m_destWindowPos = m_curMousePos - m_curWindowPos;
=======
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
<<<<<<< HEAD
     //this->move(event->globalPos() - this->m_destWindowPos);
}

void MainWindow::initMainFrame()
{
    // 主框架初始化
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 标题栏
    QWidget* pTitleWid = new QWidget();
    pTitleWid->setFixedHeight(35);
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

    m_pContentPane->addWidget(initMonitorConfigPane());       // 2

    m_pContentPane->addWidget(initOneToOneComparePane());     // 3

    m_pContentPane->addWidget(initOneToNComparePane());       // 4

    m_pContentPane->addWidget(initIdentityAuthenPane());      // 5

    m_pContentPane->addWidget(initHistoryFaceComparePane());  // 6

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
    QWidget* pWid = new QWidget();
    pWid->setMinimumWidth(250);
=======
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

    m_pFaceOneToNPane2 = new FaceOneToNPane2();
    m_pContentPane->addWidget(m_pFaceOneToNPane2);       // 4

    m_pFaceIdentityRecog2 = new FaceIdentityRecog2();
    m_pContentPane->addWidget(m_pFaceIdentityRecog2);      // 5

    m_pFaceHistoryCompare2 = new FaceHistoryCompare2();
    m_pContentPane->addWidget(m_pFaceHistoryCompare2);  // 6

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
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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

<<<<<<< HEAD
    m_pBtnHistoryFace = new MyToolButton("      历史人脸库对比");
=======
    m_pBtnHistoryFace = new MyToolButton("历史人脸库对比");
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    playout->addWidget(m_pBtnHistoryFace);
    m_pBtnHistoryFace->setVisible(false);
    connect(m_pBtnHistoryFace,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnHistoryFace()));

    m_pBtnModeManage = new MyToolButton("模板库管理","://images//左侧图标03.png","://images//左侧图标03-01.png");
    playout->addWidget(m_pBtnModeManage);
    connect(m_pBtnModeManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnModeManage()));

<<<<<<< HEAD
=======
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

>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    m_pBtnWarningManage = new MyToolButton("告警管理","://images//左侧图标04.png","://images//左侧图标04-01.png");
    playout->addWidget(m_pBtnWarningManage);
    connect(m_pBtnWarningManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnWarningManage()));

<<<<<<< HEAD
=======
    m_pBtnRealWarningManager = new MyToolButton("实时告警管理");
    playout->addWidget(m_pBtnRealWarningManager);
    m_pBtnRealWarningManager->setVisible(false);
    connect(m_pBtnRealWarningManager,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnRealWarningManager()));

>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    m_pBtnInfoManage = new MyToolButton("基础信息维护","://images//左侧图标05.png","://images//左侧图标05-01.png");
    playout->addWidget(m_pBtnInfoManage);
    connect(m_pBtnInfoManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnInfoManage()));

<<<<<<< HEAD
=======
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

>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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

<<<<<<< HEAD
QWidget* MainWindow::initRealTimeMonitorPane()
{

}

QWidget* MainWindow::initMonitorConfigPane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel("布控设置");
    QHBoxLayout* pLayout = new QHBoxLayout(pWid);
    pLayout->addWidget(pLabel);
    return pWid;
}

QWidget* MainWindow::initOneToOneComparePane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel("1:1对比");
    QHBoxLayout* pLayout = new QHBoxLayout(pWid);
    pLayout->addWidget(pLabel);
    return pWid;
}

QWidget* MainWindow::initOneToNComparePane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel("1：N对比");
    QHBoxLayout* pLayout = new QHBoxLayout(pWid);
    pLayout->addWidget(pLabel);
    return pWid;
}

QWidget* MainWindow::initIdentityAuthenPane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel("身份验证");
    QHBoxLayout* pLayout = new QHBoxLayout(pWid);
    pLayout->addWidget(pLabel);
    return pWid;
}

QWidget* MainWindow::initHistoryFaceComparePane()
{
    QWidget* pWid = new QWidget();
    QLabel* pLabel = new QLabel("历史人脸库对比");
    QHBoxLayout* pLayout = new QHBoxLayout(pWid);
    pLayout->addWidget(pLabel);
    return pWid;
}

=======
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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
<<<<<<< HEAD
void MainWindow::onSlotBtnRealTimeMonitor()
{
    m_pBtnRealTimeMonitor->setChecked(true);

    m_pContentPane->setCurrentIndex(1);
    m_pBtnMonitorConfig->setChecked(false);
    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnIndentify->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);

    updateRealTimeMonitorData();
}
void MainWindow::onSlotBtnMonitorConfig()
{
    m_pBtnMonitorConfig->setChecked(true);

    m_pContentPane->setCurrentIndex(2);
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnIndentify->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);
}
=======
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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
<<<<<<< HEAD
void MainWindow::onSlotBtnFaceOneToOne()
{
    m_pBtnFaceOneToOne->setChecked(true);

    m_pContentPane->setCurrentIndex(3);
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnMonitorConfig->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnIndentify->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);
}
void MainWindow::onSlotBtnFaceOneToN()
{
    m_pBtnFaceOneToN->setChecked(true);

    m_pContentPane->setCurrentIndex(4);
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnMonitorConfig->setChecked(false);
    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnIndentify->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);
}
void MainWindow::onSlotBtnIndentify()
{
    m_pBtnIndentify->setChecked(true);

    m_pContentPane->setCurrentIndex(5);
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnMonitorConfig->setChecked(false);
    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnHistoryFace->setChecked(false);
}
void MainWindow::onSlotBtnHistoryFace()
{
    m_pBtnHistoryFace->setChecked(true);

    m_pContentPane->setCurrentIndex(6);
    m_pBtnRealTimeMonitor->setChecked(false);
    m_pBtnMonitorConfig->setChecked(false);
    m_pBtnFaceOneToOne->setChecked(false);
    m_pBtnFaceOneToN->setChecked(false);
    m_pBtnIndentify->setChecked(false);
=======
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
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
}
void MainWindow::onSlotBtnModeManage()
{
    if(m_pBtnModeManage->isChecked())
    {
        m_pBtnModeManage->select();
<<<<<<< HEAD
=======
        m_pBtnTargetPersonManager->setVisible(true);
        m_pBtnTemplateManager->setVisible(true);
        m_pBtnLibraryManager->setVisible(true);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    }
    else
    {
        m_pBtnModeManage->unSelect();
<<<<<<< HEAD
=======
        m_pBtnTargetPersonManager->setVisible(false);
        m_pBtnTemplateManager->setVisible(false);
        m_pBtnLibraryManager->setVisible(false);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    }
}
void MainWindow::onSlotBtnWarningManage()
{
    if(m_pBtnWarningManage->isChecked())
    {
        m_pBtnWarningManage->select();
<<<<<<< HEAD
=======
        m_pBtnRealWarningManager->setVisible(true);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    }
    else
    {
        m_pBtnWarningManage->unSelect();
<<<<<<< HEAD
=======
        m_pBtnRealWarningManager->setVisible(false);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    }
}
void MainWindow::onSlotBtnInfoManage()
{
    if(m_pBtnInfoManage->isChecked())
    {
        m_pBtnInfoManage->select();
<<<<<<< HEAD
=======
        m_pBtnMonitorAreaMaintain->setVisible(true);
        m_pBtnMonitorPositionMaintain->setVisible(true);
        m_pBtnMonitorDeviceMaintain->setVisible(true);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    }
    else
    {
        m_pBtnInfoManage->unSelect();
<<<<<<< HEAD
=======
        m_pBtnMonitorAreaMaintain->setVisible(false);
        m_pBtnMonitorPositionMaintain->setVisible(false);
        m_pBtnMonitorDeviceMaintain->setVisible(false);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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

<<<<<<< HEAD
void MainWindow::updateRealTimeMonitorData()
{
    // by ly
    // 获取图片数据
    SocketManager* inst = Singleton<SocketManager>::Instance();
//    QString test = "{\"ACTION_NAME\": \"QUERY_SUSPECT_ALARM_WITH_PAGE\",\"PARAMS\": {\"PAGER\": {\"startIndex\": 1,\"pageSize\": 15,\"firstPage\": 1,\
//                \"endIndex\": 15,\"currentPage\": 1},\"PARAM\": {}}}";
    QString test = "{\
                   \"ACTION_NAME\": \"QUERY_SUSPECT_ALARM_REAL\",\
                   \"PARAMS\": {}\
               }";
    test += "\n\n";
    inst->sendMessage(test.toStdString().c_str());
    QString repStr = "";
    char RecvBuf[10000] = {0};       //接受的数据缓存
    int count = inst->receive(RecvBuf, 10000);
    QString resultString(RecvBuf);
    int falglength = resultString.indexOf(","); //查找返回字符串中长度结束符，
    int totalcount = resultString.left(falglength).toInt();
    int tempcount = resultString.trimmed().length();
    bool flagQuit = true;
    while (flagQuit)
    {
        count = inst->receive(RecvBuf, 10000);
        QString tempRet(RecvBuf);
        resultString += tempRet;
        tempcount += tempRet.trimmed().length();
        if(tempcount > totalcount)
        {
            flagQuit = false;
        }
    }
    resultString = resultString.mid(falglength + 1); //截断返回长度+，
    //repStr += resultString;
    //开始解析返回的数据
    QJsonParseError login_json_error;
    QString RET_CODE;    //返回标志
    QJsonArray  RET_LIST;    //数组数据
    std::vector<Sysuser> data;
    //RETJSON所有的元素
    QJsonDocument login_parse_doucment = QJsonDocument::fromJson(resultString.toUtf8(), &login_json_error);
    //检查json是否有错误
    if (login_json_error.error == QJsonParseError::NoError)
    {
        if (login_parse_doucment.isObject())
        {
            //开始解析json对象
            QJsonObject obj = login_parse_doucment.object();
            //如果包含RET_CODE
            if (obj.contains("RET_CODE"))
            {
                //得到RET_CODE
                QJsonValue ret_code_value = obj.take("RET_CODE");
                if (ret_code_value.isString())
                {
                    //转换RET_CODE
                    RET_CODE = ret_code_value.toVariant().toString();
                }
            }
//            if(obj.contains("RET_LIST"))
//            {
//                //得到RET_CODE
//                QJsonValue ret_list_value = obj.take("RET_LIST");
//                if (ret_list_value.isArray())
//                {
//                    //转换RET_CODE
//                   //RET_LIST =  QJsonDocument::fromJson(ret_list_value.toArray(), &login_json_error);
//                }
//            }
            if (obj.contains("RET_LIST"))
            {
                //得到RET_CODE
                QJsonValue ret_List_value = obj.take("RET_LIST");
                QJsonArray JsonArray= ret_List_value.toArray();

                for(int i = 0;i < JsonArray.size(); ++i)
                {

                    QJsonValue value=JsonArray.at(i);
                    if(value.isObject())
                    {
                        QJsonObject jsonobj=value.toObject();
                        Sysuser user;
                        ObjectFormat objF;
                        objF.FormatObject(jsonobj,user);
                        data.push_back(user);
                    }
                }
            }
        }
    }
    std::vector<Sysuser>::iterator it;
    for(it = data.begin(); it != data.end(); ++it)
    {
        RealTimeMonitorPane::stImageData stimagedata;
        stimagedata.time = (*it).alarmTime();
    }
=======

void MainWindow::slot_test()
{
    if(m_pTargetButton->isChecked())
    {
        m_pTargetButton->selected();
    }
    else
    {
        m_pTargetButton->unSelect();
    }
}

void MainWindow::updateRealTimeMonitorData()
{
    // by ly
    // 获取图片数据

>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    QList<RealTimeMonitorPane::stImageData> list;
    for(int i = 0 ; i < 9 ; i++)
    {
        RealTimeMonitorPane::stImageData data;
<<<<<<< HEAD
        data.pix = QPixmap("://images//head.jpg");
        data.date = "2017-6-5";
        data.time = "12:59:59";
        data.position = "成都市.高新区.天府五街";
        list.append(data);
    }
    m_pRealTimeMonitorPane->updateUIData(list);
=======
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
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
}




<<<<<<< HEAD
=======
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



>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

