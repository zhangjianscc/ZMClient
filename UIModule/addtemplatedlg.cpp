#include "addtemplatedlg.h"
#include "ui_addtemplate.h"

AddTemplateDlg::AddTemplateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTemplate)
{
    ui->setupUi(this);
    initUI();
}

AddTemplateDlg::~AddTemplateDlg()
{
    delete ui;
}

void AddTemplateDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    //按钮组
    QString btnStyle = "QPushButton{font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{color:rgb(255,255,255);background-color:rgb(4,119,182)}"
                       "QPushButton:pressed{color:rgb(255,255,255);background-color:rgb(4,119,182)}";
    ui->m_btnSave->setStyleSheet(btnStyle);
    connect(ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSlotSave()));
    ui->m_btnCancel->setStyleSheet(btnStyle);
    connect(ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onSlotCancel()));

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    // 添加照片
    QString addStyle = "QPushButton{color:rgb(255,255,255);font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(76,76,76)}"
                       "QPushButton:hover{background-color:rgb(30,30,30)}"
                       "QPushButton:pressed{background-color:rgb(30,30,30)}";
    ui->m_btnAddImage->setStyleSheet(addStyle);
    connect(ui->m_btnAddImage,SIGNAL(clicked(bool)),this,SLOT(onSlotAddImage()));
}

void AddTemplateDlg::onSlotSave()
{
    this->accept();
}

void AddTemplateDlg::onSlotCancel()
{
    this->reject();
}

void AddTemplateDlg::onSlotClose()
{
    this->reject();
}

void AddTemplateDlg::onSlotAddImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择照片"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        QPixmap pix(fileName);
        ui->m_labelImage->setPixmap(pix);
    }
}

void AddTemplateDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void AddTemplateDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void AddTemplateDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}

