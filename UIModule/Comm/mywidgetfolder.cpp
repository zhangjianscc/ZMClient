#include "mywidgetfolder.h"
#include "stable.h"

MyWidgetFolder::MyWidgetFolder(QString iconPath,QString title) :
    QWidget(0),
    m_strIconPath(iconPath),
    m_strTitle(title)
{
    this->setStyleSheet("MyWidgetFolder{border:2px solid rgb(180,180,180);border-radius:2px;background-color:rgb(236,236,236)}");

    QWidget* pWidTitleBar = new QWidget();
    pWidTitleBar->setFixedHeight(25);
    pWidTitleBar->setStyleSheet("QWidget{border-radius:0px;"
                                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(235, 235, 235, 255), stop:1 rgba(170, 170, 170, 255));}");

    QLabel* pLabelIcon = new QLabel();
    pLabelIcon->setPixmap(QPixmap(iconPath));
    pLabelIcon->setAttribute(Qt::WA_TranslucentBackground);
    pLabelIcon->setStyleSheet("QLabel{border:none;}");

    QLabel* pLabelTitle = new QLabel();
    pLabelTitle->setAttribute(Qt::WA_TranslucentBackground);
    pLabelTitle->setStyleSheet("QLabel{border:none;font: 12pt Arial Black;}");
    pLabelTitle->setText(title);

    QHBoxLayout* pTitleLayout = new QHBoxLayout(pWidTitleBar);
    pTitleLayout->setContentsMargins(10,0,0,0);
    pTitleLayout->addWidget(pLabelIcon);
    pTitleLayout->addWidget(pLabelTitle);
    pTitleLayout->addStretch();

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->setMargin(0);
    m_pMainLayout->setSpacing(0);
    m_pMainLayout->addWidget(pWidTitleBar);
}

void MyWidgetFolder::setContentWidget(QWidget* pWid)
{
    while(m_pMainLayout->count() > 1)
    {
        m_pMainLayout->removeItem(m_pMainLayout->itemAt(m_pMainLayout->count()-1));
    }

    pWid->setStyleSheet("QWidget{background:transparent}");
    m_pMainLayout->addWidget(pWid,1);
}

void MyWidgetFolder::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
