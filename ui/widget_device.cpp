#include "widget_device.h"
#include "ui_widget_device.h"
#pragma execution_character_set("utf-8")


/*****************红外视频线程**************************/
ThreadInfraredImg::ThreadInfraredImg(std::shared_ptr<Global>& sp_global) :
    sp_global(sp_global) {}

void ThreadInfraredImg::run()
{
    while (!isInterruptionRequested())
    {
        if(sp_global->sp_infrared->getDataIfUpdated(img_src))
        {
            if(!img_src.empty())
            {
                // 将cv::Mat转换为QImage
                QImage qimg(img_src.data, img_src.cols, img_src.rows, img_src.step, QImage::Format_BGR888);
                // 将QImage转换为QPixmap
                pixmap = QPixmap::fromImage(qimg);
                // 发送信号以更新UI
                emit imageUpdated(pixmap);
            }
        }
    }
}
/*****************红外视频线程**************************/


/*****************可见光视频线程**************************/
ThreadVideoImg::ThreadVideoImg(std::shared_ptr<Global>& sp_global) :
    sp_global(sp_global) {}

void ThreadVideoImg::run()
{
    while (!isInterruptionRequested())
    {
        if(sp_global->sp_video->getDataIfUpdated(img_src))
        {
            if(!img_src.empty())
            {
                // 将cv::Mat转换为QImage
                QImage qimg(img_src.data, img_src.cols, img_src.rows, img_src.step, QImage::Format_BGR888);
                // 将QImage转换为QPixmap
                pixmap = QPixmap::fromImage(qimg);
                // 发送信号以更新UI
                emit imageUpdated(pixmap);
            }
        }
    }
}
/*****************可见光视频线程**************************/


/*****************初始化**************************/
// 界面初始化
WidgetDevice::WidgetDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDevice)
{
    ui->setupUi(this);
    thread_video = nullptr;
    is_video_running = false;
    thread_infrared = nullptr;
    is_infrared_running = false;

    ui->label_infrared_img->setStyleSheet("border: 1px solid white;");
    ui->label_video_img->setStyleSheet("border: 1px solid white;");

    icon_play.addFile(":/icons/icons/play.png");
    icon_pause.addFile(":/icons/icons/pause.png");
    icon_x_up.addFile(":/icons/icons/x_up.png");
    icon_x_down.addFile(":/icons/icons/x_down.png");
    icon_y_up.addFile(":/icons/icons/y_up.png");
    icon_y_down.addFile(":/icons/icons/y_down.png");
    icon_z_up.addFile(":/icons/icons/z_up.png");
    icon_z_down.addFile(":/icons/icons/z_down.png");

    // 可见光设置
    ui->bt_video->setIcon(icon_play);
    ui->bt_video->setIconSize(ui->bt_video->size());
    ui->bt_video->setStyleSheet("background: transparent; border: none;");
    ui->spinbox_video_exposure->blockSignals(true);
    ui->spinbox_video_exposure->setValue(1);
    ui->spinbox_video_exposure->setRange(1, 6);
    ui->spinbox_video_exposure->blockSignals(false);
    ui->hs_video_exposure->setValue(1);
    ui->hs_video_exposure->setRange(1, 6);
    // 将SpinBox和horizontalSlider连接到槽函数
    connect(ui->spinbox_video_exposure, QOverload<int>::of(&QSpinBox::valueChanged), this, &WidgetDevice::updateSPandHSValue);
    connect(ui->hs_video_exposure, &QSlider::valueChanged, this, &WidgetDevice::updateSPandHSValue);

    // 红外设置
    ui->bt_infrared->setIcon(icon_play);
    ui->bt_infrared->setIconSize(ui->bt_infrared->size());
    ui->bt_infrared->setStyleSheet("background: transparent; border: none;");
    ui->spinbox_infrared_region_x->setRange(0, 639);
    ui->spinbox_infrared_region_y->setRange(0, 511);
    ui->spinbox_infrared_region_w->setRange(0, 639);
    ui->spinbox_infrared_region_h->setRange(0, 511);
    ui->spinbox_infrared_region_remove->setRange(1, 10);
    ui->spinbox_infrared_region_remove->setValue(1);
    ui->combobox_infrared_color->blockSignals(true);
    ui->combobox_infrared_color->setCurrentIndex(2);
    ui->combobox_infrared_color->blockSignals(false);

    // 运动平台设置
//    ui->spinbox_axis_move_pos->setRange(-10, 6000);
    ui->spinbox_axis_move_pos->setValue(0);
}

WidgetDevice::~WidgetDevice()
{
    delete ui;
}

// 设备参数初始化
void WidgetDevice::init(std::shared_ptr<Global> &sp_global_in)
{
    sp_global = sp_global_in;

    int color = 2;
    sp_global->sp_infrared->setColor(color);
    int exposure_level = 1;
    sp_global->sp_video->setExposureLevel(exposure_level);
}
/*****************初始化**************************/


/*****************红外图像**************************/
// 将红外图像显示到label
void WidgetDevice::updateInfraredImage(const QPixmap &pixmap_infrared)
{
    pixmap_label_infrared = pixmap_infrared.scaled(ui->label_video_img->size());
    ui->label_infrared_img->setPixmap(pixmap_label_infrared);
}


void WidgetDevice::on_bt_infrared_clicked()
{
    if (!is_infrared_running)  // 开启显示
    {
        // 创建并启动线程
        thread_infrared = new ThreadInfraredImg(sp_global);
        connect(thread_infrared, &ThreadInfraredImg::imageUpdated, this, &WidgetDevice::updateInfraredImage);
        thread_infrared->start();
        is_infrared_running = true;
        ui->bt_infrared->setIcon(icon_pause);
        ui->bt_infrared->setIconSize(ui->bt_infrared->size());
    }
    else // 关闭显示
    {
        thread_infrared->requestInterruption(); // 停止线程
        thread_infrared->wait(); // 等待线程执行完毕
        delete thread_infrared;
        thread_infrared = nullptr;
        is_infrared_running = false;
        ui->bt_infrared->setIcon(icon_play);
        ui->bt_infrared->setIconSize(ui->bt_infrared->size());
        QMetaObject::invokeMethod(ui->label_infrared_img, "clear", Qt::QueuedConnection);
    }
}
/*****************红外图像**************************/


/*****************可见光图像**************************/
// 将可见光图像显示到label
void WidgetDevice::updateVideoImage(const QPixmap &pixmap_video)
{
    pixmap_label_video = pixmap_video.scaled(ui->label_video_img->width(), ui->label_video_img->height());
    ui->label_video_img->setPixmap(pixmap_label_video);
}


void WidgetDevice::on_bt_video_clicked()
{
    if (!is_video_running)  // 开启显示
    {
        // 创建并启动线程
        thread_video = new ThreadVideoImg(sp_global);
        connect(thread_video, &ThreadVideoImg::imageUpdated, this, &WidgetDevice::updateVideoImage);
        thread_video->start();
        is_video_running = true;
        ui->bt_video->setIcon(icon_pause);
        ui->bt_video->setIconSize(ui->bt_video->size());
    }
    else // 关闭显示
    {
        thread_video->requestInterruption(); // 停止线程
        thread_video->wait(); // 等待线程执行完毕
        delete thread_video;
        thread_video = nullptr;
        is_video_running = false;
        ui->bt_video->setIcon(icon_play);
        ui->bt_video->setIconSize(ui->bt_video->size());
        QMetaObject::invokeMethod(ui->label_video_img, "clear", Qt::QueuedConnection);
    }
}
/*****************可见光图像**************************/


/*****************可见光相机控制**************************/
void WidgetDevice::on_bt_video_add_zoom_clicked()
{
    sp_global->sp_video->addZoom(200);
}

void WidgetDevice::on_bt_video_sub_zoom_clicked()
{
    sp_global->sp_video->subZoom(200);
}

void WidgetDevice::on_bt_video_add_focus_clicked()
{
    sp_global->sp_video->addFocus(200);
}

void WidgetDevice::on_bt_video_sub_focus_clicked()
{
    sp_global->sp_video->subFocus(200);
}

void WidgetDevice::on_bt_video_reset_clicked()
{
    sp_global->sp_video->resetAll();
}

void WidgetDevice::on_spinbox_video_exposure_valueChanged(int arg1)
{
    sp_global->sp_video->setExposureLevel(arg1);
}

void WidgetDevice::on_spinbox_video_exposure_editingFinished()
{
    int value = ui->spinbox_video_exposure->value();
    sp_global->sp_video->setExposureLevel(value);
}

void WidgetDevice::updateSPandHSValue(int value)
{
    // 根据信号的发送者确定哪个控件的值发生了变化
    QObject *senderObject = QObject::sender();

    if (senderObject == ui->spinbox_video_exposure) {
        // SpinBox的值发生了变化，更新horizontalSlider的值
        ui->hs_video_exposure->setValue(value);
    } else if (senderObject == ui->hs_video_exposure) {
        // horizontalSlider的值发生了变化，更新SpinBox的值
        ui->spinbox_video_exposure->setValue(value);
    }
}
/*****************可见光相机控制**************************/


/*****************红外相机控制**************************/
void WidgetDevice::on_bt_infrared_autofocus_clicked()
{
    sp_global->sp_infrared->autoFocus();
}

void WidgetDevice::on_bt_infrared_add_focus_clicked()
{
    sp_global->sp_infrared->increaseFocus();
}

void WidgetDevice::on_bt_infrared_sub_focus_clicked()
{
    sp_global->sp_infrared->decreaseFocus();
}

void WidgetDevice::on_combobox_infrared_color_currentIndexChanged(int index)
{
    sp_global->sp_infrared->setColor(index);
}

void WidgetDevice::on_bt_infrared_set_region_clicked()
{
    int area_x = ui->spinbox_infrared_region_x->value();
    int area_y = ui->spinbox_infrared_region_y->value();
    int area_w = ui->spinbox_infrared_region_w->value();
    int area_h = ui->spinbox_infrared_region_h->value();
    int area_index = 1;
    if (!sp_global->sp_infrared->setRegion(area_index, area_x, area_y, area_w, area_h))
    {
        QMessageBox::warning(nullptr, "警告 ", "设置温区失败! ", QMessageBox::Ok);
    }
}

void WidgetDevice::on_bt_infrared_region_remove_clicked()
{
    int area_index = ui->spinbox_infrared_region_remove->value();
    if (!sp_global->sp_infrared->removeRegion(area_index))
    {
        QMessageBox::warning(nullptr, "警告 ", "删除温区失败! ", QMessageBox::Ok);
    }
}

void WidgetDevice::on_bt_infrared_region_all_remove_clicked()
{
    sp_global->sp_infrared->removeAllRegion();
}
/*****************红外相机控制**************************/


/*****************运动平台控制**************************/
void WidgetDevice::on_bt_axis_y_up_pressed()
{
    int axis = 3;
    sp_global->sp_sport_console->jog_sport_up(axis);
}

void WidgetDevice::on_bt_axis_y_down_pressed()
{
    int axis = 3;
    sp_global->sp_sport_console->jog_sport_down(axis);
}

void WidgetDevice::on_bt_axis_x_up_pressed()
{
    int axis = 2;
    sp_global->sp_sport_console->jog_sport_up(axis);
}

void WidgetDevice::on_bt_axis_x_down_pressed()
{
    int axis = 2;
    sp_global->sp_sport_console->jog_sport_down(axis);
}

void WidgetDevice::on_bt_axis_z_up_pressed()
{
    int axis = 4;
    sp_global->sp_sport_console->jog_sport_up(axis);
}

void WidgetDevice::on_bt_axis_z_down_pressed()
{
    int axis = 4;
    sp_global->sp_sport_console->jog_sport_down(axis);
}

void WidgetDevice::on_bt_axis_y_up_released()
{
    int axis = 3;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_y_down_released()
{
    int axis = 3;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_x_up_released()
{
    int axis = 2;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_x_down_released()
{
    int axis = 2;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_z_up_released()
{
    int axis = 4;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_z_down_released()
{
    int axis = 4;
    sp_global->sp_sport_console->stopSport(axis);
}

void WidgetDevice::on_bt_axis_move_clicked()
{
    int axis_index = ui->combobox_axis->currentIndex();
    axis_index += 2;
    long pos = static_cast<long>(ui->spinbox_axis_move_pos->value());
    sp_global->sp_sport_console->setPos(axis_index, pos);
}
/*****************运动平台控制**************************/



