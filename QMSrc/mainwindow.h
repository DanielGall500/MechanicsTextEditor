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
#include <QComboBox>

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
    int iter;

    QFont *textFontSettings;
    QString fontName;
    int fontSize;
    QComboBox *fontSizeBox;

    QScrollArea *greekScrollArea, *mathematicalScrollArea;
    QGridLayout *symbolLayout;

    ScientificNotationSelection *symbolSelection;
    QPushButton *symbolButton;
    QStringList *symbolList;
    QLabel *symbolLabel;

    QVector<QPushButton*>  capitalGreekButtons, lowerGreekButtons, mathematicalButtons, advMathematicalButtons;

    void addButtons(QVector<QPushButton *> buttonList, QScrollArea *symbolScrollArea, QString labelText);

public slots:
    void onNotationClicked();
    void onFontSizeChanged(QString text);
};

#endif // MAINWINDOW_H
