#ifndef BASE64_H
#define BASE64_H
#include <string>
#include <QByteArray>
#include <QBuffer>
#include <QImage>
#include <QPixmap>
#include <sstream>

class Base64
{
public:
    Base64();
    QByteArray Base64QString_TO_QByteArray(QString string);
    QString QByteArray_TO_Base64QString(QByteArray QbyteArray);
    QByteArray QString_To_Base64(QString string);
    QString Base64_To_QString(QByteArray QbyteArray);
    QByteArray Image_To_Base64(QString ImgPath);
    QPixmap Base64_To_Image(QByteArray bytearray,QString SavePath);
};

#endif // BASE64_H
