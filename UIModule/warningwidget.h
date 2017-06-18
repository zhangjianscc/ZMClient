#ifndef WARNINGWIDGET_H
#define WARNINGWIDGET_H

#include "stable.h"

class WarningWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WarningWidget(QWidget *parent = 0);

    struct stData
    {
        QString time;
        QString addr;
        QString same;
        QString name;
        QString sex;
        int age;
        int number;
        QString type;
    };

    void setData(QPixmap pixMap, stData &data);

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

public slots:
    void slot_okButClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void initUi();

    QWidget *m_pPictureWidget;
    QLabel *m_pTimeDataLabel;
    QLabel *m_pAddrDataLabel;
    QLabel *m_pSameDataLabel;
    QLabel *m_pNameDataLabel;
    QLabel *m_pSexDataLabel;
    QLabel *m_pAgeDataLabel;
    QLabel *m_pNumberDataLabel;
    QLabel *m_pTypeDataLabel;
};

#endif // WARNINGWIDGET_H
