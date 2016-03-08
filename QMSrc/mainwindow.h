#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>

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

    QScrollArea *symbolScrollArea;
    QPushButton *symbolButton;
    QStringList *symbolList;
};

#endif // MAINWINDOW_H
