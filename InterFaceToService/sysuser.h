#ifndef SYSUSER_H
#define SYSUSER_H

#include <QJsonObject>
#include <QObject>
#include <QString>

class Sysuser :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setid)
    Q_PROPERTY(QString monitorId READ monitorId WRITE setmonitorId)
    Q_PROPERTY(QString monitorPhotoPath READ monitorPhotoPath WRITE setmonitorPhotoPath)
    Q_PROPERTY(QString alarmAddress READ alarmAddress WRITE setalarmAddress)
    Q_PROPERTY(QString alarmTime READ alarmTime WRITE setalarmTime)
public:
    Sysuser(){}
    Sysuser(const Sysuser& user){
        m_id=user.m_id;
        m_monitorId=user.m_monitorId;
        m_monitorPhotoPath=user.m_monitorPhotoPath;
        m_alarmAddress=user.m_alarmAddress;
        m_alarmTime=user.m_alarmTime;
    }
public:

    Q_INVOKABLE void setid(QString id){m_id=id;}
    Q_INVOKABLE void setmonitorId(QString  monitorId){m_monitorId=monitorId;}
    Q_INVOKABLE void setmonitorPhotoPath(QString monitorPhotoPath){m_monitorPhotoPath=monitorPhotoPath;}
    Q_INVOKABLE void setalarmAddress(QString alarmAddress){m_alarmAddress=alarmAddress;}
    Q_INVOKABLE void setalarmTime(QString alarmTime){m_alarmTime=alarmTime;}

    QString id(){return m_id;}
    QString monitorId(){return m_monitorId;}
    QString monitorPhotoPath(){return m_monitorPhotoPath;}
    QString alarmAddress(){return m_alarmAddress;}
    QString alarmTime(){return m_alarmTime;}


private:
    QString m_id;
    QString m_monitorId;
    QString m_monitorPhotoPath;
    QString m_alarmAddress;
    QString m_alarmTime;

};


#endif // SYSUSER_H
