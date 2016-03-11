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

    foreach(symbolButton, capitalGreekButtons)
    {
        symbolButton->setMaximumSize
                (QSize(symbolScrollArea->width() / 5, symbolScrollArea->height() / 20));

        symbolScrollArea->layout()->addWidget(symbolButton);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

