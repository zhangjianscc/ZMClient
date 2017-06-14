#ifndef PARAMCOMMON_H
#define PARAMCOMMON_H

#include <QObject>
#include <QJsonObject>
#include <QString>
class ParamCommon :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString account READ account WRITE setaccount)
    Q_PROPERTY(QString password READ password WRITE setpassword)
public:
    Q_INVOKABLE void setaccount(QString& account){m_account=account;}
    Q_INVOKABLE void setpassword(QString& password){m_password=password;}
    QString account(){return m_account;}
    QString password(){return m_password;}
private:
    QString m_account;
    QString m_password;
};

#endif // PARAMCOMMON_H
