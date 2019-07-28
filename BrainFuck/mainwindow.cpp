#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bf = new BrainFuck;
}

MainWindow::~MainWindow()
{
    delete bf;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bf->setInputBuffer(ui->lineEdit->text().toStdString());
    try {
        bf->compliteProgram(ui->textEdit->toPlainText().toStdString());
    } catch () {

    }
    ui->textEdit_2->setText(QString(bf->getOutputBuffer().c_str()));
}
