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
    Q_PROPERTY(QJsonObject PARAM READ PARAM WRITE setPARAM)

public:

    QJsonObject PARAM(){return m_param;}
    void setPARAM(QJsonObject& param){m_param=param;}

public:
    void SetParam(QObject& param)
    {
        JsonFormat Jf;
        QJsonObject JsonObj=Jf.ToJsonObj(param);
        setPARAM(JsonObj);
    }
private:
    QJsonObject m_param;
};

#endif // PARAMSCOMMON_H
