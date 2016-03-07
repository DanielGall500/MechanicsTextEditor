#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();

    QFont customFont("Arial", 35, QFont::Bold);
    ui->mainTextEdit->setFont(customFont);
    symbolScrollArea = new QScrollArea;

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    ui->tabWidget->addTab(symbolScrollArea, "Symbols");

    ui->tabWidget->widget(0)
                 ->resize(QSize(symbolScrollArea->width(),
                                symbolScrollArea->height() / 2));
}

MainWindow::~MainWindow()
{
    delete ui;
}
