#ifndef FACEONETOONEPANE_H
#define FACEONETOONEPANE_H

#include <QWidget>
class QLabel;
class QProgressBar;
class FaceOneToOnePane : public QWidget
{
    Q_OBJECT
public:
    explicit FaceOneToOnePane(QWidget *parent = 0);
private:
    void initUI();                   /// 初始化界面
    void updateCompareResultPane();  /// 更新比较界面
private:
    QLabel* m_pLabelImage1;          /// 图片1
    QLabel* m_pLabelImage2;          /// 图片2
    QProgressBar* m_pProSimilar;     /// 相似度进度条
    QString m_strImagePath1;         /// 图片1路径
    QString m_strImagePath2;         /// 图片2路径
    double  m_dSimilarValue;         /// 相似度
    QLabel* m_pSimilarText;          /// 相似度label
    QLabel* m_pLabelCompareIamge1;
    QLabel* m_pLabelCompareIamge2;

signals:

public slots:
    void onSlotSelectImage1();       /// 选择图片1
    void onSlotSelectImage2();       /// 选择图片2
    void onSlotCompare();            /// 按钮 开始比较
};

#endif // FACEONETOONEPANE_H
