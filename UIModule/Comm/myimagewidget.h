#ifndef MYIMAGEWIDGET_H
#define MYIMAGEWIDGET_H

#include <QWidget>
#include <QPoint>
class QLabel;
class MyImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyImageWidget();
    void setChecked(bool checked);
    void reset();
    void setData(QPixmap& pixmap,QString name,QString date,QString time,QString position);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

public:
    QPoint  m_mousePos;
    QString m_strName;
    QString m_strDate;
    QString m_strTime;
    QString m_strPosition;
private:
    bool    m_bIsChecked;
    QLabel* m_pLabelImage;
    QLabel* m_pLabelDate;
    QLabel* m_pLabelTime;
    QLabel* m_pLabelPosition;


signals:
    void clicked();

public slots:
};

#endif // MYIMAGEWIDGET_H
