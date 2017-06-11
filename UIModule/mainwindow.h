#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class QToolButton;
class MyToolButton;
class QStackedWidget;
class MyTargetButton;
class RealTimeMonitorPane;
class FaceOneToOnePane;
class FaceOneToNPane;
class FaceOneToNPane2;
class FaceIdentityRecog2;
class FaceHistoryCompare2;
class MonitorConfigPane;
class TargetPersonManager;
class TemplateManager;
class LibraryManager;
class RealWarningManager;
class MonitorAreaMaintain;
class MonitorPositionMaintain;
class MonitorDeviceMaintain;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateRealTimeMonitorData();                    /// 更新实时监控面板数据
private:
    void initUserInfo();                                 /// 初始化用户信息
    void initMainFrame();                                /// 主界面初始化
    QWidget* initNavePane();                             /// 导航面板
    void initUserPane(QWidget* pWid);                    /// 用户面板
    QWidget* initBackGroundImagePane();                  /// 背景面板
    void mousePressEvent(QMouseEvent *event);            ///
    void mouseMoveEvent(QMouseEvent *event);             ///
    void mouseReleaseEvent(QMouseEvent *event);          ///
    void checkPane(MyToolButton* pBtn);
private:
    QPoint                m_curWindowPos;                /// 窗口当前位置
    QPoint                m_curMousePos;                 /// 鼠标当前位置
    QPoint                m_destWindowPos;               /// 移动后窗口所在的位置
    QStackedWidget*       m_pContentPane;
    MyToolButton*         m_pBtnNaviCtr;                 /// 布控 ==
    MyToolButton*         m_pBtnRealTimeMonitor;         /// 实时监控
    MyToolButton*         m_pBtnMonitorConfig;           /// 布控设置
    MyToolButton*         m_pBtnFaceDetection;           /// 人脸识别 ==
    MyToolButton*         m_pBtnFaceOneToOne;            /// 1:1
    MyToolButton*         m_pBtnFaceOneToN;              /// 1：N
    MyToolButton*         m_pBtnIndentify;               /// 身份验证
    MyToolButton*         m_pBtnHistoryFace;             /// 历史库
    MyToolButton*         m_pBtnModeManage;              /// 模板管理 ==
    MyToolButton*         m_pBtnWarningManage;           /// 告警管理 ==
    MyToolButton*         m_pBtnInfoManage;              /// 基础信息管理 ==
    MyToolButton*         m_pBtnTargetPersonManager;     /// 目标人管理
    MyToolButton*         m_pBtnTemplateManager;         /// 模板管理
    MyToolButton*         m_pBtnLibraryManager;          /// 库管理
    MyToolButton*         m_pBtnRealWarningManager;      /// 实时告警管理
    MyToolButton*         m_pBtnMonitorAreaMaintain;     /// 监控区域信息维护
    MyToolButton*         m_pBtnMonitorPositionMaintain; /// 监控位置信息维护
    MyToolButton*         m_pBtnMonitorDeviceMaintain;   /// 人脸采集设备信息维护

    QString               m_strUserType;                 /// 用户类型
    QString               m_strUserName;                 /// 用户名


    MyTargetButton *m_pTargetButton;


    bool                  m_bIsMoveing;

    RealTimeMonitorPane*  m_pRealTimeMonitorPane;        /// 布控->实时监控面板
    MonitorConfigPane*    m_pMonitorConfigPane;          /// 布控->布控设置

    FaceOneToOnePane*     m_pFaceOneToOnePane;           /// 人脸识别-> 1:1
    FaceOneToNPane2*      m_pFaceOneToNPane2;            /// 人脸识别-> 1:N
    FaceIdentityRecog2*   m_pFaceIdentityRecog2;         /// 人脸识别-> 身份验证
    FaceHistoryCompare2*  m_pFaceHistoryCompare2;        /// 人脸识别-> 历史人脸库对比

    TargetPersonManager*  m_pTargetPersonManager;        ///
    TemplateManager*      m_pTemplateManager;
    LibraryManager*       m_pLibraryManager;
    RealWarningManager*   m_pRealWarningManager;
    MonitorAreaMaintain*  m_pMonitorAreaMaintain;
    MonitorPositionMaintain* m_pMonitorPositionMaintain;
    MonitorDeviceMaintain*   m_pMonitorDeviceMaintain;


public slots:
    void onSlotBtnMinimize();                             /// 最小化
    void onSlotBtnClose();                                /// 关闭
    void onSlotBtnNaviCtr();                              /// 布控
    void onSlotBtnRealTimeMonitor();                      /// 实时监控
    void onSlotBtnMonitorConfig();                        /// 布控设置
    void onSlotBtnFaceDetection();                        /// 人脸识别
    void onSlotBtnFaceOneToOne();                         /// 1:1
    void onSlotBtnFaceOneToN();                           /// 1：N
    void onSlotBtnIndentify();                            /// 身份验证
    void onSlotBtnHistoryFace();                          /// 历史库
    void onSlotBtnModeManage();                           /// 模板管理
    void onSlotBtnWarningManage();                        /// 告警管理
    void onSlotBtnInfoManage();                           /// 基础信息管理
    void onSlotBtnTargetPersonManager();                  /// 目标人管理
    void onSlotBtnTemplateManager();                      /// 模板管理
    void onSlotBtnLibraryManager();                       /// 库管理
    void onSlotBtnRealWarningManager();                   /// 实时告警管理
    void onSlotBtnMonitorAreaMaintain();                  /// 监控区域信息维护
    void onSlotBtnMonitorPositionMaintain();              /// 监控位置信息维护
    void onSlotBtnDeviceMaintain();                       /// 人像采集设备维护

    void slot_test();
};

#endif // MAINWINDOW_H
