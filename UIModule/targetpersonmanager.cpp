#include "targetpersonmanager.h"
#include "ui_targetpersonmanager.h"
#include "UIModule/Comm/mytablewidget.h"
#include "UIModule/Comm/mycheckboxheaderview.h"
#include "UIModule/addtargetpersondlg.h"
#include "UIModule/edittargetpersondlg.h"
#include "UIModule/deletetargetperson.h"

TargetPersonManager::TargetPersonManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetPersonManager)
{
    ui->setupUi(this);
    initUI();
    // test
    onBtnEditTargetPerson();
    DeleteTargetPerson dlg("确认要删除该记录，删除后将","无法恢复","？");
    dlg.exec();
}

TargetPersonManager::~TargetPersonManager()
{
    delete ui;
}

void TargetPersonManager::initUI()
{
    // 添加联系人
    ui->m_btnAddTargetPerson->setStyleSheet("QPushButton{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}"
                                   "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                                   "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}");

    // 翻页按钮
    QString m_stringStyle = "QPushButton{border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{background-color:rgb(104,180,234)}"
                       "QPushButton:pressed{background-color:rgb(4,119,182)}"
                       "QPushButton:checked{background-color:rgb(4,119,182)}";
    ui->m_btnSearch->setStyleSheet(m_stringStyle);
    ui->m_btnSelectAll->setStyleSheet(m_stringStyle);
    ui->m_btnReSelectAll->setStyleSheet(m_stringStyle);
    ui->m_btnDelete->setStyleSheet(m_stringStyle);
    ui->m_btnPageFirst->setStyleSheet(m_stringStyle);
    ui->m_btnPagePre->setStyleSheet(m_stringStyle);
    ui->m_btnPageOne->setStyleSheet(m_stringStyle);
    ui->m_btnPageOne->setCheckable(true);
    ui->m_btnPageTwo->setStyleSheet(m_stringStyle);
    ui->m_btnPageTwo->setCheckable(true);
    ui->m_btnPageThree->setStyleSheet(m_stringStyle);
    ui->m_btnPageThree->setCheckable(true);
    ui->m_btnPageFive->setStyleSheet(m_stringStyle);
    ui->m_btnPageFive->setCheckable(true);
    ui->m_btnPageNext->setStyleSheet(m_stringStyle);
    ui->m_btnPageLast->setStyleSheet(m_stringStyle);


    // 表格
    ui->m_table->verticalHeader()->setVisible(false);
    //ui->m_table->verticalHeader()->setStretchLastSection(true);
    ui->m_table->horizontalHeader()->setVisible(false);
    //ui->m_table->horizontalHeader()->setStretchLastSection(true);

    ui->m_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->m_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_table->setAlternatingRowColors(true);

    //
    ui->m_table->setColumnCount(10);
    m_iPageRowCount = 18;
    ui->m_table->setRowCount(m_iPageRowCount);
    QStringList hheader;
    hheader<<tr("")<<tr("姓名")<<tr("性别")<<tr("出生日期")<<tr("证件信息")<<tr("重要等级")<<tr("危险等级")<<tr("类型")<<tr("状态")<<tr("操作");
    MyCheckBoxHeaderView *myHeader = new MyCheckBoxHeaderView(0, Qt::Horizontal, ui->m_table);
    ui->m_table->setHorizontalHeader(myHeader);
    ui->m_table->setColumnWidth(0,29);
    for(int i = 1 ; i <10 ; ++i )
    {
        ui->m_table->setColumnWidth(i,117);
    }
    connect(myHeader,SIGNAL(checkStausChange(bool)),this,SLOT(onSlotselectAllRows(bool)));
    //

    ui->m_table->setHorizontalHeaderLabels(hheader);
    for(int i=0; i<hheader.count(); ++i)
    {
        QTableWidgetItem *item = ui->m_table->horizontalHeaderItem(i);
        item->setFont(QFont("Helvetica")); //设置字体
        item->setBackgroundColor(QColor(0,60,10)); //设置单元格背景颜色
        item->setTextColor(QColor(104, 186, 233)); //设置文字颜色
        item->setCheckState(Qt::Checked);
    }



    // 底部按钮
    connect(ui->m_btnSearch,SIGNAL(clicked(bool)),this,SLOT(onBtnSearch()));
    connect(ui->m_btnSelectAll,SIGNAL(clicked(bool)),this,SLOT(onBtnSelectAll()));
    connect(ui->m_btnReSelectAll,SIGNAL(clicked(bool)),this,SLOT(onBtnReSelectAll()));
    connect(ui->m_btnDelete,SIGNAL(clicked(bool)),this,SLOT(onBtnDelete()));
    connect(ui->m_btnPageFirst,SIGNAL(clicked(bool)),this,SLOT(onBtnPageFirst()));
    connect(ui->m_btnPagePre,SIGNAL(clicked(bool)),this,SLOT(onBtnPagePre()));
    connect(ui->m_btnPageOne,SIGNAL(clicked(bool)),this,SLOT(onBtnPage1()));
    connect(ui->m_btnPageTwo,SIGNAL(clicked(bool)),this,SLOT(onBtnPage2()));
    connect(ui->m_btnPageThree,SIGNAL(clicked(bool)),this,SLOT(onBtnPage3()));
    connect(ui->m_btnPageFive,SIGNAL(clicked(bool)),this,SLOT(onBtnPage5()));
    connect(ui->m_btnPageNext,SIGNAL(clicked(bool)),this,SLOT(onBtnPageNext()));
    connect(ui->m_btnPageLast,SIGNAL(clicked(bool)),this,SLOT(onBtnPageLast()));
    connect(ui->m_btnAddTargetPerson,SIGNAL(clicked(bool)),this,SLOT(onBtnAddTargetPerson()));
}
void TargetPersonManager::onBtnSearch()
{}
void TargetPersonManager::onBtnSelectAll()
{}
void TargetPersonManager::onBtnReSelectAll()
{}
void TargetPersonManager::onBtnDelete()
{}
void TargetPersonManager::onBtnPageFirst()
{}
void TargetPersonManager::onBtnPagePre()
{}
void TargetPersonManager::onBtnPage1()
{}
void TargetPersonManager::onBtnPage2()
{}
void TargetPersonManager::onBtnPage3()
{}
void TargetPersonManager::onBtnPage5()
{}
void TargetPersonManager::onBtnPageNext()
{}
void TargetPersonManager::onBtnPageLast()
{}
void TargetPersonManager::onBtnEdit()
{}
void TargetPersonManager::onSlotselectChanged(bool checked)
{
    if(checked) // 全选
    {}
    else // 全反选
    {}
}
void TargetPersonManager::onBtnAddTargetPerson()
{
    AddTargetPersonDlg* pDlg = new AddTargetPersonDlg(NULL);
    pDlg->show();
}
void TargetPersonManager::onBtnEditTargetPerson()
{
    EditTargetPersonDlg* pDlg = new EditTargetPersonDlg(NULL);
    pDlg->show();
}
/*
void TargetPersonManager::updateData()
{
    ui->tableWidget->clearContents();

    // 计算页数
    m_iCouPage = m_dataList.size() / 8;
    if(m_dataList.size() % 8)
    {
        ++m_iCouPage;
    }
    if(m_iCurPage > m_iCouPage)
    {
        m_iCurPage = m_iCouPage;
    }

    if(0 == m_iCouPage)
    {
        ui->startPushButton->setVisible(false);
        ui->frontPushButton->setVisible(false);
        ui->oneButton->setVisible(false);
        ui->twoButton->setVisible(false);
        ui->threeButton->setVisible(false);
        ui->buttonLabel->setVisible(false);
        ui->fiveButton->setVisible(false);
        ui->nextPushButton->setVisible(false);
        ui->endPushButton->setVisible(false);
    }
    if(1 == m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(false);
        ui->threeButton->setVisible(false);
        ui->buttonLabel->setVisible(false);
        ui->fiveButton->setVisible(false);
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }
    if(2 == m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(true);
        ui->threeButton->setVisible(false);
        ui->buttonLabel->setVisible(false);
        ui->fiveButton->setVisible(false);
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }
    if(3 == m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(true);
        ui->threeButton->setVisible(true);
        ui->buttonLabel->setVisible(false);
        ui->fiveButton->setVisible(false);
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }
    if(4 == m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(true);
        ui->threeButton->setVisible(true);
        ui->buttonLabel->setVisible(false);
        ui->fiveButton->setVisible(true);
        ui->fiveButton->setText("4");
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }
    if(5 == m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(true);
        ui->threeButton->setVisible(true);
        ui->buttonLabel->setVisible(true);
        ui->fiveButton->setVisible(true);
        ui->fiveButton->setText("5");
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }
    if(5 < m_iCouPage)
    {
        ui->startPushButton->setVisible(true);
        ui->frontPushButton->setVisible(true);
        ui->oneButton->setVisible(true);
        ui->twoButton->setVisible(true);
        ui->threeButton->setVisible(true);
        ui->buttonLabel->setVisible(true);
        ui->fiveButton->setVisible(true);
        ui->fiveButton->setText(QString("%1").arg(m_iCouPage));
        ui->nextPushButton->setVisible(true);
        ui->endPushButton->setVisible(true);
    }

    // 绑定当前页数据
    int startIndex = (m_iCurPage - 1) * 8;
    for(int i = startIndex; i < startIndex + 8 ; ++i)
    {
        if(i < m_dataList.count())
        {
            QTableWidgetItem *pItem = new QTableWidgetItem(m_dataList[i].id);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 0, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].name);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 1, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].area);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 2, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].type);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 3, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].status);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 4, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].description);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 5, pItem);

            QWidget *pWidget = new QWidget;
            pWidget->setStyleSheet("QWidget{border:none}");
            QPushButton *pEditPushButton = new QPushButton(tr("编辑"));
            pEditPushButton->setFixedSize(51, 23);
            pEditPushButton->setStyleSheet(m_stringStyle);
            QHBoxLayout *pHBoxLayout = new QHBoxLayout(pWidget);
            pHBoxLayout->addWidget(pEditPushButton, 0, Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setCellWidget(i-startIndex, 6, pWidget);

            connect(pEditPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_editButClicked()));
        }
    }
}
*/
