#include "warningwidget.h"

WarningWidget::WarningWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(400, 300);
    this->setStyleSheet("WarningWidget{border:1px solid rgb(0,0,0);background-color:rgb(255,255,255)}");

    initUi();
}

void WarningWidget::mousePressEvent(QMouseEvent *ev)
{
     this->m_curWindowPos = this->pos();
     this->m_curMousePos = ev->globalPos();
     this->m_destWindowPos = m_curMousePos - m_curWindowPos;
}

void WarningWidget::mouseMoveEvent(QMouseEvent *ev)
{
     this->move(ev->globalPos() - this->m_destWindowPos);
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
    pTitleLabel->setText(tr("告警"));
    pTitleLabel->setStyleSheet("QLabel{border:1px;background-color:red}");

    QWidget *pMainWidget = new QWidget;

    /// 窗口内容
    QWidget *pPictureWidget = new QWidget;
    pPictureWidget->setStyleSheet("QWidget{border:1px;border-radius:2px;background-color:rgb(129,210,255)}");

    QLabel *pTimeLabel = new QLabel(tr("告警时间"));
    QLabel *pTimeDataLabel = new QLabel;
    QLabel *pAddrLabel = new QLabel(tr("告警地点"));
    QLabel *pAddrDataLabel = new QLabel;
    QLabel *pSameLabel = new QLabel(tr("相似度"));
    QLabel *pSameDataLabel = new QLabel;
    QLabel *pNameLabel = new QLabel(tr("目标人姓名"));
    QLabel *pNameDataLabel = new QLabel;
    QLabel *pSexLabel = new QLabel(tr("性别"));
    QLabel *pSexDataLabel = new QLabel;
    QLabel *pAgeLabel = new QLabel(tr("年龄"));
    QLabel *pAgeDataLabel = new QLabel;
    QLabel *pNumberLabel = new QLabel(tr("证件号"));
    QLabel *pNumberDataLabel = new QLabel;
    QLabel *pTypeLabel = new QLabel(tr("类型"));
    QLabel *pTypeDataLabel = new QLabel;

    QPushButton *pOkButton = new QPushButton;
    pOkButton->setFixedSize(50, 30);
    pOkButton->setText(tr("确定"));
    pOkButton->setStyleSheet("QPushButton{border:1px;border-radius:2px;background-color:red}");

    QVBoxLayout *pNameLayout = new QVBoxLayout;
    pNameLayout->addWidget(pTimeLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pAddrLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pSameLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pNameLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pSexLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pAgeLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pNumberLabel, 0, Qt::AlignRight);
    pNameLayout->addWidget(pTypeLabel, 0, Qt::AlignRight);

    QVBoxLayout *pDataLayout = new QVBoxLayout;
    pDataLayout->addWidget(pTimeDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pAddrDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pSameDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pNameDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pSexDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pAgeDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pNumberDataLabel, 0, Qt::AlignLeft);
    pDataLayout->addWidget(pTypeDataLabel, 0, Qt::AlignLeft);

    QHBoxLayout *pHboxLayout = new QHBoxLayout;
    pHboxLayout->addWidget(pPictureWidget, 2);
    pHboxLayout->addLayout(pNameLayout, 1);
    pHboxLayout->addLayout(pDataLayout, 2);

    /// 主布局
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    pMainLayout->addWidget(pTitleLabel);
    pMainLayout->addLayout(pHboxLayout);
    pMainLayout->addWidget(pOkButton, 0, Qt::AlignHCenter);
}
