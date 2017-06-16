#ifndef MYTWOIMAGECOMPAREPANE_H
#define MYTWOIMAGECOMPAREPANE_H

#include <QWidget>

namespace Ui {
class MyTwoImageComparePane;
}

class MyTwoImageComparePane : public QWidget
{
    Q_OBJECT

public:
    explicit MyTwoImageComparePane(QWidget *parent = 0);
    ~MyTwoImageComparePane();
    void setData(QPixmap pix1,QPixmap pix2,QString imageSource,double similar);

private:
    Ui::MyTwoImageComparePane *ui;
};

#endif // MYTWOIMAGECOMPAREPANE_H
