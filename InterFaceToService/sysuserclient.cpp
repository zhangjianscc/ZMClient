#include "sysuserclient.h"
#include "ParamCommon.h"
#include "ParamsCommon.h"
#include "jsonformat.h"
#include "loginobj.h"
#include "objformat.h"
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>
#include <QDebug>
#include <QString>
#include "Common/singleton.h"
#include "reqglobal.h"


bool SysUserClient::SendRecv(QString &reqQstr,QString &repQstr)
{
    SocketManager* inst = Singleton<SocketManager>::Instance();
    char RecvBuf[MAX_RECVBUFFSIZ] = {0};       //接受的数据缓存
    if(!reqQstr.isEmpty())
    {
        reqQstr += "\n\n";   //每次请求加"\n\n"
        inst->sendMessage(reqQstr.toStdString().c_str());
        memset(RecvBuf, 0x00, MAX_RECVBUFFSIZ);
        int retcount = inst->receive(RecvBuf, MAX_RECVBUFFSIZ);
        if(retcount > 0)
        {
            QString RetString(RecvBuf);
            repQstr = RetString.trimmed();
            if(repQstr.isEmpty())
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

//登录验证
bool SysUserClient::Login(LOGIN& l, QString &repQstr)
{
    ParamCommon param;
    param.setaccount(l.account);
    param.setpassword(l.password);

    ParamsCommon params;
    params.SetParam(param);

    LoginObj login;
    login.setACTION_NAME(l.ACTION_NAME);
    login.SetParams(params);

    JsonFormat Jf;
    QJsonObject JsonObj = Jf.FinalJsonObj(login);
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(!reqQstr.isEmpty())
    {
        //请求加“\n\n"
        reqQstr += "\n\n";
        //假设返回数据转换成对象
        SocketManager* inst = Singleton<SocketManager>::Instance();
        char RecvBuf[MAX_RECVBUFFSIZ] = {0};       //接受的数据缓存
        int count = inst->receive(RecvBuf, MAX_RECVBUFFSIZ);
        if(count > 0){
            QString resultString(RecvBuf);
            if("OK" == resultString.trimmed())
            {
                inst->sendMessage(reqQstr.toStdString().c_str());
                memset(RecvBuf, 0x00, MAX_RECVBUFFSIZ);
                int retcount = inst->receive(RecvBuf, MAX_RECVBUFFSIZ);
                if(retcount > 0)
                {
                    QString RetString(RecvBuf);
                    repQstr = RetString.trimmed();
                    if(repQstr.isEmpty())
                    {
                        return false;
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

//----《实时监控》 ----------
//实时告警采集
bool SysUserClient::F_QUERY_SUSPECT_ALARM_WITH_PAGE(QUERY_SUSPECT_ALARM_WITH_PAGE& Query,QString& repQstr)
{

    QJsonObject pager;
    pager.insert("startIndex",Query.startIndex);
    pager.insert("pageSize",Query.pageSize);
    pager.insert("firstPage",Query.firstPage);
    pager.insert("endIndex",Query.endIndex);
    pager.insert("currentPage",Query.currentPage);

    QJsonObject param;
    QJsonObject params;
    params.insert("PAGER",pager);
    params.insert("PARAM",param);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",Query.ACTION_NAME);
    JsonObj.insert("PARAMS",params);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }
     return SendRecv(reqQstr,repQstr);
}




//查询行政区划表记录(不分页)
//查询监控区域信息表记录(不分页)
//查询监控位置信息表记录(不分页)
//设备列表(不分页)

//----《布控设置》 ----------
//资源库所有记录查询
//告警参数资源库关系表记录查询
//告警参数表记录查询
//告警参数表记录修改


//----《人脸识别》 ----------
//1：1比对
//1：N比对
//身份验证
//比对
//行动轨迹

//----《目标人管理》 ----------
//目标人信息列表
//编辑目标人
//添加目标人


//----《库管理》 ----------
//库信息列表
//添加库

//----《模版管理》 ----------
//人脸模版列表
//添加模版
//批量添加模版

//----《实时告警管理》 -------
//实时告警列表
//告警处理

//----《监控区域维护》 -------
//监控区域信息列表
//添加区域信息
//编辑区域信息

//----监控位置信息维护 -------
//查询监控位置信息表记录
 bool SysUserClient::F_QUERY_MONITOR_LOCATION_WITH_PAGE(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr)
{
     QJsonObject PAGER;
     PAGER.insert("startIndex",data.startIndex);
     PAGER.insert("pageSize",data.pageSize);
     PAGER.insert("firstPage",data.firstPage);
     PAGER.insert("endIndex",data.endIndex);
     PAGER.insert("currentPage",data.currentPage);

     QJsonObject PARAM;
     PARAM.insert("id",data.id);
     PARAM.insert("locationCode",data.locationCode);
     PARAM.insert("locationName",data.locationName);

     QJsonObject JsonObj;
     JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
     JsonObj.insert("PAGER",PAGER);
     JsonObj.insert("PARAM",PARAM);

     JsonFormat Jf;
     QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
     if(reqQstr.isEmpty())
     {
         return false;
     }

    return SendRecv(reqQstr,repQstr);
}

//通过Id来查询监控位置信息表记录
bool SysUserClient::F_QUERY_MONITOR_LOCATION_BY_ID(QUERY_MONITOR_LOCATION_BY_ID& data,QString& repQstr)
{
    QJsonObject PAGER;
    PAGER.insert("startIndex",data.startIndex);
    PAGER.insert("pageSize",data.pageSize);
    PAGER.insert("firstPage",data.firstPage);
    PAGER.insert("endIndex",data.endIndex);
    PAGER.insert("currentPage",data.currentPage);

    QJsonObject PARAM;
    PARAM.insert("id",data.id);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PAGER",PAGER);
    JsonObj.insert("PARAM",PARAM);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);

}
//添加监控位置信息
bool SysUserClient::F_ADD_MONITOR_LOCATION(ADD_MONITOR_LOCATION& data,QString& repQstr)
{
    QJsonObject PARAMS;
    PARAMS.insert("id",data.id);
    PARAMS.insert("locationCode",data.locationCode);
    PARAMS.insert("locationType",data.locationType);
    PARAMS.insert("longitude",data.longitude);
    PARAMS.insert("locationName",data.locationName);
    PARAMS.insert("latitude",data.latitude);
    PARAMS.insert("locationState",data.locationState);
    PARAMS.insert("areaId",data.areaId);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}
//编辑监控位置信息
bool SysUserClient::F_UPDATE_MONITOR_LOCATION(ADD_MONITOR_LOCATION& data,QString& repQstr)
{
    QJsonObject PARAMS;
    PARAMS.insert("id",data.id);
    PARAMS.insert("locationCode",data.locationCode);
    PARAMS.insert("locationType",data.locationType);
    PARAMS.insert("longitude",data.longitude);
    PARAMS.insert("locationName",data.locationName);
    PARAMS.insert("latitude",data.latitude);
    PARAMS.insert("locationState",data.locationState);
    PARAMS.insert("areaId",data.areaId);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}

//废除监控位置信息
 bool SysUserClient::F_DISUSED_MONITOR_LOCATION(DISUSED_MONITOR_LOCATION& data,QString& repQstr)
 {
     QJsonObject PARAMS;
     PARAMS.insert("id",data.id);

     QJsonObject JsonObj;
     JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
     JsonObj.insert("PARAMS",PARAMS);

     JsonFormat Jf;
     QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
     if(reqQstr.isEmpty())
     {
         return false;
     }

     return SendRecv(reqQstr,repQstr);
 }
//----人脸采集设备信息维护 -------
//人脸采集设备信息列表
bool SysUserClient::F_QUERY_CAMERA_INFO_WITH_PAGE(QUERY_CAMERA_INFO_WITH_PAGE& data,QString& repQstr)
{
    QJsonObject PAGER;
    PAGER.insert("startIndex",data.startIndex);
    PAGER.insert("pageSize",data.pageSize);
    PAGER.insert("firstPage",data.firstPage);
    PAGER.insert("endIndex",data.endIndex);
    PAGER.insert("currentPage",data.currentPage);

    QJsonObject PARAM;
    PARAM.insert("id",data.id);
    PARAM.insert("cameraName",data.cameraName);

    QJsonObject PARAMS;
    PARAMS.insert("PAGER",PAGER);
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}

//添加人脸采集设备信息
bool SysUserClient::F_ADD_CAMERA_INFO(ADD_CAMERA_INFO& data,QString& repQstr)
{
    QJsonObject PARAMS;
    PARAMS.insert("cameraCode",data.cameraCode);
    PARAMS.insert("gateway",data.gateway);
    PARAMS.insert("cameraType",data.cameraType);
    PARAMS.insert("locationId",data.locationId);
    PARAMS.insert("serverIp",data.serverIp);
    PARAMS.insert("subnetMask",data.subnetMask);
    PARAMS.insert("macAddress",data.macAddress);
    PARAMS.insert("reserve1",data.reserve1);
    PARAMS.insert("id",data.id);
    PARAMS.insert("cameraName",data.cameraName);
    PARAMS.insert("cameraPort",data.cameraPort);
    PARAMS.insert("serverPort",data.serverPort);
    PARAMS.insert("managerId",data.managerId);
    PARAMS.insert("cameraModel",data.cameraModel);
    PARAMS.insert("cameraState",data.cameraState);
    PARAMS.insert("ipAddress",data.ipAddress);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}

//编辑人脸采集设备信息
bool SysUserClient::F_UPDATE_CAMERA_INFO(ADD_CAMERA_INFO& data,QString& repQstr)
{
    QJsonObject PARAMS;
    PARAMS.insert("cameraCode",data.cameraCode);
    PARAMS.insert("gateway",data.gateway);
    PARAMS.insert("cameraType",data.cameraType);
    PARAMS.insert("locationId",data.locationId);
    PARAMS.insert("serverIp",data.serverIp);
    PARAMS.insert("subnetMask",data.subnetMask);
    PARAMS.insert("macAddress",data.macAddress);
    PARAMS.insert("reserve1",data.reserve1);
    PARAMS.insert("id",data.id);
    PARAMS.insert("cameraName",data.cameraName);
    PARAMS.insert("cameraPort",data.cameraPort);
    PARAMS.insert("serverPort",data.serverPort);
    PARAMS.insert("managerId",data.managerId);
    PARAMS.insert("cameraModel",data.cameraModel);
    PARAMS.insert("cameraState",data.cameraState);
    PARAMS.insert("ipAddress",data.ipAddress);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);

}

//删除人脸采集设备信息
bool SysUserClient::F_DELETE_CAMERA_INFO(DELETE_CAMERA_INFO& Delete,QString& repQstr)
{
    QJsonObject PARAMS;
    PARAMS.insert("id",Delete.id);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",Delete.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}

//人脸采集设备参数信息列表
bool SysUserClient::F_QUERY_CAMERA_PARAM_WITH_PAGE(QUERY_CAMERA_PARAM_WITH_PAGE& Query,QString& repQstr)
{

    QJsonObject PAGER;
    PAGER.insert("startIndex",Query.startIndex);
    PAGER.insert("pageSize",Query.pageSize);
    PAGER.insert("firstPage",Query.firstPage);
    PAGER.insert("endIndex",Query.endIndex);
    PAGER.insert("currentPage",Query.currentPage);

    QJsonObject PARAM;
    PARAM.insert("id",Query.id);
    PARAM.insert("cameraId",Query.cameraId);

    QJsonObject PARAMS;
    PARAMS.insert("PAGER",PAGER);
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",Query.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);

}

//修改人脸采集设备参数信息
bool SysUserClient::F_UPDATE_CAMERA_PARAM(UPDATE_CAMERA_INFO& Update,QString& repQstr)
{

    QJsonObject PARAMS;
    PARAMS.insert("cameraCode",Update.cameraCode);
    PARAMS.insert("gateway",Update.gateway);
    PARAMS.insert("cameraType",Update.cameraType);
    PARAMS.insert("locationId",Update.locationId);
    PARAMS.insert("serverIp",Update.serverIp);
    PARAMS.insert("subnetMask",Update.subnetMask);
    PARAMS.insert("macAddress",Update.macAddress);
    PARAMS.insert("url",Update.url);
    PARAMS.insert("id",Update.id);
    PARAMS.insert("cameraName",Update.cameraName);
    PARAMS.insert("cameraPort",Update.cameraPort);
    PARAMS.insert("serverPort",Update.serverPort);
    PARAMS.insert("managerId",Update.managerId);
    PARAMS.insert("cameraModel",Update.cameraModel);
    PARAMS.insert("cameraState",Update.cameraState);
    PARAMS.insert("ipAddress",Update.ipAddress);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",Update.ACTION_NAME);
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

    return SendRecv(reqQstr,repQstr);
}




