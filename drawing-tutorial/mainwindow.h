#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_astroidButton_clicked();

    void on_cycloidButton_clicked();

    void on_huygensButton_clicked();

    void on_hypoCycloidButton_clicked();

    void on_backgroundColorButton_clicked();

    void on_lineColorButton_clicked();

    void on_scaleSpinner_valueChanged(double arg1);

    void on_intervalSpinner_valueChanged(double arg1);

    void on_stepSpinner_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    void updateSpinners();
};
#endif // MAINWINDOW_H
