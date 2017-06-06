#include "socketTcp.h"
#include "Common/readini.h"
#include <iostream>
using namespace std;
socketTcp::socketTcp(QObject *parent) :
    QObject(parent),
    socket(new QTcpSocket),
    connectBool(false),
    m_error(QAbstractSocket::ConnectionRefusedError)
{
    setIP_Port(clientIP, clientPort);
    newConnect();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(this,SIGNAL(alreadyRead()),this,SLOT(returnMessage()));
    connect(socket,SIGNAL(connected()),this,SLOT(isConnect()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(isDisconnect()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(isError(QAbstractSocket::SocketError)));
}
socketTcp::~socketTcp()
{
    delete socket;
}
//新建一个tcp链接
void socketTcp::newConnect()
{
    socket->abort();
    socket->connectToHost(clientIP,clientPort);
}
//设置服务器ip地址
void socketTcp::setIP_Port(QString ip, int port)
{
    ReadIni readini; //读取配置文件对象
    readini.ReadIniData(ip,port);
    clientIP = ip;
    clientPort = port;
}

//向服务器发送消息
void socketTcp::sendMessage(QString sendStr)
{
    socket->write(sendStr.toStdString().c_str(),strlen(sendStr.toStdString().c_str()));
    //socket->write(QByteArray(str.toLocal8Bit()));
}

//返回tcp连接状态
bool socketTcp::returnConnectState()
{
    return connectBool;
}
//返回错误
int socketTcp::returnError()
{
    return m_error;
}
//接收服务器返回的数据
void socketTcp::readMessage()
{
    QByteArray qdb = socket->readAll();
    message = QVariant(qdb).toString();
    emit alreadyRead();
}
//判断是否链接
void socketTcp::isConnect()
{
    connectBool = true;
}
//判断是否断开
void socketTcp::isDisconnect()
{
    connectBool = false;
}
//判断socket出错
void socketTcp::isError(QAbstractSocket::SocketError er)
{
    m_error = er;
}
void socketTcp::incomingConnection(qintptr handle)
{
    socket->setSocketDescriptor(handle);
}
//socket返回消息
QString socketTcp::returnMessage()
{
    return message;
}
