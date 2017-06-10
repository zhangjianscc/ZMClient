#include "myimagecomparewidget.h"
#include "stable.h"

MyImageCompareWidget::MyImageCompareWidget(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void MyImageCompareWidget::initUI()
{
    this->setStyleSheet("MyImageWidget{border-radius:2px;background-color:rgb(236,236,236)}");

    // 默认程序全屏运行 此处计算图片合适大小
    int imageWid = g_wid/12;
    int imageHei = g_hei/6;

    m_pLabelImage = new QLabel();
    m_pLabelImage->setFixedSize(imageWid,imageHei);
    m_pLabelImage->setScaledContents(true);
    m_pLabelImage->setStyleSheet("QLabel{border:1px solid rgb(109,109,109);background-color:rgb(178,178,178)}");

    m_pLabelSimilarTitle = new QLabel();
    m_pLabelSimilarTitle->setText("相似度");
    m_pLabelSimilarTitle->setStyleSheet("QLabel{border:0px;background:transparent}");

    m_pSimilayBar = new QProgressBar();
    m_pSimilayBar->setRange(0,100);
    //m_pSimilayBar->setFixedWidth(imageWid);
    m_pSimilayBar->setFixedHeight(10);
    m_pSimilayBar->setOrientation(Qt::Horizontal);
    m_pSimilayBar->setTextVisible(false);
    m_pSimilayBar->setStyleSheet("QProgressBar{border:none;border-radius:5px;background-color:rgb(178,178,178);}"
                                 "QProgressBar::chunk{border:none;border-radius:5px;background-color:rgb(255,0,0);}");

    m_pLabelSimilarValue = new QLabel();
    m_pLabelSimilarValue->setText("相似度%");
    m_pLabelSimilarValue->setStyleSheet("QLabel{border:0px;background:transparent}");

    QHBoxLayout* playout1 = new QHBoxLayout();
    playout1->setMargin(0);
    playout1->setSpacing(2);
    playout1->addWidget(m_pLabelSimilarTitle);
    playout1->addWidget(m_pSimilayBar);
    playout1->addWidget(m_pLabelSimilarValue);
    QWidget* pSimilarWid = new QWidget();
    pSimilarWid->setLayout(playout1);



    m_pLabelSourceTitle = new QLabel();
    m_pLabelSourceTitle->setText("对比照片来源");
    m_pLabelSourceTitle->setStyleSheet("QLabel{border:0px;background:transparent}");
    m_pLabelSourceValue = new QLabel();
    m_pLabelSourceValue->setText("来源");
    m_pLabelSourceValue->setStyleSheet("QLabel{border:1px solid rgb(44,149,206);"
                                       "border-radius:3px;"
                                       "background-color:rgb(44,149,206);"
                                       "color:rgb(255,255,255)}");

    QHBoxLayout* playout2 = new QHBoxLayout();
    playout2->setMargin(0);
    playout2->setSpacing(2);
    playout2->addWidget(m_pLabelSourceTitle);
    playout2->addWidget(m_pLabelSourceValue);
    QWidget* pSourceWid = new QWidget();
    pSourceWid->setLayout(playout2);


    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setSpacing(5);
    pMainLayout->addWidget(m_pLabelImage,0,Qt::AlignCenter);
    pMainLayout->addWidget(pSimilarWid,0,Qt::AlignCenter);
    pMainLayout->addWidget(pSourceWid,0,Qt::AlignCenter);

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
    int value = strValue.toInt() == 100?100:strValue.toInt()%100;
    m_pSimilayBar->setValue(value);
}

void MyImageCompareWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
