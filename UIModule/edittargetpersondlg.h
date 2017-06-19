#ifndef EDITTARGETPERSON_H
#define EDITTARGETPERSON_H

#include <QDialog>

namespace Ui {
class EditTargetPerson;
}

struct ImageItemData
{
    QPixmap pix;
    QString name;
};
class EditTargetPersonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditTargetPersonDlg(QWidget *parent = 0);
    ~EditTargetPersonDlg();
private:
    void initUI();
    void initPersonImages(QList<ImageItemData> list);

private:
    Ui::EditTargetPerson *ui;

public slots:
    void onSlotClose();
    void onSlotAddImage();
};

#endif // EDITTARGETPERSON_H
