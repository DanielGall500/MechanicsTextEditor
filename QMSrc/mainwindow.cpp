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

    symbolSelection = new ScientificNotationSelection(this);
    QStringList capitalGreekList = symbolSelection->generateSelectionList(CapitalGreek);
    capitalGreekButtons = symbolSelection->generateWidgets(capitalGreekList, symbolScrollArea);

    QVBoxLayout *symbolLayout = new QVBoxLayout;
    symbolScrollArea->setLayout(symbolLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

