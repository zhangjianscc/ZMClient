#ifndef FACEIDENTITYRECOG2_H
#define FACEIDENTITYRECOG2_H

#include <QWidget>

namespace Ui {
class FaceIdentityRecog2;
}

class FaceIdentityRecog2 : public QWidget
{
    Q_OBJECT

public:
    explicit FaceIdentityRecog2(QWidget *parent = 0);
    ~FaceIdentityRecog2();

private:
    Ui::FaceIdentityRecog2 *ui;
};

#endif // FACEIDENTITYRECOG2_H
