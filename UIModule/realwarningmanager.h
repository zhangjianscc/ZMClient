#ifndef REALWARNINGMANAGER_H
#define REALWARNINGMANAGER_H

#include <QWidget>

namespace Ui {
class RealWarningManager;
}

class RealWarningManager : public QWidget
{
    Q_OBJECT

public:
    explicit RealWarningManager(QWidget *parent = 0);
    ~RealWarningManager();

private:
    Ui::RealWarningManager *ui;
};

#endif // REALWARNINGMANAGER_H
