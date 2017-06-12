#ifndef EDITTARGETPERSON_H
#define EDITTARGETPERSON_H

#include <QDialog>

namespace Ui {
class EditTargetPerson;
}

class EditTargetPersonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditTargetPersonDlg(QWidget *parent = 0);
    ~EditTargetPersonDlg();

private:
    Ui::EditTargetPerson *ui;
};

#endif // EDITTARGETPERSON_H
