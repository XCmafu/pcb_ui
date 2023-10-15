#ifndef WIDGET_DB_H
#define WIDGET_DB_H

#include <QWidget>

namespace Ui {
class WidgetDB;
}

class WidgetDB : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDB(QWidget *parent = nullptr);
    ~WidgetDB();

private:
    Ui::WidgetDB *ui;
};

#endif // WIDGET_DB_H
