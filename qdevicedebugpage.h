#ifndef QDEVICEDEBUGPAGE_H
#define QDEVICEDEBUGPAGE_H

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

//运动平台
class QMovementPlatformWidget : public QWidget
{
public:
    QMovementPlatformWidget();
    void init();
};

//红外相机控制
class QInfraredCameraControlWidget : public QWidget
{
public:
    QInfraredCameraControlWidget();
    void init();

};

//可见光相机控制
class QVisibleCameraControlWidget : public QWidget
{
public:
    QVisibleCameraControlWidget();
    void init();

};

//播放图像控件
class QPlayImageWidget : public QWidget
{
public:
    QPlayImageWidget();
    void init();
protected:
    QPointer<QLabel> m_labelImage;          //播放图像label
    QPointer<QPushButton> m_pushbtnPlay;    //播放按钮
    QPointer<QPushButton> m_pushbtnSave;   //保存图像
};

//设备调试界面
class QDeviceDebugPage : public WidgetBase<QWidget>
{
    Q_OBJECT
public:
    QDeviceDebugPage();
    //初始化函数
    virtual void init() override;
    //初始化控件
    virtual void initWidget() override;
    //初始化信号槽
    virtual void initSignals() override;

public slots:
    //槽函数
    void slot_something();

protected:
    QPointer<QGroupBox> m_groupBoxInfraredImage;                            //红外图像
    QPointer<QGroupBox> m_groupBoxVisibleImage;                             //可见光图
    QPointer<QPlayImageWidget> m_playImageWidgetInfrared;                   //红外图像控件
    QPointer<QPlayImageWidget> m_playImageWidgetVisible;                    //可见光图像控件

    QPointer<QGroupBox> m_groupBoxInfraredCameraControl;                    //红外相机控制groupBox
    QPointer<QGroupBox> m_groupBoxvisibleCameraControl;                     //可见光相机控制groupBox
    QPointer<QMovementPlatformWidget> m_movementPlatformWidget;
    QPointer<QInfraredCameraControlWidget> m_infraredCameraControlWidget;   //红外相机控制
    QPointer<QVisibleCameraControlWidget> m_visibleCameraControlWidget;     //可见光相机控制
};

#endif // QDEVICEDEBUGPAGE_H
