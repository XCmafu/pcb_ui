#include "qdevicedebugpage.h"

QMovementPlatformWidget::QMovementPlatformWidget()
{

}

void QMovementPlatformWidget::init()
{

}

QInfraredCameraControlWidget::QInfraredCameraControlWidget()
{

}

void QInfraredCameraControlWidget::init()
{

}

QVisibleCameraControlWidget::QVisibleCameraControlWidget()
{

}

void QVisibleCameraControlWidget::init()
{

}

QPlayImageWidget::QPlayImageWidget()
{
    init();
}

void QPlayImageWidget::init()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);

    m_labelImage = new QLabel();
    vbox->addWidget(m_labelImage);

    QHBoxLayout* hbox = new QHBoxLayout();
    vbox->addLayout(hbox);

    m_pushbtnPlay = new QPushButton(u8"play");
    vbox->addWidget(m_pushbtnPlay);

    vbox->addStretch(1);

    m_pushbtnSave = new QPushButton(u8"save");
    vbox->addWidget(m_pushbtnSave);
}


QDeviceDebugPage::QDeviceDebugPage()
{
    initWidget();
    initSignals();
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
        }

        m_groupBoxVisibleImage = new QGroupBox(u8"可见光图");
        hbox->addWidget(m_groupBoxVisibleImage);
        {
            QHBoxLayout* h = new QHBoxLayout(m_groupBoxVisibleImage);
            m_playImageWidgetVisible = new QPlayImageWidget();
        }
    }

}

void QDeviceDebugPage::initSignals()
{

}

void QDeviceDebugPage::slot_something()
{

}

