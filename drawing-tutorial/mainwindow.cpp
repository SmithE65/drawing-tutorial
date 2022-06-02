#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "parametricshape.h"
#include "parametricshapes.h"

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
    this->ui->renderArea->setShape(ParametricShapes::Astroid());
    this->ui->renderArea->update();
}


void MainWindow::on_cycloidButton_clicked()
{
    this->ui->renderArea->setShape(ParametricShapes::Cycloid());
    this->ui->renderArea->update();
}


void MainWindow::on_huygensButton_clicked()
{
    this->ui->renderArea->setShape(ParametricShapes::Huygens());
    this->ui->renderArea->update();
}


void MainWindow::on_hypoCycloidButton_clicked()
{
    this->ui->renderArea->setShape(ParametricShapes::HypoCycloid());
    this->ui->renderArea->update();
}

