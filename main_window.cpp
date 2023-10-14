#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    initWidget();
    initSignals();
}

MainWindow::~MainWindow()
{
    //delete ui;
}


bool MainWindow::init()
{
    std::cout << "aa" << std::endl;
    // 读取PNG图像
    //cv::Mat image = cv::imread("1.png", cv::IMREAD_COLOR);

//    if (image.empty()) {
//        std::cerr << "无法加载图像" << std::endl;
//        return false;
//    }

    // 显示图像
    //cv::namedWindow("Loaded Image", cv::WINDOW_NORMAL);
    //cv::imshow("Loaded Image", image);
    //cv::waitKey(50);

    return true;
}

void MainWindow::initWidget()
{
    this->setFixedSize(1600,800);

    QWidget* mainWidget = new QWidget();
    this->setCentralWidget(mainWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout(mainWidget);

    m_tabWidget = new QTabWidget();
    mainLayout->addWidget(m_tabWidget);

    //5个页面
    m_mainPage = new QMainPage();
    m_tabWidget->addTab(m_mainPage,u8"首页");

    m_deviceDebugPage = new QDeviceDebugPage();
    m_tabWidget->addTab(m_deviceDebugPage,u8"设备调试");

    m_dbmanagePage = new QDbManagePage();
    m_tabWidget->addTab(m_dbmanagePage,u8"数据库管理");

    m_tempatureMonitorPage = new QTempatureMonitorPage();
    m_tabWidget->addTab(m_tempatureMonitorPage,u8"温度监测");

    m_detectionPage = new QDetectionPage();
    m_tabWidget->addTab(m_detectionPage,u8"检测结果");
}

void MainWindow::initSignals()
{

}

