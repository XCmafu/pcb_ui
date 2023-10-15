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

void QMovementPlatformWidget::initSignalsBy(QDeviceDebugPage *deviceDebugPage)
{
    bool ret= true;
    ret = connect(this->m_pushbtnTop,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnTopClicked);

}

QInfraredCameraControlWidget::QInfraredCameraControlWidget()
{
    init();
    initPseudoColorComboBox();
}

void QInfraredCameraControlWidget::init()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    {
        QHBoxLayout* hbox = new QHBoxLayout();
        vbox->addLayout(hbox,1);

        QVBoxLayout* vv=new QVBoxLayout();
        hbox->addLayout(vv,1);
        {
            QHBoxLayout* hh = new QHBoxLayout();
            vv->addLayout(hh);

            m_labelPseudocolor = new QLabel(u8"伪彩颜色");
            hh->addWidget(m_labelPseudocolor);

            m_comboBoxPseudocolor = new QComboBox();
            hh->addWidget(m_comboBoxPseudocolor);

            m_groupBoxLens = new QGroupBox(u8"镜头");
            vv->addWidget(m_groupBoxLens);
            {
                QVBoxLayout* vvv = new QVBoxLayout(m_groupBoxLens);
                {
                    QHBoxLayout* hhh = new QHBoxLayout();
                    vvv->addLayout(hhh);
                    m_labelFocus = new QLabel(u8"聚焦");
                    hhh->addWidget(m_labelFocus);

                    hhh->addStretch();

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
        hbox->addWidget(m_groupBoxDelTemperatureZone,1);
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
        vbox->addLayout(hbox,1);

        m_groupBoxSetTemperatureZone = new QGroupBox(u8"设置温区");
        hbox->addWidget(m_groupBoxSetTemperatureZone,1);
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
        hbox->addWidget(m_groupBoxReadTemperatureZone,1);
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

void QInfraredCameraControlWidget::initPseudoColorComboBox()
{
    m_comboBoxPseudocolor->addItem(u8"白热");
    m_comboBoxPseudocolor->addItem(u8"黑热");
    m_comboBoxPseudocolor->addItem(u8"彩虹");
    m_comboBoxPseudocolor->addItem(u8"彩虹HC");
    m_comboBoxPseudocolor->addItem(u8"铁红");
    m_comboBoxPseudocolor->addItem(u8"熔岩");
    m_comboBoxPseudocolor->addItem(u8"天空");
    m_comboBoxPseudocolor->addItem(u8"中灰");
    m_comboBoxPseudocolor->addItem(u8"灰红");
    m_comboBoxPseudocolor->addItem(u8"紫橙");
    m_comboBoxPseudocolor->addItem(u8"特殊");

    m_comboBoxPseudocolor->setCurrentIndex(2);  //默认是彩虹
}

void QInfraredCameraControlWidget::initSignalsBy(QDeviceDebugPage *deviceDebugPage)
{
    bool ret = true;
    ret = connect(this->m_pushbtnFocusIn,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnInfraredFoucsInClicked);
    ret = connect(this->m_pushbtnFocusOut,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnInfraredFoucsOutClicked);
    ret = connect(this->m_pushbtnAutoFocus,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnInfraredAutoFoucsClicked);

    ret =connect(this->m_pushbtnDelZone,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnDelTemparetureZoneClicked);
    ret =connect(this->m_pushbtnDelAllZone,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnDelAllTemparetureZoneClicked);

    ret =connect(this->m_pushbtnSetting,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnSetTemparetureZoneClicked);
    ret =connect(this->m_pushbtnRead,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnReadTemparetureZoneClicked);
}

QVisibleCameraControlWidget::QVisibleCameraControlWidget()
{
    init();
}

void QVisibleCameraControlWidget::init()
{
    QGridLayout* grid = new QGridLayout(this);

    m_labelExposureTime = new QLabel(u8"曝光时间");
    grid->addWidget(m_labelExposureTime,0,0);

    m_spinBoxExposure = new QSpinBox();
    grid->addWidget(m_spinBoxExposure,0,1);

    m_sliderExposure = new QSlider();
    m_sliderExposure->setOrientation(Qt::Horizontal);
    grid->addWidget(m_sliderExposure,0,2,1,1);

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

void QVisibleCameraControlWidget::initSignalsBy(QDeviceDebugPage *deviceDebugPage)
{
    bool ret =true;
    ret = connect(m_pushbtnZoomIn,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnVisibleZoomInClicked);
    ret = connect(m_pushbtnZoomOut,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnVisibleZoomOutClicked);
    ret = connect(m_pushbtnFocusIn,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnVisibleFocusInClicked);
    ret = connect(m_pushbtnFocusOut,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnVisibleFocusOutClicked);
    ret = connect(m_pushbtnReset,&QPushButton::clicked,deviceDebugPage,&QDeviceDebugPage::slot_pushbtnVisibleResetClicked);
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
    mainLayout->addLayout(hbox,1);
    {
        m_groupBoxInfraredImage = new QGroupBox(u8"红外图像");
        hbox->addWidget(m_groupBoxInfraredImage,2);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxInfraredImage);
            m_playImageWidgetInfrared = new QPlayImageWidget();
            h->addWidget(m_playImageWidgetInfrared);
        }
        m_groupBoxMovementPlatform = new QGroupBox(u8"运动平台");
        hbox->addWidget(m_groupBoxMovementPlatform,1);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxMovementPlatform);
            m_movementPlatformWidget = new QMovementPlatformWidget();
            h->addWidget(m_movementPlatformWidget);
        }

        m_groupBoxVisibleImage = new QGroupBox(u8"可见光图");
        hbox->addWidget(m_groupBoxVisibleImage,2);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxVisibleImage);
            m_playImageWidgetVisible = new QPlayImageWidget();
            h->addWidget(m_playImageWidgetVisible);
        }
    }

    QHBoxLayout* hbox1 = new QHBoxLayout(this);
    mainLayout->addLayout(hbox1,2);
    {
        m_groupBoxInfraredCameraControl = new QGroupBox(u8"红外相机控制");
        hbox1->addWidget(m_groupBoxInfraredCameraControl,1);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxInfraredCameraControl);
            m_infraredCameraControlWidget = new QInfraredCameraControlWidget();
            h->addWidget(m_infraredCameraControlWidget);
        }
        m_groupBoxvisibleCameraControl = new QGroupBox(u8"可见光相机控制");
        hbox1->addWidget(m_groupBoxvisibleCameraControl,1);
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
    //红外图像
    ret = connect(m_playImageWidgetInfrared->m_labelImage,&QDoubleClickebleLabel::sig_labelDoubleClicked,this,&QDeviceDebugPage::slot_infraredLabelDoubleClicked);
    ret = connect(m_playImageWidgetInfrared->m_pushbtnPlay,&QPushButton::clicked,this,&QDeviceDebugPage::slot_pushbtnInfraredPlayClicked);
    ret = connect(m_playImageWidgetInfrared->m_pushbtnCutSave,&QPushButton::clicked,this,&QDeviceDebugPage::slot_pushbtnInfraredCutClicked);
    //可见光图
    ret = connect(m_playImageWidgetVisible->m_labelImage,&QDoubleClickebleLabel::sig_labelDoubleClicked,this,&QDeviceDebugPage::slot_visibleLabelDoubleClicked);
    ret = connect(m_playImageWidgetVisible->m_pushbtnPlay,&QPushButton::clicked,this,&QDeviceDebugPage::slot_pushbtnVisiblePlayClicked);
    ret = connect(m_playImageWidgetVisible->m_pushbtnCutSave,&QPushButton::clicked,this,&QDeviceDebugPage::slot_pushbtnVisibleCutClicked);

    //运动平台
    m_movementPlatformWidget->initSignalsBy(this);
    //红外相机控制
    m_infraredCameraControlWidget->initSignalsBy(this);
    //可见光相机控制
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

void QDeviceDebugPage::slot_pushbtnInfraredPlayClicked()
{
    //1.开启播放线程


}

void QDeviceDebugPage::slot_pushbtnInfraredCutClicked()
{

}


void QDeviceDebugPage::slot_visibleLabelDoubleClicked()
{
    //1.获取图像数据
    QImage image;
    //2.显示
    GlobalUtils::showImageViewer(image);
}

void QDeviceDebugPage::slot_pushbtnVisiblePlayClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleCutClicked()
{

}

void QDeviceDebugPage::slot_pushbtnTopClicked()
{

}

void QDeviceDebugPage::slot_pushbtnLeftClicked()
{

}

void QDeviceDebugPage::slot_pushbtnRightClicked()
{

}

void QDeviceDebugPage::slot_pushbtnBottomClicked()
{

}

void QDeviceDebugPage::slot_pushbtnInfraredFoucsInClicked()
{

}

void QDeviceDebugPage::slot_pushbtnInfraredFoucsOutClicked()
{

}

void QDeviceDebugPage::slot_pushbtnInfraredAutoFoucsClicked()
{

}

void QDeviceDebugPage::slot_pushbtnDelTemparetureZoneClicked()
{

}

void QDeviceDebugPage::slot_pushbtnDelAllTemparetureZoneClicked()
{

}

void QDeviceDebugPage::slot_pushbtnSetTemparetureZoneClicked()
{

}

void QDeviceDebugPage::slot_pushbtnReadTemparetureZoneClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleZoomInClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleZoomOutClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleFocusInClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleFocusOutClicked()
{

}

void QDeviceDebugPage::slot_pushbtnVisibleResetClicked()
{

}

