#ifndef MYCHECKBOXHEADERVIEW_H
#define MYCHECKBOXHEADERVIEW_H

#include <QtGui>
#include <QHeaderView>
#include <QStyleOptionButton>
#include <QStyle>

class MyCheckBoxHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit MyCheckBoxHeaderView( int checkColumnIndex,Qt::Orientation orientation,QWidget * parent = 0);
signals:
    void checkStausChange(bool);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
    void mousePressEvent(QMouseEvent *event);

private:
    bool isChecked;
    int  m_checkColIdx;
};
#endif // MYCHECKBOXHEADERVIEW_H
