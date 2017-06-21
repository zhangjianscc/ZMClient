#ifndef DELETETARGETPERSON_H
#define DELETETARGETPERSON_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class DeleteTargetPerson;
}

class DeleteConfirmationDlg : public QDialog
{
    Q_OBJECT

public:
    // info1 + redinfo + info3 组成提示字符串 其中redInfo为红色高亮显示
    explicit DeleteConfirmationDlg(QString info1,QString redInfo,QString info3);
    ~DeleteConfirmationDlg();
private:
    void initUI();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);          ///
    bool                  m_bIsMoveing;
    QPoint                m_curWindowPos;                /// 窗口当前位置
    QPoint                m_curMousePos;                 /// 鼠标当前位置
    QPoint                m_destWindowPos;               /// 移动后窗口所在的位置

private:
    Ui::DeleteTargetPerson *ui;
public slots:
    void onSlotClose();
    void onSlotDelete();
    void onSlotCancel();
};

#endif // DELETETARGETPERSON_H
