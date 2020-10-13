#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_zoomAmountSlider_valueChanged(int position);

    void on_moonPositionSlider_valueChanged(int position);

    void on_horizontalViewSlider_valueChanged(int position);

    void on_verticalViewSlider_valueChanged(int value);

    void on_cameraPositionSlider_valueChanged(int value);

    void on_configPresetComboBox_activated(const QString &arg1);

    void keyPressEvent(QKeyEvent *event);

    void on_automaticMoonMovementCheckBox_clicked(bool checked);

    void on_moonPositionSlider_sliderPressed();

    void on_moonPositionSlider_sliderReleased();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
