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
    //pLayoutReal->setMargin(20);
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
    m_pTableWarningPane = new QTableWidget();
    pFolderWarning->setContentWidget(m_pTableWarningPane);
    m_pTableWarningPane->horizontalHeader()->setVisible(false);
    m_pTableWarningPane->verticalHeader()->setVisible(false);
    m_pTableWarningPane->setColumnCount(2);
    m_pTableWarningPane->setShowGrid(false);
    m_pTableWarningPane->horizontalHeader()->setStretchLastSection(true);
    m_pTableWarningPane->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pTableWarningPane->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   // m_pTableWarningPane->setSelectionMode(QAbstractItemView::NoSelection);
    m_pTableWarningPane->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");

    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolderReal,3);
    pMainLayout->addWidget(pFolderWarning,2);
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
    // 初始化表格
    m_pTableWarningPane->clearContents();
    m_pTableWarningPane->setColumnCount(2);
    m_pTableWarningPane->setColumnWidth(0,m_pTableWarningPane->width()/2 - 1);
    m_pTableWarningPane->setColumnWidth(1,m_pTableWarningPane->width()/2 - 1);
    m_pTableWarningPane->setRowCount(list.size()/2 + list.size()%2);


    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MyImageCompareWidget* pImage = new MyImageCompareWidget();
        pImage->setData(list[i].pix,list[i].similarity,list[i].source);
        int hei = pImage->height() + 10;
        m_pTableWarningPane->setRowHeight(i/2,hei);
        m_pTableWarningPane->setCellWidget(i/2,i%2,pImage);
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
            data.pix = QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1));
            data.similarity = 0.123456;
            data.source = "全球失踪人口库";
            list.append(data);
        }
        updateImageSimilarityData(list);
    }
    else if(pImageWid->getName() == "image2")
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        for(int i = 0 ; i < 5 ; i++)
        {
            RealTimeMonitorPane::stImageSimilarData data;
            data.name = QString("image").arg(i);
            data.pix = QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1));
            data.similarity = 0.753256;
            data.source = "成都犯罪分子库";
            list.append(data);
        }
        updateImageSimilarityData(list);
    }
    else if(pImageWid->getName() == "image3")
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        for(int i = 0 ; i < 15 ; i++)
        {
            RealTimeMonitorPane::stImageSimilarData data;
            data.name = QString("image").arg(i);
            data.pix = QPixmap(QString("://images//head%1.jpg").arg(qrand()%7 + 1));
            data.similarity = 1.0;
            data.source = "全国失踪人口库";
            list.append(data);
        }

        updateImageSimilarityData(list);
    }
    else
    {
        QList<RealTimeMonitorPane::stImageSimilarData> list;
        list.clear();
        updateImageSimilarityData(list);
    }
}





