#ifndef QIMAGEVIEWER_H
#define QIMAGEVIEWER_H

#include "widgetbase.h"
#include <QLabel>
#include <QPointer>

#include <QVBoxLayout>
#include <QHBoxLayout>

class QImageViewer : public WidgetBase<QWidget>
{
public:
    QImageViewer(QWidget* parent=nullptr);
public:
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;

    void setImage(const QImage& image);
protected:
    QPointer<QLabel>    m_labelImage;       //展示用图像
};

#endif // QIMAGEVIEWER_H
