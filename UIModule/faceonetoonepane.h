#ifndef FACEONETOONEPANE_H
#define FACEONETOONEPANE_H

#include <QWidget>

class FaceOneToOnePane : public QWidget
{
    Q_OBJECT
public:
    explicit FaceOneToOnePane(QWidget *parent = 0);
private:
    void initUI();

signals:

public slots:
};

#endif // FACEONETOONEPANE_H
