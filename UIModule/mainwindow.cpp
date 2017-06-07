#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UIModule/Comm/mytreeitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    initMainFrame();
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
     //this->m_curWindowPos = this->pos();
     //this->m_curMousePos = event->globalPos();
     //this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
     //this->move(event->globalPos() - this->m_destWindowPos);
}

void MainWindow::initMainFrame()
{
    // 主框架初始化
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 标题栏
    QWidget* pTitleWid = new QWidget();
    pTitleWid->setFixedHeight(35);
    pTitleWid->setStyleSheet("QWidget{color: rgb(238, 238, 238);border: 1px solid rgb(228,228,228);}");

    QLabel* pLogLabel = new QLabel();
    pLogLabel->setStyleSheet("QLabel{border: none}");
    pLogLabel->setFixedSize(103,32);
    pLogLabel->setPixmap(QPixmap("://images//左上角logo.png"));
    pLogLabel->setScaledContents(true);

    QPushButton* pBtnMinimize = new QPushButton();
    pBtnMinimize->setFixedSize(30,26);
    pBtnMinimize->setStyleSheet("QPushButton{background-image:url(://images//shutdown-02.png);border: none;border-top-left-radius: 0px;}"
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
    playout->setContentsMargins(10,0,10,0);
    playout->setSpacing(0);
    playout->addWidget(pLogLabel,0,Qt::AlignVCenter);
    playout->addStretch();
    playout->addWidget(pBtnMinimize,0,Qt::AlignTop);
    playout->addWidget(pBtnClose,0,Qt::AlignTop);

    // 内容区域
    QWidget* pContentWid = new QWidget();
    QWidget* pNaviPane = initNavePane();

    QStackedWidget* pContentPane = new QStackedWidget();
    pContentPane->addWidget(initBackGroundImagePane());     // 0
    pContentPane->addWidget(initRealTimeMonitorPane());     // 1
    pContentPane->addWidget(initWarningPane());             // 2
    pContentPane->addWidget(initMonitorConfigPane());       // 3
    pContentPane->addWidget(initOneToOneComparePane());     // 4
    pContentPane->addWidget(initOneToNComparePane());       // 5
    pContentPane->addWidget(initIdentityAuthenPane());      // 6
    pContentPane->addWidget(initHistoryFaceComparePane());  // 7
    QHBoxLayout* playout2 = new QHBoxLayout(pContentWid);
    playout2->setMargin(0);
    playout2->setSpacing(0);
    playout2->addWidget(pNaviPane,1);
    playout2->addWidget(pContentPane,7);

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
    pWid->setMinimumWidth(200);
    pWid->setStyleSheet("QWidget{background-color:rgb(217,217,217);border: 1px solid rgb(180,180,180)}");
    QVBoxLayout* playout = new QVBoxLayout(pWid);
    playout->setMargin(0);
    playout->setSpacing(0);

    QWidget* pWidTitle = new QWidget();
    pWidTitle->setFixedHeight(120);
    playout->addWidget(pWidTitle);

    QToolButton* pBtn;

    m_pBtnNaviCtr = addClassifyButton("布控","://images//左侧图标01.png","://images//左侧图标01-02.png");
    playout->addWidget(m_pBtnNaviCtr);
    connect(m_pBtnNaviCtr,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    m_pBtnRealTimeMonitor = addDetailButton("实时监控");
    playout->addWidget(m_pBtnRealTimeMonitor);
    m_pBtnRealTimeMonitor->setVisible(false);
    connect(m_pBtnRealTimeMonitor,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnRealTimeMonitor()));

    m_pBtnMonitorConfig = addDetailButton("布控设置");
    playout->addWidget(m_pBtnMonitorConfig);
    m_pBtnMonitorConfig->setVisible(false);
    connect(m_pBtnMonitorConfig,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMonitorConfig()));

    pBtn = addClassifyButton("人脸识别","://images//左侧图标02.png","://images//左侧图标02-02.png");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addDetailButton("1:1对比");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addDetailButton("1:N对比");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addDetailButton("身份验证");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addDetailButton("历史人脸库对比");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addClassifyButton("模板库管理","://images//左侧图标03.png","://images//左侧图标03-01.png");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addClassifyButton("告警管理","://images//左侧图标04.png","://images//左侧图标04-01.png");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

    pBtn = addClassifyButton("基础信息维护","://images//左侧图标05.png","://images//左侧图标05-01.png");
    playout->addWidget(pBtn);
    connect(pBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnNaviCtr()));

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

QWidget* MainWindow::initRealTimeMonitorPane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initWarningPane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initMonitorConfigPane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initOneToOneComparePane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initOneToNComparePane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initIdentityAuthenPane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QWidget* MainWindow::initHistoryFaceComparePane()
{
    QWidget* pWid = new QWidget();
    return pWid;
}

QToolButton* MainWindow::addClassifyButton(QString text,QString icon1,QString icon2)
{
    QToolButton* pBtn;

    pBtn = new QToolButton();
    pBtn->setText(text);
    pBtn->setIcon(QIcon(QPixmap(icon1)));
    pBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    pBtn->setCheckable(true);
    pBtn->setIconSize(QSize(21,20));
    pBtn->setFixedHeight(40);
    pBtn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pBtn->setStyleSheet("QToolButton{background-color:rgb(217,217,217)}"
                        "QToolButton:pressed{background-color:rgb(76,76,76)}"
                        "QToolButton:checked{background-color:rgb(76,76,76)}"
                        "QToolButton::icon{back}");

    return pBtn;
}

QToolButton* MainWindow::addDetailButton(QString text)
{
    QToolButton* pBtn;

    pBtn = new QToolButton();
    pBtn->setText(text);
    pBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    pBtn->setCheckable(true);
    pBtn->setFixedHeight(30);
    pBtn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pBtn->setStyleSheet("QToolButton{background-color:rgb(217,217,217)}"
                        "QToolButton:pressed{border-image: url(:/images/导航栏选中.png);}"
                        "QToolButton:checked{border-image: url(:/images/导航栏选中.png);}");

    return pBtn;
}

void MainWindow::onSlotBtnNaviCtr()
{
    if(m_pBtnNaviCtr->isChecked())
    {
        m_pBtnRealTimeMonitor->setVisible(true);
        m_pBtnMonitorConfig->setVisible(true);
    }
    else
    {
        m_pBtnRealTimeMonitor->setVisible(false);
        m_pBtnMonitorConfig->setVisible(false);
    }
}
void MainWindow::onSlotBtnRealTimeMonitor()
{}
void MainWindow::onSlotBtnMonitorConfig()
{}
