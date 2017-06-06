#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_bRemenberUser(false)
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
    QBitmap objBitmap(size());
    QPainter painter(&objBitmap); //QPainter用于在位图上绘画
    painter.fillRect(rect(),Qt::white);//填充位图矩形框(用白色填充)
    painter.setBrush(QColor(0,0,0));
    painter.drawRoundedRect(this->rect(),12,12);//在位图上画圆角矩形(用黑色填充)
    setMask(objBitmap);    //使用setmask过滤即可

    // 最小化按钮
    ui->m_btnMinimize->setStyleSheet("QPushButton{border-image:url(://images//mouseenter-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//mouseenter-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//mouseenter-02.png);}");
    connect(ui->m_btnMinimize,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMinimize()));

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//mouseenter03.png);border: 0px;border-top-left-radius: 0px;"
                                  "border-top-right-radius: 12px;border-bottom-left-radius: 0px;border-bottom-right-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//mouseenter.png);}"
                                              "QPushButton:pressed{border-image:url(://images//mouseenter.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnClose()));


    // 用户名输入框
    ui->m_editUserName->setTextMargins(ui->m_editUserName->height(), 0, 0, 0);
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
    font.setPointSize(ui->m_editUserName->height() / 3);
    ui->m_editUserName->setFont(font);
    ui->m_editUserName->setText("请输入用户名   ");
    ui->m_editUserName->setAlignment(Qt::AlignHCenter);
    ui->m_editUserName->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:gray}");
    connect(ui->m_editUserName,SIGNAL(textChanged(QString)),this,SLOT(onSlotUserNameChanged(QString)));
    connect(ui->m_editUserName,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(onSlotUserNameEditClicked(int,int)));



    // 用户密码输入框
    ui->m_editUserKey->setTextMargins(ui->m_editUserKey->height(), 0, 0, 0);
    QLabel *label2 = new QLabel();
    label2->setPixmap(QPixmap("://images//login-password.png"));
    label2->setScaledContents(true);
    label2->setFixedSize(ui->m_editUserKey->height()/2,ui->m_editUserKey->height()/2);
    label2->setCursor(QCursor(Qt::ArrowCursor));
    QHBoxLayout *editLayout2 = new QHBoxLayout();
    editLayout2->addWidget(label2,0,Qt::AlignCenter);
    editLayout2->addStretch();
    ui->m_editUserKey->setLayout(editLayout2);
    QFont font2 = ui->m_editUserKey->font();
    font2.setPointSize(ui->m_editUserKey->height() / 3);
    ui->m_editUserKey->setFont(font2);
    ui->m_editUserKey->setText("请输入你的密码   ");
    ui->m_editUserKey->setAlignment(Qt::AlignHCenter);
    ui->m_editUserKey->setEchoMode(QLineEdit::Normal);
    ui->m_editUserKey->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:gray}");
    connect(ui->m_editUserKey,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(onSlotUserKeyEditClicked(int,int)));


    // 记住用户复选框
    ui->m_checkBoxRemenber->setStyleSheet("QCheckBox::indicator:unchecked{border-image:url(://images//checkbox.png);}"
                                          "QCheckBox::indicator:checked{border-image:url(://images//checkbox02.png);}"
                                          "QCheckBox::indicator:checked:disabled{border-image:url(://images//checkbox02.png);}");
    connect(ui->m_checkBoxRemenber,SIGNAL(stateChanged(int)),this,SLOT(onSlotRemenberUserStateChanged(int)));

    // 登录按钮
    ui->m_btnLogin->setStyleSheet("QPushButton{border-image:url(://images//login-btn.png);border: 0px; border-radius: 3px;}"
                                              "QPushButton:hover{border-image:url(://images//login-btn-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//login-btn-03.png);}");
    connect(ui->m_btnLogin,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnLogin()));
    ui->m_btnLogin->setFocus();

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
    this->accept();
}

void LoginDialog::onSlotRemenberUserStateChanged(int value)
{
    if(0 == value)
    {
        m_bRemenberUser = false;
    }
    else
    {
        m_bRemenberUser = true;
    }
}

void LoginDialog::onSlotUserNameChanged(QString userName)
{
    QMap<QString,QString>::const_iterator it = m_mapSavedUser.find(userName);
    if(it != m_mapSavedUser.end())
    {
        onSlotUserKeyEditClicked(0,0);
        ui->m_editUserKey->setText(it.value());
    }
}

void  LoginDialog::onSlotUserNameEditClicked(int,int)
{
    if(ui->m_editUserName->text() == "请输入用户名   ")  // 第一次点击时修改状态
    {
        ui->m_editUserName->setText("");
        ui->m_editUserName->setAlignment(Qt::AlignLeft);
        ui->m_editUserName->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:black}");
    }
}

void  LoginDialog::onSlotUserKeyEditClicked(int,int)
{
    if(ui->m_editUserKey->text() == "请输入你的密码   ") // 第一次点击时修改状态
    {
        ui->m_editUserKey->setText("");
        ui->m_editUserKey->setAlignment(Qt::AlignLeft);
        ui->m_editUserKey->setEchoMode(QLineEdit::Password);
        ui->m_editUserKey->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:black}");
    }
}







