#include "stable.h"
#include "stable.h"
#include "UIModule/mainwindow.h"
#include "UIModule/logindialog.h"
#include <QApplication>
#include "Common/socketTcp.h"


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
    QString style("QComboBox{border-radius:3px;background-color:rgb(255,255,255)}"
                  "QComboBox::drop-down {"
                  "subcontrol-origin: padding;"
                  "subcontrol-position: center right;"
                  "border:none;"
                  "width: 15px;"
                  "height: 15px;"
                  "}"
                  "QComboBox::down-arrow {"
                  "image: url(://images//down-01.png);"
                  "}");
    a.setStyleSheet(style);

    //loadStyleSheet(QString(":/stylesheet.qss"));

    // 初始化网络通信等其它模块
    // by ly

    // 启动登录界面
    //LoginDialog dlg;
    //if(dlg.exec() != QDialog::Accepted)
    //{
    //    return 0;
    //}

    // 启动主界面
    MainWindow w;
    w.setFixedSize(g_wid,g_hei);

    QDesktopWidget *deskWgt = QApplication::desktop();
    int x = deskWgt->width();
    int y = deskWgt->height();
    int pointX = (x - w.width())/2 > 0?(x - w.width())/2:0;
    int pointY = (y - w.height())/2 > 0?(y - w.height())/2:0;
    w.move(pointX,pointY);
    w.show();

    return a.exec();
}

