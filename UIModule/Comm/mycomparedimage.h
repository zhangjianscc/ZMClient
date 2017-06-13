#ifndef MYCOMPAREDIMAGE_H
#define MYCOMPAREDIMAGE_H

#include <QWidget>
class QLabel;
class QProgressBar;

/**
 * @brief The MyComparedImage class
 * size 215*180
 */
class MyComparedImage : public QWidget
{
    Q_OBJECT
public:
    explicit MyComparedImage(QWidget *parent = 0);
    void setData(QPixmap pix,QString source,double similar);
protected:
    void paintEvent(QPaintEvent *event);
private:
    void initUI();

private:
    QLabel* m_pLabelTitle;
    QLabel* m_pLabelImage;
    QProgressBar* m_pProSimilar;
    QLabel* m_pLabelSimilarValue;

signals:

public slots:
};

#endif // MYCOMPAREDIMAGE_H
