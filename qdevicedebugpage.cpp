#include "qdevicedebugpage.h"
#include "globalutils.h"

QMovementPlatformWidget::QMovementPlatformWidget()
{
    init();
}

void QMovementPlatformWidget::init()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox);

        QGridLayout* grid = new QGridLayout();
        hbox->addLayout(grid);

        {
            m_pushbtnTop = new QPushButton(u8"top");
            m_pushbtnLeft = new QPushButton(u8"left");
            m_pushbtnRight = new QPushButton(u8"right");
            m_pushbtnBottom = new QPushButton(u8"bottom");

            grid->addWidget(m_pushbtnTop,0,1);
            grid->addWidget(m_pushbtnLeft,1,0);
            grid->addWidget(m_pushbtnRight,1,2);
            grid->addWidget(m_pushbtnBottom,2,1);
        }

        QVBoxLayout*  rightVbox = new QVBoxLayout();
        hbox->addLayout(rightVbox);
        {
            m_pushbtnUp = new QPushButton(u8"up");
            m_pushbtnDown = new QPushButton(u8"down");

            rightVbox->addWidget(m_pushbtnUp);
            rightVbox->addStretch();
            rightVbox->addWidget(m_pushbtnDown);
        }
    }

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox);

        m_comboBoxAxis = new QComboBox();
        hbox->addWidget(m_comboBoxAxis);

        hbox->addStretch();

        m_labelMovement = new QLabel(u8"移动");
        hbox->addWidget(m_labelMovement);
    }

    m_spinBoxMoveValue = new QSpinBox();
    vbox->addWidget(m_spinBoxMoveValue);

}

QInfraredCameraControlWidget::QInfraredCameraControlWidget()
{
    init();
}

void QInfraredCameraControlWidget::init()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox);

        QVBoxLayout* vv=new QVBoxLayout();
        hbox->addLayout(vv);
        {
            QHBoxLayout* hh = new QHBoxLayout();
            vv->addLayout(hh);

            m_groupBoxLens = new QGroupBox(u8"镜头");
            vv->addWidget(m_groupBoxLens);
            {
                QVBoxLayout* vvv = new QVBoxLayout(m_groupBoxLens);
                {
                    QHBoxLayout* hhh = new QHBoxLayout();
                    vvv->addLayout(hhh);
                    m_labelFocus = new QLabel(u8"聚焦");
                    hhh->addWidget(m_labelFocus);

                    vvv->addStretch();

                    m_pushbtnFocusIn = new QPushButton(u8"+");
                    hhh->addWidget(m_pushbtnFocusIn);

                    m_pushbtnFocusOut = new QPushButton(u8"-");
                    hhh->addWidget(m_pushbtnFocusOut);
                }
                m_pushbtnAutoFocus = new QPushButton(u8"自动聚焦");
                vvv->addWidget(m_pushbtnAutoFocus);
            }

        }

        m_groupBoxDelTemperatureZone = new QGroupBox(u8"删除温区");
        hbox->addWidget(m_groupBoxDelTemperatureZone);
        {
            QVBoxLayout* vv = new QVBoxLayout(m_groupBoxDelTemperatureZone);
            {
                QHBoxLayout* hh = new QHBoxLayout();
                vv->addLayout(hh);

                m_spinBoxDelTemperatureZone = new QSpinBox();
                hh->addWidget(m_spinBoxDelTemperatureZone);

                m_pushbtnDelZone = new QPushButton(u8"删除温区");
                hh->addWidget(m_pushbtnDelZone);
            }

           m_pushbtnDelAllZone = new QPushButton(u8"删除所有温区");
           vv->addWidget(m_pushbtnDelAllZone);
        }
    }

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox);

        m_groupBoxSetTemperatureZone = new QGroupBox(u8"设置温区");
        hbox->addWidget(m_groupBoxSetTemperatureZone);
        {
            QVBoxLayout* vv = new QVBoxLayout(m_groupBoxSetTemperatureZone);
            {
                QHBoxLayout* hh = new QHBoxLayout();
                vv->addLayout(hh);

                m_labelX = new QLabel(u8"X");
                hh->addWidget(m_labelX);

                m_spinBoxX = new QSpinBox();
                hh->addWidget(m_spinBoxX);

                m_labelY = new QLabel(u8"Y");
                hh->addWidget(m_labelY);

                m_spinBoxY = new QSpinBox();
                hh->addWidget(m_spinBoxY);
            }

            {
                QHBoxLayout* hh = new QHBoxLayout();
                vv->addLayout(hh);

                m_labelW = new QLabel(u8"W");
                hh->addWidget(m_labelW);

                m_spinBoxW = new QSpinBox();
                hh->addWidget(m_spinBoxW);

                m_labelH = new QLabel(u8"H");
                hh->addWidget(m_labelH);

                m_spinBoxH = new QSpinBox();
                hh->addWidget(m_spinBoxH);
            }

            m_pushbtnSetting = new QPushButton(u8"设置");
            vv->addWidget(m_pushbtnSetting);
        }

        m_groupBoxReadTemperatureZone = new QGroupBox(u8"读取温区");
        hbox->addWidget(m_groupBoxReadTemperatureZone);
        {
            QVBoxLayout* vv = new QVBoxLayout(m_groupBoxReadTemperatureZone);
            {
                QHBoxLayout* hh= new QHBoxLayout();
                vv->addLayout(hh);
                m_labelReadTemperatureZone =new QLabel(u8"温区");
                hh->addWidget(m_labelReadTemperatureZone);

                m_spinBoxReadTemperatureZone = new QSpinBox();
                hh->addWidget(m_spinBoxReadTemperatureZone);

                m_pushbtnRead = new QPushButton();
                hh->addWidget(m_pushbtnRead);

            }
            {
                QHBoxLayout* hh= new QHBoxLayout();
                vv->addLayout(hh);

                m_labelMaxTemperature =new QLabel(u8"最高温");
                hh->addWidget(m_labelMaxTemperature);

                m_labelMaxTemperatureValue =new QLabel(u8"***");
                hh->addWidget(m_labelMaxTemperatureValue);

                m_labelMinTemperature =new QLabel(u8"最低温");
                hh->addWidget(m_labelMinTemperature);

                m_labelMinTemperatureValue =new QLabel(u8"***");
                hh->addWidget(m_labelMinTemperatureValue);
            }
            {
                QHBoxLayout* hh= new QHBoxLayout();
                vv->addLayout(hh);
                m_labelAverageTemperature =new QLabel(u8"平均温");
                hh->addWidget(m_labelAverageTemperature);

                m_labelAverageTemperatureValue =new QLabel(u8"***");
                hh->addWidget(m_labelAverageTemperatureValue);

                m_labelCenterTemperature =new QLabel(u8"中心温");
                hh->addWidget(m_labelCenterTemperature);

                m_labelCenterTemperatureValue =new QLabel(u8"***");
                hh->addWidget(m_labelCenterTemperatureValue);
            }
        }
    }
}

QVisibleCameraControlWidget::QVisibleCameraControlWidget()
{
    init();
}

void QVisibleCameraControlWidget::init()
{
    QGridLayout* grid = new QGridLayout(this);

    m_LabelExposureTime = new QLabel(u8"曝光时间");
    grid->addWidget(m_LabelExposureTime,0,0);

    m_spinBoxExposure = new QSpinBox();
    grid->addWidget(m_spinBoxExposure,0,1);

    m_sliderExposure = new QSlider();
    m_sliderExposure->setOrientation(Qt::Horizontal);
    grid->addWidget(m_sliderExposure,0,2);

    m_labelZoom = new QLabel(u8"变倍");
    grid->addWidget(m_labelZoom,1,0);

    m_pushbtnZoomIn = new QPushButton(u8"+");
    grid->addWidget(m_pushbtnZoomIn,1,1);

    m_pushbtnZoomOut = new QPushButton(u8"-");
    grid->addWidget(m_pushbtnZoomOut,1,2);

    m_labelFocus = new QLabel(u8"聚焦");
    grid->addWidget(m_labelFocus,2,0);

    m_pushbtnFocusIn = new QPushButton(u8"+");
    grid->addWidget(m_pushbtnFocusIn,2,1);

    m_pushbtnFocusOut = new QPushButton(u8"-");
    grid->addWidget(m_pushbtnFocusOut,2,2);

    m_pushbtnReset = new QPushButton(u8"重置");
    grid->addWidget(m_pushbtnReset,3,0,1,3);
}

QPlayImageWidget::QPlayImageWidget()
{
    init();
}

void QPlayImageWidget::init()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    m_labelImage = new QDoubleClickebleLabel();
    m_labelImage->setText(u8"图像");

    vbox->addWidget(m_labelImage);

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox);

        m_pushbtnPlay = new QPushButton(u8"play");
        hbox->addWidget(m_pushbtnPlay);

        hbox->addStretch(1);

        m_pushbtnCutSave = new QPushButton(u8"cutSave");
        hbox->addWidget(m_pushbtnCutSave);
    }

}

QPointer<QDoubleClickebleLabel> QPlayImageWidget::labelImage()
{
    return m_labelImage;
}


QDeviceDebugPage::QDeviceDebugPage()
{
}

void QDeviceDebugPage::init()
{

}

void QDeviceDebugPage::initWidget()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* hbox = new QHBoxLayout(this);
    mainLayout->addLayout(hbox);
    {
        m_groupBoxInfraredImage = new QGroupBox(u8"红外图像");
        hbox->addWidget(m_groupBoxInfraredImage);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxInfraredImage);
            m_playImageWidgetInfrared = new QPlayImageWidget();
            h->addWidget(m_playImageWidgetInfrared);
        }
        m_groupBoxMovementPlatform = new QGroupBox(u8"运动平台");
        hbox->addWidget(m_groupBoxMovementPlatform);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxMovementPlatform);
            m_movementPlatformWidget = new QMovementPlatformWidget();
            h->addWidget(m_movementPlatformWidget);
        }

        m_groupBoxVisibleImage = new QGroupBox(u8"可见光图");
        hbox->addWidget(m_groupBoxVisibleImage);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxVisibleImage);
            m_playImageWidgetVisible = new QPlayImageWidget();
            h->addWidget(m_playImageWidgetVisible);
        }
    }

    QHBoxLayout* hbox1 = new QHBoxLayout(this);
    mainLayout->addLayout(hbox1);
    {
        m_groupBoxInfraredCameraControl = new QGroupBox(u8"红外相机控制");
        hbox1->addWidget(m_groupBoxInfraredCameraControl);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxInfraredCameraControl);
            m_infraredCameraControlWidget = new QInfraredCameraControlWidget();
            h->addWidget(m_infraredCameraControlWidget);
        }
        m_groupBoxvisibleCameraControl = new QGroupBox(u8"可见光相机控制");
        hbox1->addWidget(m_groupBoxvisibleCameraControl);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxvisibleCameraControl);
            m_visibleCameraControlWidget = new QVisibleCameraControlWidget();
            h->addWidget(m_visibleCameraControlWidget);
        }
    }
}

void QDeviceDebugPage::initSignals()
{
    bool ret =true;

    ret = connect(m_playImageWidgetInfrared->labelImage(),&QDoubleClickebleLabel::sig_labelDoubleClicked,this,&QDeviceDebugPage::slot_infraredLabelDoubleClicked);
    ret = connect(m_playImageWidgetVisible->labelImage(),&QDoubleClickebleLabel::sig_labelDoubleClicked,this,&QDeviceDebugPage::slot_visibleLabelDoubleClicked);



}

void QDeviceDebugPage::slot_something()
{

}

void QDeviceDebugPage::slot_infraredLabelDoubleClicked()
{
    //1.获取图像数据
    QImage image;
    image = GlobalUtils::cvmat2image();
    image = QImage(":/image/sample.jpg");
    //2.显示
    GlobalUtils::showImageViewer(image,this);
}

void QDeviceDebugPage::slot_visibleLabelDoubleClicked()
{
    //1.获取图像数据
    QImage image;
    //2.显示
    GlobalUtils::showImageViewer(image);
}

