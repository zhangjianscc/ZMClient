#ifndef MYIMAGEWIDGET_H
#define MYIMAGEWIDGET_H

#include <QWidget>
#include <QPoint>
class QLabel;
class MyImageWidget : public QWidget
{
    Q_OBJECT
public:
<<<<<<< HEAD
    explicit MyImageWidget();
    void setChecked(bool checked);
    void reset();
    void setData(QPixmap& pixmap,QString name,QString date,QString time,QString position);
=======
    explicit MyImageWidget(QWidget* parent = 0);
    void initUI();
    void setChecked(bool checked);
    void reset();
    void setData(QPixmap& pixmap,QString name,QString date,QString time,QString position);
    QString getName();
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
<<<<<<< HEAD

public:
=======
    void paintEvent(QPaintEvent *event);

private:
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
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
<<<<<<< HEAD
    void clicked();
=======
    void clicked(MyImageWidget*);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

public slots:
};

#endif // MYIMAGEWIDGET_H
