#ifndef WIDGET_RESULT_H
#define WIDGET_RESULT_H

#include <QWidget>

namespace Ui {
class WidgetResult;
}

class WidgetResult : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetResult(QWidget *parent = nullptr);
    ~WidgetResult();

private:
    Ui::WidgetResult *ui;
};

#endif // WIDGET_RESULT_H
