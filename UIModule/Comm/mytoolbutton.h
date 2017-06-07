#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QObject>

class MyToolButton : public QToolButton
{
    Q_OBJECT
public:
    MyToolButton(QString text);
    MyToolButton(QString text,QString icon1,QString icon2);
    void select();
    void unSelect();
private:
    QString m_text;
    QString m_iconNomal;
    QString m_iconSelect;
    bool    m_bImageButton;
};

#endif // MYPUSHBUTTON_H
