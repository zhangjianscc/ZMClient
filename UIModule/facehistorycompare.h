#ifndef FACEHISTORYCOMPARE2_H
#define FACEHISTORYCOMPARE2_H

#include <QWidget>

namespace Ui {
class FaceHistoryCompare;
}

class FaceHistoryCompare : public QWidget
{
    Q_OBJECT

public:
    explicit FaceHistoryCompare(QWidget *parent = 0);
    ~FaceHistoryCompare();

private:
    Ui::FaceHistoryCompare *ui;
};

#endif // FACEHISTORYCOMPARE2_H
