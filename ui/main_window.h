#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "app/global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    explicit MainWindow(std::shared_ptr<Global>& sp_global_in, QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool init(std::shared_ptr<Global>& sp_global_in);

private slots:
    void on_bt_device_clicked();
    void on_bt_db_clicked();
    void on_bt_detect_clicked();
    void on_bt_result_clicked();

private:
    Ui::MainWindow *ui;

    std::shared_ptr<Global> sp_global;
};

#endif // MAIN_WINDOW_H
