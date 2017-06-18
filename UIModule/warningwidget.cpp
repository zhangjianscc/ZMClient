#include "warningwidget.h"

WarningWidget::WarningWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setFixedSize(600, 400);
    this->setStyleSheet("WarningWidget{border:1px solid rgb(200,200,200);border-radius:5px;background-color:rgb(255,255,255)}");
    initUi();
}

void WarningWidget::mousePressEvent(QMouseEvent *event)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = event->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void WarningWidget::mouseMoveEvent(QMouseEvent *event)
{
     this->move(event->globalPos() - this->m_destWindowPos);
}

void WarningWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void WarningWidget::initUi()
{
    /// 标题栏
    QLabel *pTitleLabel = new QLabel;
    pTitleLabel->setFixedHeight(30);
    pTitleLabel->setText(tr("    告警"));
    pTitleLabel->setStyleSheet("QLabel{border:1px;background-color:rgb(255,0,0);color:rgb(255,255,255);"
                               "border-top-left-radius:5px;border-top-right-radius:5px;}");

    /// 窗口内容
    m_pPictureWidget = new QWidget;
    m_pPictureWidget->setFixedSize(200, 230);
    m_pPictureWidget->setStyleSheet("QWidget{border:1px solid rgb(180,180,180);background-color:rgb(200,200,200)}");

    QLabel *pTimeLabel = new QLabel(tr("告警时间"));
    m_pTimeDataLabel = new QLabel;
    m_pTimeDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pAddrLabel = new QLabel(tr("告警地点"));
    m_pAddrDataLabel = new QLabel;
    m_pAddrDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pSameLabel = new QLabel(tr("相似度"));
    m_pSameDataLabel = new QLabel;
    m_pSameDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pNameLabel = new QLabel(tr("目标人姓名"));
    m_pNameDataLabel = new QLabel;
    m_pNameDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pSexLabel = new QLabel(tr("性别"));
    m_pSexDataLabel = new QLabel;
    m_pSameDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pAgeLabel = new QLabel(tr("年龄"));
    m_pAgeDataLabel = new QLabel;
    m_pAgeDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pNumberLabel = new QLabel(tr("证件号"));
    m_pNumberDataLabel = new QLabel;
    m_pNumberDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");
    QLabel *pTypeLabel = new QLabel(tr("类型"));
    m_pTypeDataLabel = new QLabel;
    m_pTypeDataLabel->setStyleSheet("QLabel{border:none;color:rgb(255,0,0);background-color:rgb(255,255,255)}");

    QPushButton *pOkButton = new QPushButton;
    pOkButton->setFixedSize(100, 40);
    pOkButton->setStyleSheet("QPushButton{border-image:url(://images//确定.png);border: 0px;border-radius: 0px;}"
                             "QPushButton:hover{border-image:url(://images//确定-01.png);}"
                             "QPushButton:pressed{border-image:url(://images//确定-02.png);}");

    QVBoxLayout *pNameLayout = new QVBoxLayout;
    //pNameLayout->setSpacing(5);
    pNameLayout->addWidget(pTimeLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pAddrLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pSameLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pNameLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pSexLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pAgeLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pNumberLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pTypeLabel, 0, Qt::AlignRight);

    QVBoxLayout *pDataLayout = new QVBoxLayout;
    //pDataLayout->setSpacing(2);
    pDataLayout->addWidget(m_pTimeDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pAddrDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pSameDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pNameDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pSexDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pAgeDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pNumberDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(m_pTypeDataLabel, 0, Qt::AlignLeft);

    QHBoxLayout *pHboxLayout = new QHBoxLayout;
    pHboxLayout->setMargin(40);
    pHboxLayout->addWidget(m_pPictureWidget, 2);
    pHboxLayout->addLayout(pNameLayout, 1);
    pHboxLayout->addLayout(pDataLayout, 2);

    /// 主布局
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    pMainLayout->setContentsMargins(0, 0, 0, 10);
    pMainLayout->addWidget(pTitleLabel);
    pMainLayout->addLayout(pHboxLayout);
    pMainLayout->addWidget(pOkButton, 0, Qt::AlignHCenter);

    connect(pOkButton, SIGNAL(clicked(bool)), this, SLOT(slot_okButClicked()));
}

void WarningWidget::setData(QPixmap pixMap, stData &data)
{
    m_pPictureWidget->setWindowIcon(QIcon(pixMap));
    m_pTimeDataLabel->setText(data.time);
    m_pAddrDataLabel->setText(data.addr);
    m_pSameDataLabel->setText(data.same);
    m_pNameDataLabel->setText(data.name);
    m_pSexDataLabel->setText(data.sex);
    m_pAgeDataLabel->setText(QString::number(data.age));
    m_pNumberDataLabel->setText(QString::number(data.number));
    m_pTypeDataLabel->setText(data.type);
}

void WarningWidget::slot_okButClicked()
{
    this->close();
}
