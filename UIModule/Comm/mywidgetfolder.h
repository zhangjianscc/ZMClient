#ifndef MYWIDGETFOLDER_H
#define MYWIDGETFOLDER_H

#include <QWidget>
class QVBoxLayout;
class MyWidgetFolder : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgetFolder(QString iconPath = "",QString title = "");
    void setContentWidget(QWidget* pWid);
<<<<<<< HEAD
=======
protected:
    void paintEvent(QPaintEvent *event);
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
private:
    QString      m_strIconPath;
    QString      m_strTitle;
    QVBoxLayout* m_pMainLayout;

signals:

public slots:
};

#endif // MYWIDGETFOLDER_H
