#include "readini.h"
#include <QSettings>
ReadIni::ReadIni()
{

}
void ReadIni::ReadIniData(QString &qstrIP, QString &qstrPort)
{
    QSettings *configIniRead = new QSettings("config.ini", QSettings::IniFormat);
    //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
    qstrIP = configIniRead->value("Service/ServiceIP").toString(); //IP地址
    qstrPort = configIniRead->value("Service/ServicePort").toString();    //端口
    //读入入完成后删除指针
    delete configIniRead;
}
