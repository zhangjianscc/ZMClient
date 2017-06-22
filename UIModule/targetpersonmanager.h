#ifndef TARGETPERSONMANAGER_H
#define TARGETPERSONMANAGER_H

#include <QWidget>

namespace Ui {
class TargetPersonManager;
}

struct PersonData
{
    QString name;
    QString sex;
    QString birthday;
    QString identityNumber;
    QString importanceLevel;
    QString dangersLevel;
    QString type;
    QString status;
};
class QCheckBox;
class QPushButton;
class TargetPersonManager : public QWidget
{
    Q_OBJECT

public:
    explicit TargetPersonManager(QWidget *parent = 0);
    ~TargetPersonManager();
private:
    void initUI();
    void updateData();
    void updateBtnStatus();
    void updateTableView();

private:
    Ui::TargetPersonManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iRowCount;
    int m_iColumCount;
    QList<PersonData>   m_listData;
    QString             m_strBtnStyle;
    QList<QCheckBox*>   m_listCheckBox;
    QList<QPushButton*> m_listButtons;
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
    void onSlotBtnEdit();
    void onSlotRowCheckBoxChanged(int checked);
    void onSlotHeaderCheckBoxChanged(bool checked);
};

#endif // TARGETPERSONMANAGER_H
