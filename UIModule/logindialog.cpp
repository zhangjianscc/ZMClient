#include "logindialog.h"
#include "ui_logindialog.h"
#include "Common/singleton.h"
#include "InterFaceToService/sysuserclient.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QMessageBox>

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
    QPixmap pix("://images//login_back.png");
    this->setMask(pix.mask());

    // 最小化按钮
    ui->m_btnMinimize->setStyleSheet("QPushButton{border-image:url(://images//mouseenter-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//mouseenter-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//mouseenter-02.png);}");
    connect(ui->m_btnMinimize,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnMinimize()));

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//mouseenter03.png);border: 0px;border-radius: 0px;}"
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
    ui->m_editUserName->setText(QStringLiteral("请输入用户名  "));
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
    ui->m_editUserKey->setText(QStringLiteral("请输入你的密码  "));
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
    m_mapSavedUser.insert(this->ui->m_editUserName->text(),this->ui->m_editUserKey->text());
    //m_mapSavedUser.insert("admin","123");
    //m_mapSavedUser.insert("test1","123");
    //m_mapSavedUser.insert("test2","123");
    //m_mapSavedUser.insert("test3","123");
}

void LoginDialog::loginResult(bool result,QString retMsg)
{
    if(result)
    {
        this->accept();
    }
    else
    {
        retMsg = "登陆异常";
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
   LOGIN login;
   login.account=ui->m_editUserName->text();
   login.password=ui->m_editUserKey->text();
   // by ly添加登陆业务逻辑请求以及返回
   QString retStr = "";
   SysUserClient sysuserclient;
   sysuserclient.Login(login, retStr);  //登陆接口
   //开始解析返回的数据
   QJsonParseError login_json_error;
   QString RET_CODE;
   //RETJSON所有的元素
   QJsonDocument login_parse_doucment = QJsonDocument::fromJson(retStr.toUtf8(), &login_json_error);
   //检查json是否有错误
   if (login_json_error.error == QJsonParseError::NoError)
   {
       if (login_parse_doucment.isObject())
       {
           //开始解析json对象
           QJsonObject obj = login_parse_doucment.object();
           //如果包含RET_CODE
           if (obj.contains("RET_CODE"))
           {
               //得到RET_CODE
               QJsonValue ret_code_value = obj.take("RET_CODE");
               if (ret_code_value.isString())
               {
                   //转换RET_CODE
                   RET_CODE = ret_code_value.toVariant().toString();
               }
           }
       }
   }
   if("0" == RET_CODE)
   {
       this->loginResult(true, NULL);
   }
   else {
       QMessageBox::information(this,"提示","登陆失败");
       this->loginResult(false, "登陆失败");
   }
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
    if(ui->m_editUserName->text() == QStringLiteral("请输入用户名  "))  // 第一次点击时修改状态
    {
        ui->m_editUserName->setText("");
        ui->m_editUserName->setAlignment(Qt::AlignLeft);
        ui->m_editUserName->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:black}");
    }
}

void  LoginDialog::onSlotUserKeyEditClicked(int,int)
{
    if(ui->m_editUserKey->text() == QStringLiteral("请输入你的密码  ")) // 第一次点击时修改状态
    {
        ui->m_editUserKey->setText("");
        ui->m_editUserKey->setAlignment(Qt::AlignLeft);
        ui->m_editUserKey->setEchoMode(QLineEdit::Password);
        ui->m_editUserKey->setStyleSheet("QLineEdit{border-image:url(://images//textbox.png);border: 0px; border-radius: 3px;color:black}");
    }
}







