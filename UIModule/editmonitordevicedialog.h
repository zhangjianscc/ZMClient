#ifndef EDITMONITORDEVICEDIALOG_H
#define EDITMONITORDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class EditMonitorDeviceDialog;
}

class EditMonitorDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditMonitorDeviceDialog(QWidget *parent = 0);
    ~EditMonitorDeviceDialog();

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
    Ui::EditMonitorDeviceDialog *ui;

    void initUi();
};

#endif // EDITMONITORDEVICEDIALOG_H
