#ifndef FACEONETONPANE2_H
#define FACEONETONPANE2_H

#include <QWidget>
#include "UIModule/Comm/mysearchedit.h"

namespace Ui {
class FaceOneToNPane;
}

struct ComparedImageInfo
{
    QPixmap pix;
    QString source;
    double similar;
};
class FaceOneToNPane : public QWidget
{
    Q_OBJECT

public:
    explicit FaceOneToNPane(QWidget *parent = 0);
    ~FaceOneToNPane();
private:
    void initUI();
    void initTargetLibraryData(QStringList listLibrary); // by ly
    void initComparedImageData(QList<ComparedImageInfo> list);// by ly

private:
    Ui::FaceOneToNPane *ui;
public slots:
    void onSlotBeginCompare();
    void onSlotSelectImage();
    void onSlotSearchBtnClicked();

    void slot_test();
};

#endif // FACEONETONPANE2_H
