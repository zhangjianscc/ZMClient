#ifndef MAPTRACKPANE_H
#define MAPTRACKPANE_H

#include <QWidget>

namespace Ui {
class MapTrackPane;
}

class MapTrackPane : public QWidget
{
    Q_OBJECT

public:
    explicit MapTrackPane(QWidget *parent = 0);
    ~MapTrackPane();

private:
    Ui::MapTrackPane *ui;
};

#endif // MAPTRACKPANE_H
