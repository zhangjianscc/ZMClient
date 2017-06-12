#ifndef WARNIGDISPOSEDLG_H
#define WARNIGDISPOSEDLG_H

#include <QDialog>

namespace Ui {
class WarnigDisposeDlg;
}

class WarnigDisposeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarnigDisposeDlg(QWidget *parent = 0);
    ~WarnigDisposeDlg();

private:
    Ui::WarnigDisposeDlg *ui;
};

#endif // WARNIGDISPOSEDLG_H
