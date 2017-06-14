#ifndef JSONFORMAT_H
#define JSONFORMAT_H
#include <QObject>
#include <QJsonObject>
#include <QString>

class JsonFormat
{
public:
    //JsonFormat();
    QJsonObject  FinalJsonObj(QObject& obj);
    QJsonObject  ToJsonObj(QObject& obj);
    QString JsonObjStr(QJsonObject& JsonObj);
private:
    QJsonObject CJsonObj;
    QJsonObject finalJsonObj;
};

#endif // JSONFORMAT_H
