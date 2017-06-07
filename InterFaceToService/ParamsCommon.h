#ifndef PARAMSCOMMON_H
#define PARAMSCOMMON_H

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QJsonObject>
#include "ParamCommon.h"
#include "jsonformat.h"
class ParamsCommon:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonObject PARAM READ Param WRITE setParam)
public:
    void SetParam(QObject& param)
    {
        JsonFormat Jf;
        QJsonObject JsonObj=Jf.ToJsonObj(param);
        setParam(JsonObj);
    }
    QJsonObject Param(){return m_param;}
private:
    void setParam(QJsonObject& param){m_param=param;}
private:
    QJsonObject m_param;
};

#endif // PARAMSCOMMON_H
