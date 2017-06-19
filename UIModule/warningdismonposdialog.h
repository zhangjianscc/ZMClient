#ifndef WARNINGDISMONPOSDIALOG_H
#define WARNINGDISMONPOSDIALOG_H

#include <QDialog>

namespace Ui {
class WarningDisMonPosdialog;
}

class WarningDisMonPosdialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDisMonPosdialog(QWidget *parent = 0);
    ~WarningDisMonPosdialog();

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
    Ui::WarningDisMonPosdialog *ui;

    void initUi();
};

#endif // WARNINGDISMONPOSDIALOG_H
