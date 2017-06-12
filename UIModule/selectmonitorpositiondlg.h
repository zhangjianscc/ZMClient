#ifndef SELECTMONITORPOSITIONDLG_H
#define SELECTMONITORPOSITIONDLG_H

#include <QDialog>

namespace Ui {
class SelectMonitorPositionDlg;
}

class SelectMonitorPositionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SelectMonitorPositionDlg(QWidget *parent = 0);
    ~SelectMonitorPositionDlg();

private:
    Ui::SelectMonitorPositionDlg *ui;
};

#endif // SELECTMONITORPOSITIONDLG_H
