#include "faceonetonpane.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"

FaceOneToNPane::FaceOneToNPane(QWidget* parent) : QWidget(parent)
{
    initUI();
}

void FaceOneToNPane::initUI()
{
    this->setStyleSheet("FaceOneToNPane{border:none;background-color:rgb(227,227,227)}");
    MyWidgetFolder* pFolder = new MyWidgetFolder("://images//1比N小图标.png","1:N对比");
    QWidget* pContent = new QWidget();
    pFolder->setContentWidget(pContent);

    // 填充内容区

    //

    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolder,0,Qt::AlignCenter);

}
