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
    QString imageName;
    QString name;
    QString sex;
    int     age;
    QString identityNumber;
    QString importanceLevel;
    QString dangersLevel;
};
class RealWarningManager : public QWidget
{
    Q_OBJECT

public:
    explicit RealWarningManager(QWidget *parent = 0);
    ~RealWarningManager();
private:
    void initUI();
    void updateTemplateData();
    void updateBtnStatus();
    void updateTableView();
private:
    Ui::RealWarningManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iRowCount;
    int m_iColumnCount;
    QString m_strBtnStyle;
    QList<TemplateData> m_listData;
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
    void onSlotBtnAdd();
    void onSlotBatchAdd();
};

#endif // REALWARNINGMANAGER_H
