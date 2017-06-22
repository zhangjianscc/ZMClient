#ifndef TEMPLATEMANAGER_H
#define TEMPLATEMANAGER_H

#include <QWidget>

namespace Ui {
class TemplateManager;
}
struct TemplateData
{
    QPixmap pix;
    QString imageName;
    QString name;
    QString sex;
    int     age;
    QString identityNumber;
    QString importanceLevel;
    QString dangersLevel;
};
class TemplateManager : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateManager(QWidget *parent = 0);
    ~TemplateManager();
private:
    void initUI();
    void updateData();
    void updateBtnStatus();
    void updateTableView();
private:
    Ui::TemplateManager *ui;
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

#endif // TEMPLATEMANAGER_H
