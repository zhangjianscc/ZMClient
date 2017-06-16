#ifndef FACEHISTORYIMAGEITEM_H
#define FACEHISTORYIMAGEITEM_H

#include <QWidget>

namespace Ui {
class FaceHistoryImageItem;
}

class FaceHistoryImageItem : public QWidget
{
    Q_OBJECT

public:
    explicit FaceHistoryImageItem(QWidget *parent = 0);
    ~FaceHistoryImageItem();
    void setData(QPixmap pix,QString address,QString dateTime,double similar);
private:
    void initUI();

private:
    Ui::FaceHistoryImageItem *ui;
};

#endif // FACEHISTORYIMAGEITEM_H
