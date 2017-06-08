#include "realtimemonitorpane.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"
#include "UIModule/Comm/myimagewidget.h"
#include "UIModule/Comm/myimagecomparewidget.h"

RealTimeMonitorPane::RealTimeMonitorPane(QWidget *parent) : QWidget(parent)
{
    m_listImageWid.clear();
    m_listImageCompareWid.clear();
    initFrame();
}

void RealTimeMonitorPane::initFrame()
{
    this->setStyleSheet("RealTimeMonitorPane{border:none;background-color:rgb(220,220,220)}");

    MyWidgetFolder* pFolderReal = new MyWidgetFolder("://images//实时监控图标01.png","实时采集");
    QWidget* pRealContent = new QWidget();
    pRealContent->setStyleSheet("QWidget{border:1px;border-radius:2px;background-color:rgb(236,236,236)}");
    pFolderReal->setContentWidget(pRealContent);
    QGridLayout* pLayoutReal = new QGridLayout(pRealContent);
    pLayoutReal->setMargin(50);
    pLayoutReal->setSpacing(50);
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            MyImageWidget* pImageWid = new MyImageWidget();
            pLayoutReal->addWidget(pImageWid,i,j,Qt::AlignCenter);
            m_listImageWid.append(pImageWid);
        }
    }


    MyWidgetFolder* pFolderWarning = new MyWidgetFolder("://images//实时监控图标02.png","告警信息");
    QWidget* pWarningContent = new QWidget();
    pWarningContent->setStyleSheet("QWidget{border:1px;border-radius:2px;background-color:rgb(236,236,236)}");
    pFolderWarning->setContentWidget(pWarningContent);
    QGridLayout* pLayoutWarning = new QGridLayout(pWarningContent);
    for(int i = 0 ; i < 2 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            MyImageCompareWidget* pImageWid = new MyImageCompareWidget();
            pLayoutWarning->addWidget(pImageWid,i,j,Qt::AlignCenter);
            m_listImageCompareWid.append(pImageWid);
        }
    }


    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolderReal,3);
    pMainLayout->addWidget(pFolderWarning,2);
}

void RealTimeMonitorPane::updateUIData(QList<stImageData>& list)
{
    for(int i = 0 ; i < list.count() ; ++i)
    {
        if(i < m_listImageWid.size())
        {
            m_listImageWid[i]->setData(list[i].pix,list[i].name,list[i].date,list[i].time,list[i].position);
        }
    }
}
