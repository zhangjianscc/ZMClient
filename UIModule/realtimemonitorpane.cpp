#include "realtimemonitorpane.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"
#include "UIModule/Comm/myimagewidget.h"
#include "UIModule/Comm/myimagecomparewidget.h"

RealTimeMonitorPane::RealTimeMonitorPane(QWidget *parent) : QWidget(parent)
{
    m_listImageWid.clear();
    m_listImageCompareWid.clear();
    initUI();
}

void RealTimeMonitorPane::initUI()
{
    this->setStyleSheet("RealTimeMonitorPane{border:none;background-color:rgb(227,227,227)}");

    MyWidgetFolder* pFolderReal = new MyWidgetFolder("://images//实时监控图标01.png","实时采集");
    QWidget* pRealContent = new QWidget();
    pFolderReal->setContentWidget(pRealContent);
    QGridLayout* pLayoutReal = new QGridLayout(pRealContent);
    pLayoutReal->setMargin(20);
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            MyImageWidget* pImageWid = new MyImageWidget();
            connect(pImageWid,SIGNAL(clicked(MyImageWidget*)),this,SLOT(onSlotLeftImageClieked(MyImageWidget*)));
            pLayoutReal->addWidget(pImageWid,i,j,Qt::AlignCenter);
            m_listImageWid.append(pImageWid);
        }
    }


    MyWidgetFolder* pFolderWarning = new MyWidgetFolder("://images//实时监控图标02.png","告警信息");
    QScrollArea* pScrollContent = new QScrollArea();
    pFolderWarning->setContentWidget(pScrollContent);

    QWidget* pScrollWid = new QWidget();
    pScrollContent->setWidget(pScrollWid);
    pScrollContent->setWidgetResizable(true);
    m_pLayoutWarning = new QGridLayout(pScrollWid);
    m_pLayoutWarning->setMargin(10);


    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolderReal,2);
    pMainLayout->addWidget(pFolderWarning,1);
}

void RealTimeMonitorPane::updateImageData(QList<stImageData>& list)
{
    for(int i = 0 ; i < list.count() ; ++i)
    {
        if(i < m_listImageWid.size())
        {
            m_listImageWid[i]->setData(list[i].pix,list[i].name,list[i].date,list[i].time,list[i].position);
        }
    }
}

void RealTimeMonitorPane::updateImageSimilarityData(QList<stImageSimilarData>& list)
{
    // 隐藏之前的图片数据
    for(int i = 0 ; i < m_listImageCompareWid.size() ; ++i)
    {
        m_listImageCompareWid[i]->setVisible(false);
    }

    // 刷新数据
    for(int i = 0 ; i < list.count() ; ++i)
    {
        if( i < m_listImageCompareWid.size())
        {
            m_listImageCompareWid[i]->setData(list[i].pix,list[i].similarity,list[i].source);
            m_listImageCompareWid[i]->setVisible(true);
        }
        else
        {
            MyImageCompareWidget* pWid = new MyImageCompareWidget();
            pWid->setData(list[i].pix,list[i].similarity,list[i].source);
            m_listImageCompareWid.append(pWid);
            m_pLayoutWarning->addWidget(pWid,m_listImageCompareWid.size() / 2,m_listImageCompareWid.size() % 2);
        }
    }
}

void RealTimeMonitorPane::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void RealTimeMonitorPane::onSlotLeftImageClieked(MyImageWidget* pImageWid)
{
    // 切换其他图片为未选中状态
    foreach (MyImageWidget* pWid, m_listImageWid) {
        if(pWid != pImageWid)
        {
            pWid->setChecked(false);
        }
    }



    // by ly
    // 请求相似度数据
    if(pImageWid->getName() == "image1")
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        for(int i = 0 ; i < 3 ; i++)
        {
            RealTimeMonitorPane::stImageSimilarData data;
            data.name = QString("image").arg(i);
            data.pix = QPixmap("://images//head.jpg");
            data.similarity = 0.123456;
            data.source = "全球失踪人口库";
            list.append(data);
            //
            updateImageSimilarityData(list);
        }
    }
    else if(pImageWid->getName() == "image2")
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        for(int i = 0 ; i < 5 ; i++)
        {
            RealTimeMonitorPane::stImageSimilarData data;
            data.name = QString("image").arg(i);
            data.pix = QPixmap("://images//head.jpg");
            data.similarity = 0.753256;
            data.source = "成都犯罪分子库";
            list.append(data);
            //
            updateImageSimilarityData(list);
        }
    }
    else if(pImageWid->getName() == "image3")
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        for(int i = 0 ; i < 5 ; i++)
        {
            RealTimeMonitorPane::stImageSimilarData data;
            data.name = QString("image").arg(i);
            data.pix = QPixmap("://images//head.jpg");
            data.similarity = 1.0;
            data.source = "全国失踪人口库";
            list.append(data);
            //
            updateImageSimilarityData(list);
        }
    }
    else
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        list.clear();
        updateImageSimilarityData(list);
    }
}





