#ifndef TARGETPERSONMANAGER_H
#define TARGETPERSONMANAGER_H

#include <QWidget>

namespace Ui {
class TargetPersonManager;
}

class TargetPersonManager : public QWidget
{
    Q_OBJECT

public:
    explicit TargetPersonManager(QWidget *parent = 0);
    ~TargetPersonManager();
private:
    void initUI();
    //void updateData();

private:
    Ui::TargetPersonManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iPageRowCount;
signals:

public slots:
    void onBtnSearch();
    void onBtnSelectAll();
    void onBtnReSelectAll();
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
};

#endif // TARGETPERSONMANAGER_H
