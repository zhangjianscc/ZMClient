#include "faceonetoonepane.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"

FaceOneToOnePane::FaceOneToOnePane(QWidget *parent) : QWidget(parent)
{

}

void FaceOneToOnePane::initUI()
{
    this->setStyleSheet("RealTimeMonitorPane{border:none;background-color:rgb(227,227,227)}");

    MyWidgetFolder* pFolderReal = new MyWidgetFolder("://images//实时监控图标01.png","实时采集");
    QWidget* pRealContent = new QWidget();
    pFolderReal->setContentWidget(pRealContent);
    QGridLayout* pLayoutReal = new QGridLayout(pRealContent);
    //pLayoutReal->setMargin(20);
    /*
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
    */



    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolderReal);
}
