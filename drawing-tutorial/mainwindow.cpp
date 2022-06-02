#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "parametricshape.h"
#include "parametricshapes.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateSpinners();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_astroidButton_clicked()
{
    ui->renderArea->setShape(ParametricShapes::Astroid());
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_cycloidButton_clicked()
{
    ui->renderArea->setShape(ParametricShapes::Cycloid());
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_huygensButton_clicked()
{
    ui->renderArea->setShape(ParametricShapes::Huygens());
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_hypoCycloidButton_clicked()
{
    ui->renderArea->setShape(ParametricShapes::HypoCycloid());
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_backgroundColorButton_clicked()
{
    ui->renderArea->setBackgroundColor(QColorDialog::getColor(ui->renderArea->backgroundColor(), this, "Select Color"));
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_lineColorButton_clicked()
{
    ui->renderArea->setShapeColor((QColorDialog::getColor(ui->renderArea->shapeColor(), this, "Select Color")));
    ui->renderArea->update();
    updateSpinners();
}


void MainWindow::on_scaleSpinner_valueChanged(double arg1)
{
    ui->renderArea->setScale(arg1);
    ui->renderArea->update();
}


void MainWindow::on_intervalSpinner_valueChanged(double arg1)
{
    ui->renderArea->setInterval(arg1);
    ui->renderArea->update();
}


void MainWindow::on_stepSpinner_valueChanged(int arg1)
{
    ui->renderArea->setSteps(arg1);
    ui->renderArea->update();
}

void MainWindow::updateSpinners()
{
    ui->scaleSpinner->setValue(ui->renderArea->scale());
    ui->intervalSpinner->setValue(ui->renderArea->interval());
    ui->stepSpinner->setValue(ui->renderArea->steps());
}

