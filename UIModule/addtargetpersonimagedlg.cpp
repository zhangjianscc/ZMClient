#include "addtargetpersonimagedlg.h"
#include "ui_addtargetpersonimage.h"

AddTargetPersonImageDlg::AddTargetPersonImageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTargetPersonImage)
{
    ui->setupUi(this);
    initUI();
    //test
    updatePersonInfo("黎勇","男",30,"极度危险","在逃强奸犯","身份证","510824198603038856");
}

AddTargetPersonImageDlg::~AddTargetPersonImageDlg()
{
    delete ui;
}

void AddTargetPersonImageDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    // 选择照片按钮
    ui->m_btnSelectImage->setText("");
    ui->m_btnSelectImage->setStyleSheet("QPushButton{border-image:url(://images//选择照片.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//选择照片-01.png);}"
                                              "QPushButton:pressed{border-image:url(://images//选择照片-02.png);}");
    connect(ui->m_btnSelectImage,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectImage()));

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    //按钮组
    QString btnStyle = "QPushButton{font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{color:rgb(255,255,255);background-color:rgb(4,119,182)}"
                       "QPushButton:pressed{color:rgb(255,255,255);background-color:rgb(4,119,182)}";
    ui->m_btnSave->setStyleSheet(btnStyle);
    connect(ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSlotSave()));
    ui->m_btnCancel->setStyleSheet(btnStyle);
    connect(ui->m_btnCancel,SIGNAL(clicked(bool)),this,SLOT(onSlotCancel()));

}
void AddTargetPersonImageDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void AddTargetPersonImageDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void AddTargetPersonImageDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}

void AddTargetPersonImageDlg::onSlotSelectImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择照片"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        QPixmap pix(fileName);
        ui->m_labelImage->setPixmap(pix);
    }
}

void AddTargetPersonImageDlg::onSlotClose()
{
    this->reject();
}

void AddTargetPersonImageDlg::onSlotSave()
{
    this->accept();
}

void AddTargetPersonImageDlg::onSlotCancel()
{
    this->reject();
}

void AddTargetPersonImageDlg::updatePersonInfo(QString name,QString sex,int age,QString dangersLevel,QString status,QString identitype,QString identiNumber)
{
    ui->m_labelName->setText(name);
    ui->m_labelSex->setText(sex);
    ui->m_labelAge->setText(QString("%1岁").arg(age));
    ui->m_labelDangers->setText(dangersLevel);
    ui->m_labelStatus->setText(status);
    ui->m_labelIdentityType->setText(identitype);
    ui->m_labelIndentityNumber->setText(identiNumber);
}



