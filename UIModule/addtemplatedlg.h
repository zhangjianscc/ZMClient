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
    Ui::AddTemplate *ui;
};

#endif // ADDTEMPLATE_H
