#include "addmonitorareadlg.h"
#include "ui_addmonitorareadlg.h"

AddMonitorAreaDlg::AddMonitorAreaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMonitorAreaDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    initUi();
}

AddMonitorAreaDlg::~AddMonitorAreaDlg()
{
    delete ui;
}

void AddMonitorAreaDlg::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void AddMonitorAreaDlg::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void AddMonitorAreaDlg::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void AddMonitorAreaDlg::initUi()
{
    ui->closePushButton->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-top-right-radius: 5px;}"
                                       "QPushButton:hover{border-image:url(://images//弹窗X选-02.png)}"
                                       "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png)}");

    QString string = "QPushButton{color:rgb(0,0,0); border:1px solid rgb(200,200,200); border-radius:5px;background-color:rgb(255,255,255)}"
                     "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                     "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}";
    ui->savePushButton->setStyleSheet(string);
    ui->cancelPushButton->setStyleSheet(string);

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_closeButClicked()));
    connect(ui->savePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_saveButClicked()));
    connect(ui->cancelPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_cancelButClicked()));
}

void AddMonitorAreaDlg::slot_closeButClicked()
{
    this->close();
}

void AddMonitorAreaDlg::slot_saveButClicked()
{
    QString sName = ui->nameLineEdit->text();
    QString sArea = ui->areaComboBox->currentText();
    QString sType = ui->typeComboBox->currentText();
    QString sDescription = ui->descriptionTextEdit->toPlainText();
    QString sRemake = ui->remakeTextEdit->toPlainText();
}

void AddMonitorAreaDlg::slot_cancelButClicked()
{
    this->close();
}
