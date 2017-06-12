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

private:
    Ui::EditMonitorPositionDlg *ui;
};

#endif // EDITMONITORPOSITIONDLG_H
