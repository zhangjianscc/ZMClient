#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class QToolButton;
class MyToolButton;
class QStackedWidget;
class RealTimeMonitorPane;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateRealTimeMonitorData();/// 更新实时监控面板数据
private:
    void initUserInfo();                         /// 初始化用户信息
    void initMainFrame();                        /// 主界面初始化
    QWidget* initNavePane();                     /// 导航面板
    void initUserPane(QWidget* pWid);            /// 用户面板
    QWidget* initBackGroundImagePane();          /// 背景面板
    QWidget* initRealTimeMonitorPane();          /// 实时监控面板
    QWidget* initMonitorConfigPane();            /// 告警面板
    QWidget* initOneToOneComparePane();          /// 1:1对比面板
    QWidget* initOneToNComparePane();            /// 1:N对比面板
    QWidget* initIdentityAuthenPane();           /// 身份验证面板
    QWidget* initHistoryFaceComparePane();       /// 历史对比面板
    void mousePressEvent(QMouseEvent *event);    ///
    void mouseMoveEvent(QMouseEvent *event);     ///
private:
    QPoint                m_curWindowPos;         /// 窗口当前位置
    QPoint                m_curMousePos;          /// 鼠标当前位置
    QPoint                m_destWindowPos;        /// 移动后窗口所在的位置
    QStackedWidget*       m_pContentPane;
    MyToolButton*         m_pBtnNaviCtr;          /// 布控 ==
    MyToolButton*         m_pBtnRealTimeMonitor;  /// 实时监控
    MyToolButton*         m_pBtnMonitorConfig;    /// 布控设置
    MyToolButton*         m_pBtnFaceDetection;    /// 人脸识别 ==
    MyToolButton*         m_pBtnFaceOneToOne;     /// 1:1
    MyToolButton*         m_pBtnFaceOneToN;       /// 1：N
    MyToolButton*         m_pBtnIndentify;        /// 身份验证
    MyToolButton*         m_pBtnHistoryFace;      /// 历史库
    MyToolButton*         m_pBtnModeManage;       /// 模板管理 ==
    MyToolButton*         m_pBtnWarningManage;    /// 告警管理 ==
    MyToolButton*         m_pBtnInfoManage;       /// 基础信息管理 ==

    QString               m_strUserType;          /// 用户类型
    QString               m_strUserName;          /// 用户名

    RealTimeMonitorPane*  m_pRealTimeMonitorPane; /// 实时监控面板
public slots:
    void onSlotBtnMinimize();                     /// 最小化
    void onSlotBtnClose();                        /// 关闭
    void onSlotBtnNaviCtr();                      /// 布控
    void onSlotBtnRealTimeMonitor();              /// 实时监控
    void onSlotBtnMonitorConfig();                /// 布控设置
    void onSlotBtnFaceDetection();                /// 人脸识别
    void onSlotBtnFaceOneToOne();                 /// 1:1
    void onSlotBtnFaceOneToN();                   /// 1：N
    void onSlotBtnIndentify();                    /// 身份验证
    void onSlotBtnHistoryFace();                  /// 历史库
    void onSlotBtnModeManage();                   /// 模板管理
    void onSlotBtnWarningManage();                /// 告警管理
    void onSlotBtnInfoManage();                   /// 基础信息管理
};

#endif // MAINWINDOW_H
