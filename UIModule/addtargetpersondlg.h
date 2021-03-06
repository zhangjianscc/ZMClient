#ifndef ADDTARGETPERSON_H
#define ADDTARGETPERSON_H

#include <QDialog>

namespace Ui {
class AddTargetPerson;
}

class AddTargetPersonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddTargetPersonDlg(QWidget *parent = 0);
    ~AddTargetPersonDlg();
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
    Ui::AddTargetPerson *ui;
public slots:
    void onSlotClose();
    void onSlotSave();
    void onSlotCancel();
};

#endif // ADDTARGETPERSON_H
