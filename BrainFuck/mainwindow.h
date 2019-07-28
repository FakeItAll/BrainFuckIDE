#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>

#include "brainfuck.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCompl_triggered();

    void on_actionComp_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    BrainFuck *bf;
};

#endif // MAINWINDOW_H
