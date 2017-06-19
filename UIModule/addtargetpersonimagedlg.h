#ifndef ADDTARGETPERSONIMAGE_H
#define ADDTARGETPERSONIMAGE_H

#include <QDialog>

namespace Ui {
class AddTargetPersonImage;
}

class AddTargetPersonImageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddTargetPersonImageDlg(QWidget *parent = 0);
    ~AddTargetPersonImageDlg();
private:
    void initUI();
    void updatePersonInfo(QString name,QString sex,int age,QString dangersLevel,QString status,QString identitype,QString identiNumber);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);          ///
    bool                  m_bIsMoveing;
    QPoint                m_curWindowPos;                /// 窗口当前位置
    QPoint                m_curMousePos;                 /// 鼠标当前位置
    QPoint                m_destWindowPos;               /// 移动后窗口所在的位置

private:
    Ui::AddTargetPersonImage *ui;
public slots:
    void onSlotSelectImage();
    void onSlotClose();
    void onSlotSave();
    void onSlotCancel();
};

#endif // ADDTARGETPERSONIMAGE_H
