#ifndef ADDMONITORDEVICEDIALOG_H
#define ADDMONITORDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class AddMonitorDeviceDialog;
}

class AddMonitorDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMonitorDeviceDialog(QWidget *parent = 0);
    ~AddMonitorDeviceDialog();

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

public slots:
    void slot_closeButClicked();
    void slot_saveButClicked();
    void slot_cancelButClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::AddMonitorDeviceDialog *ui;

    void initUi();
};

#endif // ADDMONITORDEVICEDIALOG_H
