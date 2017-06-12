#ifndef MYIMAGECOMPAREWIDGET_H
#define MYIMAGECOMPAREWIDGET_H

#include <QWidget>
<<<<<<< HEAD

=======
class QLabel;
class QProgressBar;
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
class MyImageCompareWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyImageCompareWidget(QWidget *parent = 0);
<<<<<<< HEAD
=======
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
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

signals:

public slots:
};

<<<<<<< HEAD
#endif // MYIMAGECOMPAREWIDGET_H
=======
#endif // MYIMAGECOMPAREWIDGET_H
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
