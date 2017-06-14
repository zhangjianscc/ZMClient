#include "faceonetoonepane.h"
#include "stable.h"
#include "UIModule/Comm/mywidgetfolder.h"

FaceOneToOnePane::FaceOneToOnePane(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void FaceOneToOnePane::initUI()
{
    this->setStyleSheet("FaceOneToNPane{border:none;background-color:rgb(227,227,227)}");
    MyWidgetFolder* pFolder = new MyWidgetFolder("://images//1比1对比图标.png","1:1对比");
    QWidget* pContent = new QWidget();
    pFolder->setContentWidget(pContent);

    // 填充内容区

    // 图片1
    QWidget* pWidImage1 = new QWidget();
    pWidImage1->setStyleSheet("QWidget{border:1px solid rgb(180,180,180);border-radius:5px;background:rgb(222,222,222)}");
    QLabel* pLabel1Title = new QLabel("请添加照片");
    pLabel1Title->setStyleSheet("QLabel{border:none;font: 12pt Arial;}");
    m_pLabelImage1 = new QLabel();
    m_pLabelImage1->setScaledContents(true);
    m_pLabelImage1->setFixedWidth((g_wid-g_leftNaviPaneWid)/5);
    m_pLabelImage1->setFixedHeight((g_hei-g_topMenuPaneHei)/3);
    m_pLabelImage1->setStyleSheet("QLabel{border:1px solid rgb(200,200,200);border-radius:0px;background:rgb(236,236,236)}");
    QPushButton* pBtn1 = new QPushButton();
    pBtn1->setFixedSize(m_pLabelImage1->width()/2,m_pLabelImage1->height()/4);
    connect(pBtn1,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectImage1()));
    pBtn1->setStyleSheet("QPushButton{border-image:url(://images//选择照片.png);border: 0px; border-radius: 3px;}"
                         "QPushButton:hover{border-image:url(://images//选择照片-01.png);}"
                         "QPushButton:pressed{border-image:url(://images//选择照片-02.png);}");
    QVBoxLayout* playout1 = new QVBoxLayout(pWidImage1);
    playout1->setMargin(20);
    playout1->setSpacing(5);
    playout1->addWidget(pLabel1Title,0,Qt::AlignCenter);
    playout1->addWidget(m_pLabelImage1,0,Qt::AlignCenter);
    playout1->addWidget(pBtn1,0,Qt::AlignCenter);

    // 图片2
    QWidget* pWidImage2 = new QWidget();
    pWidImage2->setStyleSheet("QWidget{border:1px solid rgb(180,180,180);border-radius:5px;background:rgb(222,222,222)}");
    QLabel* pLabel2Title = new QLabel("请添加比对照片");
    pLabel2Title->setStyleSheet("QLabel{border:none;font: 12pt Arial;}");
    m_pLabelImage2 = new QLabel();
    m_pLabelImage2->setScaledContents(true);
    m_pLabelImage2->setFixedWidth((g_wid-g_leftNaviPaneWid)/5);
    m_pLabelImage2->setFixedHeight((g_hei-g_topMenuPaneHei)/3);
    m_pLabelImage2->setStyleSheet("QLabel{border:1px solid rgb(200,200,200);border-radius:0px;background:rgb(236,236,236)}");
    QPushButton* pBtn2 = new QPushButton();
    pBtn2->setFixedSize(m_pLabelImage2->width()/2,m_pLabelImage2->height()/4);
    connect(pBtn2,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectImage2()));
    pBtn2->setStyleSheet("QPushButton{border-image:url(://images//选择照片.png);border: 0px; border-radius: 3px;}"
                         "QPushButton:hover{border-image:url(://images//选择照片-01.png);}"
                         "QPushButton:pressed{border-image:url(://images//选择照片-02.png);}");
    QVBoxLayout* playout2 = new QVBoxLayout(pWidImage2);
    playout2->setMargin(20);
    playout2->setSpacing(5);
    playout2->addWidget(pLabel2Title,0,Qt::AlignCenter);
    playout2->addWidget(m_pLabelImage2,0,Qt::AlignCenter);
    playout2->addWidget(pBtn2,0,Qt::AlignCenter);

    // 左侧区域 整合pWidImage1  pWidImage2
    QWidget* pLeftWid = new QWidget();
    pLeftWid->setStyleSheet("QWidget{border:1px solid rgb(212,212,212)}");
    QPushButton* pBtnCompare = new QPushButton();
    pBtnCompare->setFixedSize(m_pLabelImage2->width()/2 + 20,m_pLabelImage2->width()/4 + 5);
    connect(pBtnCompare,SIGNAL(clicked(bool)),this,SLOT(onSlotCompare()));
    pBtnCompare->setObjectName("btnBeginCompare");
    QWidget* pLeftHWid = new QWidget();
    pLeftHWid->setStyleSheet("QWidget{border:none}");
    QHBoxLayout* pLeftHLayout = new QHBoxLayout(pLeftHWid);
    pLeftHLayout->setSpacing(5);
    pLeftHLayout->addWidget(pWidImage1);
    pLeftHLayout->addWidget(pWidImage2);

    QVBoxLayout* pLeftLayout = new QVBoxLayout(pLeftWid);
    pLeftLayout->setContentsMargins(20,m_pLabelImage2->height()/4,20,20);
    pLeftLayout->setSpacing(10);
    pLeftLayout->addWidget(pLeftHWid,0,Qt::AlignCenter);
    pLeftLayout->addWidget(pBtnCompare,0,Qt::AlignCenter);
    pLeftLayout->addStretch();

    // 右侧区域
    QLabel* pLabelResult = new QLabel("比对结果");
    pLabelResult->setStyleSheet("QLabel{border:none;font: 16pt Arial;}");

    m_pLabelCompareIamge1 = new QLabel();
    m_pLabelCompareIamge1->setScaledContents(true);
    m_pLabelCompareIamge1->setFixedWidth((g_wid-g_leftNaviPaneWid)/7);
    m_pLabelCompareIamge1->setFixedHeight((g_hei-g_topMenuPaneHei)/3.5);
    m_pLabelCompareIamge1->setStyleSheet("QLabel{border:1px solid rgb(200,200,200);background:rgb(236,236,236)}");
    m_pLabelCompareIamge2 = new QLabel();
    m_pLabelCompareIamge2->setScaledContents(true);
    m_pLabelCompareIamge2->setFixedWidth((g_wid-g_leftNaviPaneWid)/7);
    m_pLabelCompareIamge2->setFixedHeight((g_hei-g_topMenuPaneHei)/3.5);
    m_pLabelCompareIamge2->setStyleSheet("QLabel{border:1px solid rgb(200,200,200);background:rgb(236,236,236)}");
    QWidget* pWidImage3 = new QWidget();
    QHBoxLayout* pLayout3 = new QHBoxLayout(pWidImage3);
    pLayout3->setMargin(5);
    pLayout3->setSpacing(10);
    pLayout3->addWidget(m_pLabelCompareIamge1);
    pLayout3->addWidget(m_pLabelCompareIamge2);

    QLabel* pLabel5 = new QLabel("相似度");
    m_pProSimilar = new QProgressBar();
    m_pProSimilar->setTextVisible(false);
    m_pProSimilar->setRange(0,100);
    m_pProSimilar->setFixedSize(m_pLabelCompareIamge2->width(), 10);
    m_pProSimilar->setStyleSheet("QProgressBar{border:none;border-radius:5px;background-color:rgb(178,178,178);}"
                                 "QProgressBar::chunk{border:none;border-radius:5px;background-color:rgb(255,0,0);}");
    m_pSimilarText = new QLabel("0.0%");
    QWidget* pWidSimilar = new QWidget();
    QHBoxLayout* pLayout4 = new QHBoxLayout(pWidSimilar);
    pLayout4->addWidget(pLabel5);
    pLayout4->addWidget(m_pProSimilar);
    pLayout4->addWidget(m_pSimilarText);

    QWidget* pRightWid = new QWidget();
    pRightWid->setStyleSheet("QWidget{border:none}");
    QVBoxLayout* pRightLayout = new QVBoxLayout(pRightWid);
    pRightLayout->setContentsMargins(20,m_pLabelImage2->height()/4 + (m_pLabelImage2->height() - m_pLabelCompareIamge1->height())/2,20,20);
    pRightLayout->setSpacing(20);
    pRightLayout->addWidget(pLabelResult,0,Qt::AlignHCenter);
    pRightLayout->addWidget(pWidImage3,0,Qt::AlignCenter);
    pRightLayout->addWidget(pWidSimilar,0,Qt::AlignHCenter | Qt::AlignTop);
    pRightLayout->addStretch();


    //
    QHBoxLayout* pContentLayout = new QHBoxLayout(pContent);
    pContentLayout->setMargin(0);
    pContentLayout->setSpacing(0);
    pContentLayout->addWidget(pLeftWid);
    pContentLayout->addWidget(pRightWid);


    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(10,20,10,20);
    pMainLayout->setSpacing(10);
    pMainLayout->addWidget(pFolder);
}

void FaceOneToOnePane::onSlotSelectImage1()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        m_strImagePath1 = fileName;
        QPixmap pix(m_strImagePath1);
        m_pLabelImage1->setPixmap(pix);
    }
}

void FaceOneToOnePane::onSlotSelectImage2()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        m_strImagePath2 = fileName;
        QPixmap pix(m_strImagePath2);
        m_pLabelImage2->setPixmap(pix);
    }
}

void FaceOneToOnePane::onSlotCompare()
{
    // by ly
    m_dSimilarValue = 0.75325;

    // by ly end
    updateCompareResultPane();
}

void FaceOneToOnePane::updateCompareResultPane()
{
    int value = m_dSimilarValue * 100;
    value = value < 0?0:value;
    value = value > 100?100:value;

    m_pProSimilar->setValue(value);
    m_pSimilarText->setText(QString("%1%").arg(m_dSimilarValue * 100));

    m_pLabelCompareIamge1->setPixmap(QPixmap(m_strImagePath1));
    m_pLabelCompareIamge2->setPixmap(QPixmap(m_strImagePath2));
}
