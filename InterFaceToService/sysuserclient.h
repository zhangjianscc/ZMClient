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

    //根据时间查询实时告警采集行数
    bool F_QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE(QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE& data,QString& repQstr);

    //实时告警采集-固定10条数据
    bool F_QUERY_SUSPECT_ALARM_REAL(QString& repQstr);
    //查询行政区划信息-不分页
    //查询监控区域信息
    bool F_QUERY_MONITOR_AREA_WITH_PAGE_BY_ID(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr);
    //查询监控位置信息表记录
    bool F_QUERY_CAMERA_INFO_ALL_DATA(QUERY_MONITOR_LOCATION_ALL_DATA& data,QString& repQstr);
    //通过位置Id查询人脸采集设备信息
    bool F_QUERY_CAMERA_INFO_ALL_DATA(QUERY_CAMERA_INFO_WITH_PAGE& data,QString& repQstr);
    //告警参数资源库关系表记录查询
    bool F_QUERY_LIBRARY_INFO_BY_PARAM_ID(QUERY_LIBRARY_INFO_BY_PARAM_ID& data,QString& repQstr);
    //告警参数表记录查询
    bool F_QUERY_ALARM_PARAM_ALL_DATA(QString& repQstr);
    //告警参数表记录修改
    bool F_UPDATE_PARAM_LIBRARY(UPDATE_PARAM_LIBRARY& data,QString& repQstr);
    //1：1比对
    bool F_ONE_THAN_ONE(ONE_THAN_ONE& data,QString& repQstr);
    //1：N比对
    bool F_ONE_THAN_MORE(ONE_THAN_MORE& data,QString& repQstr);
    //通过目标人查询目标人脸照片-视图
    bool F_QUERY_FACE_PHOTO_WITH_VIEW(QUERY_FACE_PHOTO_ALL_DATA& data,QString& repQstr);
    //查询目标人表记录
    bool F_QUERY_TARGET_INFO_WITH_PAGE(QUERY_TARGET_INFO_WITH_PAGE& data,QString& repQstr);
    //通过目标人查询目标人脸照片
    bool F_QUERY_FACE_PHOTO_ALL_DATA(QUERY_FACE_PHOTO_ALL_DATA& data,QString& repQstr);
    //删除目标人表记录
    bool F_DELETE_TARGET_INFO(DELETE_TARGET_INFO& data,QString& repQstr);
    //修改目标人表记录
    bool F_UPDATE_TARGET_INFO(UPDATE_TARGET_INFO& data,QString& repQstr);
    //添加目标人表记录
    bool F_ADD_TARGET_INFO(ADD_TARGET_INFO& data,QString& repQstr);
    //删除资源库表记录
    bool F_DELETE_LIBRARY_INFO(DELETE_LIBRARY_INFO& data,QString& repQstr);
    //添加资源库表记录
    bool F_ADD_LIBRARY_INFO(ADD_LIBRARY_INFO& data,QString& repQstr);
    //查询目标人脸照片表记录
    bool F_QUERY_FACE_PHOTO_WITH_PAGE(QUERY_FACE_PHOTO_WITH_PAGE& data,QString& repQstr);
    //资源库所有记录查询
    bool F_QUERY_LIBRARY_INFO_ALL_DATA(QString& repQstr);
    //添加目标人脸照片表记录
    bool F_ADD_FACE_PHOTO(ADD_FACE_PHOTO& data,QString& repQstr);
    //查询目标人表记录
    bool F_QUERY_TARGET_INFO_ALL_DATA(QString& repQstr);
    //实时告警采集
    bool F_QUERY_SUSPECT_ALARM_WITH_PAGE(QUERY_SUSPECT_ALARM_WITH_PAGE& data,QString& repQstr);
    //告警信息处理
    bool F_UPDATE_SUSPECT_ALARM(UPDATE_SUSPECT_ALARM& data,QString& repQstr);
    //查询监控区域信息（分页）
    bool F_QUERY_MONITOR_AREA_WITH_PAGE(QUERY_MONITOR_AREA_WITH_PAGE& data,QString& repQstr);
    //查询行政区划信息-不分页
    bool F_QUERY_REGION_INFO_ALL_DATA(QUERY_REGION_INFO_ALL_DATA& data,QString& repQstr);
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
