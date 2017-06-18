#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class MyTableWidget;
}

class MyTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyTableWidget(QWidget *parent = 0);
    ~MyTableWidget();
    void initColumHeader(QStringList list);
    void bindData(QList<QList<QString>> list);
    void setHorizatalHeaderVisible(bool visible);
    void setVerticalHeaderVisible(bool visible);
    void setOperatorColumVisible(bool visible);
    void setPageRowCount(int count);
    void setCellWidget(int rowNumber,int columNumber,QWidget* pwid);
    void updateTableData(int page);
private:
    void initUI();
    void updateNaviBtn();
private:
    Ui::MyTableWidget *ui;
    int m_iTotalPage;
    int m_iCurPage;
    int m_iPageRowCount;
    bool m_bHHeaderVisible;
    bool m_bVHeaderVisible;
    bool m_bOperatorColumVisible;
    QList<QList<QString>> m_data;
signals:
public slots:
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
};

#endif // MYTABLEWIDGET_H
