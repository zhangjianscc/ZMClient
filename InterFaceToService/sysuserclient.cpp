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
                    int falglength = RetString.indexOf(","); //查找返回字符串中长度结束符，
                    repQstr = RetString.mid(falglength + 1); //截断返回长度+，
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



bool SysUserClient::F_QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE(QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("beginDate",data.beginDate);

    QJsonObject PARAMS;
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

bool  SysUserClient::F_QUERY_SUSPECT_ALARM_REAL(QString& repQstr)
{

    QJsonObject PARAMS;

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME","QUERY_SUSPECT_ALARM_REAL");
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

   return SendRecv(reqQstr,repQstr);
}

bool SysUserClient::F_QUERY_MONITOR_AREA_WITH_PAGE_BY_ID(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr)
{

    QJsonObject PARAM;
    PARAM.insert("id",data.id);

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME",data.ACTION_NAME);

    JsonObj.insert("PARAM",PARAM);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

   return SendRecv(reqQstr,repQstr);
}

bool SysUserClient::F_QUERY_CAMERA_INFO_ALL_DATA(QUERY_MONITOR_LOCATION_ALL_DATA& data,QString& repQstr)
{
    QJsonObject PAGER;
    PAGER.insert("startIndex",data.startIndex);
    PAGER.insert("pageSize",data.pageSize);
    PAGER.insert("firstPage",data.firstPage);
    PAGER.insert("endIndex",data.endIndex);
    PAGER.insert("currentPage",data.currentPage);

    QJsonObject PARAM;
    PARAM.insert("id",data.id);
    PARAM.insert("areaId",data.areaId);

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

bool SysUserClient::F_QUERY_CAMERA_INFO_ALL_DATA(QUERY_CAMERA_INFO_WITH_PAGE& data,QString& repQstr)
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
    PARAM.insert("locationId",data.locationId);

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

bool SysUserClient::F_QUERY_ALARM_PARAM_ALL_DATA(QString& repQstr)
{
    QJsonObject PARAM;

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME","QUERY_ALARM_PARAM_ALL_DATA");
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

   return SendRecv(reqQstr,repQstr);
}

bool SysUserClient::F_QUERY_LIBRARY_INFO_BY_PARAM_ID(QUERY_LIBRARY_INFO_BY_PARAM_ID& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("id",data.id);

    QJsonObject PARAMS;
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

bool SysUserClient::F_UPDATE_PARAM_LIBRARY(UPDATE_PARAM_LIBRARY& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("id",data.id);
    PARAM.insert("alarmThreshold",data.alarmThreshold);
    PARAM.insert("contrastThreshold",data.contrastThreshold);

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);
    PARAMS.insert("LIBRARY_INFO_LIST",data.LIBRARY_INFO_LIST);

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

bool SysUserClient::F_ONE_THAN_ONE(ONE_THAN_ONE& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("PHOTO_ONE",data.PHOTO_ONE);
    PARAM.insert("PHOTO_TWO",data.PHOTO_TWO);

    QJsonObject PARAMS;
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

bool SysUserClient::F_ONE_THAN_MORE(ONE_THAN_MORE& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("groupIds",data.groupIds);
    PARAM.insert("count",data.count);
    PARAM.insert("gender",data.gender);
    PARAM.insert("pic",data.pic);
    PARAM.insert("threshold",data.threshold);

    QJsonObject PARAMS;
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

bool SysUserClient::F_QUERY_FACE_PHOTO_WITH_VIEW(QUERY_FACE_PHOTO_ALL_DATA& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("targetId",data.targetId);

    QJsonObject PARAMS;
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

bool SysUserClient::F_QUERY_TARGET_INFO_WITH_PAGE(QUERY_TARGET_INFO_WITH_PAGE& data,QString& repQstr)
{
    QJsonObject PAGER;
    PAGER.insert("startIndex",data.startIndex);
    PAGER.insert("pageSize",data.pageSize);
    PAGER.insert("firstPage",data.firstPage);
    PAGER.insert("endIndex",data.endIndex);
    PAGER.insert("currentPage",data.currentPage);

    QJsonObject PARAM;
    PARAM.insert("account",data.account);

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

bool SysUserClient::F_QUERY_FACE_PHOTO_ALL_DATA(QUERY_FACE_PHOTO_ALL_DATA& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("targetId",data.targetId);

    QJsonObject PARAMS;
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

bool SysUserClient::F_DELETE_TARGET_INFO(DELETE_TARGET_INFO& data,QString& repQstr)
 {
     QJsonObject PARAM;
     PARAM.insert("id",data.id);

     QJsonObject PARAMS;
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

bool SysUserClient::F_UPDATE_TARGET_INFO(UPDATE_TARGET_INFO& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("targetSex",data.targetSex);
    PARAM.insert("id",data.id);
    PARAM.insert("dangerLv",data.dangerLv);
    PARAM.insert("targetName",data.targetName);

    QJsonObject PARAMS;
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

bool SysUserClient::F_ADD_TARGET_INFO(ADD_TARGET_INFO& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("targetName",data.targetName);

    QJsonObject PARAMS;
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

bool SysUserClient::F_DELETE_LIBRARY_INFO(DELETE_LIBRARY_INFO& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("id",data.id);

    QJsonObject PARAMS;
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

bool SysUserClient::F_ADD_LIBRARY_INFO(ADD_LIBRARY_INFO& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("libraryName",data.libraryName);
    PARAM.insert("userAccount",data.userAccount);


    QJsonObject PARAMS;
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

//查询目标人脸照片表记录--分页
 bool SysUserClient::F_QUERY_FACE_PHOTO_WITH_PAGE(QUERY_FACE_PHOTO_WITH_PAGE& data,QString& repQstr)
 {
     QJsonObject PAGER;
     PAGER.insert("startIndex",data.startIndex);
     PAGER.insert("pageSize",data.pageSize);
     PAGER.insert("firstPage",data.firstPage);
     PAGER.insert("endIndex",data.endIndex);
     PAGER.insert("currentPage",data.currentPage);

     QJsonObject PARAM;

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
//资源库所有记录查询
bool SysUserClient::F_QUERY_LIBRARY_INFO_ALL_DATA(QString& repQstr)
{
    QJsonObject PARAM;

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME","QUERY_LIBRARY_INFO_ALL_DATA");
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

   return SendRecv(reqQstr,repQstr);
}

//批量添加模版
bool SysUserClient::F_ADD_FACE_PHOTO(ADD_FACE_PHOTO& data,QString& repQstr)
{
    QJsonObject PARAM;
    PARAM.insert("photoState",data.photoState);
    PARAM.insert("photoTime",data.photoTime);
    PARAM.insert("photoName",data.photoName);
    PARAM.insert("targetId",data.targetId);
    PARAM.insert("photoAddress",data.photoAddress);
    PARAM.insert("userAccount",data.userAccount);
    PARAM.insert("photoPath",data.photoPath);

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);
    PARAMS.insert("LIBRARY_ID",data.LIBRARY_ID);

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
//查询目标人表记录
bool SysUserClient::F_QUERY_TARGET_INFO_ALL_DATA(QString& repQstr)
{

    QJsonObject PARAM;

    QJsonObject PARAMS;
    PARAMS.insert("PARAM",PARAM);

    QJsonObject JsonObj;
    JsonObj.insert("ACTION_NAME","QUERY_TARGET_INFO_ALL_DATA");
    JsonObj.insert("PARAMS",PARAMS);

    JsonFormat Jf;
    QString reqQstr = Jf.JsonObjStr(JsonObj);  //返回请求json串
    if(reqQstr.isEmpty())
    {
        return false;
    }

   return SendRecv(reqQstr,repQstr);
}
//----《实时告警管理》 -------
//实时告警列表
bool SysUserClient::F_QUERY_SUSPECT_ALARM_WITH_PAGE(QUERY_SUSPECT_ALARM_WITH_PAGE& data,QString& repQstr)
{
    QJsonObject PAGER;
    PAGER.insert("startIndex",data.startIndex);
    PAGER.insert("pageSize",data.pageSize);
    PAGER.insert("firstPage",data.firstPage);
    PAGER.insert("endIndex",data.endIndex);
    PAGER.insert("currentPage",data.currentPage);

    QJsonObject PARAM;

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
//告警处理
bool SysUserClient::F_UPDATE_SUSPECT_ALARM(UPDATE_SUSPECT_ALARM& data,QString& repQstr)
{
    QJsonObject PAGER;

    QJsonObject PARAM;
    PARAM.insert("id",data.id);
    PARAM.insert("monitorId",data.monitorId);
    PARAM.insert("faceId",data.faceId);
    PARAM.insert("alarmAddress",data.alarmAddress);
    PARAM.insert("suspectState",data.suspectState);
    PARAM.insert("similarity",data.similarity);
    PARAM.insert("suspectType",data.suspectType);
    PARAM.insert("alarmTime",data.alarmTime);

    QJsonObject PARAM2;
    PARAM2.insert("confirmResult",data.confirmResult);
    PARAM2.insert("targetId",data.targetId);
    PARAM2.insert("userAccount",data.userAccount);

    QJsonObject PARAMS;
    PARAMS.insert("PAGER",PAGER);
    PARAMS.insert("PARAM",PARAM);
    PARAMS.insert("PARAM2",PARAM2);

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

//----《监控区域维护》 -------
 bool SysUserClient::F_QUERY_MONITOR_AREA_WITH_PAGE(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr)
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
//监控区域信息列表
//添加区域信息 同下
//查询行政区划信息-不分页
 bool SysUserClient::F_QUERY_REGION_INFO_ALL_DATA(QUERY_REGION_INFO_ALL_DATA& data,QString& repQstr)
 {
     QJsonObject PAGER;

     QJsonObject PARAM;
     PARAM.insert("id",data.id);
     PARAM.insert("codeLv",data.codeLv);

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
    PARAM.insert("locationId",data.locationId);

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




