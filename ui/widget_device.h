#ifndef WIDGET_DEVICE_H
#define WIDGET_DEVICE_H
#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QThread>
#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QMessageBox>
#include "app/global.h"
#include "cap/video/video.h"

// 红外视频线程
class ThreadInfraredImg : public QThread
{
    Q_OBJECT

public:
    ThreadInfraredImg(std::shared_ptr<Global>& sp_global);

signals:
    void imageUpdated(const QPixmap &pixmap);

protected:
    void run() override;

private:
    std::shared_ptr<Global> sp_global;
    cv::Mat img_src;
    QPixmap pixmap;
};


// 可见光视频线程
class ThreadVideoImg : public QThread
{
    Q_OBJECT

public:
    ThreadVideoImg(std::shared_ptr<Global>& sp_global);

signals:
    void imageUpdated(const QPixmap &pixmap);

protected:
    void run() override;

private:
    std::shared_ptr<Global> sp_global;
    cv::Mat img_src;
    QPixmap pixmap;
};



namespace Ui {
class WidgetDevice;
}



class WidgetDevice : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDevice(QWidget *parent = nullptr);
    ~WidgetDevice();

    void init(std::shared_ptr<Global>& sp_global_in);

private slots:
    void on_bt_infrared_clicked(); // 红外图像显示槽函数
    void on_bt_video_clicked(); // 可见光图像显示槽函数
    void on_bt_video_add_zoom_clicked(); // 可见光图像正向变倍槽函数
    void on_bt_video_sub_zoom_clicked(); // 可见光图像反向变倍槽函数
    void on_bt_video_add_focus_clicked(); // 可见光图像正向聚焦槽函数
    void on_bt_video_sub_focus_clicked(); // 可见光图像反向聚焦槽函数
    void on_bt_video_reset_clicked(); // 可见光图像重置槽函数
    void on_spinbox_video_exposure_valueChanged(int arg1); // 可见光图像曝光时间槽函数1
    void on_spinbox_video_exposure_editingFinished(); // 可见光图像曝光时间槽函数2

    void on_bt_infrared_autofocus_clicked(); // 红外图像自动聚焦槽函数
    void on_bt_infrared_add_focus_clicked(); // 红外图像正向聚焦槽函数
    void on_bt_infrared_sub_focus_clicked(); // 红外图像反向聚焦槽函数
    void on_combobox_infrared_color_currentIndexChanged(int index); // 红外图像设置伪彩槽函数
    void on_bt_infrared_set_region_clicked(); // 红外图像设置温区槽函数
    void on_bt_infrared_region_remove_clicked(); // 红外图像删除温区槽函数
    void on_bt_infrared_region_all_remove_clicked(); // 红外图像删除所有温区槽函数

    void on_bt_axis_y_up_pressed(); // 运动平台y轴正向移动
    void on_bt_axis_y_down_pressed(); // 运动平台y轴反向移动
    void on_bt_axis_x_up_pressed(); // 运动平台x轴正向移动
    void on_bt_axis_x_down_pressed(); // 运动平台x轴反向移动
    void on_bt_axis_z_up_pressed(); // 运动平台z轴正向移动
    void on_bt_axis_z_down_pressed(); // 运动平台z轴反向移动
    void on_bt_axis_y_up_released();
    void on_bt_axis_y_down_released();
    void on_bt_axis_x_up_released();
    void on_bt_axis_x_down_released();
    void on_bt_axis_z_up_released();
    void on_bt_axis_z_down_released();
    void on_bt_axis_move_clicked();  // 运动平台移动到指定位置


private:
    void updateInfraredImage(const QPixmap &pixmap_infrared);  // 将红外图像显示到label
    void updateVideoImage(const QPixmap &pixmap_video); // 将可见光图像显示到label
    void updateSPandHSValue(int value);

    Ui::WidgetDevice *ui;
    std::shared_ptr<Global> sp_global;

    // 图像显示线程参数
    ThreadVideoImg* thread_video;
    bool is_video_running;
    ThreadInfraredImg* thread_infrared;
    bool is_infrared_running;
    // label图像数据
    QPixmap pixmap_label_infrared;
    QPixmap pixmap_label_video;
    // 按钮图像
    QIcon icon_play;
    QIcon icon_pause;
    QIcon icon_x_up;
    QIcon icon_x_down;
    QIcon icon_y_up;
    QIcon icon_y_down;
    QIcon icon_z_up;
    QIcon icon_z_down;
};



#endif // WIDGET_DEVICE_H
