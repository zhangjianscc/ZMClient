#ifndef SOCKETTCP_H
#define SOCKETTCP_H
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QAbstractProxyModel>

class socketTcp : public QObject
{
    Q_OBJECT
public:
    explicit socketTcp(QObject *parent = 0);
    ~socketTcp();
    void newConnect();
    void setIP_Port(QString ip, int port);
    void sendMessage(QString sendStr);
    bool returnConnectState();
    int returnError();
signals:
    void alreadyRead();
public slots:
    QString returnMessage();
private slots:
    void readMessage();
    void isConnect();
    void isDisconnect();
    void isError(QAbstractSocket::SocketError er);
protected:
    void incomingConnection(qintptr handle);
public:
    QTcpSocket *socket;
    QString clientIP;
    int clientPort;
    QString message;
    bool connectBool;
    QAbstractSocket::SocketError m_error;
};

#endif // SOCKETTCP_H
