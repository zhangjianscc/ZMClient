#ifndef MONITORDEVICEMAINTAIN_H
#define MONITORDEVICEMAINTAIN_H

#include <QWidget>

namespace Ui {
class MonitorDeviceMaintain;
}

class MonitorDeviceMaintain : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorDeviceMaintain(QWidget *parent = 0);
    ~MonitorDeviceMaintain();

private:
    Ui::MonitorDeviceMaintain *ui;
};

#endif // MONITORDEVICEMAINTAIN_H
