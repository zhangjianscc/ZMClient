#include "addmonitorpositiondlg.h"
#include "ui_addmonitorpositiondlg.h"

AddMonitorPositionDlg::AddMonitorPositionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMonitorPositionDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    initUi();
}

AddMonitorPositionDlg::~AddMonitorPositionDlg()
{
    delete ui;
}

void AddMonitorPositionDlg::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void AddMonitorPositionDlg::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void AddMonitorPositionDlg::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void AddMonitorPositionDlg::initUi()
{
    ui->closePushButton->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-top-right-radius: 5px;}"
                                       "QPushButton:hover{border-image:url(://images//弹窗X选-02.png)}"
                                       "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png)}");

    ui->openPushButton->setStyleSheet("QPushButton{color:rgb(0,0,0); background-color:rgb(255,255,255)}"
                                      "QPushButton:hover{color:rgb(255,255,255); background-color:rgb(180,180,180)}"
                                      "QPushButton:pressed{color:rgb(255,255,255); background-color:rgb(160,160,160)}");

    QString string = "QPushButton{color:rgb(0,0,0); border:1px solid rgb(200,200,200); border-radius:5px;background-color:rgb(255,255,255)}"
                     "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                     "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}";
    ui->savePushButton->setStyleSheet(string);
    ui->cancelPushButton->setStyleSheet(string);

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_closeButClicked()));
    connect(ui->openPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_openButClicked()));
    connect(ui->savePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_saveButClicked()));
    connect(ui->cancelPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_cancelButClicked()));
}

void AddMonitorPositionDlg::slot_closeButClicked()
{
    this->close();
}

void AddMonitorPositionDlg::slot_openButClicked()
{
    QString temp = "东经20.234123\t北纬12.124123";
    ui->displayLabel->setText(tr("当前：%1").arg(temp));
}

void AddMonitorPositionDlg::slot_saveButClicked()
{
    QString sName = ui->nameLineEdit->text();
    QString sAddr = ui->areaComboBox->currentText();
    QString sArea = ui->areaComboBox->currentText();
}

void AddMonitorPositionDlg::slot_cancelButClicked()
{
    this->close();
}
