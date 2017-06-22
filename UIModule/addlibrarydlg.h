#ifndef ADDLIBRARY_H
#define ADDLIBRARY_H

#include <QDialog>

namespace Ui {
class AddLibrary;
}

class AddLibraryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddLibraryDlg(QWidget *parent = 0);
    ~AddLibraryDlg();
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
    Ui::AddLibrary *ui;
public slots:
    void onSlotSave();
    void onSlotCancel();
    void onSlotClose();
};

#endif // ADDLIBRARY_H
