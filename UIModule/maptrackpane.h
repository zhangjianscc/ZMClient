#ifndef MAPTRACKPANE_H
#define MAPTRACKPANE_H

#include <QWidget>
#include <QMap>

namespace Ui {
class MapTrackPane;
}

struct MapTrackData
{
    QPixmap pixmap;
    QString postion;
    QString dateTime; //
    double  longitude;
    double  latitude;
};
class MapTrackPane : public QWidget
{
    Q_OBJECT

public:
    explicit MapTrackPane(QWidget *parent = 0);
    ~MapTrackPane();
private:
    void initUI();
    void initTableData();
    void initMapData();
    void loadMap();

private:
    Ui::MapTrackPane *ui;
    QMap<QDateTime,MapTrackData> m_mapData;
signals:
public slots:
    void onSlotReturn();
    void onSlotClose();
};

#endif // MAPTRACKPANE_H
