#ifndef MAPTRACKITEM_H
#define MAPTRACKITEM_H

#include <QWidget>

namespace Ui {
class MapTrackItem;
}

class MapTrackItem : public QWidget
{
    Q_OBJECT

public:
    explicit MapTrackItem(QWidget *parent = 0);
    ~MapTrackItem();
    void setData(QPixmap pix,QString position,QString dateTime);

private:
    Ui::MapTrackItem *ui;
};

#endif // MAPTRACKITEM_H
