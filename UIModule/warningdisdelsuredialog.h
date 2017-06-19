#ifndef WARNINGDISDELSUREDIALOG_H
#define WARNINGDISDELSUREDIALOG_H

#include <QDialog>

namespace Ui {
class WarningDisDelSureDialog;
}

class WarningDisDelSureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDisDelSureDialog(QString text, QWidget *parent = 0);
    ~WarningDisDelSureDialog();

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

public slots:
    void slot_closeButClicked();
    void slot_deleteButClicked();
    void slot_cancelButClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::WarningDisDelSureDialog *ui;

    void initUi();

    QString m_text;
};

#endif // WARNINGDISDELSUREDIALOG_H
