#ifndef MONITORDEVICEMAINTAIN_H
#define MONITORDEVICEMAINTAIN_H

#include <QWidget>

struct Device
{
    QString id;             /// 设备编号
    QString name;           /// 设备名称
    QString number;         /// 设备型号
    QString ip;             /// IP地址
    QString addr;           /// 行政区划
    QString area;           /// 监控区域
    QString position;       /// 监控位置
    QString status;         /// 状态
};

namespace Ui {
class MonitorDeviceMaintain;
}

class MonitorDeviceMaintain : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorDeviceMaintain(QWidget *parent = 0);
    ~MonitorDeviceMaintain();

public slots:
    void slot_searchButClicked();   /// 搜索
    void slot_addButClicked();      /// 添加区域
    void slot_editButClicked();     /// 编辑
    void slot_allSelButClicked();   /// 全选
    void slot_allCleButClicked();   /// 反选
    void slot_deleteButClicked();   /// 删除
    void slot_startButClicked();    /// "<<"
    void slot_frontButClicked();    /// "<"
    void slot_oneButClicked();      /// "1"
    void slot_twoButClicked();      /// "2"
    void slot_threeButClicked();    /// "3"
    void slot_fiveButClicked();     /// "5"
    void slot_nextButClicked();     /// ">"
    void slot_endButClicked();      /// ">>"

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MonitorDeviceMaintain *ui;

    void initUi();                      /// 初始化界面
    void updateData();                  /// 更新列表数据显示

    QList<Device> m_dataList;           /// 搜索匹配到的数据缓存

    QString m_stringStyle;              ///
    int m_iCurPage;                     /// 当前页数，从1开始
    int m_iCouPage;                     /// 总页数
};

#endif // MONITORDEVICEMAINTAIN_H
