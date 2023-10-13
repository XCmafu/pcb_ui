#ifndef QTEMPATUREMONITORPAGE_H
#define QTEMPATUREMONITORPAGE_H

#include "widgetbase.h"

class QTempatureMonitorPage : public WidgetBase<QWidget>
{
public:
    QTempatureMonitorPage();
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;
};

#endif // QTEMPATUREMONITORPAGE_H
