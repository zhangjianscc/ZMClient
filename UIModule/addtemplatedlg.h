#ifndef ADDTEMPLATE_H
#define ADDTEMPLATE_H

#include <QDialog>

namespace Ui {
class AddTemplate;
}

class AddTemplateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddTemplateDlg(QWidget *parent = 0);
    ~AddTemplateDlg();
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
    Ui::AddTemplate *ui;
public slots:
    void onSlotSave();
    void onSlotCancel();
    void onSlotClose();
    void onSlotAddImage();
};

#endif // ADDTEMPLATE_H
