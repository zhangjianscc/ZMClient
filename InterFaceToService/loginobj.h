#ifndef LOGINOBJ_H
#define LOGINOBJ_H
#include <QJsonObject>
#include <QObject>
#include <QString>
#include "ParamsCommon.h"
#include "jsonformat.h"
class LoginObj :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ACTION_NAME READ ActionName WRITE setActionName)
    Q_PROPERTY(QJsonObject PARAMS READ Params WRITE setParams)
public:

    void setActionName(const QString & actionName){m_actionName=actionName;}
    QString ActionName(){return m_actionName;}
    void SetParams(ParamsCommon& params)
    {
        JsonFormat Jf;
        QJsonObject JsonObj=Jf.ToJsonObj(params);
        setParams(JsonObj);
    }
    QJsonObject Params(){return m_params;}
private:
    void setParams(QJsonObject& params){m_params=params;}
private:
    QString m_actionName;   
    QJsonObject m_params;
};

#endif // LOGINOBJ_H
