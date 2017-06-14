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
    void initUI();
private:
    Ui::FaceIdentityDiscern *ui;
signals:
public slots:
    void onSlotSearchBtnClicked();
};

#endif // FACEIDENTITYRECOG2_H
