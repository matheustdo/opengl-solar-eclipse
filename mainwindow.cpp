#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
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

void MainWindow::on_zoomAmountSlider_valueChanged(int value)
{
    this->ui->widget->zoomAmount = value;
    this->ui->zoomAmountLabel->setText("Zoom Amount (" + QString::number(value) + "):");
}

void MainWindow::on_moonPositionSlider_valueChanged(int value)
{
    this->ui->widget->moonPosition = value;
    this->ui->moonPositionLabel->setText("Moon Position (" + QString::number(value) + "):");
}

void MainWindow::on_horizontalViewSlider_valueChanged(int value)
{
    this->ui->widget->horizontalAngle = value*M_PI/180.0f;
    this->ui->horizontalViewLabel->setText("Horizontal View (" + QString::number(value) + "):");
}

void MainWindow::on_verticalViewSlider_valueChanged(int value)
{
    this->ui->widget->verticalAngle = (value + 1)*M_PI/180.0f;
    this->ui->verticalViewLabel->setText("Vertical View (" + QString::number(value) + "):");
}

void MainWindow::on_cameraPositionSlider_valueChanged(int value)
{
    this->ui->widget->cameraPosition = value;
    this->ui->cameraPositionLabel->setText("Camera Position (" + QString::number(value) + "):");
}


// Key handler
void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Escape:
        close(); // Quit on Escape
        break;
    case Qt::Key_F1:
        setWindowState(windowState() ^ Qt::WindowFullScreen); // Toggle fullscreen on F1
        break;
    }
}

void MainWindow::on_configPresetComboBox_activated(const QString &arg1)
{
    if (arg1 == "Preset 1") {
        this->ui->widget->cameraPosition = 18;
        this->ui->cameraPositionSlider->setValue(18);
        this->ui->cameraPositionLabel->setText("Camera Position (18):");
        this->ui->widget->zoomAmount = 130;
        this->ui->zoomAmountSlider->setValue(130);
        this->ui->zoomAmountLabel->setText("Zoom Amount (130):");
        this->ui->widget->horizontalAngle = 30*M_PI/180.0f;
        this->ui->horizontalViewSlider->setValue(30);
        this->ui->horizontalViewLabel->setText("Horizontal View (30):");
        this->ui->widget->verticalAngle = (70 + 1)*M_PI/180.0f;
        this->ui->verticalViewSlider->setValue(70);
        this->ui->verticalViewLabel->setText("Vertical View (70):");
        this->ui->widget->moonPosition = 0;
        this->ui->moonPositionSlider->setValue(0);
        this->ui->moonPositionLabel->setText("Moon Position (0):");
    } else if (arg1 == "Preset 2") {
        this->ui->widget->cameraPosition = 450;
        this->ui->cameraPositionSlider->setValue(450);
        this->ui->cameraPositionLabel->setText("Camera Position (450):");
        this->ui->widget->zoomAmount = 15;
        this->ui->zoomAmountSlider->setValue(15);
        this->ui->zoomAmountLabel->setText("Zoom Amount (15):");
        this->ui->widget->horizontalAngle = 35*M_PI/180.0f;
        this->ui->horizontalViewSlider->setValue(35);
        this->ui->horizontalViewLabel->setText("Horizontal View (35):");
        this->ui->widget->verticalAngle = (67 + 1)*M_PI/180.0f;
        this->ui->verticalViewSlider->setValue(67);
        this->ui->verticalViewLabel->setText("Vertical View (67):");
        this->ui->widget->moonPosition = 0;
        this->ui->moonPositionSlider->setValue(0);
        this->ui->moonPositionLabel->setText("Moon Position (0):");
    } else if (arg1 == "Preset 3") {
        this->ui->widget->cameraPosition = 27;
        this->ui->cameraPositionSlider->setValue(27);
        this->ui->cameraPositionLabel->setText("Camera Position (27):");
        this->ui->widget->zoomAmount = 111;
        this->ui->zoomAmountSlider->setValue(111);
        this->ui->zoomAmountLabel->setText("Zoom Amount (111):");
        this->ui->widget->horizontalAngle = 151*M_PI/180.0f;
        this->ui->horizontalViewSlider->setValue(151);
        this->ui->horizontalViewLabel->setText("Horizontal View (151):");
        this->ui->widget->verticalAngle = (77 + 1)*M_PI/180.0f;
        this->ui->verticalViewSlider->setValue(77);
        this->ui->verticalViewLabel->setText("Vertical View (77):");
        this->ui->widget->moonPosition = 310;
        this->ui->moonPositionSlider->setValue(310);
        this->ui->moonPositionLabel->setText("Moon Position (310):");
    }
}

void MainWindow::on_automaticMoonMovementCheckBox_clicked(bool checked)
{
    this->ui->widget->automaticMoonMovement = checked;
}

void MainWindow::on_moonPositionSlider_sliderPressed()
{
    if(this->ui->automaticMoonMovementCheckBox->checkState()) {
        this->ui->widget->automaticMoonMovement = false;
    }
}

void MainWindow::on_moonPositionSlider_sliderReleased()
{
    if(this->ui->automaticMoonMovementCheckBox->checkState()) {
        this->ui->widget->automaticMoonMovement = true;
    }
}
