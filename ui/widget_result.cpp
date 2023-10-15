#include "widget_result.h"
#include "ui_widget_result.h"

WidgetResult::WidgetResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetResult)
{
    ui->setupUi(this);
}

WidgetResult::~WidgetResult()
{
    delete ui;
}
