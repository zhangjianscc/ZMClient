#ifndef MONITORCONFIGPANE_H
#define MONITORCONFIGPANE_H

#include <QWidget>

class QRoundProgressBar;
class MyTargetButton;

namespace Ui {
class MonitorConfigPane;
}

class MonitorConfigPane : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorConfigPane(QWidget *parent = 0);
    ~MonitorConfigPane();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MonitorConfigPane *ui;

    void initUi();
    void updateData(QList<MyTargetButton*> &listMyTargetButton);

    int m_iWarningNumber;
    int m_iWarningValue;
    bool m_bWarningEnable;
};

#endif // MONITORCONFIGPANE_H
