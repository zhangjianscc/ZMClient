#ifndef ADDLIBRARY_H
#define ADDLIBRARY_H

#include <QDialog>

namespace Ui {
class AddLibrary;
}

class AddLibraryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddLibraryDlg(QWidget *parent = 0);
    ~AddLibraryDlg();

private:
    Ui::AddLibrary *ui;
};

#endif // ADDLIBRARY_H
