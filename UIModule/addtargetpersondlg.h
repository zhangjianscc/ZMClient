#ifndef ADDTARGETPERSON_H
#define ADDTARGETPERSON_H

#include <QDialog>

namespace Ui {
class AddTargetPerson;
}

class AddTargetPersonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddTargetPersonDlg(QWidget *parent = 0);
    ~AddTargetPersonDlg();

private:
    Ui::AddTargetPerson *ui;
};

#endif // ADDTARGETPERSON_H
