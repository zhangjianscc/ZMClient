#include "targetpersonmanager.h"
#include "ui_targetpersonmanager.h"
#include "UIModule/Comm/mytablewidget.h"
#include "UIModule/Comm/mycheckboxheaderview.h"
#include "UIModule/addtargetpersondlg.h"
#include "UIModule/edittargetpersondlg.h"
#include "UIModule/deletetargetperson.h"
#include "stable.h"

TargetPersonManager::TargetPersonManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetPersonManager)
{
    ui->setupUi(this);
    initUI();
    m_iCurPage = 1;
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
    m_strBtnStyle = "QPushButton{border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{background-color:rgb(104,180,234)}"
                       "QPushButton:pressed{background-color:rgb(4,119,182)}"
                       "QPushButton:checked{background-color:rgb(4,119,182)}";
    ui->m_btnSearch->setStyleSheet(m_strBtnStyle);
    ui->m_btnSelectAll->setStyleSheet(m_strBtnStyle);
    ui->m_btnReSelectAll->setStyleSheet(m_strBtnStyle);
    ui->m_btnDelete->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageFirst->setStyleSheet(m_strBtnStyle);
    ui->m_btnPagePre->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageOne->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageOne->setCheckable(true);
    ui->m_btnPageTwo->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageTwo->setCheckable(true);
    ui->m_btnPageThree->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageThree->setCheckable(true);
    ui->m_btnPageFive->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageFive->setCheckable(true);
    ui->m_btnPageNext->setStyleSheet(m_strBtnStyle);
    ui->m_btnPageLast->setStyleSheet(m_strBtnStyle);


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
    m_iPageRowCount = 15;
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
    connect(myHeader,SIGNAL(checkStausChange(bool)),this,SLOT(onSlotselectChanged(bool)));
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
    connect(ui->m_btnReSelectAll,SIGNAL(clicked(bool)),this,SLOT(onBtnUnSelectAll()));
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
{
    updatePersonData();
}
void TargetPersonManager::onBtnSelectAll()
{
    for(int i = 0 ; i < m_iPageRowCount ; ++i)
    {
        if(i < m_listCheckBox.size())
        {
            m_listCheckBox[i]->setChecked(true);
        }
    }
}
void TargetPersonManager::onBtnUnSelectAll()
{
    for(int i = 0 ; i < m_iPageRowCount ; ++i)
    {
        if(i < m_listCheckBox.size())
        {
            m_listCheckBox[i]->setChecked(false);
        }
    }
}
void TargetPersonManager::onBtnDelete()
{
    // by ly
    int curRow = ui->m_table->currentRow();
    int index = (m_iCurPage - 1) * m_iPageRowCount + curRow;
    m_listPersonData.removeAt(index);
    ui->m_table->removeRow(curRow);
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPageFirst()
{
    m_iCurPage = 1;
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPagePre()
{
    m_iCurPage--;
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPage1()
{
    m_iCurPage = ui->m_btnPageOne->text().toInt();
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPage2()
{
    m_iCurPage = ui->m_btnPageTwo->text().toInt();
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPage3()
{
    m_iCurPage = ui->m_btnPageThree->text().toInt();
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPage5()
{
    m_iCurPage = ui->m_btnPageFive->text().toInt();
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPageNext()
{
    m_iCurPage++;
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::onBtnPageLast()
{
    m_iCurPage = m_iTotalPage;
    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}

void TargetPersonManager::onSlotselectChanged(bool checked)
{
    if(checked) // 全选
    {
        onBtnSelectAll();
    }
    else // 全反选
    {
        onBtnUnSelectAll();
    }
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

void TargetPersonManager::updatePersonData()
{
    // by ly
    m_listPersonData.clear();
    for(int i = 0 ; i < 50 ; ++i)
    {
        PersonData data;
        data.name = QString("宝马%1").arg(i);
        data.sex = "人妖";
        data.birthday = "1900-04-11";
        data.identityNumber = "11112356421544";
        data.importanceLevel = "非常重要";
        data.dangersLevel = "极度危险";
        data.type = "在逃";
        data.status = "流窜中";
        m_listPersonData.append(data);
    }

    // 更新按钮状态
    updateBtnStatus();
    // 更新表格显示
    updateTableView();
}
void TargetPersonManager::updateBtnStatus()
{
    // 计算页码
    int count = m_listPersonData.size();
    m_iTotalPage = count/m_iPageRowCount;
    if(count%m_iPageRowCount)
    {
        ++m_iTotalPage;
    }
    m_iCurPage = m_iCurPage>m_iTotalPage?m_iTotalPage:m_iCurPage;
    m_iCurPage = m_iCurPage<1?1:m_iCurPage;

    // 更新页码标签
    if(count <= m_iPageRowCount)
    {
        ui->m_btnPageOne->setVisible(true);
        ui->m_btnPageOne->setText("1");
        ui->m_btnPageOne->setChecked(true);
        ui->m_btnPageTwo->setVisible(false);
        ui->m_btnPageThree->setVisible(false);
        ui->m_btnPageFive->setVisible(false);
        ui->m_labelPage->setVisible(false);
    }
    else if(count <= m_iPageRowCount * 2)
    {
        ui->m_btnPageOne->setVisible(true);
        ui->m_btnPageOne->setText("1");
        ui->m_btnPageOne->setChecked(false);

        ui->m_btnPageTwo->setVisible(true);
        ui->m_btnPageTwo->setText("2");
        ui->m_btnPageTwo->setChecked(false);

        ui->m_btnPageThree->setVisible(false);
        ui->m_btnPageFive->setVisible(false);
        ui->m_labelPage->setVisible(false);

        if(m_iCurPage == 1)
        {
            ui->m_btnPageOne->setChecked(true);
        }
        else
        {
            ui->m_btnPageTwo->setChecked(true);
        }
    }
    else if(count <= m_iPageRowCount * 3)
    {
        ui->m_btnPageOne->setVisible(true);
        ui->m_btnPageOne->setText("1");
        ui->m_btnPageOne->setChecked(false);

        ui->m_btnPageTwo->setVisible(true);
        ui->m_btnPageTwo->setText("2");
        ui->m_btnPageTwo->setChecked(false);

        ui->m_btnPageThree->setVisible(true);
        ui->m_btnPageThree->setText("3");
        ui->m_btnPageThree->setChecked(false);

        ui->m_btnPageFive->setVisible(false);
        ui->m_labelPage->setVisible(false);

        if(m_iCurPage == 1)
        {
            ui->m_btnPageOne->setChecked(true);
        }
        else if(m_iCurPage == 2)
        {
            ui->m_btnPageTwo->setChecked(true);
        }
        else
        {
            ui->m_btnPageThree->setChecked(true);
        }
    }
    else if(count <= m_iPageRowCount * 4)
    {
        ui->m_btnPageOne->setVisible(true);
        ui->m_btnPageOne->setText("1");
        ui->m_btnPageOne->setChecked(false);

        ui->m_btnPageTwo->setVisible(true);
        ui->m_btnPageTwo->setText("2");
        ui->m_btnPageTwo->setChecked(false);

        ui->m_btnPageThree->setVisible(true);
        ui->m_btnPageThree->setText("3");
        ui->m_btnPageThree->setChecked(false);

        ui->m_btnPageFive->setVisible(true);
        ui->m_btnPageFive->setText("4");
        ui->m_btnPageFive->setChecked(false);

        ui->m_labelPage->setVisible(false);

        if(m_iCurPage == 1)
        {
            ui->m_btnPageOne->setChecked(true);
        }
        else if(m_iCurPage == 2)
        {
            ui->m_btnPageTwo->setChecked(true);
        }
        else if(m_iCurPage == 3)
        {
            ui->m_btnPageThree->setChecked(true);
        }
        else
        {
            ui->m_btnPageFive->setChecked(true);
        }
    }
    else // >4页
    {
        if(m_iCurPage == 1)
        {
            ui->m_btnPageOne->setVisible(true);
            ui->m_btnPageOne->setText("1");
            ui->m_btnPageOne->setChecked(true);

            ui->m_btnPageTwo->setVisible(true);
            ui->m_btnPageTwo->setText("2");
            ui->m_btnPageTwo->setChecked(false);

            ui->m_btnPageThree->setVisible(true);
            ui->m_btnPageThree->setText("3");
            ui->m_btnPageThree->setChecked(false);

            ui->m_btnPageFive->setVisible(true);
            ui->m_btnPageFive->setText(QString::number(m_iTotalPage));
            ui->m_btnPageFive->setChecked(false);

            ui->m_labelPage->setVisible(true);
        }
        else if(m_iCurPage == 2)
        {
            ui->m_btnPageOne->setVisible(true);
            ui->m_btnPageOne->setText("1");
            ui->m_btnPageOne->setChecked(false);

            ui->m_btnPageTwo->setVisible(true);
            ui->m_btnPageTwo->setText("2");
            ui->m_btnPageTwo->setChecked(true);

            ui->m_btnPageThree->setVisible(true);
            ui->m_btnPageThree->setText("3");
            ui->m_btnPageThree->setChecked(false);

            ui->m_btnPageFive->setVisible(true);
            ui->m_btnPageFive->setText("4");
            ui->m_btnPageFive->setChecked(false);

            ui->m_labelPage->setVisible(true);
        }
        else if(m_iCurPage == 3)
        {
            ui->m_btnPageOne->setVisible(true);
            ui->m_btnPageOne->setText("1");
            ui->m_btnPageOne->setChecked(false);

            ui->m_btnPageTwo->setVisible(true);
            ui->m_btnPageTwo->setText("2");
            ui->m_btnPageTwo->setChecked(false);

            ui->m_btnPageThree->setVisible(true);
            ui->m_btnPageThree->setText("3");
            ui->m_btnPageThree->setChecked(true);

            ui->m_btnPageFive->setVisible(true);
            ui->m_btnPageFive->setText(QString::number(m_iTotalPage));
            ui->m_btnPageFive->setChecked(false);

            ui->m_labelPage->setVisible(true);
        }
        else if(m_iCurPage == m_iTotalPage)
        {
            ui->m_btnPageOne->setVisible(true);
            ui->m_btnPageOne->setText(QString::number(m_iTotalPage-3));
            ui->m_btnPageOne->setChecked(false);

            ui->m_btnPageTwo->setVisible(true);
            ui->m_btnPageTwo->setText(QString::number(m_iTotalPage-2));
            ui->m_btnPageTwo->setChecked(false);

            ui->m_btnPageThree->setVisible(true);
            ui->m_btnPageThree->setText(QString::number(m_iTotalPage-1));
            ui->m_btnPageThree->setChecked(false);

            ui->m_btnPageFive->setVisible(true);
            ui->m_btnPageFive->setText(QString::number(m_iTotalPage));
            ui->m_btnPageFive->setChecked(true);

            ui->m_labelPage->setVisible(true);
        }
        else
        {
            ui->m_btnPageOne->setVisible(true);
            ui->m_btnPageOne->setText(QString::number(m_iCurPage-2));
            ui->m_btnPageOne->setChecked(false);

            ui->m_btnPageTwo->setVisible(true);
            ui->m_btnPageTwo->setText(QString::number(m_iCurPage-1));
            ui->m_btnPageTwo->setChecked(false);

            ui->m_btnPageThree->setVisible(true);
            ui->m_btnPageThree->setText(QString::number(m_iCurPage));
            ui->m_btnPageThree->setChecked(true);

            ui->m_btnPageFive->setVisible(true);
            ui->m_btnPageFive->setText(QString::number(m_iTotalPage));
            ui->m_btnPageFive->setChecked(false);

            ui->m_labelPage->setVisible(true);
        }
    }
}
void TargetPersonManager::updateTableView()
{
    m_listButtons.clear();
    m_listCheckBox.clear();
    ui->m_table->clearContents();
    ui->m_table->setRowCount(m_iPageRowCount);
    //
    int index = m_iPageRowCount * (m_iCurPage - 1);
    for(int i = 0 ; i < m_iPageRowCount ; ++i)
    {
        if(index + i < m_listPersonData.size())
        {
            QWidget* pWid = new QWidget(ui->m_table);
            pWid->setStyleSheet("QWidget{background:rgba(0,0,0,0);border:none}");
            QHBoxLayout* playout = new QHBoxLayout(pWid);
            playout->setMargin(0);
            QCheckBox* box = new QCheckBox();
            connect(box,SIGNAL(stateChanged(int)),this,SLOT(onSlotCheckBoxChanged(int)));
            m_listCheckBox.append(box);
            playout->addWidget(box,0,Qt::AlignCenter);
            ui->m_table->setCellWidget(i,0,pWid);

            QTableWidgetItem *pItem;

            pItem = new QTableWidgetItem(m_listPersonData[index + i].name);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 1, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].sex);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 2, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].birthday);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 3, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].identityNumber);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 4, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].importanceLevel);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 5, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].dangersLevel);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 6, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].type);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 7, pItem);

            pItem = new QTableWidgetItem(m_listPersonData[index + i].status);
            pItem->setTextAlignment(Qt::AlignCenter);
            //pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->m_table->setItem(i, 8, pItem);

            QWidget* pWid2 = new QWidget(ui->m_table);
            pWid2->setStyleSheet("QWidget{background:rgba(0,0,0,0);border:none}");
            QHBoxLayout* playout2 = new QHBoxLayout(pWid2);
            playout2->setMargin(0);
            QPushButton* btn = new QPushButton("编辑");
            m_listButtons.append(btn);
            btn->setFixedSize(51, 23);
            btn->setStyleSheet(m_strBtnStyle);
            connect(btn,SIGNAL(clicked(bool)),this,SLOT(onBtnEditTargetPerson()));
            playout2->addWidget(btn,0,Qt::AlignCenter);
            ui->m_table->setCellWidget(i,9,pWid2);
        }
    }
}

void TargetPersonManager::onSlotCheckBoxChanged(int checked)
{}















