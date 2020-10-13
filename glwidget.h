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
    void createEarth();
    void createMoon();
    void createSun();

    float horizontalAngle, verticalAngle;
    float horizontalPosition;
    int zoom;
    float earthRot;
    int moonPos;

private:
    QTimer timer;
};

#endif // GLWIDGET_H
