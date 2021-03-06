#ifndef MYIMAGECOMPAREWIDGET_H
#define MYIMAGECOMPAREWIDGET_H

#include <QWidget>
class QLabel;
class QProgressBar;
class MyImageCompareWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyImageCompareWidget(QWidget *parent = 0);
    void setData(QPixmap& pix,double similarity,QString source);
protected:
    void paintEvent(QPaintEvent *event);
private:
    void initUI();
private:
    QLabel*    m_pLabelImage;
    QLabel*    m_pLabelSimilarTitle;
    QLabel*    m_pLabelSimilarValue;
    QProgressBar* m_pSimilayBar;
    double     m_dSimilary;
    QString    m_strSource;
    QLabel*    m_pLabelSourceTitle;
    QLabel*    m_pLabelSourceValue;

signals:

public slots:
};

#endif // MYIMAGECOMPAREWIDGET_H
