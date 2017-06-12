#include "faceonetonpane.h"
#include "ui_faceonetonpane.h"
#include "UIModule/Comm/mytargetbutton.h"

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

    // 开始比对按钮
    ui->m_btnBeginConpare->setStyleSheet("QPushButton{border-image:url(://images//比对btn-01.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//比对btn-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//比对btn-03.png);}");

    // 性别选择框
    ui->m_comboSex->setStyleSheet("QComboBox{border-radius:3px;background-color:rgb(255,255,255)}");
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
    ui->m_tableDestLibary->setSelectionMode(QAbstractItemView::NoSelection);
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
    ui->m_tableCompareResult->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                            "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");
}


void FaceOneToNPane::initTargetLibraryData(QStringList list)
{
    ui->m_tableDestLibary->clearContents();
    ui->m_tableDestLibary->setRowCount(list.size());


    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        MyTargetButton* pBtn = new MyTargetButton(list.at(i));
        //pWid->setData(list[i].pix,list[i].similarity,list[i].source);
        QWidget* pWid = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWid);
        pLayout->addWidget(pBtn,0,Qt::AlignHCenter);
        ui->m_tableDestLibary->setCellWidget(i,0,pWid);
        ui->m_tableDestLibary->setRowHeight(i,pWid->height() + 10);
        //ui->m_tableDestLibary->setColumnWidth(0,ui->m_tableDestLibary->width() - 2);
    }

}








