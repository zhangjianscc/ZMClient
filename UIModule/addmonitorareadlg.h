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

public slots:
    void slot_saveButClicked();
    void slot_cancelButClicked();

private:
    Ui::AddMonitorAreaDlg *ui;

    void initUi();
};

#endif // ADDMONITORAREADLG_H
