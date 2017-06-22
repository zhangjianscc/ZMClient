#include "realwarningitem.h"
#include "ui_realwarningitem.h"
#include "stable.h"
#include "warningdisposdlg.h"

RealWarningItem::RealWarningItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RealWarningItem)
{
    ui->setupUi(this);
    initUI();
}

RealWarningItem::~RealWarningItem()
{
    delete ui;
}

void RealWarningItem::initUI()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(236,236,236);border:1px solid rgb(180,180,180)}");
    connect(ui->m_checkBox,SIGNAL(stateChanged(int)),this,SLOT(onSlotCheckBoxStatusChanged(int)));

    connect(ui->m_btnDispos,SIGNAL(clicked(bool)),this,SLOT(onSlotDispos()));
}

void RealWarningItem::select()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(129,210,255);border:1px solid rgb(180,180,180)}");
    ui->m_checkBox->setChecked(true);
}

void RealWarningItem::unSelect()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(236,236,236);border:1px solid rgb(180,180,180)}");
    ui->m_checkBox->setChecked(false);
}

void RealWarningItem::setData(QPixmap pix1,
                           QPixmap pix2,
                           double similar,
                           QString name,
                           QString sex,
                           int     age,
                           QString importanceLevel,
                           QString dangersLevel,
                           QString warningTime,
                           QString warningPlace,
                           QString area)
{
    ui->m_labelImage1->setPixmap(pix1);
    ui->m_labelImage2->setPixmap(pix2);
    ui->m_labelSimilar->setText(QString("%1%").arg(similar*100));
    ui->m_labelName->setText(name);
    ui->m_labelSex->setText(sex);
    ui->m_labelAge->setText(QString::number(age));
    ui->m_labelImportanceLevel->setText(importanceLevel);
    ui->m_labelDangersLevel->setText(dangersLevel);
    ui->m_labelWarningTime->setText(warningTime);
    ui->m_labelWarningPlace->setText(warningPlace);
    ui->m_labelArea->setText(area);
}

bool RealWarningItem::isSelected()
{
    return ui->m_checkBox->isChecked();
}

void RealWarningItem::onSlotCheckBoxStatusChanged(int sta)
{
    if(ui->m_checkBox->isChecked())
    {
        ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(129,210,255);border:1px solid rgb(180,180,180)}");
    }
    else
    {
        ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(236,236,236);border:1px solid rgb(180,180,180)}");
    }
}

void RealWarningItem::onSlotDispos()
{
    QString result;
    WarningDisposDlg dlg(result);
    dlg.exec();
    ui->m_btnDispos->setText(result);
}









