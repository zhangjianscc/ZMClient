#ifndef MONITORPOSITIONMAINTAIN_H
#define MONITORPOSITIONMAINTAIN_H

#include <QWidget>

namespace Ui {
class MonitorPositionMaintain;
}

class MonitorPositionMaintain : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorPositionMaintain(QWidget *parent = 0);
    ~MonitorPositionMaintain();

private:
    Ui::MonitorPositionMaintain *ui;
};

#endif // MONITORPOSITIONMAINTAIN_H
