#include "mylineedit.h"
#include <QLabel>
#include <QHBoxLayout>

MyLineEdit::MyLineEdit(QString imagePath,QString text) :
    QLineEdit()
{
    // 加载图片
    QPixmap pixmap(imagePath);
    //QSize imageSize = pixmap.size();

    // 计算控件最小尺寸
    //int editHeight = imageSize.height() * 2;
    this->setFixedHeight(50);
    this->setTextMargins(this->height() + 10, 0, 0, 0);

    // label承载图标
    QLabel *label = new QLabel(this);
    label->setScaledContents(true);
    label->setFixedSize(30,30);
    label->setCursor(QCursor(Qt::ArrowCursor));
    label->setPixmap(pixmap);

    // 布局
    QHBoxLayout *editLayout = new QHBoxLayout();
    editLayout->addWidget(label,0,Qt::AlignCenter);
    editLayout->addStretch();
    this->setLayout(editLayout);

    // 显示默认文字
    QFont font = this->font();
    font.setPointSize(this->height() / 4);
    //font.setWeight(2);
    this->setFont(font);
    this->setText(text);


}
