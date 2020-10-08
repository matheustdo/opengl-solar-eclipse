#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zoomSlider_valueChanged(int value)
{
    this->ui->widget->zoom = value;
}

void MainWindow::on_moonPosSlider_valueChanged(int value)
{
    this->ui->widget->moonPos = value;
}

void MainWindow::on_horizontalViewSlider_valueChanged(int value)
{
    this->ui->widget->horizontalAngle = value*M_PI/180.0f;
}

void MainWindow::on_verticalViewSlider_valueChanged(int value)
{
    this->ui->widget->verticalAngle = (value + 1)*M_PI/180.0f;
}
