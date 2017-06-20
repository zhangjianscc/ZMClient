#include "edittargetpersondlg.h"
#include "ui_edittargetperson.h"
#include "UIModule/Comm/targetpersonimageitem.h"
#include "UIModule/addtargetpersonimagedlg.h"

EditTargetPersonDlg::EditTargetPersonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTargetPerson)
{
    ui->setupUi(this);
    initUI();
    // test by ly
    QList<ImageItemData> list;
    for(int i = 1 ; i < 7 ; ++i)
    {
        ImageItemData data;
        data.pix = QPixmap("://images//head2.jpg");
        data.name = QString("沃尔沃%1").arg(i);
        list.append(data);
    }
    initPersonImages(list);
}

EditTargetPersonDlg::~EditTargetPersonDlg()
{
    delete ui;
}

void EditTargetPersonDlg::initUI()
{
    // 去除窗口标题栏 设置圆角对话框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    //
    QString btnStyle = "QPushButton{font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(180,180,180)}"
                       "QPushButton:hover{color:rgb(255,255,255);background-color:rgb(4,119,182)}"
                       "QPushButton:pressed{color:rgb(255,255,255);background-color:rgb(4,119,182)}";
    ui->m_btnSave->setStyleSheet(btnStyle);
    ui->m_btnCancel->setStyleSheet(btnStyle);

    // 关闭按钮
    ui->m_btnClose->setStyleSheet("QPushButton{border-image:url(://images//弹窗X选.png);border: 0px;border-radius: 0px;}"
                                              "QPushButton:hover{border-image:url(://images//弹窗X选-02.png);}"
                                              "QPushButton:pressed{border-image:url(://images//弹窗X选-02.png);}");
    connect(ui->m_btnClose,SIGNAL(clicked(bool)),this,SLOT(onSlotClose()));

    // 添加照片
    QString addStyle = "QPushButton{color:rgb(255,255,255);font: 14pt \"黑体\";border: none;border-radius: 2px;background-color:rgb(76,76,76)}"
                       "QPushButton:hover{background-color:rgb(30,30,30)}"
                       "QPushButton:pressed{background-color:rgb(30,30,30)}";
    ui->m_btnAddImage->setStyleSheet(addStyle);
    connect(ui->m_btnAddImage,SIGNAL(clicked(bool)),this,SLOT(onSlotAddImage()));

    // 表格
    ui->m_table->verticalHeader()->setVisible(false);
    ui->m_table->verticalHeader()->setStretchLastSection(true);
    ui->m_table->horizontalHeader()->setVisible(false);
    ui->m_table->horizontalHeader()->setStretchLastSection(true);
    ui->m_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->m_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->m_table->setSelectionMode(QAbstractItemView::NoSelection);
    ui->m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_table->setFocusPolicy(Qt::NoFocus);
    ui->m_table->setShowGrid(false);
}

void EditTargetPersonDlg::onSlotClose()
{
    this->close();
}

void EditTargetPersonDlg::initPersonImages(QList<ImageItemData> list)
{
    // 初始化表格
    ui->m_table->clearContents();
    ui->m_table->setColumnCount(2);
    ui->m_table->setRowCount(list.size() / 2 + list.size() % 2);

    // 添加数据
    for(int i = 0 ; i < list.size() ; ++i)
    {
        TargetPersonImageItem* pItem = new TargetPersonImageItem();
        pItem->setData(list[i].pix,list[i].name);
        QWidget* pWid = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWid);
        pLayout->setMargin(0);
        pLayout->addWidget(pItem,0,Qt::AlignCenter);
        int hei = pItem->height() + 10;
        ui->m_table->setRowHeight(i/2,hei);
        ui->m_table->setCellWidget(i/2,i%2,pWid);
    }
}

void EditTargetPersonDlg::onSlotAddImage()
{
    AddTargetPersonImageDlg* pDlg = new AddTargetPersonImageDlg();
    pDlg->show();
}

void EditTargetPersonDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= 35)
    {
        m_bIsMoveing = true;
        this->m_curWindowPos = this->pos();
        this->m_curMousePos = event->globalPos();
        this->m_destWindowPos = m_curMousePos - m_curWindowPos;
    }
}

void EditTargetPersonDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMoveing)
    {
        this->move(event->globalPos() - this->m_destWindowPos);
    }
}

void EditTargetPersonDlg::mouseReleaseEvent(QMouseEvent *event)
{
    m_bIsMoveing = false;
}
