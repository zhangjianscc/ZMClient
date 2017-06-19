#include "warningdisdelsuredialog.h"
#include "ui_warningdisdelsuredialog.h"

WarningDisDelSureDialog::WarningDisDelSureDialog(QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDisDelSureDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    m_text = text;
    initUi();
}

WarningDisDelSureDialog::~WarningDisDelSureDialog()
{
    delete ui;
}

void WarningDisDelSureDialog::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void WarningDisDelSureDialog::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void WarningDisDelSureDialog::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void WarningDisDelSureDialog::initUi()
{
    ui->closePushButton->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-top-right-radius: 5px;}"
                                       "QPushButton:hover{border-image:url(://images//弹窗X选-02.png)}"
                                       "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png)}");

    ui->contentLabel->setText(tr("<font color=#000000 size=3>是否确认要</font><font color=#ff0000 size=3>删除</font><font color=#000000 size=3>该%1？</font>").arg(m_text));
    ui->contentLabel->setAlignment(Qt::AlignCenter);

    ui->deletePushButton->setStyleSheet("QPushButton{color:rgb(0,0,0); background-color:rgb(255,255,255)}"
                                        "QPushButton:hover{color:rgb(255,255,255); background-color:rgb(255,0,0)}"
                                        "QPushButton:pressed{color:rgb(255,255,255); background-color:rgb(200,0,0)}");

    ui->cancelPushButton->setStyleSheet("QPushButton{color:rgb(0,0,0); background-color:rgb(255,255,255)}"
                                        "QPushButton:hover{color:rgb(255,255,255); background-color:rgb(200,200,200)}"
                                        "QPushButton:pressed{color:rgb(255,255,255); background-color:rgb(180,180,180)}");

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_closeButClicked()));
    connect(ui->deletePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_deleteButClicked()));
    connect(ui->cancelPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_cancelButClicked()));
}

void WarningDisDelSureDialog::slot_closeButClicked()
{
    this->close();
}

void WarningDisDelSureDialog::slot_deleteButClicked()
{
    this->close();
}

void WarningDisDelSureDialog::slot_cancelButClicked()
{
    this->close();
}
