#ifndef WARNINGDISPOSDLG_H
#define WARNINGDISPOSDLG_H

#include <QDialog>

namespace Ui {
class WarningDisposDlg;
}

class WarningDisposDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDisposDlg(QString& result);
    ~WarningDisposDlg();
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
    Ui::WarningDisposDlg *ui;
    QString& m_result;
public slots:
    void onSlotSave();
    void onSlotCancel();
    void onSlotClose();
    void onSlotDispos(QString text);
};

#endif // WARNINGDISPOSDLG_H
