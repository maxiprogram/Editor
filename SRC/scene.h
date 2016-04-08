#ifndef SCENE_H
#define SCENE_H

#include <QtOpenGL/QGLWidget>
//#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "setprojectionform.h"

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "E:\Projects\For_Git\PacManRun\PacManRun\SRC\Engine\resources.h"
#endif

class Scene:public QGLWidget, public QOpenGLFunctions
{
public:
    Scene(QWidget *parent) : QGLWidget(parent) { }
    void SetKeyScene(QString name);
    void SetProjection(DataProjection proj);
    void UpdateSize(int w, int h);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QString key;
    DataProjection data_proj;
    QMatrix4x4 projection;
};

#endif // SCENE_H
