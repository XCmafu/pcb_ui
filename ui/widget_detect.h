#ifndef WIDGET_DETECT_H
#define WIDGET_DETECT_H

#include <QWidget>

namespace Ui {
class WidgetDetect;
}

class WidgetDetect : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDetect(QWidget *parent = nullptr);
    ~WidgetDetect();

private:
    Ui::WidgetDetect *ui;
};

#endif // WIDGET_DETECT_H
