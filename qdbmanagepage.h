#ifndef QDBMANAGEPAGE_H
#define QDBMANAGEPAGE_H

#include "widgetbase.h"

class QDbManagePage :public WidgetBase<QWidget>
{
public:
    QDbManagePage();
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;
};

#endif // QDBMANAGEPAGE_H
