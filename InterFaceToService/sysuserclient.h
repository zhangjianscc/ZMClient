#ifndef SYSUSERCLIENT_H
#define SYSUSERCLIENT_H
#include "QString"


class SysUserClient
{
public:
    SysUserClient();

   // queryAllData
    bool Login(QString &account, QString &passwd, QString &ReqJson);//登陆请求接口
};

#endif // SYSUSERCLIENT_H
