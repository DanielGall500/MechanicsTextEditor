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
}

MainWindow::~MainWindow()
{
    delete ui;
}
