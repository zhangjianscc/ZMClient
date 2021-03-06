#ifndef BATCHADDTEMPLATEDLG_H
#define BATCHADDTEMPLATEDLG_H

#include <QDialog>

namespace Ui {
class BatchAddTemplateDlg;
}

class BatchAddTemplateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BatchAddTemplateDlg(QWidget *parent = 0);
    ~BatchAddTemplateDlg();
private:
    void initUI();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool                  m_bIsMoveing;
    QPoint                m_curWindowPos;                /// 窗口当前位置
    QPoint                m_curMousePos;                 /// 鼠标当前位置
    QPoint                m_destWindowPos;               /// 移动后窗口所在的位置

private:
    Ui::BatchAddTemplateDlg *ui;
public slots:
    void onSlotSelectFile();
    void onSlotUploadFile();
    void onSlotDownloadTemplate();
    void onSlotCancel();
    void onSlotClose();
};

#endif // BATCHADDTEMPLATEDLG_H
