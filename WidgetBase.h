#ifndef WIDGETBASE_H
#define WIDGETBASE_H

#include <QWidget>

template<class T>
class WidgetBase : public T
{
public:
    //初始化函数
    virtual void init(){}
    //初始化控件
    virtual void initWidget(){}
    //初始化信号槽
    virtual void initSignals(){}
};

#endif // WIDGETBASE_H
