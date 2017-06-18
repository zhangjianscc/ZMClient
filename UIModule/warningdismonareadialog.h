#ifndef WARNINGDISMONAREADIALOG_H
#define WARNINGDISMONAREADIALOG_H

#include <QDialog>

namespace Ui {
class WarningDisMonAreaDialog;
}

class WarningDisMonAreaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDisMonAreaDialog(QWidget *parent = 0);
    ~WarningDisMonAreaDialog();

    QPoint m_curWindowPos;
    QPoint m_curMousePos;
    QPoint m_destWindowPos;

public slots:
    void slot_closeButClicked();
    void slot_okButClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::WarningDisMonAreaDialog *ui;

    void initUi();
};

#endif // WARNINGDISMONAREADIALOG_H
