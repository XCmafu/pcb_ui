﻿#ifndef QDEVICEDEBUGPAGE_H
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
#include <QGridLayout>

#include "globalui.h"

//运动平台
class QMovementPlatformWidget : public QWidget
{
public:
    QMovementPlatformWidget();
    void init();
protected:
    QPointer<QPushButton> m_pushbtnTop;
    QPointer<QPushButton> m_pushbtnLeft;
    QPointer<QPushButton> m_pushbtnRight;
    QPointer<QPushButton> m_pushbtnBottom;

    //移动
    QPointer<QPushButton> m_pushbtnUp;
    QPointer<QPushButton> m_pushbtnDown;

    //轴
    QPointer<QComboBox> m_comboBoxAxis;
    //移动文字
    QPointer<QLabel> m_labelMovement;
    //移动量
    QPointer<QSpinBox> m_spinBoxMoveValue;
};

//红外相机控制
class QInfraredCameraControlWidget : public QWidget
{
public:
    QInfraredCameraControlWidget();
    void init();
protected:
    QPointer<QLabel>        m_labelPseudocolor;             //伪彩颜色
    QPointer<QComboBox>     m_comboBoxPseudocolor;

    QPointer<QGroupBox>     m_groupBoxLens;                 //镜头
    QPointer<QLabel>        m_labelFocus;                   //聚焦
    QPointer<QPushButton>   m_pushbtnFocusIn;               //+
    QPointer<QPushButton>   m_pushbtnFocusOut;              //-
    QPointer<QPushButton>   m_pushbtnAutoFocus;             //自动聚焦


    QPointer<QGroupBox>     m_groupBoxDelTemperatureZone;   //删除温区
    QPointer<QSpinBox>      m_spinBoxDelTemperatureZone;    //spinBox 温区
    QPointer<QPushButton>   m_pushbtnDelZone;               //删除
    QPointer<QPushButton>   m_pushbtnDelAllZone;            //删除所有温区

    QPointer<QGroupBox>     m_groupBoxSetTemperatureZone;   //设置温区
    QPointer<QLabel>        m_labelX;
    QPointer<QLabel>        m_labelY;
    QPointer<QLabel>        m_labelW;
    QPointer<QLabel>        m_labelH;
    QPointer<QSpinBox>      m_spinBoxX;
    QPointer<QSpinBox>      m_spinBoxY;
    QPointer<QSpinBox>      m_spinBoxW;
    QPointer<QSpinBox>      m_spinBoxH;
    QPointer<QPushButton>   m_pushbtnSetting;               //设置

    QPointer<QGroupBox>     m_groupBoxReadTemperatureZone;   //读取温区
    QPointer<QLabel>        m_labelReadTemperatureZone;      //温区
    QPointer<QSpinBox>      m_spinBoxReadTemperatureZone;
    QPointer<QPushButton>   m_pushbtnRead;
    QPointer<QLabel>        m_labelMaxTemperature;           //最高温
    QPointer<QLabel>        m_labelMinTemperature;           //最低温
    QPointer<QLabel>        m_labelAverageTemperature;       //平均温
    QPointer<QLabel>        m_labelCenterTemperature;        //中心温
    QPointer<QLabel>        m_labelMaxTemperatureValue;
    QPointer<QLabel>        m_labelMinTemperatureValue;
    QPointer<QLabel>        m_labelAverageTemperatureValue;
    QPointer<QLabel>        m_labelCenterTemperatureValue;

};

//可见光相机控制
class QVisibleCameraControlWidget : public QWidget
{
public:
    QVisibleCameraControlWidget();
    void init();
protected:
    QPointer<QLabel> m_LabelExposureTime;       //曝光时间
    QPointer<QSpinBox> m_spinBoxExposure;
    QPointer<QSlider> m_sliderExposure;
    QPointer<QLabel> m_labelZoom;               //变倍
    QPointer<QPushButton> m_pushbtnZoomIn;      //+
    QPointer<QPushButton> m_pushbtnZoomOut;     //-
    QPointer<QLabel> m_labelFocus;              //聚焦
    QPointer<QPushButton> m_pushbtnFocusIn;     //+
    QPointer<QPushButton> m_pushbtnFocusOut;    //-

    QPointer<QPushButton> m_pushbtnReset;       //重置
};

//播放图像控件
class QPlayImageWidget : public QWidget
{
public:
    QPlayImageWidget();
    void init();

    QPointer<QDoubleClickebleLabel>  labelImage();
protected:
    QPointer<QDoubleClickebleLabel> m_labelImage;              //播放图像label
    QPointer<QPushButton> m_pushbtnPlay;        //播放按钮
    QPointer<QPushButton> m_pushbtnCutSave;     //截图保存图像
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
    void slot_infraredLabelDoubleClicked();                                 //红外图像被点击
    void slot_visibleLabelDoubleClicked();                                  //可见光图被点击

protected:
    QPointer<QGroupBox> m_groupBoxInfraredImage;                            //红外图像
    QPointer<QGroupBox> m_groupBoxVisibleImage;                             //可见光图
    QPointer<QPlayImageWidget> m_playImageWidgetInfrared;                   //红外图像控件
    QPointer<QPlayImageWidget> m_playImageWidgetVisible;                    //可见光图像控件
    QPointer<QGroupBox> m_groupBoxMovementPlatform;                         //运动平台
    QPointer<QMovementPlatformWidget> m_movementPlatformWidget;             //运动平台控件

    QPointer<QGroupBox> m_groupBoxInfraredCameraControl;                    //红外相机控制groupBox
    QPointer<QGroupBox> m_groupBoxvisibleCameraControl;                     //可见光相机控制groupBox
    QPointer<QInfraredCameraControlWidget> m_infraredCameraControlWidget;   //红外相机控制
    QPointer<QVisibleCameraControlWidget> m_visibleCameraControlWidget;     //可见光相机控制
};

#endif // QDEVICEDEBUGPAGE_H
