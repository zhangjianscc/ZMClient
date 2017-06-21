#ifndef NOTICEDLG_H
#define NOTICEDLG_H

#include <QDialog>

namespace Ui {
class NoticeDlg;
}

class NoticeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NoticeDlg(QString info1 = "",QString info2 = "");
    ~NoticeDlg();
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
    Ui::NoticeDlg *ui;
public slots:
    void onSlotClose();
    void onSlotOk();

};

#endif // NOTICEDLG_H
