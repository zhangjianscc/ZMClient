#include "objformat.h"
#include <QJsonValue>
#include <QtDebug>
#include <QJsonArray>
#include <QMetaObject>
#include <QMetaProperty>
#include <QJsonObject>
#include <QObject>
#include <QString>
#include <QByteArray>

void ObjectFormat::FormatValue(QJsonValue& JsonValue,const char* method,QObject& ClassObj)
{
    if(JsonValue.isArray())
    {
        QJsonArray JsonAarray=JsonValue.toArray();
        for(int i=0;i<JsonAarray.size();++i){

            QJsonValue value=JsonAarray.at(i);
            FormatValue(value,method,ClassObj);
        }
       //QMetaObject::invokeMethod(&ClassObj,method,Q_ARG(QJsonArray,JsonValue.toArray()));

    }
    else if(JsonValue.isBool())
    {
        QMetaObject::invokeMethod(&ClassObj,method,Q_ARG(bool,JsonValue.toBool()));
    }
    else if(JsonValue.isDouble())
    {
       QMetaObject::invokeMethod(&ClassObj,method,Q_ARG(double,JsonValue.toDouble()));

    }
    else if(JsonValue.isObject())
    {
        QJsonObject JsonObject=JsonValue.toObject();
        FormatObject(JsonObject,ClassObj);
        //QMetaObject::invokeMethod(&ClassObj,method,Q_ARG(QJsonObject&,JsonValue.toObject()));

    }
    else if(JsonValue.isString())
    {
       QString value=JsonValue.toString();
       QMetaObject::invokeMethod(&ClassObj,method,Q_ARG(QString,value));
    }
    else
    {
        qDebug()<<"No type found!";
    }
}

void ObjectFormat::FormatObject(QJsonObject& JsonObj,QObject& ClassObj)
{

   //const QMetaObject* metaObject = static_cast<LoginObj*>(&ClassObj)->metaObject();
    const QMetaObject* metaObject = ClassObj.metaObject();
    for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
    {
         const char * name=metaObject->property(i).name();

         QString methodName=QString("set")+QString(name);

         QJsonValue JsonValue= JsonObj.value(QString(name));

         if(JsonValue.isUndefined()){
             qDebug()<<"Undefined Json Node!";
             continue;
         }

         QByteArray norm =QMetaObject::normalizedType(methodName.toUtf8().data());

         const char* method=norm;

        // qDebug()<<method;

        FormatValue(JsonValue,method,ClassObj);
    }
}
