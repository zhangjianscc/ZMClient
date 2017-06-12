#ifndef FACEONETONPANE2_H
#define FACEONETONPANE2_H

#include <QWidget>

namespace Ui {
class FaceOneToNPane2;
}

class FaceOneToNPane2 : public QWidget
{
    Q_OBJECT

public:
    explicit FaceOneToNPane2(QWidget *parent = 0);
    ~FaceOneToNPane2();

private:
    Ui::FaceOneToNPane2 *ui;
};

#endif // FACEONETONPANE2_H
