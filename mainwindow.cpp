#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->listTasks, &QListWidget::currentRowChanged,
            ui->stackedPages, &QStackedWidget::setCurrentIndex);
    connect(ui->btnCalcTask1, &QPushButton::clicked, this, &MainWindow::runTask1);
    connect(ui->btnCalcTask2, &QPushButton::clicked, this, &MainWindow::runTask2);
    connect(ui->btnCalcTask3, &QPushButton::clicked, this, &MainWindow::runTask3);
    connect(ui->btnCalcTask4, &QPushButton::clicked, this, &MainWindow::runTask4);
    connect(ui->btnCalcTask5, &QPushButton::clicked, this, &MainWindow::runTask5);
    connect(ui->btnCalcTask6, &QPushButton::clicked, this, &MainWindow::runTask6);
    connect(ui->btnCalcTask7, &QPushButton::clicked, this, &MainWindow::runTask7);
    connect(ui->btnCalcTask8, &QPushButton::clicked, this, &MainWindow::runTask8);
    connect(ui->btnCalcTask9, &QPushButton::clicked, this, &MainWindow::runTask9);
    connect(ui->btnCalcTask10, &QPushButton::clicked, this, &MainWindow::runTask10);
    connect(ui->btnCalcTask11, &QPushButton::clicked, this, &MainWindow::runTask11);
    connect(ui->btnSortTask12, &QPushButton::clicked, this, &MainWindow::runTask12);
    connect(ui->btnCalcTask13, &QPushButton::clicked, this, &MainWindow::runTask13);
    connect(ui->btnOpenFile13, &QPushButton::clicked, this, &MainWindow::on_btnOpenFile13_clicked);
    connect(ui->btnCalcTask14, &QPushButton::clicked, this, &MainWindow::runTask14);
    connect(ui->btnCalcTask15, &QPushButton::clicked, this, &MainWindow::runTask15);
    connect(ui->btnCalcTask16, &QPushButton::clicked, this, &MainWindow::runTask16);
    connect(ui->btnRunTask17, &QPushButton::clicked, this, &MainWindow::runTask17);
    // Устанавливаем начальный выбор на первую задачу
    ui->listTasks->setCurrentRow(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
