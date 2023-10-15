#include "main_window.h"
#include "ui_main_window.h"
#pragma execution_character_set("utf-8")


//MainWindow::MainWindow(std::shared_ptr<Global> &sp_global_in, QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow),
//    sp_global(sp_global_in)
//{
//    ui->setupUi(this);
//    ui->page_3->init(sp_global);
//}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::init(std::shared_ptr<Global> &sp_global_in)
{
    QFile qfile(":/style/style_app.css");
    qfile.open(QFile::ReadOnly);
    setStyleSheet(QString::fromLatin1(qfile.readAll()));

    sp_global = sp_global_in;

    ui->page_3->init(sp_global);
    return true;
}


void MainWindow::on_bt_detect_clicked()
{
    ui->stacked_widget->setCurrentIndex(0);
}


void MainWindow::on_bt_result_clicked()
{
    ui->stacked_widget->setCurrentIndex(1);
}


void MainWindow::on_bt_device_clicked()
{
    ui->stacked_widget->setCurrentIndex(2);
}


void MainWindow::on_bt_db_clicked()
{
    ui->stacked_widget->setCurrentIndex(3);
}

