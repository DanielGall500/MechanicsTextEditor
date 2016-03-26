#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();

    fontSize = 24, fontName = "Arial";
    textFontSettings = new QFont(fontName, fontSize, QFont::Bold);
    ui->mainTextEdit->setFont(*textFontSettings);

    //Main Toolbar

    fontSizeBox = new QComboBox(this);

    for (uint i = 0; i <= 50; i+=2)
        fontSizeBox->addItem(QString::number(i));

    fontSizeBox->setCurrentText(QString::number(fontSize));
    ui->mainToolBar->addWidget(fontSizeBox);

    connect(fontSizeBox, SIGNAL(activated(QString)), this, SLOT(onFontSizeChanged(QString)));

    //Symbol selection area
    symbolSelection = new ScientificNotationSelection(this);
    greekScrollArea = new QScrollArea;
    mathematicalScrollArea = new QScrollArea;

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(mathematicalScrollArea, "Fundamentals");
    ui->tabWidget->addTab(greekScrollArea, "Greek");

    // Mathematical symbols
    symbolLayout = new QGridLayout;
    mathematicalScrollArea->setLayout(symbolLayout);

    QStringList mathematicalList = symbolSelection->getBasicMathematicalList(),
                advMathematicalList = symbolSelection->getAdvancedMathematicalList();

    mathematicalButtons = symbolSelection->generateWidgets(mathematicalList, mathematicalScrollArea);
    advMathematicalButtons = symbolSelection->generateWidgets(advMathematicalList, mathematicalScrollArea);

    row = 0; column = -1;
    addButtons(mathematicalButtons, mathematicalScrollArea, "Fundamentals");
    addButtons(advMathematicalButtons, mathematicalScrollArea, "Advanced");


    // Greek symbols
    symbolLayout = new QGridLayout;
    greekScrollArea->setLayout(symbolLayout);

    QStringList capitalGreekList = symbolSelection->getCapitalGreekList(),
                lowerGreekList = symbolSelection->getLowerGreekList();

    lowerGreekButtons = symbolSelection->generateWidgets(lowerGreekList, greekScrollArea);
    capitalGreekButtons = symbolSelection->generateWidgets(capitalGreekList, greekScrollArea);

    row = 0, column = -1;
    addButtons(lowerGreekButtons, greekScrollArea, "Lowercase Greek");
    addButtons(capitalGreekButtons, greekScrollArea, "Capital Greek");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNotationClicked()
{
   QString text = ((QPushButton*)sender())->text();
   ui->mainTextEdit->insertPlainText(text);
   ui->mainTextEdit->setFocus();
}

void MainWindow::onFontSizeChanged(QString text)
{
    fontSize = int(&text);
    qDebug() << "Changing font to: " << fontSize;
    textFontSettings->setPixelSize(50);
    ui->mainTextEdit->setFont(*textFontSettings);
    ui->mainTextEdit->setFocus();
}

void MainWindow::addButtons(QVector<QPushButton *> buttonList, QScrollArea *symbolScrollArea, QString labelText)
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

        symbolLayout->addWidget(symbolButton, row, column);

        connect(symbolButton, SIGNAL(clicked()), this, SLOT(onNotationClicked()));

        iter++;
        if(iter == buttonList.length())
        {
            row++;
            column = -1;
        }
    }
}






















