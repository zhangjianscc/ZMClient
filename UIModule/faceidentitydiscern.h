#ifndef FACEIDENTITYRECOG2_H
#define FACEIDENTITYRECOG2_H

#include <QWidget>

namespace Ui {
class FaceIdentityDiscern;
}

class FaceIdentityDiscern : public QWidget
{
    Q_OBJECT

public:
    explicit FaceIdentityDiscern(QWidget *parent = 0);
    ~FaceIdentityDiscern();

private:
    Ui::FaceIdentityDiscern *ui;
};

#endif // FACEIDENTITYRECOG2_H
