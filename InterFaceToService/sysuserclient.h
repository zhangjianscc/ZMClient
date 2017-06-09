#ifndef SYSUSERCLIENT_H
#define SYSUSERCLIENT_H
#include <QString>
#include "InterFaceToService/loginobj.h"
#include "reqglobal.h"

class SysUserClient
{
public:
    //SysUserClient();
    bool SendRecv(QString &reqQstr,QString &repQstr);

    bool Login(LOGIN& l,QString &repQstr);//登陆请求接口
    //实时告警采集
    bool F_QUERY_SUSPECT_ALARM_WITH_PAGE(QUERY_SUSPECT_ALARM_WITH_PAGE& Query,QString& repQstr);

    // .....
    //查询监控位置信息（分页）
    bool F_QUERY_MONITOR_LOCATION_WITH_PAGE(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr);
    //通过Id查询监控位置信息
    bool F_QUERY_MONITOR_LOCATION_BY_ID(QUERY_MONITOR_LOCATION_BY_ID& data,QString& repQstr);
   //添加监控位置信息
    bool F_ADD_MONITOR_LOCATION(ADD_MONITOR_LOCATION& data,QString& repQstr);
    //编辑监控位置信息
    bool F_UPDATE_MONITOR_LOCATION(ADD_MONITOR_LOCATION& data,QString& repQstr);
    //废除监控位置信息
    bool F_DISUSED_MONITOR_LOCATION(DISUSED_MONITOR_LOCATION& data,QString& repQstr);
    //人脸采集设备信息列表
    bool F_QUERY_CAMERA_INFO_WITH_PAGE(QUERY_CAMERA_INFO_WITH_PAGE& data,QString& repQstr);
    //添加人脸采集设备信息
    bool F_ADD_CAMERA_INFO(ADD_CAMERA_INFO& data,QString& repQstr);
    //修改人脸采集设备信息
    bool F_UPDATE_CAMERA_INFO(ADD_CAMERA_INFO& data,QString& repQstr);
    //删除人脸采集设备信息
    bool F_DELETE_CAMERA_INFO(DELETE_CAMERA_INFO& Delete,QString& repQstr);
    //查询人脸采集设备参数信息（分页）
    bool F_QUERY_CAMERA_PARAM_WITH_PAGE(QUERY_CAMERA_PARAM_WITH_PAGE& Query,QString& repQstr);
     //修改人脸采集设备参数信息
    bool F_UPDATE_CAMERA_PARAM(UPDATE_CAMERA_INFO& Update,QString& repQstr);

};

#endif // SYSUSERCLIENT_H
