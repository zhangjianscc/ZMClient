#ifndef FACEHISTORYCOMPARE2_H
#define FACEHISTORYCOMPARE2_H

#include <QWidget>

namespace Ui {
class FaceHistoryCompare;
}

struct FaceHistoryCompareData
{
    QPixmap pix;
    QString address;
    QString dateTime;
    double  similar;
};
class FaceHistoryCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FaceHistoryCompare(QWidget *parent = 0);
    ~FaceHistoryCompare();
private:
    void initUI();
    void initCompareResultTable(QList<FaceHistoryCompareData> list);

private:
    Ui::FaceHistoryCompare *ui;
signals:

public slots:
    void onSlotSelectImage();
    void onSlotBeginCompare();
    void onSlotRunTrack();

};

#endif // FACEHISTORYCOMPARE2_H
