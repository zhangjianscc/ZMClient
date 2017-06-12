#ifndef REALTIMEMONITORPANE_H
#define REALTIMEMONITORPANE_H

#include <QWidget>
#include <QList>

class MyImageWidget;
class MyImageCompareWidget;
<<<<<<< HEAD
=======
class QGridLayout;
class QTableWidget;
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
class RealTimeMonitorPane : public QWidget
{
    Q_OBJECT
public:
    explicit RealTimeMonitorPane(QWidget *parent = 0);
    struct stImageData
    {
        QPixmap pix;
        QString name;
        QString date;
        QString time;
        QString position;
    };
<<<<<<< HEAD
    void updateUIData(QList<stImageData>& list);
private:
    void initFrame();
=======
    struct stImageSimilarData
    {
        QString name;
        QPixmap pix;
        double  similarity;
        QString source;
    };
    void updateImageData(QList<stImageData>& list);
    void updateImageSimilarityData(QList<stImageSimilarData>& list);
protected:
    void paintEvent(QPaintEvent *event);
private:
    void initUI();
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

private:
    QList<MyImageWidget*> m_listImageWid;
    QList<MyImageCompareWidget*> m_listImageCompareWid;
<<<<<<< HEAD
=======
    QTableWidget* m_pTableWarningPane;
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

signals:

public slots:
<<<<<<< HEAD
=======
    void onSlotLeftImageClieked(MyImageWidget*);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
};

#endif // REALTIMEMONITORPANE_H
