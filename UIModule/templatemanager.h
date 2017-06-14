#ifndef TEMPLATEMANAGER_H
#define TEMPLATEMANAGER_H

#include <QWidget>

namespace Ui {
class TemplateManager;
}

class TemplateManager : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateManager(QWidget *parent = 0);
    ~TemplateManager();

private:
    Ui::TemplateManager *ui;
};

#endif // TEMPLATEMANAGER_H
