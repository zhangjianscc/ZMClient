#include "stable.h"
<<<<<<< HEAD
#include "Common/readini.h"
#include "Common/singleton.h"
=======
#include "stable.h"
#include "UIModule/mainwindow.h"
#include "UIModule/logindialog.h"
#include <QApplication>
#include "Common/socketTcp.h"
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9


void loadStyleSheet(QString qssName)
{
    QFile data(qssName);

    QString qssFile;
    if(data.open(QFile::ReadOnly))
    {
        QTextStream styleIn(&data);
        qssFile = styleIn.readAll();
        data.close();
        qApp->setStyleSheet(qssFile);
    }

}

int main(int argc, char *argv[])
{
    // 指定编码格式为utf-8
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

<<<<<<< HEAD
    //  by ly 初始化网络通信等其它模块,读取配置文件ini
    SocketManager* inst = Singleton<SocketManager>::Instance();
    ReadIni readinidata;  //读取配置文件对象
    QString serviceIP = "127.0.0.1";  //缺省服务器ip地址
    QString servicePort = "1990";    //缺省服务器端口
    readinidata.ReadIniData(serviceIP, servicePort);
    inst->connetService(serviceIP.toStdString(), servicePort.toStdString());
    inst->sendMessage("socket_begin");   //连接请求服务器的时候发送socket_begin,结束发送socket_end;
=======
    loadStyleSheet(QString(":/stylesheet.qss"));

    // 初始化网络通信等其它模块
    // by ly
    socketTcp sockettcp;  //socket 对象
    sockettcp.newConnect();
    sockettcp.sendMessage("socket_begin");//连接服务器socket时发送socket_begin，结束发送socket_end
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
    // 启动登录界面
    //LoginDialog dlg;
    //if(dlg.exec() != QDialog::Accepted)
    //{
    //    return 0;
    //}

    // 启动主界面
    MainWindow w;
<<<<<<< HEAD
    w.showMaximized();
    //w.show();
=======
    w.setFixedSize(g_wid,g_hei);

    QDesktopWidget *deskWgt = QApplication::desktop();
    int x = deskWgt->width();
    int y = deskWgt->height();
    int pointX = (x - w.width())/2 > 0?(x - w.width())/2:0;
    int pointY = (y - w.height())/2 > 0?(y - w.height())/2:0;
    w.move(pointX,pointY);
    w.show();
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

    return a.exec();
}

