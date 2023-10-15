#include "widget_detect.h"
#include "ui_widget_detect.h"

WidgetDetect::WidgetDetect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDetect)
{
    ui->setupUi(this);
}

WidgetDetect::~WidgetDetect()
{
    delete ui;
}
