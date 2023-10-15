#ifndef GLOBALUTILS_H
#define GLOBALUTILS_H


#include <QImage>

class GlobalUtils
{
public:
    GlobalUtils();

    //显示图像浏览器
    static void showImageViewer(const QImage& image,QWidget* parent = nullptr);
    static void hideImageViewer();

    //cvmat 和 qimage转换
    static QImage cvmat2image(/* cvmat */);
    static/* cvmat */ void image2cvmat(const QImage& image);
protected:
};

#endif // GLOBALUTILS_H
