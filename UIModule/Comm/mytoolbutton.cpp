#include "mytoolbutton.h"
#include "stable.h"

MyToolButton::MyToolButton(QString text) :
    QToolButton(0),
    m_text(text),
    m_bImageButton(false)
{
    this->setText(text);
    this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    this->setCheckable(true);
    this->setFixedHeight(30);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QFont font = this->font();
    font.setPointSize(12);
    this->setFont(font);
    this->setText(QString("      %1").arg(m_text));

    this->setStyleSheet("MyToolButton{background-color:rgb(217,217,217);font: 12pt Arial Black;text-align:left}"
                        "MyToolButton:checked{border-image: url(:/images/导航栏选中.png);color:rgb(255,255,255);font: 12pt Arial Black;}");
}

MyToolButton::MyToolButton(QString text,QString icon1,QString icon2) :
    QToolButton(0),
    m_text(text),
    m_iconNomal(icon1),
    m_iconSelect(icon2),
    m_bImageButton(true)
{
    this->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    this->setCheckable(true);
    this->setFixedHeight(50);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPalette pa = this->palette();
    pa.setColor(QPalette::Background, QColor(217, 217, 217));
    pa.setColor(QPalette::WindowText, QColor(76, 76, 76));

    QFont font = this->font();
    font.setPointSize(18);
    this->setFont(font);
    this->setText(text);

    this->setIconSize(QSize(39,37));
    this->setIcon(QIcon(QPixmap(icon1)));

    //设置样式表  图标设置失败
    QString stylesheet = QString("MyToolButton{background-color:rgb(217,217,217);color:rgb(0,0,0);font: 18pt Arial Black;}"
                                 "MyToolButton:checked{background-color:rgb(76,76,76);color:rgb(255,255,255)}");
    this->setStyleSheet(stylesheet);

}

void MyToolButton::select()
{
    if(!m_bImageButton)return;

    //this->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //this->setCheckable(true);
    //this->setFixedHeight(40);
    //this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPalette pa = this->palette();
    pa.setColor(QPalette::Background, QColor(76,76,76));
    pa.setColor(QPalette::WindowText, QColor(255,255,255));
    this->setPalette(pa);

    this->setIconSize(QSize(39,37));
    this->setIcon(QIcon(QPixmap(m_iconSelect)));
}

void MyToolButton::unSelect()
{
    if(!m_bImageButton)return;

    //this->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //this->setCheckable(true);
    //this->setFixedHeight(60);
    //this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPalette pa = this->palette();
    pa.setColor(QPalette::Background, QColor(217, 217, 217));
    pa.setColor(QPalette::WindowText, QColor(76, 76, 76));
    this->setPalette(pa);

    this->setIconSize(QSize(39,37));
    this->setIcon(QIcon(QPixmap(m_iconNomal)));
}
