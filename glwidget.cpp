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
GLuint TextureId[2];

// Constructor
GLWidget::GLWidget(QWidget *parent)
    :QGLWidget(parent) {
    this->horizontalAngle = 30*M_PI/180.0f;
    this->verticalAngle = 70*M_PI/180.0f;
    this->cameraPosition = 18.0f;
    this->zoomAmount = 130.0f;
    this->earthRotation = 0.0f;
    this->moonPosition = 0.0f;
    this->automaticMoonMovement = false;
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}

// Empty destructor
GLWidget::~GLWidget() {}

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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Define the operation of blending
    glEnable(GL_BLEND); // Enable Bending

    QImage earthImg; // Load Earth Texture
    if(!earthImg.load("Assets/Earth.bmp")) {
        exit(1);
    }

    QImage moonImg; // Load Moon Texture
    if(!moonImg.load("Assets/Moon.bmp")) {
        exit(1);
    }

    QImage earthFormattedImg;
    earthFormattedImg = QGLWidget::convertToGLFormat(earthImg);
    if(earthFormattedImg.isNull()) {
        exit(1);
    }

    QImage moonFormattedImg;
    moonFormattedImg = QGLWidget::convertToGLFormat(moonImg);
    if(moonFormattedImg.isNull()) {
        exit(1);
    }

    glGenTextures(2, TextureId);
    glBindTexture(GL_TEXTURE_2D, TextureId[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, earthFormattedImg.width(), earthFormattedImg.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, earthFormattedImg.bits());
    glBindTexture(GL_TEXTURE_2D, TextureId[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, moonFormattedImg.width(), moonFormattedImg.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, moonFormattedImg.bits());

    quadric = gluNewQuadric(); // Initialize Quadratic
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
        gluLookAt(cameraPosition + (165 - zoomAmount)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoomAmount)*cos(verticalAngle), (165 - zoomAmount)*sin(horizontalAngle)*sinf(verticalAngle), cameraPosition, 0, 0, 0, 1, 0);
    } else {
        gluLookAt(cameraPosition + (165 - zoomAmount)*cos(horizontalAngle)*sin(verticalAngle), (165 - zoomAmount)*cos(verticalAngle), (165 - zoomAmount)*sin(horizontalAngle)*sinf(verticalAngle), cameraPosition, 0, 0, 0, -1, 0);
    }

    glLightfv(GL_LIGHT0, GL_POSITION, LightPos); // Set Light Position
    glEnable(GL_LIGHT0); // Enable Light0
    createEarth(); // Create Earth
    createMoon(); // Create Moon
    glDisable(GL_LIGHT0); // Disable Light0

    glEnable(GL_LIGHT1); // Enable Light1
    createSun(); // Create Sun
    glDisable(GL_LIGHT1); // Disable Light1

    earthRotation += 0.1f;

    if(automaticMoonMovement) {
        if(moonPosition >= 360) {
            moonPosition = 0.0f;
        } else {
            moonPosition += 0.2f;
        }
    }

}

// Create Earth
void GLWidget::createEarth() {
    GLfloat MatAmb[] = { 0.0f, 0.0f, 0.0f };

    // Create the Earth
    glPushMatrix();

    glEnable(GL_TEXTURE_2D); // Enable Texture Use
    glBindTexture(GL_TEXTURE_2D, TextureId[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3f(1.0f, 1.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(23.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-earthRotation, 0.0f, 0.0f, 1.0f);

    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GL_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, 4, 40, 40);
    glDisable(GL_TEXTURE_2D); // Disable Texture Use

    glPopMatrix();

    // Create the shadow to the Moon
    glPushMatrix();

    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);
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

    glEnable(GL_TEXTURE_2D); // Enable Texture Use
    glBindTexture(GL_TEXTURE_2D, TextureId[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_EMISSION, MatClean);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor3f(1.0f, 1.0f, 1.0f);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(moonPosition, 0.0f, 0.0f, 1.0f);
    glTranslatef(30.0f, 0.0f, 0.0f);
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GL_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, 1, 20, 20);
    glDisable(GL_TEXTURE_2D); // Disable Texture Use

    glPopMatrix();

    // Create the shadow to the Earh
    if(moonPosition < 15 || moonPosition > 345) {
        glPushMatrix();

        glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(moonPosition*9, 0.0f, 0.0f, 1.0f);
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


