#ifndef FACEIDENTITYRECOG2_H
#define FACEIDENTITYRECOG2_H

#include <QWidget>

namespace Ui {
class FaceIdentityDiscern;
}

struct CompareResultData
{
    QPixmap pix1;
    QPixmap pix2;
    QString imageSource;
    double  similar;
};

class FaceIdentityDiscern : public QWidget
{
    Q_OBJECT

public:
    explicit FaceIdentityDiscern(QWidget *parent = 0);
    ~FaceIdentityDiscern();
private:
    void initUI();
    void initCameraImage(QPixmap pix);
    void initTargetPerson(QList<QPixmap> list);
    void initCompareResultTable(QList<CompareResultData> list);
private:
    Ui::FaceIdentityDiscern *ui;
signals:
public slots:
    void onSlotSearchBtnClicked();
    void onSlotBeginCompare();
};

#endif // FACEIDENTITYRECOG2_H
