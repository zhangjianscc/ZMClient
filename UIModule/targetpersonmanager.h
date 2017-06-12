#ifndef TARGETPERSONMANAGER_H
#define TARGETPERSONMANAGER_H

#include <QWidget>

namespace Ui {
class TargetPersonManager;
}

class TargetPersonManager : public QWidget
{
    Q_OBJECT

public:
    explicit TargetPersonManager(QWidget *parent = 0);
    ~TargetPersonManager();

private:
    Ui::TargetPersonManager *ui;
};

#endif // TARGETPERSONMANAGER_H
