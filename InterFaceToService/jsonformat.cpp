#include "jsonformat.h"
#include <QString>
#include <QMetaObject>
#include <QJsonValue>
#include <QMetaProperty>
#include <QJsonValue>
#include <QVariant>
#include <QJsonDocument>


QJsonObject  JsonFormat::ToJsonObj(QObject& obj)
{

    const QMetaObject* metaObject = obj.metaObject();
    for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
    {
         const char * name=metaObject->property(i).name();
         QVariant var=obj.property(name);
         if(!var.isNull()) //忽略没有给值的属性
         {
            QJsonValue JsonValue=QJsonValue::fromVariant(var);
            CJsonObj.insert(QString::fromLatin1(name),JsonValue);
         }
    }

    return CJsonObj;
}

QJsonObject  JsonFormat::FinalJsonObj(QObject& obj)
{

    const QMetaObject* metaObject = obj.metaObject();
    for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
    {
         const char * name=metaObject->property(i).name();
         QVariant var=obj.property(name);
         if(!var.isNull()) //忽略没有给值的属性
         {
            QJsonValue JsonValue=QJsonValue::fromVariant(var);
            finalJsonObj.insert(QString::fromLatin1(name),JsonValue);
         }
    }
    return finalJsonObj;
}


QString JsonFormat::JsonObjStr(QJsonObject& JsonObj)
{
    QJsonDocument document;
    document.setObject(JsonObj);
    QByteArray byteArray=document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    return strJson;
}
