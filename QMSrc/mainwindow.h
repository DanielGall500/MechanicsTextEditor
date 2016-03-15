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

    ScientificNotationSelection *symbolSelection;
    QScrollArea *symbolScrollArea;
    QPushButton *symbolButton;
    QStringList *symbolList;

    QVector<QPushButton*>  capitalGreekButtons;

public slots:
    void onNotationClicked();
};

#endif // MAINWINDOW_H
