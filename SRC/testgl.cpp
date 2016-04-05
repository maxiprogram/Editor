#include "testgl.h"

void testgl::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 0.0, 0.0, 1.0);
}

void testgl::paintGL()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void testgl::resizeGL(int w, int h)
{
    this->resize(w, h);
}
