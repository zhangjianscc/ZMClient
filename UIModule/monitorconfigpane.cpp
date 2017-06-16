#include "monitorconfigpane.h"
#include "ui_monitorconfigpane.h"
#include "Comm/mytargetbutton.h"

MonitorConfigPane::MonitorConfigPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorConfigPane)
{
    ui->setupUi(this);

    m_listString.clear();
    m_listSelButton.clear();

    initUi();
}

MonitorConfigPane::~MonitorConfigPane()
{
    delete ui;
}

void MonitorConfigPane::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void MonitorConfigPane::initUi()
{
    /// 显示数量下拉项
    for(int i=0; i<50; ++i)
    {
        ui->comboBox->addItem(QString("%1").arg(i + 1));
    }

    ///
    ui->roundProBarWidget->setNullPosition(QRoundProgressBar::PositionTop);
    ui->roundProBarWidget->setDecimals(0);
    //QGradientStops gradientPoints;
    //gradientPoints << QGradientStop(0, Qt::red) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    //ui->roundProBarWidget->setDataColors(gradientPoints);

    /// 搜索框
    ui->searchPushButton->setStyleSheet("QPushButton{border:none;border-image:url(://images//search-02.png);background-color:rgb(255,255,255);}"
                                      "QPushButton:hover{border-image:url(://images//search-01.png)}"
                                      "QPushButton:pressed{border-image:url(://images//search-02.png)}");

    /// 选择目标库区域
    ui->selectTarConTableWidget->horizontalHeader()->setVisible(false);
    ui->selectTarConTableWidget->verticalHeader()->setVisible(false);
    ui->selectTarConTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->selectTarConTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->selectTarConTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->selectTarConTableWidget->setShowGrid(false);
    ui->selectTarConTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->selectTarConTableWidget->setFocusPolicy(Qt::NoFocus);
    ui->selectTarConTableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                                    "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");

    /// 已选择目标库区域
    ui->selectedTarConTableWidget->horizontalHeader()->setVisible(false);
    ui->selectedTarConTableWidget->verticalHeader()->setVisible(false);
    ui->selectedTarConTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->selectTarConTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->selectedTarConTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->selectedTarConTableWidget->setShowGrid(false);
    ui->selectedTarConTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->selectedTarConTableWidget->setFocusPolicy(Qt::NoFocus);
    ui->selectedTarConTableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{border:none;width:10px;background:rgb(236,236,236)}"
                                                                    "QScrollBar::handle{border:none;border-radius:5px;width:10px;background:rgb(178,178,178);}");

    ui->savePushButton->setStyleSheet("QPushButton{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}"
                                      "QPushButton:hover{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,255)}"
                                      "QPushButton:pressed{color:rgb(255,255,255); border:1px; border-radius:5px;background-color:rgb(18,132,194)}");

    connect(ui->heighSpinBox, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged()));
    connect(ui->lowSpinBox, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged()));
    connect(ui->searchPushButton, SIGNAL(clicked(bool)), this, SLOT(slot_searchButClicked()));
    connect(ui->savePushButton, SIGNAL(clicked(bool)), this, SLOT(slot_saveButClicked()));
}

void MonitorConfigPane::updateSelectData(QList<QString> &listString)
{
    ui->selectTarConTableWidget->clear();

    ui->selectTarConTableWidget->setColumnCount(3);
    ui->selectTarConTableWidget->setRowCount(listString.count()/3 + listString.count()%3);

    for(int i=0; i<listString.count(); ++i)
    {
        MyTargetButton *pButton = new MyTargetButton(listString[i]);
        pButton->m_pCloseButton->m_iId = i + 1;
        QWidget *pWidget = new QWidget;
        pWidget->setStyleSheet("QWidget{border:none}");
        QHBoxLayout *pHboxLayout = new QHBoxLayout(pWidget);
        pHboxLayout->setMargin(0);
        pHboxLayout->addWidget(pButton, 0, Qt::AlignHCenter);
        ui->selectTarConTableWidget->setCellWidget(i/3, i%3, pWidget);
        ui->selectTarConTableWidget->setRowHeight(i/3, pButton->height()+4);

        connect(pButton, SIGNAL(clicked(bool)), this, SLOT(slot_buttonClicked()));
    }
}

void MonitorConfigPane::updateSelectedData()
{
    ui->selectedTarConTableWidget->clear();

    ui->selectedTarConTableWidget->setColumnCount(3);
    ui->selectedTarConTableWidget->setRowCount(m_listSelButton.count()/3 + m_listSelButton.count()%3);

    for(int i=0; i<m_listSelButton.count(); ++i)
    {
        MyTargetButton *pButton = new MyTargetButton(m_listSelButton[i]->m_pNameLabel->text());
        pButton->m_pCloseButton->m_iId = m_listSelButton[i]->m_pCloseButton->m_iId;
        QWidget *pWidget = new QWidget;
        pWidget->setStyleSheet("QWidget{border:none}");
        QHBoxLayout *pHboxLayout = new QHBoxLayout(pWidget);
        pHboxLayout->setMargin(0);
        pHboxLayout->addWidget(pButton, 0, Qt::AlignHCenter);
        ui->selectedTarConTableWidget->setCellWidget(i/3, i%3, pWidget);
        ui->selectedTarConTableWidget->setRowHeight(i/3, pButton->height()+4);

        pButton->selected();

        connect(pButton->m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(slot_closeButClicked()));
    }
}

void MonitorConfigPane::loadInfo(QList<QString> &listName)
{
    m_listString = listName;

    updateSelectData(m_listString);
}

void MonitorConfigPane::slot_valueChanged()
{
    int iValue = ui->heighSpinBox->value() * 10 + ui->lowSpinBox->value();
    ui->roundProBarWidget->setValue(iValue);
}

void MonitorConfigPane::slot_buttonClicked()
{
    MyTargetButton *pButton = qobject_cast<MyTargetButton*>(sender());
    if(Q_NULLPTR == pButton)
    {
        return;
    }
    else
    {
        if(pButton->isChecked())
        {
            pButton->select();

            m_listSelButton.append(pButton);
        }
        else
        {

            pButton->unSelect();

            for(int i=0; i<m_listSelButton.count(); ++i)
            {
                if(pButton->m_pCloseButton->m_iId == m_listSelButton[i]->m_pCloseButton->m_iId)
                {
                    m_listSelButton.removeAt(i);
                }
            }
        }
    }

    updateSelectedData();
}

void MonitorConfigPane::slot_closeButClicked()
{
    MyButton *pButton = qobject_cast<MyButton*>(sender());
    if(Q_NULLPTR == pButton)
    {
        return;
    }
    else
    {
        for(int i=0; i<m_listSelButton.count(); ++i)
        {
            if(pButton->m_iId == m_listSelButton[i]->m_pCloseButton->m_iId)
            {
                m_listSelButton[i]->setChecked(false);
                m_listSelButton[i]->unSelect();

                m_listSelButton.removeAt(i);
            }
        }
    }

    updateSelectedData();
}

void MonitorConfigPane::slot_searchButClicked()
{
    if(Q_NULLPTR != ui->searchLineEdit->text())
    {
        QList<QString> tempList;
        tempList.clear();
        for(int i=0; i<m_listString.count(); ++i)
        {
            if(ui->searchLineEdit->text() == m_listString[i])
            {
                tempList.append(m_listString[i]);
            }
        }

        updateSelectData(tempList);
    }
    else
    {
        updateSelectData(m_listString);
    }
}

void MonitorConfigPane::slot_saveButClicked()
{}
