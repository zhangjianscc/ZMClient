#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    playout->setContentsMargins(5,0,0,0);
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
    QTreeWidget* pTree = new QTreeWidget();
    pTree->setStyleSheet("QTreeWidget{background-color:rgb(217,217,217)}");
    pTree->setColumnCount(1);
    pTree->setHeaderHidden(true);
    pTree->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 构造所有的树节点
    QTreeWidgetItem* titleItem = new QTreeWidgetItem(pTree,QStringList("标题"));
    titleItem->setData(0,Qt::UserRole,QVariant(0));

    QTreeWidgetItem* moniterItem = new QTreeWidgetItem(pTree,QStringList("布控"));
    moniterItem->setIcon(0,QIcon("://images//左侧图标01.png"));
    moniterItem->setData(0,Qt::UserRole,QVariant(1));
    QTreeWidgetItem* realTimeMonitorItem = new QTreeWidgetItem(moniterItem,QStringList("实时监控"));
    QTreeWidgetItem* MonitorConfigItem = new QTreeWidgetItem(moniterItem,QStringList("布控设置"));

    QTreeWidgetItem* faceItem = new QTreeWidgetItem(pTree,QStringList("人脸识别"));
    QTreeWidgetItem* oneToOneItem = new QTreeWidgetItem(faceItem,QStringList("1:1对比"));
    QTreeWidgetItem* oneToNItem = new QTreeWidgetItem(faceItem,QStringList("1:N对比"));
    QTreeWidgetItem* identityItem = new QTreeWidgetItem(faceItem,QStringList("身份验证"));
    QTreeWidgetItem* historyItem = new QTreeWidgetItem(faceItem,QStringList("历史人脸库对比"));

    QTreeWidgetItem* modeItem = new QTreeWidgetItem(pTree,QStringList("模板库管理"));

    QTreeWidgetItem* warningItem = new QTreeWidgetItem(pTree,QStringList("告警管理"));

    QTreeWidgetItem* infoItem = new QTreeWidgetItem(pTree,QStringList("基础信息维护"));

    //
    QHBoxLayout* playout = new QHBoxLayout(pWid);
    playout->setMargin(0);
    playout->addWidget(pTree);
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
