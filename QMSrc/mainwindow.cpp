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

    symbolLayout = new QGridLayout;
    symbolScrollArea->setLayout(symbolLayout);

    symbolSelection = new ScientificNotationSelection(this);

    QStringList mathematicalList = symbolSelection->getBasicMathematicalList();
    QStringList capitalGreekList = symbolSelection->getCapitalGreekList();
    QStringList lowerGreekList = symbolSelection->getLowerGreekList();

    lowerGreekButtons = symbolSelection->generateWidgets(lowerGreekList, symbolScrollArea);
    capitalGreekButtons = symbolSelection->generateWidgets(capitalGreekList, symbolScrollArea);
    mathematicalButtons = symbolSelection->generateWidgets(mathematicalList, symbolScrollArea);

    row = 0, column = -1;

    addButtons(lowerGreekButtons, "Lowercase Greek");
    addButtons(capitalGreekButtons, "Capital Greek");
    addButtons(mathematicalButtons, "Mathematics");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNotationClicked()
{
   QString text = ((QPushButton*)sender())->text();
   qDebug() << "TEXT OUTPUT: " << text;
   ui->mainTextEdit->insertPlainText(text);
   ui->mainTextEdit->setFocus();
}

void MainWindow::addButtons(QVector<QPushButton *> buttonList, QString labelText)
{
    iter = 0;
    row++, column = 0;

    symbolLabel = new QLabel(this);
    QString HTMLtext = "<b>" + labelText + "</b>";
    symbolLabel->setText(HTMLtext);
    symbolLayout->addWidget(symbolLabel, row, column);

    row++, column = -1;

    foreach(symbolButton, buttonList)
    {
        if(column == 5)
        {
            column = 0;
            row++;
        }
        else
            column++;

        symbolButton->setMinimumHeight(symbolScrollArea->height() / 5);

        qDebug() << "Adding " << symbolButton << " to: row " << row << ", column " << column;
        symbolLayout->addWidget(symbolButton, row, column);

        connect(symbolButton, SIGNAL(clicked()), this, SLOT(onNotationClicked()));

        iter++;
        if(iter == uint(buttonList.length()))
        {
            row++;
            column = -1;
        }
    }
}






















