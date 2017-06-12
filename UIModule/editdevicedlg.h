#ifndef EDITDEVICEDLG_H
#define EDITDEVICEDLG_H

#include <QDialog>

namespace Ui {
class EditDeviceDlg;
}

class EditDeviceDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeviceDlg(QWidget *parent = 0);
    ~EditDeviceDlg();

private:
    Ui::EditDeviceDlg *ui;
};

#endif // EDITDEVICEDLG_H
