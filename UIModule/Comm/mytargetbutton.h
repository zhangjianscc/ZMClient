#ifndef MYTARGETBUTTON_H
#define MYTARGETBUTTON_H

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class MyTargetButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyTargetButton(QString text);

    void select();                      /// 按钮按下
    void selected();                    /// 按钮已选
    void unSelect();                    /// 按钮自由状态

    QPushButton *m_pCloseButton;        /// 关闭项按钮

private:
    QLabel *m_pNameLabel;               /// 按钮上显示的名称
    QLabel *m_pStatusLabel;             /// 文字"已选"
};

#endif // MYTARGETBUTTON_H
