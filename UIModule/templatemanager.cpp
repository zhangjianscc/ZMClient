#include "templatemanager.h"
#include "ui_templatemanager.h"
#include "UIModule/Comm/templateitem.h"
#include "UIModule/Comm/deleteconfirmationdlg.h"
#include "addtemplatedlg.h"
#include "batchaddtemplatedlg.h"

TemplateManager::TemplateManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateManager)
{
    ui->setupUi(this);
    initUI();
    m_iCurPage = 1;
    m_iRowCount = 2;
    m_iColumnCount = 3;
    m_iTotalPage = 0;
}

TemplateManager::~TemplateManager()
{
    delete ui;
}

void TemplateManager::initUI()
{
    // 添加按钮
    QString strAddStyle = "QPushButton{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}"
                          "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                          "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}";

    ui->m_btnAddTemplate->setStyleSheet(strAddStyle);
    ui->m_btnBatchAddTemplate->setStyleSheet(strAddStyle);

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
    ui->m_table->horizontalHeader()->setVisible(false);
    ui->m_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->m_table->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->m_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_table->setAlternatingRowColors(true);
    ui->m_table->setRowCount(m_iRowCount);
    ui->m_table->setColumnCount(m_iColumnCount);
    ui->m_table->setShowGrid(false);
    ui->m_table->setFocusPolicy(Qt::NoFocus);


    // 底部按钮
    connect(ui->m_btnSearch,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnSearch()));
    connect(ui->m_btnSelectAll,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnSelectAll()));
    connect(ui->m_btnReSelectAll,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnUnSelectAll()));
    connect(ui->m_btnDelete,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnDelete()));
    connect(ui->m_btnPageFirst,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPageFirst()));
    connect(ui->m_btnPagePre,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPagePre()));
    connect(ui->m_btnPageOne,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPage1()));
    connect(ui->m_btnPageTwo,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPage2()));
    connect(ui->m_btnPageThree,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPage3()));
    connect(ui->m_btnPageFive,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPage5()));
    connect(ui->m_btnPageNext,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPageNext()));
    connect(ui->m_btnPageLast,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnPageLast()));
    connect(ui->m_btnAddTemplate,SIGNAL(clicked(bool)),this,SLOT(onSlotBtnAdd()));
    connect(ui->m_btnBatchAddTemplate,SIGNAL(clicked(bool)),this,SLOT(onSlotBatchAdd()));
}
void TemplateManager::onSlotBtnSearch()
{
    updateTemplateData();
}
void TemplateManager::onSlotBtnSelectAll()
{
    for(int i = 0 ; i < m_iRowCount ; ++i)
    {
        for(int j = 0 ; j < m_iColumnCount ; ++j)
        {
            TemplateItem* item = qobject_cast<TemplateItem*>(ui->m_table->cellWidget(i,j));
            if(item != Q_NULLPTR)
            {
                item->select();
            }
        }
    }
}
void TemplateManager::onSlotBtnUnSelectAll()
{
    for(int i = 0 ; i < m_iRowCount ; ++i)
    {
        for(int j = 0 ; j < m_iColumnCount ; ++j)
        {
            TemplateItem* item = qobject_cast<TemplateItem*>(ui->m_table->cellWidget(i,j));
            if(item != Q_NULLPTR)
            {
                item->unSelect();
            }
        }
    }
}
void TemplateManager::onSlotBtnDelete()
{
    // by ly
    DeleteConfirmationDlg* pDlg = new DeleteConfirmationDlg("确认要删除该模板，删除后将","无法恢复","？");
    if(pDlg->exec() == QDialog::Accepted)
    {
        for(int i = 0 ; i < m_iRowCount ; ++i)
        {
            for(int j = 0 ; j < m_iColumnCount ; ++j)
            {
                TemplateItem* item = qobject_cast<TemplateItem*>(ui->m_table->cellWidget(i,j));
                if(item != Q_NULLPTR)
                {
                    if(item->isSelected())
                    {
                        // 先删除数据 再刷新界面
                        // by ly  此处用唯一标示才能正常删除数据
                        // test
                        m_listData.removeAt(i* m_iColumnCount + j);
                    }
                }
            }
        }
        // 刷新界面
        updateBtnStatus();
        updateTableView();
    }
}
void TemplateManager::onSlotBtnPageFirst()
{
    m_iCurPage = 1;

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPagePre()
{
    m_iCurPage--;
    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPage1()
{
    m_iCurPage = ui->m_btnPageOne->text().toInt();

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPage2()
{
    m_iCurPage = ui->m_btnPageTwo->text().toInt();

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPage3()
{
    m_iCurPage = ui->m_btnPageThree->text().toInt();

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPage5()
{
    m_iCurPage = ui->m_btnPageFive->text().toInt();

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPageNext()
{
    m_iCurPage++;

    updateBtnStatus();
    updateTableView();
}
void TemplateManager::onSlotBtnPageLast()
{
    m_iCurPage = m_iTotalPage;

    updateBtnStatus();
    updateTableView();
}

void TemplateManager::updateTemplateData()
{
    // by ly
    m_listData.clear();
    for(int i = 0 ; i < 14 ; ++i)
    {
        TemplateData data;
        data.pix = QPixmap("://images//head2.jpg");
        data.imageName = "正面照";
        data.name = QString("宝马%1").arg(i);
        data.sex = "人妖";
        data.age = 100;
        data.identityNumber = "11112356421544";
        data.importanceLevel = "非常重要";
        data.dangersLevel = "极度危险";
        m_listData.append(data);
    }

    // 更新界面
    updateBtnStatus();
    updateTableView();
}
void TemplateManager::updateBtnStatus()
{
    // 计算页码
    int itemCount = m_listData.size();
    int pageItemCount = m_iRowCount * m_iColumnCount;

    m_iTotalPage = itemCount / pageItemCount;
    if(itemCount%pageItemCount)
    {
        ++m_iTotalPage;
    }
    m_iCurPage = m_iCurPage>m_iTotalPage?m_iTotalPage:m_iCurPage;
    m_iCurPage = m_iCurPage<1?1:m_iCurPage;


    // 更新页码标签
    if(itemCount <= pageItemCount)
    {
        ui->m_btnPageOne->setVisible(true);
        ui->m_btnPageOne->setText("1");
        ui->m_btnPageOne->setChecked(true);
        ui->m_btnPageTwo->setVisible(false);
        ui->m_btnPageThree->setVisible(false);
        ui->m_btnPageFive->setVisible(false);
        ui->m_labelPage->setVisible(false);
    }
    else if(itemCount <= pageItemCount * 2)
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
    else if(itemCount <= pageItemCount * 3)
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
    else if(itemCount <= pageItemCount * 4)
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
void TemplateManager::updateTableView()
{
    ui->m_table->clearContents();
    ui->m_table->setRowCount(m_iRowCount);
    ui->m_table->setColumnCount(m_iColumnCount);
    //
    int base = m_iRowCount * m_iColumnCount * (m_iCurPage - 1);
    for(int i = 0 ; i < m_iRowCount; ++i)
    {
        for(int j = 0 ; j < m_iColumnCount ; ++j)
        {
            int index = base + i * m_iColumnCount + j;
            if(index < m_listData.size())
            {
                TemplateItem* pItem = new TemplateItem();
                pItem->setData(m_listData[index].pix,
                               m_listData[index].imageName,
                               m_listData[index].name,
                               m_listData[index].sex,
                               m_listData[index].age,
                               m_listData[index].identityNumber,
                               m_listData[index].importanceLevel,
                               m_listData[index].dangersLevel);
                ui->m_table->setCellWidget(i,j,pItem);
            }
        }
    }
}

void TemplateManager::onSlotBtnAdd()
{
    AddTemplateDlg dlg;
    dlg.exec();
}
void TemplateManager::onSlotBatchAdd()
{
    BatchAddTemplateDlg dlg;
    dlg.exec();
}





