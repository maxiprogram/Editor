#ifndef TESTGL_H
#define TESTGL_H

#include <QtOpenGL/QGLWidget>
//#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class testgl:public QGLWidget, public QOpenGLFunctions
{
public:
    testgl(QWidget *parent) : QGLWidget(parent) { }

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // TESTGL_H
