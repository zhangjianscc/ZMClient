#ifndef EDITMONITORPOSITIONDLG_H
#define EDITMONITORPOSITIONDLG_H

#include <QDialog>

namespace Ui {
class EditMonitorPositionDlg;
}

class EditMonitorPositionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditMonitorPositionDlg(QWidget *parent = 0);
    ~EditMonitorPositionDlg();

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
    Ui::EditMonitorPositionDlg *ui;

    void initUi();
};

#endif // EDITMONITORPOSITIONDLG_H
