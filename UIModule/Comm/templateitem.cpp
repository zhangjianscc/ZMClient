#include "templateitem.h"
#include "ui_templateitem.h"

TemplateItem::TemplateItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateItem)
{
    ui->setupUi(this);
    initUI();
}

TemplateItem::~TemplateItem()
{
    delete ui;
}

void TemplateItem::initUI()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(236,236,236);border:1px solid rgb(180,180,180)}");
    connect(ui->m_checkBox,SIGNAL(stateChanged(int)),this,SLOT(onSlotCheckBoxStatusChanged(int)));
}

void TemplateItem::select()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(129,210,255);border:1px solid rgb(180,180,180)}");
    ui->m_checkBox->setChecked(true);
}

void TemplateItem::unSelect()
{
    ui->m_backWidget->setStyleSheet("QWidget{background-color:rgb(236,236,236);border:1px solid rgb(180,180,180)}");
    ui->m_checkBox->setChecked(false);
}

void TemplateItem::setData(QPixmap pix,QString imageName,QString name,QString sex,int age,QString identityNumber,QString importanceLevel,QString dangersLevel)
{
    ui->m_lableImage->setPixmap(pix);
    ui->m_labelImageName->setText(imageName);
    ui->m_labelName->setText(name);
    ui->m_labelSex->setText(sex);
    ui->m_labelAge->setText(QString("%1岁").arg(age));
    ui->m_labelNumber->setText(identityNumber);
    ui->m_labelImportanceLevel->setText(importanceLevel);
    ui->m_labelDangersLevel->setText(dangersLevel);
}

bool TemplateItem::isSelected()
{
    return ui->m_checkBox->isChecked();
}

void TemplateItem::onSlotCheckBoxStatusChanged(int sta)
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





