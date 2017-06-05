#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "stable.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private:

    /**
     * @brief 初始化界面元素
     */
    void initUI();

    /**
     * @brief 加载保存的用户数据
     */
    void loadSavedUserInfo();

    /**
     * @brief 登录请求完成后触发
     * @param result 登录结构 true：登录成功 false：登录失败
     * @param retMsg 登录失败时返回的字符串
     */
    void loginResult(bool result,QString retMsg);

    /**
     * @brief 鼠标按压事件
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief 鼠标移动事件
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void onSlotBtnMinimize();                     /// 最小化按钮响应
    void onSlotBtnClose();                        /// 关闭按钮响应
    void onSlotBtnLogin();                        /// 界面点击登录按钮触发
    void onSlotRemenberUserStateChanged(int);     /// 记住用户复选框选中状态变化
    void onSlotUserNameChanged(QString);          /// 根据输入用户名匹配密码
    void onSlotUserNameEditClicked(int,int);      /// 用户名编辑框点击事件
    void onSlotUserKeyEditClicked(int,int);       /// 用户密码编辑框点击事件
private:
    Ui::LoginDialog *ui;                          /// ui对象
    QMap<QString,QString> m_mapSavedUser;         /// 缓存的用户数据<用户名,密码>
    QPoint                m_curWindowPos;         /// 窗口当前位置
    QPoint                m_curMousePos;          /// 鼠标当前位置
    QPoint                m_destWindowPos;        /// 移动后窗口所在的位置
    bool                  m_bRemenberUser;        /// 是否记住用户名密码标志
};

#endif // LOGINDIALOG_H
