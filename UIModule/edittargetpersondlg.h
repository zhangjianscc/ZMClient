#ifndef EDITTARGETPERSON_H
#define EDITTARGETPERSON_H

#include <QDialog>

namespace Ui {
class EditTargetPerson;
}

struct ImageItemData
{
    QPixmap pix;
    QString name;
};
class EditTargetPersonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditTargetPersonDlg(QWidget *parent = 0);
    ~EditTargetPersonDlg();
private:
    void initUI();
    void initPersonImages(QList<ImageItemData> list);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);          ///
    bool                  m_bIsMoveing;
    QPoint                m_curWindowPos;                /// 窗口当前位置
    QPoint                m_curMousePos;                 /// 鼠标当前位置
    QPoint                m_destWindowPos;               /// 移动后窗口所在的位置

private:
    Ui::EditTargetPerson *ui;

public slots:
    void onSlotClose();
    void onSlotAddImage();
};

#endif // EDITTARGETPERSON_H
