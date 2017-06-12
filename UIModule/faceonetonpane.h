#ifndef FACEONETONPANE2_H
#define FACEONETONPANE2_H

#include <QWidget>

namespace Ui {
class FaceOneToNPane;
}

class FaceOneToNPane : public QWidget
{
    Q_OBJECT

public:
    explicit FaceOneToNPane(QWidget *parent = 0);
    ~FaceOneToNPane();
private:
    void initUI();
    void initTargetLibraryData(QStringList listLibrary); // by ly

private:
    Ui::FaceOneToNPane *ui;
};

#endif // FACEONETONPANE2_H
