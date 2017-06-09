#ifndef REALTIMEMONITORPANE_H
#define REALTIMEMONITORPANE_H

#include <QWidget>
#include <QList>

class MyImageWidget;
class MyImageCompareWidget;
class QGridLayout;
class QTableWidget;
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

private:
    QList<MyImageWidget*> m_listImageWid;
    QList<MyImageCompareWidget*> m_listImageCompareWid;
    QTableWidget* m_pTableWarningPane;

signals:

public slots:
    void onSlotLeftImageClieked(MyImageWidget*);
};

#endif // REALTIMEMONITORPANE_H
