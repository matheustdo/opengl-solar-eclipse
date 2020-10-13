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
    void on_zoomSlider_valueChanged(int position);

    void on_moonPosSlider_valueChanged(int position);

    void on_horizontalViewSlider_valueChanged(int position);

    void on_verticalViewSlider_valueChanged(int value);

    void keyPressEvent(QKeyEvent *event);

    void on_cameraPositionSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
