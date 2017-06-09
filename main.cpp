#include "UIModule/mainwindow.h"
#include <QApplication>
#include "UIModule/logindialog.h"
#include "stable.h"
#include "Common/readini.h"
#include "Common/singleton.h"

int main(int argc, char *argv[])
{
    // 指定编码格式为utf-8
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

    //  by ly 初始化网络通信等其它模块,读取配置文件ini
    SocketManager* inst = Singleton<SocketManager>::Instance();
    ReadIni readinidata;  //读取配置文件对象
    QString serviceIP = "127.0.0.1";  //缺省服务器ip地址
    QString servicePort = "1990";    //缺省服务器端口
    readinidata.ReadIniData(serviceIP, servicePort);
    inst->connetService(serviceIP.toStdString(), servicePort.toStdString());
    inst->sendMessage("socket_begin");   //连接请求服务器的时候发送socket_begin,结束发送socket_end;
    // 启动登录界面
    LoginDialog dlg;
    if(dlg.exec() != QDialog::Accepted)
    {
        return 0;
    }

    // 启动主界面
    MainWindow w;
    w.showMaximized();
    //w.show();

    return a.exec();
}
