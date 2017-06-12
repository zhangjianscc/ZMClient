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

private:
    Ui::AddMonitorAreaDlg *ui;
};

#endif // ADDMONITORAREADLG_H
