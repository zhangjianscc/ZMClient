#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loadSavedUserInfo();
    initUI();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void LoginDialog::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPainterPath path;
    QRectF rect = QRectF(this->x(), this->y(), this->width(),this->height());
    path.addRoundRect(rect,2,2);
    QPolygon polygon= path.toFillPolygon().toPolygon();
    QRegion region(polygon);
    this->setMask(region);

    // 最小化按钮
    //ui->m_btnMinimize->setFixedSize(31,33);
    ui->m_btnMinimize->setStyleSheet("QPushButton{border-image:url(://images//mouseenter-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//mouseenter-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//mouseenter-02.png);}");
    connect(ui->m_btnMinimize,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMinimize()));

    // 关闭按钮
    //ui->m_btnClose->setFixedSize(36,33);
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//mouseenter03.png);border: 0px;border-radius-top-right: 15px;}"
                                              "QPushButton:hover{border-image:url(://images//mouseenter.png);}"
                                              "QPushButton:pressed{border-image:url(://images//mouseenter.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnClose()));

    // 登录按钮
    ui->m_btnLogin->setStyleSheet("QPushButton{border-image:url(://images//login-btn.png);border: 0px; border-radius: 3px;}"
                                              "QPushButton:hover{border-image:url(://images//login-btn-02.png);border: 0px; border-radius: 3px;}"
                                              "QPushButton:pressed{border-image:url(://images//login-btn-03.png);border: 0px; border-radius: 3px;}");

    // 用户名输入框
    ui->m_editUserName->setTextMargins(ui->m_editUserName->height() + 10, 0, 0, 0);
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap("://images//login-admin.png"));
    label->setScaledContents(true);
    label->setFixedSize(ui->m_editUserName->height()/2,ui->m_editUserName->height()/2);
    label->setCursor(QCursor(Qt::ArrowCursor));
    QHBoxLayout *editLayout = new QHBoxLayout();
    editLayout->addWidget(label,0,Qt::AlignCenter);
    editLayout->addStretch();
    ui->m_editUserName->setLayout(editLayout);
    QFont font = ui->m_editUserName->font();
    font.setPointSize(ui->m_editUserName->height() / 4);
    ui->m_editUserName->setFont(font);
    ui->m_editUserName->setText("请输入用户名");
    ui->m_editUserName->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;}");


    // 用户密码输入框
    ui->m_editUserKey->setTextMargins(ui->m_editUserKey->height() + 10, 0, 0, 0);
    QLabel *label2 = new QLabel();
    label2->setPixmap(QPixmap("://images//login-password.png"));
    label2->setScaledContents(true);
    label2->setFixedSize(ui->m_editUserKey->height()/2,ui->m_editUserKey->height()/2);
    label2->setCursor(QCursor(Qt::ArrowCursor));
    QHBoxLayout *editLayout2 = new QHBoxLayout();
    editLayout2->addWidget(label2,0,Qt::AlignCenter);
    editLayout2->addStretch();
    ui->m_editUserKey->setLayout(editLayout2);
    //QFont font2 = ui->m_editUserKey->font();
    //font2.setPointSize(ui->m_editUserKey->height() / 4);
    //ui->m_editUserKey->setFont(font2);
    ui->m_editUserKey->setText("请输入你的密码");
    ui->m_editUserKey->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;}");

    // 记住用户复选框
    QString checkstyle = "QCheckBox::indicator:unchecked{image:url(://images//checkbox.png);}"
                         "QCheckBox::indicator:checked{image:url(://images//checkbox02.png);}"
                         "QCheckBox::indicator:checked:disabled{image:url(://images//checkbox02.png);}";
    ui->m_checkBoxRemenber->setStyleSheet(checkstyle);

}

void LoginDialog::loadSavedUserInfo()
{
    // by ly
    m_mapSavedUser.clear();
    m_mapSavedUser.insert("admin","123");
    m_mapSavedUser.insert("test1","123");
    m_mapSavedUser.insert("test2","123");
    m_mapSavedUser.insert("test3","123");
}

void LoginDialog::loginResult(bool result,QString retMsg)
{
    if(result)
    {
        this->accept();
    }
    else
    {

    }
}

void LoginDialog::onSlotBtnMinimize()
{
    this->showMinimized();
}

void LoginDialog::onSlotBtnClose()
{
    this->reject();
}

void LoginDialog::onSlotBtnLogin()
{
    QString userName = ui->m_editUserName->text();
    QString userKey  = ui->m_editUserKey->text();
    // by ly
}












