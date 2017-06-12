#ifndef REQGLOBAL_H
#define REQGLOBAL_H
#include <QString>
#define MAX_RECVBUFFSIZ 1024 * 4   //先定义4k的接收缓存
#include <QJsonArray>
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

//查询行政区划信息-不分页
typedef struct _QUERY_REGION_INFO_ALL_DATA
{
    QString ACTION_NAME;
    QString id;
    QString codeLv;

    _QUERY_REGION_INFO_ALL_DATA(){ACTION_NAME="QUERY_REGION_INFO_ALL_DATA";}

}QUERY_REGION_INFO_ALL_DATA;

//告警信息处理
typedef struct _UPDATE_SUSPECT_ALARM
{
    QString ACTION_NAME;
    QString id;
    QString monitorId;
    QString faceId;
    QString alarmAddress;
    QString suspectState;
    QString similarity;
    QString suspectType;
    QString alarmTime;

    QString confirmResult;
    QString targetId;
    QString userAccount;

    _UPDATE_SUSPECT_ALARM(){ACTION_NAME="UPDATE_SUSPECT_ALARM";}

}UPDATE_SUSPECT_ALARM;

//添加目标人脸照片表记录
typedef struct _ADD_FACE_PHOTO
{
    QString ACTION_NAME;

    QString photoState;
    QString photoTime;
    QString photoName;
    QString targetId;
    QString photoAddress;
    QString userAccount;
    QString photoPath;

    QString LIBRARY_ID;

    _ADD_FACE_PHOTO(){ACTION_NAME="ADD_FACE_PHOTO";}

}ADD_FACE_PHOTO;


//查询目标人脸照片表记录--分页
typedef struct _QUERY_FACE_PHOTO_WITH_PAGE
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;

    _QUERY_FACE_PHOTO_WITH_PAGE(){ACTION_NAME="QUERY_FACE_PHOTO_WITH_PAGE";}

}QUERY_FACE_PHOTO_WITH_PAGE;

//添加资源库表记录
typedef struct _ADD_LIBRARY_INFO
{
    QString ACTION_NAME;

    QString libraryName;
    QString userAccount;

    _ADD_LIBRARY_INFO(){ACTION_NAME="ADD_LIBRARY_INFO";}

}ADD_LIBRARY_INFO;

//删除资源库表记录
typedef struct _DELETE_LIBRARY_INFO
{
    QString ACTION_NAME;

    QString id;

    _DELETE_LIBRARY_INFO(){ACTION_NAME="DELETE_LIBRARY_INFO";}

}DELETE_LIBRARY_INFO;

//添加目标人表记录
typedef struct _ADD_TARGET_INFO
{
    QString ACTION_NAME;

    QString targetName;

    _ADD_TARGET_INFO(){ACTION_NAME="ADD_TARGET_INFO";}

}ADD_TARGET_INFO;


//修改目标人表记录
typedef struct _UPDATE_TARGET_INFO
{
    QString ACTION_NAME;

    QString targetSex;
    QString id;
    QString dangerLv;
    QString targetName;

    _UPDATE_TARGET_INFO(){ACTION_NAME="UPDATE_TARGET_INFO";}

}UPDATE_TARGET_INFO;

//删除目标人表记录
typedef struct _DELETE_TARGET_INFO
{
    QString ACTION_NAME;

    QString id;

    _DELETE_TARGET_INFO(){ACTION_NAME="DELETE_TARGET_INFO";}

}DELETE_TARGET_INFO;

//通过目标人查询目标人脸照片
typedef struct _QUERY_FACE_PHOTO_ALL_DATA
{
    QString ACTION_NAME;

    QString targetId;

    _QUERY_FACE_PHOTO_ALL_DATA(){ACTION_NAME="QUERY_FACE_PHOTO_ALL_DATA";}

}QUERY_FACE_PHOTO_ALL_DATA;


//查询目标人表记录
typedef struct _QUERY_TARGET_INFO_WITH_PAGE
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;

    QString account;

    _QUERY_TARGET_INFO_WITH_PAGE(){ACTION_NAME="QUERY_TARGET_INFO_WITH_PAGE";}

}QUERY_TARGET_INFO_WITH_PAGE;

//1：N比对

typedef struct _ONE_THAN_MORE
{
    QString ACTION_NAME;

    QString groupIds;
    QString count;
    QString gender;
    QString pic;
    QString threshold;

    _ONE_THAN_MORE(){ACTION_NAME="ONE_THAN_MORE";}

}ONE_THAN_MORE;


//1：1比对
typedef struct _ONE_THAN_ONE
{
    QString ACTION_NAME;

    QString PHOTO_TWO;
    QString PHOTO_ONE;

    _ONE_THAN_ONE(){ACTION_NAME="ONE_THAN_ONE";}

}ONE_THAN_ONE;

//告警参数表记录修改


typedef struct _UPDATE_PARAM_LIBRARY
{
    QString ACTION_NAME;

    QString id;
    QString alarmThreshold;
    QString contrastThreshold;

    QJsonArray LIBRARY_INFO_LIST;

    _UPDATE_PARAM_LIBRARY(){ACTION_NAME="UPDATE_PARAM_LIBRARY";}

}UPDATE_PARAM_LIBRARY;

//告警参数资源库关系表记录查询
typedef struct _QUERY_LIBRARY_INFO_BY_PARAM_ID
{
    QString ACTION_NAME;

    QString id;

    _QUERY_LIBRARY_INFO_BY_PARAM_ID(){ACTION_NAME="QUERY_LIBRARY_INFO_BY_PARAM_ID";}

}QUERY_LIBRARY_INFO_BY_PARAM_ID;


typedef struct _QUERY_MONITOR_LOCATION_ALL_DATA
{
    QString ACTION_NAME;

    QString startIndex;
    QString pageSize;
    QString firstPage;
    QString endIndex;
    QString currentPage;

    QString id;
    QString areaId;

    _QUERY_MONITOR_LOCATION_ALL_DATA(){ACTION_NAME="QUERY_MONITOR_LOCATION_ALL_DATA";}

}QUERY_MONITOR_LOCATION_ALL_DATA;


typedef struct _QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE
{
    QString ACTION_NAME;

    QString beginDate;

    _QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE(){ACTION_NAME="QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE";}

}QUERY_SUSPECT_ALARM_COUNT_WITH_BGEIN_DATE;



#endif // REQGLOBAL_H
