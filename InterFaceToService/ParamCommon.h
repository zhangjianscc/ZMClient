#ifndef PARAMCOMMON_H
#define PARAMCOMMON_H

#include <QObject>
#include <QJsonObject>
#include <QString>
class PARAM :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString account READ Account WRITE setAccount)
    Q_PROPERTY(QString password READ Password WRITE setPassword)
public:
    void setAccount(QString& account){m_account=account;}
    void setPassword(QString& password){m_password=password;}
    QString Account(){return m_account;}
    QString Password(){return m_password;}
private:
    QString m_account;
    QString m_password;
};

#endif // PARAMCOMMON_H
