#ifndef MYIMAGELABEL_H
#define MYIMAGELABEL_H
#include <QLabel>
#include <QResizeEvent>


class MyImageLabel : public QLabel
{
    Q_OBJECT
public:
    MyImageLabel(QWidget* parent = 0);
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // MYIMAGELABEL_H
