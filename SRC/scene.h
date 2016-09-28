#ifndef SCENE_H
#define SCENE_H

#include <QtOpenGL/QGLWidget>
//#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/glu.h>

#include "define.h"
#include "setprojectionform.h"

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "Engine/resources.h"
#endif


class Scene:public QGLWidget, public QOpenGLFunctions
{
public:
    Scene(QWidget *parent) : QGLWidget(parent) { data_proj.angle = 45; data_proj.near_ = 0; data_proj.far_ = 2; data_proj.ortho = true; }
    void SetKeyScene(QString name);
    QString GetKeyScene();
    void SetProjection(DataProjection proj);
    void UpdateSize(int w, int h);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

public:
    Mode_Cursor current_mode;

private:
    QString key;
    DataProjection data_proj;
    QMatrix4x4 projection;
    QPoint last_point_mouse;
    QPoint current_point_mouse;
    bool press_left_mouse;
    bool press_middle_mouse;
};

#endif // SCENE_H
