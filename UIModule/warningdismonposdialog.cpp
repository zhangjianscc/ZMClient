#include "warningdismonposdialog.h"
#include "ui_warningdismonposdialog.h"

WarningDisMonPosdialog::WarningDisMonPosdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDisMonPosdialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    initUi();
}

WarningDisMonPosdialog::~WarningDisMonPosdialog()
{
    delete ui;
}

void WarningDisMonPosdialog::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void WarningDisMonPosdialog::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void WarningDisMonPosdialog::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void WarningDisMonPosdialog::initUi()
{
    ui->closePushButton->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-top-right-radius: 5px;}"
                                       "QPushButton:hover{border-image:url(://images//弹窗X选-02.png)}"
                                       "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png)}");

    ui->okPushButton->setStyleSheet("QPushButton{border-image:url(://images//确定.png);border: 0px;border-radius: 5px;}"
                                    "QPushButton:hover{border-image:url(://images//确定-01.png)}"
                                    "QPushButton:pressed{border-image:url(://images//确定-02.png)}");

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_closeButClicked()));
    connect(ui->okPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_okButClicked()));
}

void WarningDisMonPosdialog::slot_closeButClicked()
{
    this->close();
}

void WarningDisMonPosdialog::slot_okButClicked()
{
    this->close();
}
