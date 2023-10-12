#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
//#include "opencv2/opencv.hpp"

#include <QTabWidget>
#include <QPointer>

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
};
#endif // MAINWINDOW_H
