#include "qimageviewer.h"

QImageViewer::QImageViewer(QWidget* parent)
    :WidgetBase<QWidget>(parent)
{

}

void QImageViewer::init()
{

}

void QImageViewer::initWidget()
{
    this->setWindowModality(Qt::ApplicationModal);       //设定为模态
    this->setFixedSize(1500,900);
    this->setAttribute(Qt::WA_ShowModal, true);
    this->setWindowTitle(u8"图像预览");

    QVBoxLayout* vbox = new QVBoxLayout(this);

    m_labelImage = new QLabel();
    vbox->addWidget(m_labelImage);
    m_labelImage->setScaledContents(true); // 图像按比例缩放
    m_labelImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // 宽高比保持不变，尽量采用空间
}

void QImageViewer::initSignals()
{

}

void QImageViewer::setImage(const QImage &image)
{
    m_labelImage->setPixmap(QPixmap::fromImage(image));
}
