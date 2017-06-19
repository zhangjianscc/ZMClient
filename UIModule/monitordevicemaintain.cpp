#include "monitordevicemaintain.h"
#include "ui_monitordevicemaintain.h"
#include "addmonitordevicedialog.h"
#include "editmonitordevicedialog.h"
#include "warningdisdelsuredialog.h"
#include "Comm/mycheckboxheaderview.h"

MonitorDeviceMaintain::MonitorDeviceMaintain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorDeviceMaintain)
{
    ui->setupUi(this);

    m_iCurPage = 1;
    m_iCouPage = 0;
    m_dataList.clear();

    initUi();
}

MonitorDeviceMaintain::~MonitorDeviceMaintain()
{
    delete ui;
}

void MonitorDeviceMaintain::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void MonitorDeviceMaintain::initUi()
{
    /// 按钮样式
    ui->addPushButton->setStyleSheet("QPushButton{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}"
                                   "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                                   "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}");

    m_stringStyle = "QPushButton{background-color:qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));border: 1px solid rgb(124, 124, 124);border-radius:5px}"
                     "QPushButton:hover{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));border-radius:5px;border: 1px solid #3C80B1}"
                     "QPushButton:pressed{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));border-radius:5px;border: 1px solid #5F92B2}";
    ui->searchPushButton->setStyleSheet(m_stringStyle);
    ui->allSelPushButton->setStyleSheet(m_stringStyle);
    ui->allClePushButton->setStyleSheet(m_stringStyle);
    ui->deletePushButton->setStyleSheet(m_stringStyle);
    ui->startPushButton->setStyleSheet(m_stringStyle);
    ui->frontPushButton->setStyleSheet(m_stringStyle);
    ui->oneButton->setStyleSheet(m_stringStyle);
    ui->twoButton->setStyleSheet(m_stringStyle);
    ui->threeButton->setStyleSheet(m_stringStyle);
    ui->fiveButton->setStyleSheet(m_stringStyle);
    ui->nextPushButton->setStyleSheet(m_stringStyle);
    ui->endPushButton->setStyleSheet(m_stringStyle);

    /// 数据列表显示区
    ui->tableWidget->verticalHeader()->setVisible(false);

    MyCheckBoxHeaderView *myCheckBoxHeaderView = new MyCheckBoxHeaderView(0, Qt::Horizontal, ui->tableWidget);
    ui->tableWidget->setHorizontalHeader(myCheckBoxHeaderView);
    connect(myCheckBoxHeaderView, SIGNAL(checkStausChange(bool)), this, SLOT(slot_allSelButClicked()));

    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setColumnCount(10);
    QStringList stringList;
    stringList.clear();
    stringList << "" << "设备编号" << "设备名称" << "设备型号" << "IP地址" << "行政区划" << "监控区域" << "监控位置" << "状态" << "操作";
    ui->tableWidget->setHorizontalHeaderLabels(stringList);
    for(int i=0; i<stringList.count(); ++i)
    {
        ui->tableWidget->horizontalHeaderItem(i)->setTextColor(QColor(18, 132, 255));
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /// 页面按钮布局
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(ui->buttonWidget);
    pHBoxLayout->setMargin(0);
    pHBoxLayout->setSpacing(10);
    pHBoxLayout->addWidget(ui->startPushButton);
    pHBoxLayout->addWidget(ui->frontPushButton);
    pHBoxLayout->addWidget(ui->oneButton);
    pHBoxLayout->addWidget(ui->twoButton);
    pHBoxLayout->addWidget(ui->threeButton);
    pHBoxLayout->addWidget(ui->buttonLabel);
    pHBoxLayout->addWidget(ui->fiveButton);
    pHBoxLayout->addWidget(ui->nextPushButton);
    pHBoxLayout->addWidget(ui->endPushButton);

    ui->startPushButton->setVisible(false);
    ui->frontPushButton->setVisible(false);
    ui->oneButton->setVisible(false);
    ui->twoButton->setVisible(false);
    ui->threeButton->setVisible(false);
    ui->buttonLabel->setVisible(false);
    ui->fiveButton->setVisible(false);
    ui->nextPushButton->setVisible(false);
    ui->endPushButton->setVisible(false);

    connect(ui->searchPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_searchButClicked()));
    connect(ui->addPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_addButClicked()));
    connect(ui->allSelPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_allSelButClicked()));
    connect(ui->allClePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_allCleButClicked()));
    connect(ui->deletePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_deleteButClicked()));
    connect(ui->startPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_startButClicked()));
    connect(ui->frontPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_frontButClicked()));
    connect(ui->oneButton, SIGNAL(clicked(bool)), this, SLOT(slot_oneButClicked()));
    connect(ui->twoButton, SIGNAL(clicked(bool)), this, SLOT(slot_twoButClicked()));
    connect(ui->threeButton, SIGNAL(clicked(bool)), this, SLOT(slot_threeButClicked()));
    connect(ui->fiveButton, SIGNAL(clicked(bool)), this, SLOT(slot_fiveButClicked()));
    connect(ui->nextPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_nextButClicked()));
    connect(ui->endPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_endButClicked()));
}

void MonitorDeviceMaintain::updateData()
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
            QWidget *pCheckBoxWidget = new QWidget;
            QCheckBox *pCheckBox = new QCheckBox;
            QHBoxLayout *pCheckBoxLayout = new QHBoxLayout(pCheckBoxWidget);
            pCheckBoxLayout->addWidget(pCheckBox, 0, Qt::AlignCenter);
            ui->tableWidget->setCellWidget(i-startIndex, 0, pCheckBoxWidget);

            QTableWidgetItem *pItem = new QTableWidgetItem(m_dataList[i].id);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 1, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].name);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 2, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].number);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 3, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].ip);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 4, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].addr);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 5, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].area);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 6, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].position);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 7, pItem);

            pItem = new QTableWidgetItem(m_dataList[i].status);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i-startIndex, 8, pItem);

            QWidget *pWidget = new QWidget;
            pWidget->setStyleSheet("QWidget{border:none}");
            QPushButton *pEditPushButton = new QPushButton(tr("编辑"));
            pEditPushButton->setFixedSize(51, 23);
            pEditPushButton->setStyleSheet(m_stringStyle);
            QHBoxLayout *pHBoxLayout = new QHBoxLayout(pWidget);
            pHBoxLayout->addWidget(pEditPushButton, 0, Qt::AlignCenter);
            pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setCellWidget(i-startIndex, 9, pWidget);

            connect(pEditPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_editButClicked()));
        }
    }
}

void MonitorDeviceMaintain::slot_searchButClicked()
{
    Device device;
    device.addr = ui->addrComboBox->currentText();
    device.name = ui->deviceNameLineEdit->text();
    device.number = ui->deviceNumberLlineEdit->text();
    device.area = ui->areaComboBox->currentText();
    device.position = ui->positionComboBox->currentText();
    device.status = ui->statusComboBox->currentText();

    //…

    /// 测试代码
    device.id = "TC1301230182";
    device.name = "一号机";
    device.number = "TC1301230182";
    device.ip = "192.168.0.156";
    device.addr = "四川省成都市高新区";
    device.area = "第九区";
    device.position = "第九区第二街道";
    device.status = "使用中";
    for(int i=0; i<50; ++i)
    {
        m_dataList.append(device);
    }

    updateData();
}

void MonitorDeviceMaintain::slot_addButClicked()
{
    AddMonitorDeviceDialog addMonitorDeviceDialog;
    addMonitorDeviceDialog.exec();
}

void MonitorDeviceMaintain::slot_editButClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton*>(sender());

    EditMonitorDeviceDialog editMonitorDeviceDialog;
    editMonitorDeviceDialog.exec();
}

void MonitorDeviceMaintain::slot_allSelButClicked()
{
    /// 测试代码
    //WarningDisMonAreaDialog warningDisMonAreaDialog;
    WarningDisDelSureDialog *warningDisMonAreaDialog = new WarningDisDelSureDialog(tr("记录，删除后将<font color=#ff0000 size=3>无法恢复</font>"));
    warningDisMonAreaDialog->exec();
}

void MonitorDeviceMaintain::slot_allCleButClicked()
{}

void MonitorDeviceMaintain::slot_deleteButClicked()
{
    QTableWidgetItem *pItem = ui->tableWidget->currentItem();
    if(Q_NULLPTR == pItem)  return;

    m_dataList.removeAt((m_iCurPage - 1) * 8 + pItem->row());
    updateData();
}

void MonitorDeviceMaintain::slot_startButClicked()
{
    m_iCurPage = 1;

    updateData();
}

void MonitorDeviceMaintain::slot_frontButClicked()
{
    if(1 == m_iCurPage) return;

    --m_iCurPage;
    updateData();
}

void MonitorDeviceMaintain::slot_oneButClicked()
{
    m_iCurPage = 1;

    updateData();
}

void MonitorDeviceMaintain::slot_twoButClicked()
{
    m_iCurPage = 2;

    updateData();
}

void MonitorDeviceMaintain::slot_threeButClicked()
{
    m_iCurPage = 3;

    updateData();
}

void MonitorDeviceMaintain::slot_fiveButClicked()
{
    m_iCurPage = ui->fiveButton->text().toInt();

    updateData();
}

void MonitorDeviceMaintain::slot_nextButClicked()
{
    if(m_iCouPage == m_iCurPage) return;

    ++m_iCurPage;
    updateData();
}

void MonitorDeviceMaintain::slot_endButClicked()
{
    m_iCurPage = m_iCouPage;

    updateData();
}

