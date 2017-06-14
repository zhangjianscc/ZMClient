#ifndef OBJECTFORMAT_H
#define OBJECTFORMAT_H
#include <QObject>
#include <QJsonObject>
#include <QString>


class ObjectFormat
{
public:
    void FormatValue(QJsonValue& JsonValue,const char* method,QObject& ClassObj);
    void FormatObject(QJsonObject& JsonObj,QObject& ClassObj);

};

#endif // OBJECTFORMAT_H
