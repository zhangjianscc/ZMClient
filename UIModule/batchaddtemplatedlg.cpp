#include "batchaddtemplatedlg.h"
#include "ui_batchaddtemplatedlg.h"

BatchAddTemplateDlg::BatchAddTemplateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatchAddTemplateDlg)
{
    ui->setupUi(this);
    initUI();
}

BatchAddTemplateDlg::~BatchAddTemplateDlg()
{
    delete ui;
}

void BatchAddTemplateDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    // 选择文件 上传文件
    QString fileBtn = "QPushButton{color:rgb(255,255,255); border:1px; border-radius:2px;background-color:rgb(18,132,194)}"
                                       "QPushButton:hover{background-color:rgb(18,132,255)}"
                                       "QPushButton:pressed{background-color:rgb(18,132,194)}";
    ui->m_btnSelectFile->setStyleSheet(fileBtn);
    connect(ui->m_btnSelectFile,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectFile()));
    ui->m_btnUpLoadFile->setStyleSheet(fileBtn);
    connect(ui->m_btnUpLoadFile,SIGNAL(clicked(bool)),this,SLOT(onSlotUploadFile()));

    // 点击下载模板 取消按钮
    QString downloadBtn = "QPushButton{color:rgb(255,255,255); border:1px; border-radius:2px;background-color:rgb(83,83,83)}"
                                       "QPushButton:hover{background-color:rgb(31,31,31)}"
                                       "QPushButton:pressed{background-color:rgb(31,31,31)}";
    ui->m_btnDownLoadTemplate->setStyleSheet(downloadBtn);
    connect(ui->m_btnDownLoadTemplate,SIGNAL(clicked(bool)),this,SLOT(onSlotDownloadTemplate()));
    ui->m_btnCancel->setStyleSheet(downloadBtn);
    connect(ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onSlotCancel()));

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));
}

void BatchAddTemplateDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void BatchAddTemplateDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void BatchAddTemplateDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}

void BatchAddTemplateDlg::onSlotSelectFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择照片"), " ",  tr("Allfile(*.*);;xls(*.xls)"));
    if(fileName != "")
    {
        ui->m_editFile->setText(fileName);
    }
}

void BatchAddTemplateDlg::onSlotUploadFile()
{}

void BatchAddTemplateDlg::onSlotDownloadTemplate()
{}

void BatchAddTemplateDlg::onSlotCancel()
{
    this->reject();
}

void BatchAddTemplateDlg::onSlotClose()
{
    this->reject();
}
