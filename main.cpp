#include "UIModule/mainwindow.h"
#include <QApplication>
#include "UIModule/logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 初始化网络通信等其它模块
    // by ly

    // 启动登录界面
    LoginDialog dlg;
    dlg.exec();

    // 启动主界面
    MainWindow w;
    w.show();

    return a.exec();
}
