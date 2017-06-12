#ifndef MONITORAREAMAINTAIN_H
#define MONITORAREAMAINTAIN_H

#include <QWidget>

namespace Ui {
class MonitorAreaMaintain;
}

class MonitorAreaMaintain : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorAreaMaintain(QWidget *parent = 0);
    ~MonitorAreaMaintain();

private:
    Ui::MonitorAreaMaintain *ui;
};

#endif // MONITORAREAMAINTAIN_H
