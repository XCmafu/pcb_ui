#include "globalutils.h"

#include "qimageviewer.h"

GlobalUtils::GlobalUtils()
{

}

void GlobalUtils::showImageViewer(const QImage &image,QWidget* parent)
{
    QImageViewer* imageViewer = new  QImageViewer(nullptr);
    imageViewer->initWidget();
    imageViewer->initSignals();
    imageViewer->setImage(image);
    imageViewer->show();
}

void GlobalUtils::hideImageViewer()
{

}

QImage GlobalUtils::cvmat2image()
{
    QImage image;
    //
    return image;
}

void GlobalUtils::image2cvmat(const QImage& image)
{

}
