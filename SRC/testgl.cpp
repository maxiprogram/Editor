#include "testgl.h"

void testgl::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 0.0, 0.0, 1.0);

    //glMatrixMode(GL_PROJECTION);
    //QMatrix4x4 mat;
    //mat.ortho(-5, 5, -5, 5, -5, 5);
    //glLoadMatrixf(mat.data());
}

void testgl::paintGL()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
}

void testgl::resizeGL(int w, int h)
{
    //this->resize(w, h);
    //glViewPort(0, 0, w, h);
    //glMatrixMode(GL_PROJECTION);
    //QMatrix4x4 mat;
    //mat.ortho(-5, 5, -5, 5, -5, 5);
    //glLoadMatrixf(mat.data());
}
