#include "glwidget.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

float LightSunFxPos[] = { 0.0f, 0.0f, 1.0f, 0.0f }; // Light Position Values
float LightSunFxAmb[] = { 1.0f, 1.0f, 0.0f, 1.0f}; // Ambient Light Values
float LightSunFxDif[] = { 1.0f, 1.0f, 1.0f, 1.0f}; // Diffuse Light Values
float LightSunFxSpc[] = {1.0f, 1.0f, 1.0f, 1.0f};	// Specular Light Values

float LightPos[] = { 60.0f, 0.0f, 0.0f, 0.0f }; // Light Position Values
float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f}; // Ambient Light Values
float LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f}; // Diffuse Light Values
float LightSpc[] = {-0.2f, -0.2f, -0.2f, 1.0f};	// Specular Light Values

float MatClean[] = { 0.0f, 0.0f, 0.0f, 1.0 }; // No Material Values

GLUquadricObj *quadric;

// Constructor
GLWidget::GLWidget(QWidget *parent)
    :QGLWidget(parent) {
    this->horizontalAngle = 30*M_PI/180.0f;
    this->verticalAngle = 70*M_PI/180.0f;
    this->zoom = 15;
    this->earthRot = 0;
    this->moonPos = 0;
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}

// Empty destructor
GLWidget::~GLWidget() {
}

// Initialize OpenGL
void GLWidget::initializeGL() {
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to a black background
    glClearDepth(1.0f); // Depth buffer setup
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Set type of depth test
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really nice perspective calculations

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);	// Set Light0 Ambience
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);	// Set Light0 Diffuse
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpc); // Set Light0 Specular
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightSunFxAmb);	// Set Light1 Ambience
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightSunFxDif);	// Set Light1 Ambience
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSunFxSpc);	// Set Light1 Ambience
    glEnable(GL_LIGHTING); // Enable Lighting

    quadric = gluNewQuadric(); // Initialize Quadratic
    gluQuadricNormals(quadric, GL_SMOOTH); // Enable Smooth Normal Generation
    gluQuadricTexture(quadric, GL_FALSE); // Disable Auto Texture Coords
}

// This is called when the OpenGL window is resized
void GLWidget::resizeGL(int width, int height)  {
    // Prevent divide by zero (in the gluPerspective call)
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height); // Reset current viewport
    glMatrixMode(GL_PROJECTION); // Select projection matrix
    glLoadIdentity(); // Reset projection matrix
    gluPerspective(45.0f, static_cast<GLfloat>(width)/height, 0.1f, 1000.0f); // Calculate aspect ratio

    updateGL();
}

// OpenGL painting
void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer

    glMatrixMode(GL_MODELVIEW); // Select matrix matrix
    glLoadIdentity(); // Reset current modelview matrix


    glLightfv(GL_LIGHT1, GL_POSITION, LightSunFxPos); // Set Light1 Position before gluLookAt

    if(verticalAngle < M_PI) {
        gluLookAt((165 - zoom)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoom)*cos(verticalAngle), (165 - zoom)*sin(horizontalAngle)*sinf(verticalAngle), 0, 0, 0, 0, 1, 0);
    } else {
        gluLookAt((165 - zoom)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoom)*cos(verticalAngle), (165 - zoom)*sin(horizontalAngle)*sinf(verticalAngle), 0, 0, 0, 0, -1, 0);
    }

    glEnable(GL_LIGHT0); // Enable Light0
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos); // Set Light Position
    createEarth(1, 23.0f); // Create Earth
    createMoon(1, 0.0f); // Create Moon
    glDisable(GL_LIGHT0); // Disable Light0

    glEnable(GL_LIGHT1); // Enable Light1
    createSun(1, 0.0f); // Create Sun
    glDisable(GL_LIGHT1); // Disable Light1

    earthRot += 0.1f;

}

void GLWidget::createEarth(int moonRadius, float angle) {
    GLfloat material_ambient[] = { 0.0f, 0.0f, 0.15f };

    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.0f, 0.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(earthRot, 0.0f, 0.0f, 1.0f);
    gluSphere(quadric, moonRadius*4, 20, 20);

    glPopMatrix();
}

void GLWidget::createMoon(int moonRadius, float angle) {
    GLfloat material_ambient[] = { 0.0f, 0.0f, 0.0f };

    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f, 1.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(moonPos, 0.0f, 0.0f, 1.0f);
    glTranslatef(30.0f, 0.0f, 0.0f);
    gluSphere(quadric, moonRadius, 20, 20);

    glPopMatrix();
}

void GLWidget::createSun(int moonRadius, float angle) {
    GLfloat material_ambient[] = { 1.0f, 0.7f, 0.0f };

    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable(GL_COLOR_MATERIAL);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, MatClean);
    //glMaterialfv(GL_FRONT, GL_EMISSION, material_ambient);
    //glColorMaterial(GL_FRONT, GL_EMISSION);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);

    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f, 8.0f, 0.6f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-50.0f, 0.0f, 0.0f);
    gluSphere(quadric, moonRadius*20, 20, 20);

    glPopMatrix();
}


