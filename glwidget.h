#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void createEarth(int radius, float angle);
    void createMoon(int radius, float angle);
    void createSun(int radius, float angle);

    float horizontalAngle;
    float verticalAngle;
    int zoom;
    float earthRot;
    int moonPos;

private:
    QTimer timer;
};

#endif // GLWIDGET_H
