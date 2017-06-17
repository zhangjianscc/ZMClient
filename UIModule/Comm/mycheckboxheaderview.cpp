#include "mycheckboxheaderview.h"
#include "stable.h"

MyCheckBoxHeaderView::MyCheckBoxHeaderView( int checkColumnIndex,Qt::Orientation orientation,QWidget * parent) :
QHeaderView(orientation, parent)
{
    m_checkColIdx = checkColumnIndex;
    isChecked = false;
}

void MyCheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();
    if (logicalIndex == m_checkColIdx)
    {
        QStyleOptionButton option;
        int width = 10;
        for (int i=0; i<logicalIndex; ++i)
        width += sectionSize( i );
        option.rect = QRect((rect.width()-21)/2, (rect.height()-21)/2, 21, 21);
        if (isChecked)
            option.state = QStyle::State_On;
        else
            option.state = QStyle::State_Off;
//        this->style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
        this->style()->drawControl(QStyle::CE_CheckBox, &option, painter);
    }

}

void MyCheckBoxHeaderView::mousePressEvent(QMouseEvent *event)
{
    if (visualIndexAt(event->pos().x()) == m_checkColIdx)
    {
        if (isChecked)
            isChecked = false;
        else
            isChecked = true;
        this->updateSection(m_checkColIdx);
        emit checkStausChange(isChecked);
    }

    QHeaderView::mousePressEvent(event);
}
