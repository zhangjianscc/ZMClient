#ifndef EDITLIBRARYDLG_H
#define EDITLIBRARYDLG_H

#include <QDialog>

namespace Ui {
class EditLibraryDlg;
}

class EditLibraryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditLibraryDlg(QWidget *parent = 0);
    ~EditLibraryDlg();
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
    Ui::EditLibraryDlg *ui;
public slots:
    void onSlotSave();
    void onSlotCancel();
    void onSlotClose();
};

#endif // EDITLIBRARYDLG_H
