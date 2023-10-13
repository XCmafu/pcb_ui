#ifndef QMAINPAGE_H
#define QMAINPAGE_H

#include "widgetbase.h"

class QMainPage : public WidgetBase<QWidget>
{
public:
    QMainPage();
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;
};

#endif // QMAINPAGE_H
