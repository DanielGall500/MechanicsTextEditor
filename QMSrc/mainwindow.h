#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>
#include <QVBoxLayout>
#include <QVector>
#include <QButtonGroup>
#include <QGroupBox>
#include <QGridLayout>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QLabel>

#include <scientificnotationselection.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int row, column;
    uint iter;

    ScientificNotationSelection *symbolSelection;
    QScrollArea *symbolScrollArea;
    QPushButton *symbolButton;
    QStringList *symbolList;
    QGridLayout *symbolLayout;
    QLabel *symbolLabel;

    QVector<QPushButton*>  capitalGreekButtons, mathematicalButtons, lowerGreekButtons;

    void addButtons(QVector<QPushButton *> buttonList, QString labelText);

public slots:
    void onNotationClicked();
};

#endif // MAINWINDOW_H
