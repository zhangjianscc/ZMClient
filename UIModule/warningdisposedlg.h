#ifndef WARNIGDISPOSEDLG_H
#define WARNIGDISPOSEDLG_H

#include <QDialog>

namespace Ui {
class WarnigDisposeDlg;
}

class WarningDisposeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDisposeDlg(QWidget *parent = 0);
    ~WarningDisposeDlg();

private:
    Ui::WarnigDisposeDlg *ui;
};

#endif // WARNIGDISPOSEDLG_H
