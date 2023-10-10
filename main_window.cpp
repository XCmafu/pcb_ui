#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::init()
{
    std::cout << "aa" << std::endl;
    // 读取PNG图像
    cv::Mat image = cv::imread("1.png", cv::IMREAD_COLOR);

//    if (image.empty()) {
//        std::cerr << "无法加载图像" << std::endl;
//        return false;
//    }

    // 显示图像
    cv::namedWindow("Loaded Image", cv::WINDOW_NORMAL);
    cv::imshow("Loaded Image", image);
    cv::waitKey(50);

    return true;
}

