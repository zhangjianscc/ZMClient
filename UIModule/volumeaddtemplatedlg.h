#ifndef VOLUMEADDTEMPLATE_H
#define VOLUMEADDTEMPLATE_H

#include <QDialog>

namespace Ui {
class VolumeAddTemplate;
}

class VolumeAddTemplateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit VolumeAddTemplateDlg(QWidget *parent = 0);
    ~VolumeAddTemplateDlg();

private:
    Ui::VolumeAddTemplate *ui;
};

#endif // VOLUMEADDTEMPLATE_H
