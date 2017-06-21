#ifndef TEMPLATEITEM_H
#define TEMPLATEITEM_H

#include <QWidget>

namespace Ui {
class TemplateItem;
}

class TemplateItem : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateItem(QWidget *parent = 0);
    ~TemplateItem();
    void select();
    void unSelect();
    bool isSelected();
    void setData(QPixmap pix,
                 QString imageName,
                 QString name,
                 QString sex,
                 int     age,
                 QString identityNumber,
                 QString importanceLevel,
                 QString dangersLevel);
private:
    void initUI();

private:
    Ui::TemplateItem *ui;

public slots:
    void onSlotCheckBoxStatusChanged(int sta);
};

#endif // TEMPLATEITEM_H
