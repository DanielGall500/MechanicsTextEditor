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
    uint row, column;

    ScientificNotationSelection *symbolSelection;
    QScrollArea *symbolScrollArea;
    QPushButton *symbolButton;
    QStringList *symbolList;
    QGridLayout *symbolLayout;

    QVector<QPushButton*>  capitalGreekButtons, mathematicalButtons;

    void addButtons(QVector<QPushButton *> buttonList);

public slots:
    void onNotationClicked();
};

#endif // MAINWINDOW_H
