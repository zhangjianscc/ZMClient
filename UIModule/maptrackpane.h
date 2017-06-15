#ifndef MAPTRACKPANE_H
#define MAPTRACKPANE_H

#include <QWidget>

namespace Ui {
class MapTrackPane;
}

struct MapTrackData
{
    QPixmap pixmap;
    QString postion;
    QString dateTime;
};
class MapTrackPane : public QWidget
{
    Q_OBJECT

public:
    explicit MapTrackPane(QWidget *parent = 0);
    ~MapTrackPane();
private:
    void initUI();
    void initTable(QList<MapTrackData> list);

private:
    Ui::MapTrackPane *ui;
signals:
public slots:
    void onSlotReturn();
};

#endif // MAPTRACKPANE_H
