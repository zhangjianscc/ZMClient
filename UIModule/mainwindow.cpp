﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UIModule/Comm/mytoolbutton.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"
#include "UIModule/Comm/myimagewidget.h"
#include "realtimemonitorpane.h"
#include "UIModule/logindialog.h"
#include "Common/singleton.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    initUserInfo();
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

    m_pBtnHistoryFace = new MyToolButton("      历史人脸库对比");
    playout->addWidget(m_pBtnHistoryFace);
    m_pBtnHistoryFace->setVisible(false);
    connect(m_pBtnHistoryFace,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnHistoryFace()));

    m_pBtnModeManage = new MyToolButton("模板库管理","://images//左侧图标03.png","://images//左侧图标03-01.png");
    playout->addWidget(m_pBtnModeManage);
    connect(m_pBtnModeManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnModeManage()));

    m_pBtnWarningManage = new MyToolButton("告警管理","://images//左侧图标04.png","://images//左侧图标04-01.png");
    playout->addWidget(m_pBtnWarningManage);
    connect(m_pBtnWarningManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnWarningManage()));

    m_pBtnInfoManage = new MyToolButton("基础信息维护","://images//左侧图标05.png","://images//左侧图标05-01.png");
    playout->addWidget(m_pBtnInfoManage);
    connect(m_pBtnInfoManage,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnInfoManage()));

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
}
void MainWindow::onSlotBtnModeManage()
{
    if(m_pBtnModeManage->isChecked())
    {
        m_pBtnModeManage->select();
    }
    else
    {
        m_pBtnModeManage->unSelect();
    }
}
void MainWindow::onSlotBtnWarningManage()
{
    if(m_pBtnWarningManage->isChecked())
    {
        m_pBtnWarningManage->select();
    }
    else
    {
        m_pBtnWarningManage->unSelect();
    }
}
void MainWindow::onSlotBtnInfoManage()
{
    if(m_pBtnInfoManage->isChecked())
    {
        m_pBtnInfoManage->select();
    }
    else
    {
        m_pBtnInfoManage->unSelect();
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
    /*SocketManager* inst = Singleton<SocketManager>::Instance();
    QString test = "{\
                   \"ACTION_NAME\": \"QUERY_SUSPECT_ALARM_REAL\",\
                   \"PARAMS\": {}\
               }";
    test += "\n\n";
    inst->sendMessage(test.toStdString().c_str());
    char RecvBuf[10000] = {0};       //接受的数据缓存
    int count = inst->receive(RecvBuf, 10000);
    QString resultString(RecvBuf);
    //开始解析返回的数据
    QJsonParseError login_json_error;
    QString RET_CODE;    //返回标志
    QJsonArray  RET_LIST;    //数组数据
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
            /*if (obj.contains("RET_CODE"))
            {
                //得到RET_CODE
                QJsonValue ret_code_value = obj.take("RET_CODE");
                if (ret_code_value.isString())
                {
                    //转换RET_CODE
                    RET_CODE = ret_code_value.toVariant().toString();
                }
            }
            if(obj.contains("RET_LIST"))
            {
                //得到RET_CODE
                QJsonValue ret_list_value = obj.take("RET_LIST");
                if (ret_list_value.isArray())
                {
                    //转换RET_CODE
                   //RET_LIST =  QJsonDocument::fromJson(ret_list_value.toArray(), &login_json_error);
                }
            }
        }
    }
    for(int i = 1; i < RET_LIST.size(); ++i)
    {
        QJsonObject jsonlist = RET_LIST.at(i).toObject();
        RealTimeMonitorPane::stImageData stimagedata;
        stimagedata.time = jsonlist.value("alarmTime").toString();
    }*/
    QList<RealTimeMonitorPane::stImageData> list;
    for(int i = 0 ; i < 9 ; i++)
    {
        RealTimeMonitorPane::stImageData data;
        data.pix = QPixmap("://images//head.jpg");
        data.date = "2017-6-5";
        data.time = "12:59:59";
        data.position = "成都市.高新区.天府五街";
        list.append(data);
    }
    m_pRealTimeMonitorPane->updateUIData(list);
}





