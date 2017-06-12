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

private:
    Ui::EditMonitorAreaDlg *ui;
};

#endif // EDITMONITORAREADLG_H
