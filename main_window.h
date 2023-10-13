#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
//#include "opencv2/opencv.hpp"

#include <QTabWidget>
#include <QPointer>

#include "qmainpage.h"
#include "qdevicedebugpage.h"
#include "qdbmanagepage.h"
#include "qtempaturemonitorpage.h"
#include "qdetectionpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool init();

    int data_temp;


private:
    //不太喜欢用Ui 设计器
    //Ui::MainWindow *ui;

public:
    //初始化控件
    void initWidget();
    //初始化信号槽
    void initSignals();

protected:
    QPointer<QTabWidget> m_mainWidget;
    QPointer<QMainPage> m_mainPage;                             //首页页面
    QPointer<QDeviceDebugPage> m_deviceDebugPage;               //设备调试页面
    QPointer<QDbManagePage> m_managePage;                       //数据库管理页面
    QPointer<QTempatureMonitorPage> m_tempatureMonitorPage;     //温度监测页面
    QPointer<QDetectionPage> m_detectionPage;                   //监测结果页面
};
#endif // MAINWINDOW_H
