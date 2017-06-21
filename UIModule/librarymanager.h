#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QWidget>

namespace Ui {
class LibraryManager;
}

struct LibraryData
{
    QString number;
    QString name;
    QString user;
};
class QCheckBox;
class QPushButton;
class LibraryManager : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryManager(QWidget *parent = 0);
    ~LibraryManager();
private:
    void initUI();
    void updateData();
    void updateBtnStatus();
    void updateTableView();

private:
    Ui::LibraryManager *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iRowCount;
    int m_iColumCount;
    QList<LibraryData> m_listData;
    QString m_strBtnStyle;
    QList<QCheckBox*>   m_listCheckBox;
    QList<QPushButton*> m_listButtons;
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

#endif // LIBRARYMANAGER_H
