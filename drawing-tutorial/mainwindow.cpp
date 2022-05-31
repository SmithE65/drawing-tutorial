#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_astroidButton_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::red);
    this->ui->renderArea->repaint();
}


void MainWindow::on_cycloidButton_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::green);
    this->ui->renderArea->repaint();
}


void MainWindow::on_huygensButton_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::blue);
    this->ui->renderArea->repaint();
}


void MainWindow::on_hypoCycloidButton_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::yellow);
    this->ui->renderArea->repaint();
}

