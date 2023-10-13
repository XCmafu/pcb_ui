#ifndef QDETECTIONPAGE_H
#define QDETECTIONPAGE_H

#include "widgetbase.h"
#include <QGroupBox>
#include <QPointer>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QSlider>

#include <QHBoxLayout>
#include <QVBoxLayout>

class QDetectionPage:public WidgetBase<QWidget>
{
public:
    QDetectionPage();
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;
protected:
};

#endif // QDETECTIONPAGE_H
