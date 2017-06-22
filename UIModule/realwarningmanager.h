#ifndef REALWARNINGMANAGER_H
#define REALWARNINGMANAGER_H

#include <QWidget>

namespace Ui {
class RealWarningManager;
}

struct WarningData
{
    QPixmap pix1;
    QPixmap pix2;
    double  similar;
    QString name;
    QString sex;
    int     age;
    QString importanceLevel;
    QString dangersLevel;
    QString warningTime;
    QString warningPlace;
    QString area;
};
class RealWarningManager : public QWidget
{
    Q_OBJECT

public:
    explicit RealWarningManager(QWidget *parent = 0);
    ~RealWarningManager();
private:
    void initUI();
    void updateData();
    void updateBtnStatus();
    void updateTableView();
private:
    Ui::RealWarningManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iRowCount;
    int m_iColumnCount;
    QString m_strBtnStyle;
    QList<WarningData> m_listData;
signals:

public slots:
    void onSlotBtnSearch();
    void onSlotBtnSelectAll();
    void onSlotBtnUnSelectAll();
    void onSlotBtnDelete();
    void onSlotBtnPageFirst();
    void onSlotBtnPagePre();
    void onSlotBtnPage1();
    void onSlotBtnPage2();
    void onSlotBtnPage3();
    void onSlotBtnPage5();
    void onSlotBtnPageNext();
    void onSlotBtnPageLast();
};

#endif // REALWARNINGMANAGER_H
