#ifndef EDITMONITORAREADLG_H
#define EDITMONITORAREADLG_H

#include <QDialog>

namespace Ui {
class EditMonitorAreaDlg;
}

class EditMonitorAreaDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditMonitorAreaDlg(QWidget *parent = 0);
    ~EditMonitorAreaDlg();

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
    Ui::EditMonitorAreaDlg *ui;

    void initUi();
};

#endif // EDITMONITORAREADLG_H
