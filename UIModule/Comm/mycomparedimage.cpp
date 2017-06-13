#include "mycomparedimage.h"
#include "stable.h"

MyComparedImage::MyComparedImage(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void MyComparedImage::initUI()
{
    //this->setFixedSize(215,180);
    this->setFixedHeight(180);

    // 标题
    m_pLabelTitle = new QLabel();
    m_pLabelTitle->setFixedSize(120,20);
    m_pLabelTitle->setStyleSheet("QLabel{border:1px solid rgb(180,180,180);background-color:rgb(76,76,76);font-size:15px;color:rgb(255,255,255)}");

    // 图片
    m_pLabelImage = new QLabel();
    m_pLabelImage->setScaledContents(true);
    m_pLabelImage->setFixedSize(120,140);
    m_pLabelImage->setStyleSheet("QLable{border:1px solid rgb(180,180,180);background-color:rgb(236,236,236)}");

    // 信息
    QLabel* pLabelSimilar = new QLabel("相似度");
    pLabelSimilar->setStyleSheet("QLabel{border:none;font-size:10px;color:rgb(0,0,0);background-color:rgb(236,236,236)}");
    m_pProSimilar = new QProgressBar();
    m_pProSimilar->setRange(0,100);
    m_pProSimilar->setFixedSize(100,10);
    m_pProSimilar->setOrientation(Qt::Horizontal);
    m_pProSimilar->setTextVisible(false);
    m_pProSimilar->setStyleSheet("QProgressBar{border:1px;border-radius:5px;background-color:rgb(178,178,178);}"
                                 "QProgressBar::chunk{border:none;border-radius:5px;background-color:rgb(255,0,0);}");
    m_pLabelSimilarValue = new QLabel("%");
    m_pLabelSimilarValue->setStyleSheet("QLabel{border:none;font-size:10px;color:rgb(0,0,0);background-color:rgb(236,236,236)}");
    QWidget* pInfoWid = new QWidget();
    QHBoxLayout* pLayout = new QHBoxLayout(pInfoWid);
    pLayout->setMargin(0);
    pLayout->setSpacing(0);
    pLayout->addWidget(pLabelSimilar);
    pLayout->addWidget(m_pProSimilar);
    pLayout->addWidget(m_pLabelSimilarValue);

    // 主布局
    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setMargin(0);
    pMainLayout->setSpacing(0);
    pMainLayout->addWidget(m_pLabelTitle,0,Qt::AlignHCenter);
    pMainLayout->addWidget(m_pLabelImage,0,Qt::AlignHCenter);
    pMainLayout->addWidget(pInfoWid,0,Qt::AlignHCenter);
}

void MyComparedImage::setData(QPixmap pix,QString source,double similar)
{
    m_pLabelImage->setPixmap(pix);
    m_pLabelTitle->setText(source);
    double si = similar * 100;
    si = si < 0?0:si;
    si = si > 100?100:si;
    m_pProSimilar->setValue((int)si);
    m_pLabelSimilarValue->setText(QString::number(si) + "%");
}

void MyComparedImage::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
