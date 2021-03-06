#ifndef ADDMONITORPOSITIONDLG_H
#define ADDMONITORPOSITIONDLG_H

#include <QDialog>

namespace Ui {
class AddMonitorPositionDlg;
}

class AddMonitorPositionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddMonitorPositionDlg(QWidget *parent = 0);
    ~AddMonitorPositionDlg();

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

public slots:
    void slot_closeButClicked();
    void slot_openButClicked();
    void slot_saveButClicked();
    void slot_cancelButClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::AddMonitorPositionDlg *ui;

    void initUi();
};

#endif // ADDMONITORPOSITIONDLG_H
