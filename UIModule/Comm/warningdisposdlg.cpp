#include "warningdisposdlg.h"
#include "ui_warningdisposdlg.h"

WarningDisposDlg::WarningDisposDlg(QString& result) :
    QDialog(0),
    ui(new Ui::WarningDisposDlg),
    m_result(result)
{
    ui->setupUi(this);
    initUI();
}

WarningDisposDlg::~WarningDisposDlg()
{
    delete ui;
}
void WarningDisposDlg::initUI()
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

    // 处理
    ui->m_comboResult->setStyleSheet("QComboBox{background-color:rgb(255,255,255);border-radius:1px solid rgb(180,180,180)}");
    ui->m_comboResult->addItem("无效");
    ui->m_comboResult->addItem("人工确认");
    ui->m_comboResult->addItem("法律确认");
    connect(ui->m_comboResult,SIGNAL(currentTextChanged(QString)),this,SLOT(onSlotDispos(QString)));

}

void WarningDisposDlg::onSlotSave()
{
    this->accept();
}

void WarningDisposDlg::onSlotCancel()
{
    this->reject();
}

void WarningDisposDlg::onSlotClose()
{
    this->reject();
}

void WarningDisposDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void WarningDisposDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void WarningDisposDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}

void WarningDisposDlg::onSlotDispos(QString text)
{
    m_result = text;
}
