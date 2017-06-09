#include "myimagewidget.h"
#include "stable.h"

MyImageWidget::MyImageWidget() :
    QWidget(0)
{
    this->setStyleSheet("MyImageWidget{border:0px;border-radius:2px;background-color:rgb(236,236,236)}");
    //this->setFixedSize(100,150);

    m_pLabelImage = new QLabel();
    m_pLabelImage->setFixedSize(100,114);
    m_pLabelImage->setScaledContents(true);
    //m_pLabelImage->setPixmap(pixmap);
    m_pLabelImage->setStyleSheet("QLabel{border:0px;background-color:rgb(178,178,178)}");

    m_pLabelDate = new QLabel();
    m_pLabelDate->setText(m_strDate);
    m_pLabelDate->setStyleSheet("QLabel{border:0px;background-color:rgb(236,236,236)}");

    m_pLabelTime = new QLabel();
    m_pLabelTime->setText(m_strTime);
    m_pLabelTime->setStyleSheet("QLabel{border:0px;background-color:rgb(236,236,236)}");

    m_pLabelPosition = new QLabel();
    m_pLabelPosition->setText(m_strPosition);
    m_pLabelPosition->setStyleSheet("QLabel{border:0px;background-color:rgb(236,236,236)}");

    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setSpacing(1);
    pMainLayout->addWidget(m_pLabelImage,0,Qt::AlignHCenter);
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
    emit clicked();
}

void MyImageWidget::setChecked(bool checked)
{
    if(checked)
    {
        this->setStyleSheet("MyImageWidget{border:none;border-radius:2px;background-color:rgb(129,210,255)}");
    }
    else
    {
        this->setStyleSheet("MyImageWidget{border:none;border-radius:2px;background-color:rgb(236,236,236)}");
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
}






