#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "stable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initMainFrame();                        /// 主界面初始化
    QWidget* initNavePane();                     /// 导航面板
    QWidget* initBackGroundImagePane();          /// 背景面板
    QWidget* initRealTimeMonitorPane();          /// 实时监控面板
    QWidget* initWarningPane();                  /// 告警面板
    QWidget* initMonitorConfigPane();            /// 布控面板
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
public slots:
    void onSlotBtnMinimize();                     /// 最小化
    void onSlotBtnClose();                        /// 关闭
};

#endif // MAINWINDOW_H
