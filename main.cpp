#include "UIModule/mainwindow.h"
#include <QApplication>
#include "UIModule/logindialog.h"
#include "stable.h"
#include "Common/socketTcp.h"

int main(int argc, char *argv[])
{
    // 指定编码格式为utf-8
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

    // 初始化网络通信等其它模块
    // by ly
    socketTcp sockettcp;  //socket 对象
    sockettcp.newConnect();
    sockettcp.sendMessage("socket_begin");//连接服务器socket时发送socket_begin，结束发送socket_end
    // 启动登录界面
    //LoginDialog dlg;
    //if(dlg.exec() != QDialog::Accepted)
    //{
    //    return 0;
    //}

    // 启动主界面
    MainWindow w;
    w.showMaximized();
    //w.show();

    return a.exec();
}
