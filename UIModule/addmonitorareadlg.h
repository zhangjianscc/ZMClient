#ifndef ADDMONITORAREADLG_H
#define ADDMONITORAREADLG_H

#include <QDialog>

namespace Ui {
class AddMonitorAreaDlg;
}

class AddMonitorAreaDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddMonitorAreaDlg(QWidget *parent = 0);
    ~AddMonitorAreaDlg();

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
    Ui::AddMonitorAreaDlg *ui;

    void initUi();
};

#endif // ADDMONITORAREADLG_H
