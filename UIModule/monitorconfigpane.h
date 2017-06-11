#ifndef MONITORCONFIGPANE_H
#define MONITORCONFIGPANE_H

#include <QWidget>

namespace Ui {
class MonitorConfigPane;
}

class MonitorConfigPane : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorConfigPane(QWidget *parent = 0);
    ~MonitorConfigPane();

private:
    Ui::MonitorConfigPane *ui;
};

#endif // MONITORCONFIGPANE_H
