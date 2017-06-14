#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QWidget>

namespace Ui {
class LibraryManager;
}

class LibraryManager : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryManager(QWidget *parent = 0);
    ~LibraryManager();

private:
    Ui::LibraryManager *ui;
};

#endif // LIBRARYMANAGER_H
