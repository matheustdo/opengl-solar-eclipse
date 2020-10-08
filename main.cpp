#include "mainwindow.h"
#include <QApplication>
#include "glwidget.h"

int main(int argc, char *argv[])
{
    // Construct a new Qt application
    QApplication a(argc, argv);

    // Check for OpenGL support
    if (!QGLFormat::hasOpenGL()) {
        qDebug("Your system does not seem to support OpenGL. Cannot run this example.");
        return EXIT_FAILURE;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
