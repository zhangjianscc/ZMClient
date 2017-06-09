#ifndef WARNINGWIDGET_H
#define WARNINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>

class WarningWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WarningWidget(QWidget *parent = 0);

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *event);

private:
    void initUi();
};

#endif // WARNINGWIDGET_H
