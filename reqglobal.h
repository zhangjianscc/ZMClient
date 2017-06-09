#ifndef REQGLOBAL_H
#define REQGLOBAL_H
#include <QString>
#define MAX_RECVBUFFSIZ 1024 * 4   //先定义4k的接收缓存
//定义请求体结构体
//登录
typedef struct _LOGIN
{
    QString ACTION_NAME;
    QString account;
    QString password;

    _LOGIN(){ACTION_NAME="LOGIN";}

}LOGIN;

//实时告警采集
typedef struct _QUERY_SUSPECT_ALARM_WITH_PAGE
{
    QString ACTION_NAME;
    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;

    _QUERY_SUSPECT_ALARM_WITH_PAGE(){ACTION_NAME="QUERY_SUSPECT_ALARM_WITH_PAGE";}

}QUERY_SUSPECT_ALARM_WITH_PAGE;

//修改人脸采集设备参数信息
typedef struct _UPDATE_CAMERA_INFO
{
    QString ACTION_NAME;

    QString cameraCode;
    QString gateway;
    QString cameraType;
    QString locationId;
    QString serverIp;
    QString subnetMask;
    QString macAddress;
    QString url;
    QString id;
    QString cameraName;
    QString cameraPort;
    QString serverPort;
    QString managerId;
    QString cameraModel;
    QString cameraState;
    QString ipAddress;

    _UPDATE_CAMERA_INFO(){ACTION_NAME="UPDATE_CAMERA_INFO";}

}UPDATE_CAMERA_INFO;

//查询人脸采集设备参数信息表记录
typedef struct _QUERY_CAMERA_PARAM_WITH_PAGE
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;
    QString id;
    QString cameraId;

    _QUERY_CAMERA_PARAM_WITH_PAGE(){ACTION_NAME="QUERY_CAMERA_PARAM_WITH_PAGE";}

}QUERY_CAMERA_PARAM_WITH_PAGE;


//删除人脸采集设备信息
typedef struct _DELETE_CAMERA_INFO
{
    QString ACTION_NAME;
    QString id;
    _DELETE_CAMERA_INFO(){ACTION_NAME="DELETE_CAMERA_INFO";}

}DELETE_CAMERA_INFO;

//修改人脸采集设备信息
typedef struct _ADD_CAMERA_INFO
{
    QString ACTION_NAME;

    QString cameraCode;
    QString gateway;
    QString cameraType;
    QString locationId;
    QString serverIp;
    QString subnetMask;
    QString macAddress;
    QString reserve1;
    QString id;
    QString cameraName;
    QString cameraPort;
    QString serverPort;
    QString managerId;
    QString cameraModel;
    QString cameraState;
    QString ipAddress;

    _ADD_CAMERA_INFO(){ACTION_NAME="ADD_CAMERA_INFO";}

}ADD_CAMERA_INFO;

//查询人脸采集设备信息（分页）
typedef struct _QUERY_CAMERA_INFO_WITH_PAGE
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;
    QString id;
    QString cameraName;
    QString locationId;

    _QUERY_CAMERA_INFO_WITH_PAGE(){ACTION_NAME="QUERY_CAMERA_INFO_WITH_PAGE";}

}QUERY_CAMERA_INFO_WITH_PAGE;

//废除监控位置信息
typedef struct _DISUSED_MONITOR_LOCATION
{
    QString ACTION_NAME;
    QString id;
    _DISUSED_MONITOR_LOCATION(){ACTION_NAME="DISUSED_MONITOR_LOCATION";}

}DISUSED_MONITOR_LOCATION;

//

typedef struct _ADD_MONITOR_LOCATION
{
    QString ACTION_NAME;

    QString id;
    QString locationCode;
    QString locationType;
    QString longitude;
    QString locationName;
    QString latitude;
    QString locationState;
    QString areaId;

    _ADD_MONITOR_LOCATION(){ACTION_NAME="ADD_MONITOR_LOCATION";}

}ADD_MONITOR_LOCATION;

//通过Id查询监控位置信息
typedef struct _QUERY_MONITOR_LOCATION_BY_ID
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;
    QString id;

    _QUERY_MONITOR_LOCATION_BY_ID(){ACTION_NAME="QUERY_MONITOR_LOCATION_BY_ID";}

}QUERY_MONITOR_LOCATION_BY_ID;

//查询监控位置信息（分页）
typedef struct _QUERY_MONITOR_AREA_WITH_PAGE
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;

    QString id;
    QString locationCode;
    QString locationName;

    _QUERY_MONITOR_AREA_WITH_PAGE(){ACTION_NAME="QUERY_MONITOR_AREA_WITH_PAGE";}

}QUERY_MONITOR_AREA_WITH_PAGE;


























#endif // REQGLOBAL_H
