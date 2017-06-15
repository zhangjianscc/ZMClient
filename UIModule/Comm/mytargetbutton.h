#ifndef MYTARGETBUTTON_H
#define MYTARGETBUTTON_H

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class MyButton :public QPushButton
{
    Q_OBJECT

public:
    explicit MyButton();
    int m_iId;
};

class MyTargetButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyTargetButton(QString text);

    void select();                      /// 按钮按下显示风格1
    void selected();                    /// 按钮按下显示风格2
    void unSelect();                    /// 按钮自由状态

    MyButton *m_pCloseButton;           /// 关闭项按钮
    QLabel *m_pNameLabel;               /// 按钮上显示的名称

protected:
    void paintEvent(QPaintEvent *event);

private:
    QLabel *m_pStatusLabel;             /// 文字"已选"
};

#endif // MYTARGETBUTTON_H
