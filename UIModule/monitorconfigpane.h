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

    void loadInfo(QList<QString> &listName);

public slots:
    void slot_valueChanged();
    void slot_buttonClicked();
    void slot_closeButClicked();
    void slot_searchButClicked();
    void slot_saveButClicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MonitorConfigPane *ui;

    void initUi();
    void updateSelectData(QList<QString> &listString);
    void updateSelectedData();

    QList<QString> m_listString;
    QList<MyTargetButton*> m_listSelButton;

    int m_iWarningNumber;
    int m_iWarningValue;
    bool m_bWarningEnable;
};

#endif // MONITORCONFIGPANE_H
