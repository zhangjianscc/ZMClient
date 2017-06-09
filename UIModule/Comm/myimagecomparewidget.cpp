#include "myimagecomparewidget.h"
#include "stable.h"

MyImageCompareWidget::MyImageCompareWidget(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void MyImageCompareWidget::initUI()
{
    this->setStyleSheet("MyImageWidget{border-radius:2px;background-color:rgb(236,236,236)}");


    m_pLabelImage = new QLabel();
    m_pLabelImage->setFixedSize(130,156);
    m_pLabelImage->setScaledContents(true);
    m_pLabelImage->setAlignment(Qt::AlignCenter);
    m_pLabelImage->setStyleSheet("QLabel{border:1px solid rgb(109,109,109);background-color:rgb(178,178,178)}");

    m_pLabelSimilarTitle = new QLabel();
    m_pLabelSimilarTitle->setText("相似度");
    m_pLabelSimilarTitle->setStyleSheet("QLabel{border:0px;background:transparent}");

    m_pSimilayBar = new QProgressBar();
    m_pSimilayBar->setRange(0,100);
    m_pSimilayBar->setFixedHeight(15);
    m_pSimilayBar->setOrientation(Qt::Horizontal);
    m_pSimilayBar->setTextVisible(false);

    m_pLabelSimilarValue = new QLabel();
    m_pLabelSimilarValue->setText("相似度%");
    m_pLabelSimilarValue->setStyleSheet("QLabel{border:0px;background:transparent}");

    QHBoxLayout* playout1 = new QHBoxLayout();
    playout1->setMargin(0);
    playout1->setSpacing(0);
    playout1->addWidget(m_pLabelSimilarTitle);
    playout1->addWidget(m_pSimilayBar);
    playout1->addWidget(m_pLabelSimilarValue);



    m_pLabelSourceTitle = new QLabel();
    m_pLabelSourceTitle->setText("对比照片来源");
    m_pLabelSourceTitle->setStyleSheet("QLabel{border:0px;background:transparent}");

    m_pLabelSourceValue = new QLabel();
    m_pLabelSourceValue->setText("来源");
    m_pLabelSourceValue->setStyleSheet("QLabel{border-radius:3px;"
                                       "background-color:rgb(44,149,206);"
                                       "font-color:rgb(255,255,255)}");

    QHBoxLayout* playout2 = new QHBoxLayout();
    playout2->setMargin(0);
    playout2->setSpacing(0);
    playout2->addWidget(m_pLabelSourceTitle);
    playout2->addWidget(m_pLabelSourceValue);


    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setSpacing(1);
    pMainLayout->addWidget(m_pLabelImage,1);
    pMainLayout->addLayout(playout1);
    pMainLayout->addLayout(playout2);

}

void MyImageCompareWidget::setData(QPixmap& pix,double similarity,QString source)
{
    m_pLabelImage->setPixmap(pix);
    m_dSimilary = similarity * 100;
    m_pLabelSimilarValue->setText(QString("%1 %").arg(m_dSimilary));
    m_strSource = source;
    m_pLabelSourceValue->setText(source);

    QString strValue = QString::number(m_dSimilary);
    strValue = strValue.mid(0,strValue.indexOf("."));
    m_pSimilayBar->setValue(strValue.toInt()%100);
}

void MyImageCompareWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
