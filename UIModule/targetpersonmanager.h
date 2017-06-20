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
class TargetPersonManager : public QWidget
{
    Q_OBJECT

public:
    explicit TargetPersonManager(QWidget *parent = 0);
    ~TargetPersonManager();
private:
    void initUI();
    void updatePersonData();
    void updateBtnStatus();
    void updateTableView();

private:
    Ui::TargetPersonManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iPageRowCount;
    QList<PersonData> m_listPersonData;
    QString m_strBtnStyle;
signals:

public slots:
    void onBtnSearch();
    void onBtnSelectAll();
    void onBtnUnSelectAll();
    void onBtnDelete();
    void onBtnPageFirst();
    void onBtnPagePre();
    void onBtnPage1();
    void onBtnPage2();
    void onBtnPage3();
    void onBtnPage5();
    void onBtnPageNext();
    void onBtnPageLast();
    void onBtnEdit();
    void onSlotselectChanged(bool checked);
    void onBtnAddTargetPerson();
    void onBtnEditTargetPerson();
    void onSlotCheckBoxChanged(int checked);
};

#endif // TARGETPERSONMANAGER_H
