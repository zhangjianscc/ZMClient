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
private:
    QString      m_strIconPath;
    QString      m_strTitle;
    QVBoxLayout* m_pMainLayout;

signals:

public slots:
};

#endif // MYWIDGETFOLDER_H
