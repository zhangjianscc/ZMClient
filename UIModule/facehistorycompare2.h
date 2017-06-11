#ifndef FACEHISTORYCOMPARE2_H
#define FACEHISTORYCOMPARE2_H

#include <QWidget>

namespace Ui {
class FaceHistoryCompare2;
}

class FaceHistoryCompare2 : public QWidget
{
    Q_OBJECT

public:
    explicit FaceHistoryCompare2(QWidget *parent = 0);
    ~FaceHistoryCompare2();

private:
    Ui::FaceHistoryCompare2 *ui;
};

#endif // FACEHISTORYCOMPARE2_H
