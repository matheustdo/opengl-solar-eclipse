#include "glwidget.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

float LightSunFxPos[] = { 0.0f, 0.0f, 1.0f, 0.0f }; // Sun Light Effect Position Values
float LightSunFxAmb[] = { 1.0f, 0.8f, 0.0f, 1.0f }; // Ambient Sun Light Effect Values
float LightSunFxDif[] = { 1.0f, 0.4f, 1.0f, 1.0f }; // Diffuse Sun Light Effect Values
float LightSunFxSpc[] = { 1.0f, 1.0f, 1.0f, 1.0f };	// Specular Sun Light Effect Values

float LightPos[] = { 60.0f, 0.0f, 0.0f, 0.0f }; // Light Position Values
float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Ambient Light Values
float LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f }; // Diffuse Light Values
float LightSpc[] = { -0.2f, -0.2f, -0.2f, 1.0f };	// Specular Light Values

float MatClean[] = { 0.0f, 0.0f, 0.0f, 1.0 }; // No Material Values

GLUquadricObj *quadric; // Quadric

// Constructor
GLWidget::GLWidget(QWidget *parent)
    :QGLWidget(parent) {
    this->horizontalAngle = 30*M_PI/180.0f;
    this->verticalAngle = 70*M_PI/180.0f;
    this->horizontalPosition = 0;
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
    glEnable(GL_COLOR_MATERIAL); // Enable Color Material
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
        gluLookAt(horizontalPosition + (165 - zoom)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoom)*cos(verticalAngle), (165 - zoom)*sin(horizontalAngle)*sinf(verticalAngle), horizontalPosition, 0, 0, 0, 1, 0);
    } else {
        gluLookAt(horizontalPosition + (165 - zoom)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoom)*cos(verticalAngle), (165 - zoom)*sin(horizontalAngle)*sinf(verticalAngle), horizontalPosition, 0, 0, 0, -1, 0);
    }

    glLightfv(GL_LIGHT0, GL_POSITION, LightPos); // Set Light Position
    glEnable(GL_LIGHT0); // Enable Light0
    createEarth(); // Create Earth
    createMoon(); // Create Moon

    glDisable(GL_LIGHT0); // Disable Light0

    glEnable(GL_LIGHT1); // Enable Light1
    createSun(); // Create Sun
    glDisable(GL_LIGHT1); // Disable Light1

    earthRot += 0.1f;

}

// Create Earth
void GLWidget::createEarth() {
    GLfloat MatAmb[] = { 0.0f, 0.0f, 0.0f };

    // Create the Earth
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3f(0.0f, 0.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(23.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(earthRot, 0.0f, 0.0f, 1.0f);
    gluSphere(quadric, 4, 40, 40);

    glPopMatrix();

    // Create the shadow to the Moon
    glPushMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-30.0f, 0.0f, 0.0f);
    glScalef(0.5f, 0.3f, 1.0f);
    gluSphere(quadric, 9, 80, 80);

    glPopMatrix();
}

// Create Moon
void GLWidget::createMoon() {
    GLfloat MatAmb[] = { 0.0f, 0.0f, 0.0f };

    // Create the Moon
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3f(1.0f, 1.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(moonPos, 0.0f, 0.0f, 1.0f);
    glTranslatef(30.0f, 0.0f, 0.0f);
    gluSphere(quadric, 1, 20, 20);

    glPopMatrix();

    // Create the shadow to the Earh
    if(moonPos < 15 || moonPos > 345) {
        glPushMatrix();

        glColor3f(0.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(moonPos*9, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.2f, 0.0f, 0.0f);
        gluSphere(quadric, 3.0f, 80, 80);

        glPopMatrix();
    }
}

// Create Sun
void GLWidget::createSun() {
    GLfloat MatAmb[] = { 1.0f, 0.7f, 0.0f };

    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3f(1.0f, 1.0f, 0.7f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(500.0f, 0.0f, 0.0f);
    gluSphere(quadric, 20, 20, 20);

    glPopMatrix();
}


