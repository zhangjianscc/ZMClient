#include "faceonetonpane.h"
#include "ui_faceonetonpane.h"
#include "UIModule/Comm/mytargetbutton.h"
#include "UIModule/Comm/mycomparedimage.h"
#include "UIModule/Comm/mysearchedit.h"

FaceOneToNPane::FaceOneToNPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceOneToNPane)
{
    ui->setupUi(this);
    initUI();
    QStringList list;
    // by ly
    list<<"全国通缉犯库1"<<"全国通缉犯库2"<<"全国通缉犯库3"<<"全国通缉犯库4"<<"全国通缉犯库5"<<"全国通缉犯库6";
    list<<"全国通缉犯库1"<<"全国通缉犯库2"<<"全国通缉犯库3"<<"全国通缉犯库4"<<"全国通缉犯库5"<<"全国通缉犯库6";
    list<<"全国通缉犯库1"<<"全国通缉犯库2"<<"全国通缉犯库3"<<"全国通缉犯库4"<<"全国通缉犯库5"<<"全国通缉犯库6";
    initTargetLibraryData(list);

}

FaceOneToNPane::~FaceOneToNPane()
{
    delete ui;
}

void FaceOneToNPane::initUI()
{
    // 选择照片按钮
    ui->m_btnSelectImage->setStyleSheet("QPushButton{border-image:url(://images//选择照片.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//选择照片-01.png);}"
                                              "QPushButton:pressed{border-image:url(://images//选择照片-02.png);}");
    connect(ui->m_btnSelectImage,SIGNAL(clicked(bool)),this,SLOT(onSlotSelectImage()));

    // 开始比对按钮btnBeginCompare
    ui->btnBeginCompare->setText("");
    connect(ui->btnBeginCompare,SIGNAL(clicked(bool)),this,SLOT(onSlotBeginCompare()));

    // 性别选择框
    //ui->m_comboSex->setStyleSheet("QComboBox{border-radius:3px;background-color:rgb(255,255,255)}");
    ui->m_comboSex->addItem("请选择");
    ui->m_comboSex->addItem("男");
    ui->m_comboSex->addItem("女");
    ui->m_comboSex->setCurrentIndex(0);

    // 目标库table
    ui->m_tableDestLibary->horizontalHeader()->setVisible(false);
    ui->m_tableDestLibary->verticalHeader()->setVisible(false);
    ui->m_tableDestLibary->setColumnCount(1);
    ui->m_tableDestLibary->setShowGrid(false);
    ui->m_tableDestLibary->horizontalHeader()->setStretchLastSection(true);
    ui->m_tableDestLibary->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_tableDestLibary->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->m_tableDestLibary->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_tableDestLibary->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");

    // 比对结果table
    ui->m_tableCompareResult->horizontalHeader()->setVisible(false);
    ui->m_tableCompareResult->verticalHeader()->setVisible(false);
    ui->m_tableCompareResult->setColumnCount(2);
    ui->m_tableCompareResult->setShowGrid(false);
    ui->m_tableCompareResult->horizontalHeader()->setStretchLastSection(true);
    ui->m_tableCompareResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_tableCompareResult->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->m_tableCompareResult->setSelectionMode(QAbstractItemView::NoSelection);
    ui->m_tableCompareResult->setFocusPolicy(Qt::NoFocus);
    ui->m_tableCompareResult->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");
    // 搜索框
    ui->m_editSearch->setTextMargins(5, 0, 40, 0);
    ui->m_editSearch->setStyleSheet("QLineEdit{border:1px solid rgb(180,180,180);background-color:rgb(255,255,255)}");
    QPushButton* pSearchBtn = new QPushButton();
    pSearchBtn->setFixedSize(20,20);
    pSearchBtn->setStyleSheet("QPushButton{border:none;border-image:url(://images//search-02.png);background-color:rgb(255,255,255);}"
                              "QPushButton:hover{border-image:url(://images//search-01.png)}"
                              "QPushButton:pressed{border-image:url(://images//search-02.png)}");
    connect(pSearchBtn,SIGNAL(clicked(bool)),this,SLOT(onSlotSearchBtnClicked()));
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,10,0);
    layout->addStretch();
    layout->addWidget(pSearchBtn,0,Qt::AlignCenter);
    ui->m_editSearch->setLayout(layout);

    // 显示比对结果数选择框
    ui->m_comboMaxDisplayCount->addItem("请选择");
    for(int i = 1 ; i < 11 ; ++i)
    {
        ui->m_comboMaxDisplayCount->addItem(QString::number(i));
    }
    ui->m_comboMaxDisplayCount->setCurrentIndex(0);
}


void FaceOneToNPane::initTargetLibraryData(QStringList list)
{
    ui->m_tableDestLibary->clearContents();
    ui->m_tableDestLibary->setColumnCount(1);
    ui->m_tableDestLibary->setRowCount(list.size());


    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MyTargetButton* pBtn = new MyTargetButton(list.at(i));
        QWidget* pWid = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWid);
        pLayout->setMargin(0);
        pLayout->addWidget(pBtn,0,Qt::AlignHCenter);
        ui->m_tableDestLibary->setCellWidget(i,0,pWid);
        ui->m_tableDestLibary->setRowHeight(i,pBtn->height() + 3);

        connect(pBtn, SIGNAL(clicked(bool)), this, SLOT(slot_test()));
    }
}


void FaceOneToNPane::initComparedImageData(QList<ComparedImageInfo> list)
{
    // 初始化表格
    ui->m_tableCompareResult->clearContents();
    ui->m_tableCompareResult->setColumnCount(2);
    ui->m_tableCompareResult->setColumnWidth(0,ui->m_tableCompareResult->width()/2);
    ui->m_tableCompareResult->setColumnWidth(1,ui->m_tableCompareResult->width()/2);
    ui->m_tableCompareResult->setRowCount(list.size()/2 + list.size()%2);

    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MyComparedImage* pImage = new MyComparedImage();
        pImage->setData(list[i].pix,list[i].source,list[i].similar);
        int hei = pImage->height() + 10;
        ui->m_tableCompareResult->setRowHeight(i/2,hei);
        ui->m_tableCompareResult->setCellWidget(i/2,i%2,pImage);
    }
}

void FaceOneToNPane::onSlotBeginCompare()
{
    // by ly
    QList<ComparedImageInfo> listImage;
    for(int i = 1 ; i < 12 ; ++i)
    {
        ComparedImageInfo info;
        info.pix = QPixmap("://images//head2.jpg");
        info.source = QString("全国失踪人口库%1").arg(i);
        info.similar = 0.128 * i;
        listImage.append(info);
    }
    initComparedImageData(listImage);
}

void FaceOneToNPane::onSlotSelectImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择照片"), " ",  tr("Allfile(*.*);;jpg(*.jpg)"));
    if(fileName != "")
    {
        QPixmap pix(fileName);
        ui->m_labelImage->setPixmap(pix);
    }
}

void FaceOneToNPane::onSlotSearchBtnClicked()
{
    // by ly
    QString str = ui->m_editSearch->text();
    // initTargetLibraryData(QStringList list)
}

void FaceOneToNPane::slot_test()
{
    MyTargetButton *pushButton = qobject_cast<MyTargetButton*>(sender());
    if(Q_NULLPTR == pushButton)
    {
        return;
    }
    else
    {
        if(pushButton->isChecked())
        {
            pushButton->select();
        }
        else
        {
            pushButton->unSelect();
        }
    }
}
