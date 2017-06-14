#ifndef LOGINOBJ_H
#define LOGINOBJ_H
#include <QJsonObject>
#include <QObject>
#include <QString>
#include "ParamsCommon.h"
#include "jsonformat.h"

//*************标准接口封装格式****************
//注意事项：
//       1.必须继承QObject
//       2.必须定义属性Q_PROPERTY (属性即Json 节点)
//       3.必须提供Q_INVOKABLE 的set方法
//       4.提供一个纯对象转QjsonObject 方法
//       4.属性和方法名对应 例如QJsonObject PARAMS(属性） READ PARAMS(获取值) WRITE setPARAMS(设置值)
//*****************************************

class LoginObj :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ACTION_NAME READ ACTION_NAME WRITE setACTION_NAME)
    Q_PROPERTY(QJsonObject PARAMS READ PARAMS WRITE setPARAMS)
public:

    Q_INVOKABLE void setACTION_NAME(const QString & actionName){m_actionName=actionName;}
    Q_INVOKABLE void setPARAMS(QJsonObject& params){m_params=params;}

    QString ACTION_NAME(){return m_actionName;}
    QJsonObject PARAMS(){return m_params;}

public:
    //提供对象传入转换JSON方法
    void SetParams(ParamsCommon& params)
    {
        JsonFormat Jf;
        QJsonObject JsonObj=Jf.ToJsonObj(params);
        setPARAMS(JsonObj);
    }
private:
    QString m_actionName;   
    QJsonObject m_params;
};

#endif // LOGINOBJ_H
