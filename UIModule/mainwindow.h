#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "stable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initMainFrame();                 /// 主界面初始化

private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
