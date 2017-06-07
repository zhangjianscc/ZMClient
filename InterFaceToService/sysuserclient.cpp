#include "sysuserclient.h"
#include "ParamCommon.h"
#include "ParamsCommon.h"
#include "jsonformat.h"
#include "loginobj.h"
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>
#include <QDebug>
#include <QString>
SysUserClient::SysUserClient()
{

}

 bool SysUserClient::Login(QString &account, QString &passwd, QString &ReqJson)
 {
     PARAM param;
     param.setAccount(account);
     param.setPassword(passwd);

     ParamsCommon params;
     params.SetParam(param);

     LoginObj login;
     login.setActionName(QString("LOGIN"));
     login.SetParams(params);

     JsonFormat Jf;
     QJsonObject JsonObj = Jf.FinalJsonObj(login);
     ReqJson = Jf.JsonObjStr(JsonObj);
     return true; //返回请求json串
     //假设返回数据转换成对象

     /*QJsonDocument JsonDocument=QJsonDocument::fromJson(Jstr.toUtf8());

     QJsonObject reJsonObj=JsonDocument.object();



     qDebug()<<reJsonObj;*/

 }
