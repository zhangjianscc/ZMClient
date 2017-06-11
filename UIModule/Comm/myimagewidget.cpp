#include "myimagewidget.h"
#include "stable.h"
#include "UIModule/Comm/myimagelabel.h"


MyImageWidget::MyImageWidget(QWidget* parent) :
    QWidget(parent)
{
    initUI();
}

void MyImageWidget::initUI()
{
    this->setStyleSheet("MyImageWidget{border-radius:2px;background-color:rgb(236,236,236)}");

    // 默认程序全屏运行 此处计算图片合适大小
    int imageWid = g_wid/9.5;
    int imageHei = g_hei/5;
    // 调整图片显示比例

    m_pLabelImage = new QLabel();
    m_pLabelImage->setFixedSize(imageWid,imageHei);
    m_pLabelImage->setScaledContents(true);
    m_pLabelImage->setAlignment(Qt::AlignCenter);
    m_pLabelImage->setStyleSheet("QLabel{border:1px solid rgb(109,109,109);background-color:rgb(178,178,178)}");

    m_pLabelDate = new QLabel();
    m_pLabelDate->setText(m_strDate);
    m_pLabelDate->setStyleSheet("QLabel{border:0px;background:transparent}");

    m_pLabelTime = new QLabel();
    m_pLabelTime->setText(m_strTime);
    m_pLabelTime->setStyleSheet("QLabel{border:0px;background:transparent}");

    m_pLabelPosition = new QLabel();
    m_pLabelPosition->setText(m_strPosition);
    m_pLabelPosition->setStyleSheet("QLabel{border:0px;background:transparent}");



    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setSpacing(1);
    pMainLayout->addWidget(m_pLabelImage,0,Qt::AlignCenter);
    pMainLayout->addWidget(m_pLabelDate,0,Qt::AlignHCenter);
    pMainLayout->addWidget(m_pLabelTime,0,Qt::AlignHCenter);
    pMainLayout->addWidget(m_pLabelPosition,0,Qt::AlignHCenter);

}
void MyImageWidget::mousePressEvent(QMouseEvent *ev)
{
    m_mousePos = QPoint(ev->x(), ev->y());
}

void MyImageWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(m_mousePos == QPoint(ev->x(), ev->y()))
    {
        m_bIsChecked = true;
        setChecked(m_bIsChecked);
    }
    emit clicked(this);
}

void MyImageWidget::setChecked(bool checked)
{
    if(checked)
    {
        this->setStyleSheet("MyImageWidget{background-color:rgb(129,210,255)}");
    }
    else
    {
        this->setStyleSheet("MyImageWidget{background-color:rgb(236,236,236)}");
    }
}

void MyImageWidget::reset()
{
    m_bIsChecked = false;
    m_strName = "";
    m_strDate = "";
    m_strTime = "";
    m_strPosition = "";

    m_pLabelImage->setPixmap(QPixmap("://images//图片丢失样式.jpg"));
    m_pLabelDate->setText(m_strDate);
    m_pLabelTime->setText(m_strTime);
    m_pLabelPosition->setText(m_strPosition);

    this->setStyleSheet("MyImageWidget{background-color:rgb(236,236,236)}");
}

void MyImageWidget::setData(QPixmap& pixmap,QString name,QString date,QString time,QString position)
{
    m_bIsChecked = false;
    m_strName = name;
    m_strDate = date;
    m_strTime = time;
    m_strPosition = position;

    m_pLabelImage->setPixmap(pixmap);

    m_pLabelDate->setText(m_strDate);
    m_pLabelTime->setText(m_strTime);
    m_pLabelPosition->setText(m_strPosition);

    this->setStyleSheet("MyImageWidget{background-color:rgb(236,236,236)}");
}


void MyImageWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

QString MyImageWidget::getName()
{
    return m_strName;
}


