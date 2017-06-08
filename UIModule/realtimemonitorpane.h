#ifndef REALTIMEMONITORPANE_H
#define REALTIMEMONITORPANE_H

#include <QWidget>
#include <QList>

class MyImageWidget;
class MyImageCompareWidget;
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
    void updateUIData(QList<stImageData>& list);
private:
    void initFrame();

private:
    QList<MyImageWidget*> m_listImageWid;
    QList<MyImageCompareWidget*> m_listImageCompareWid;

signals:

public slots:
};

#endif // REALTIMEMONITORPANE_H
