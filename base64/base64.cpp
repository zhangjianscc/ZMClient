#include "base64.h"

Base64::Base64()
{

}
//base64字符串转成byte数组
QByteArray Base64::Base64QString_TO_QByteArray(QString string)
{
    QByteArray ba,Qba;
    ba.append(string);
    return Qba.fromBase64(ba);
}

//数组转成64字符串
QString Base64::QByteArray_TO_Base64QString(QByteArray QbyteArray)
{
    QString str;
    QByteArray hexed=QbyteArray.toBase64();
    str.prepend(hexed);
    return str;
}

//字符串转成64位byte数组
QByteArray Base64::QString_To_Base64(QString string)
{
    QByteArray ba;
    ba.append(string);
    return ba.toBase64();
}

//base64 数组转成字符串
QString Base64::Base64_To_QString(QByteArray QbyteArray)
{
    QByteArray ba;
    ba.fromBase64(QbyteArray);
    QString str;
    return  str.prepend(ba);
}


QByteArray Base64::Image_To_Base64(QString ImgPath)
{
    QImage image(ImgPath);
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf,"PNG",20);
    QByteArray hexed = ba.toBase64();
    buf.close();
    return hexed;
}
QPixmap Base64::Base64_To_Image(QByteArray bytearray,QString SavePath)
{
    QByteArray Ret_bytearray;
    Ret_bytearray = QByteArray::fromBase64(bytearray);
    QBuffer buffer(&Ret_bytearray);
    buffer.open(QIODevice::WriteOnly);
    QPixmap imageresult;
    imageresult.loadFromData(Ret_bytearray);
    if(SavePath != "")
     {
          imageresult.save(SavePath);
     }
     return imageresult;

}
