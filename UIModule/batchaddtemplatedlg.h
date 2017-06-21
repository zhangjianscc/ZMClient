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
    Ui::BatchAddTemplateDlg *ui;
};

#endif // BATCHADDTEMPLATEDLG_H
