#ifndef TESTGL_H
#define TESTGL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class testgl:public QOpenGLWidget, public QOpenGLFunctions
{
public:
    testgl(QWidget *parent) : QOpenGLWidget(parent) { }

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // TESTGL_H
