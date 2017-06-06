#include "UIModule/mainwindow.h"
#include <QApplication>
#include "UIModule/logindialog.h"
#include "stable.h"

int main(int argc, char *argv[])
{
    // 指定编码格式为utf-8
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

    // 初始化网络通信等其它模块
    // by ly

    // 启动登录界面
    LoginDialog dlg;
    if(dlg.exec() != QDialog::Accepted)
    {
        return 0;
    }

    // 启动主界面
    MainWindow w;
    w.showMaximized();

    return a.exec();
}
