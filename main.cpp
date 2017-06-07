﻿#include "UIModule/mainwindow.h"
#include <QApplication>
#include "UIModule/logindialog.h"
#include "stable.h"
#include "Common/readini.h"
#include "Common/singleton.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);

    //  by ly 初始化网络通信等其它模块,读取配置文件ini
    ReadIni readinidata;  //读取配置文件对象
    QString serviceIP = "127.0.0.1";  //缺省服务器ip地址
    QString servicePort = "1990";    //缺省服务器端口
    readinidata.ReadIniData(serviceIP, servicePort);
    SocketManager* inst = Singleton<SocketManager>::Instance();
    inst->connetService(serviceIP.toStdString(), servicePort.toStdString());
    inst->sendMessage("socket_begin");   //连接请求服务器的时候发送socket_begin,结束发送socket_end;
    inst->cn.getSocket();
    // 启动登录界面
    LoginDialog dlg;
    if(dlg.exec() != QDialog::Accepted)
    {
        return 0;
    }

    // 启动主界面
    MainWindow w;
    w.show();

    return a.exec();
}
