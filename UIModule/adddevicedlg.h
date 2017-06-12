#ifndef ADDDEVICEDLG_H
#define ADDDEVICEDLG_H

#include <QDialog>

namespace Ui {
class AddDeviceDlg;
}

class AddDeviceDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddDeviceDlg(QWidget *parent = 0);
    ~AddDeviceDlg();

private:
    Ui::AddDeviceDlg *ui;
};

#endif // ADDDEVICEDLG_H
