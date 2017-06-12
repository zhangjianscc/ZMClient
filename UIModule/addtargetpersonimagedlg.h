#ifndef ADDTARGETPERSONIMAGE_H
#define ADDTARGETPERSONIMAGE_H

#include <QDialog>

namespace Ui {
class AddTargetPersonImage;
}

class AddTargetPersonImageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddTargetPersonImageDlg(QWidget *parent = 0);
    ~AddTargetPersonImageDlg();

private:
    Ui::AddTargetPersonImage *ui;
};

#endif // ADDTARGETPERSONIMAGE_H
