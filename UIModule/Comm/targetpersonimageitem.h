#ifndef TARGETPERSONIMAGEITEM_H
#define TARGETPERSONIMAGEITEM_H

#include <QWidget>

namespace Ui {
class TargetPersonImageItem;
}

class TargetPersonImageItem : public QWidget
{
    Q_OBJECT

public:
    explicit TargetPersonImageItem(QWidget *parent = 0);
    ~TargetPersonImageItem();
    void setData(QPixmap pix,QString name);
public:
    QPixmap m_pixmap;
    QString m_imageName;

private:
    Ui::TargetPersonImageItem *ui;
};

#endif // TARGETPERSONIMAGEITEM_H
