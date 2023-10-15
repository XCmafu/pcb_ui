#include "widget_db.h"
#include "ui_widget_db.h"

WidgetDB::WidgetDB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDB)
{
    ui->setupUi(this);
}

WidgetDB::~WidgetDB()
{
    delete ui;
}
