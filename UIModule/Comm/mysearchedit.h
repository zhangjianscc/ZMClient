#ifndef MYSEARCHEDIT_H
#define MYSEARCHEDIT_H
#include <QLineEdit>


class MySearchEdit : public QLineEdit
{
    Q_OBJECT
public:
    MySearchEdit(QWidget* parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
private:
    void initUI();
signals:
    void searchBtnClicked();

public slots:
    void onSlotSearchBtnBlicked();

};

#endif // MYSEARCHEDIT_H
