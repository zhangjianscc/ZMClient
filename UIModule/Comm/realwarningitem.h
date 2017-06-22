#ifndef REALWARNINGITEM_H
#define REALWARNINGITEM_H

#include <QDialog>

namespace Ui {
class RealWarningItem;
}

class RealWarningItem : public QDialog
{
    Q_OBJECT

public:
    explicit RealWarningItem(QWidget *parent = 0);
    ~RealWarningItem();
    void select();
    void unSelect();
    bool isSelected();
    void setData(QPixmap pix1,
                 QPixmap pix2,
                 double similar,
                 QString name,
                 QString sex,
                 int     age,
                 QString importanceLevel,
                 QString dangersLevel,
                 QString warningTime,
                 QString warningPlace,
                 QString area);
private:
    void initUI();

private:
    Ui::RealWarningItem *ui;

public slots:
    void onSlotCheckBoxStatusChanged(int sta);
    void onSlotDispos();


};

#endif // REALWARNINGITEM_H
