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

private:
    Ui::AddMonitorPositionDlg *ui;
};

#endif // ADDMONITORPOSITIONDLG_H
