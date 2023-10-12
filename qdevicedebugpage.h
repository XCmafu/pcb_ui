#ifndef QDEVICEDEBUGPAGE_H
#define QDEVICEDEBUGPAGE_H

#include <QWidget>
#include "WidgetBase.h"

//设备调试界面
class QDeviceDebugPage : WidgetBase<QDeviceDebugPage>
{
    Q_OBJECT
public:
    QDeviceDebugPage();

    virtual void init();

    virtual void initWidget();

    virtual void initSignals();

public slots:
    //槽函数
    void slot_something();

protected:
    //成员变量 控件
};

#endif // QDEVICEDEBUGPAGE_H
