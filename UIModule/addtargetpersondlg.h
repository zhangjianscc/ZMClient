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
    void initUI();

private:
    Ui::AddTargetPerson *ui;
public slots:
    void onSlotClose();
};

#endif // ADDTARGETPERSON_H
