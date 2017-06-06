#ifndef MYTREEITEM_H
#define MYTREEITEM_H
#include "stable.h"
#include <QWidget>

class MyTreeItem : public QWidget
{
    Q_OBJECT
public:
    explicit MyTreeItem(QString nomalImage,QString selectImage,QString text);
    void select();
    void unSelect();
private:
    QString m_nomalImage;
    QString m_selectImage;
    QString m_text;
    bool    m_bIsSelected;
    QLabel* m_pLabelImage;
    QLabel* m_pLabelText;

signals:

public slots:
};

#endif // MYTREEITEM_H
