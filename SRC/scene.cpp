#include "scene.h"

void Scene::SetKeyScene(QString name)
{
    this->key = name;
}

QString Scene::GetKeyScene()
{
    return key;
}

void Scene::SetProjection(DataProjection proj)
{
    this->data_proj = proj;
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();

    projection.setToIdentity();
    projection.ortho(0, this->width(), 0, this->height(), 0, 2);

}

void Scene::paintGL()
{
    ///*Альфа смешивание
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Альфа смешивание*/

    ///*Буфер глубины(QSurfaceFormat.setDepthBufferSize(24);)
    glEnable(GL_DEPTH_TEST);
    //Буфер глубины(QSurfaceFormat.setDepthBufferSize(24);)*/

    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    if(press_mouse)
    {
        float x = (float)(current_point_mouse.x()-last_point_mouse.x())/this->width();
        float y = (float)(current_point_mouse.y()-last_point_mouse.y())/this->height();

        Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(-x);
        Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(y);

//        if((last_point_mouse.x()-current_point_mouse.x())>0)
//            Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(0.1);
//        else
//            Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(-0.1);
//        if((last_point_mouse.y()-current_point_mouse.y())>0)
//            Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(0.1);
//        else
//            Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(-0.1);

        qDebug()<<"last:"<<last_point_mouse;
        qDebug()<<"new:"<<current_point_mouse;
        qDebug()<<"Camera:"<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }

    if (Resources::KEYBOARD()->GetKey(Qt::Key_W)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveForward(1);
        qDebug()<<"W="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }
    if (Resources::KEYBOARD()->GetKey(Qt::Key_S)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveForward(-1);
        qDebug()<<"S="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }
    if (Resources::KEYBOARD()->GetKey(Qt::Key_A)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(-1);
        qDebug()<<"A="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }
    if (Resources::KEYBOARD()->GetKey(Qt::Key_D)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(1);
        qDebug()<<"D="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }
    if (Resources::KEYBOARD()->GetKey(Qt::Key_Z)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(1);
        qDebug()<<"D="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }
    if (Resources::KEYBOARD()->GetKey(Qt::Key_X)==true)
    {
        Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(-1);
        qDebug()<<"D="<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }

    Resources::GAMESCENE()->GetValue(key)->Draw();
    //this->update();
    //qDebug()<<"Draw";

}

void Scene::UpdateSize(int w, int h)
{
    this->resizeGL(w, h);
}

void Scene::resizeGL(int w, int h)
{
    this->glViewport(0, 0, w, h);
    projection.setToIdentity();
    if (data_proj.ortho)
        projection.ortho(0, w, 0, h, data_proj.near_, data_proj.far_);
    else
        projection.perspective(data_proj.angle, w/h, data_proj.near_, data_proj.far_);
}

void Scene::mousePressEvent(QMouseEvent* event)
{
    Resources::MOUSE()->Update(event);
    press_mouse = true;
    last_point_mouse.setX(event->x());
    last_point_mouse.setY(event->y());
    qDebug()<<"mousePressEvent";
    this->update();
}

void Scene::mouseReleaseEvent(QMouseEvent* event)
{
    Resources::MOUSE()->Update(event, false);
    press_mouse = false;
    qDebug()<<"mouseReleaseEvent";
    this->update();
}

void Scene::mouseMoveEvent(QMouseEvent* event)
{
    Resources::MOUSE()->Update(event, false);
    last_point_mouse.setX(current_point_mouse.x());
    last_point_mouse.setY(current_point_mouse.y());
    current_point_mouse.setX(event->x());
    current_point_mouse.setY(event->y());
    //qDebug()<<"mouseMoveEvent";
    this->update();
}

void Scene::keyPressEvent(QKeyEvent* event)
{
    Resources::KEYBOARD()->Update(event);
    qDebug()<<"keyPressEvent";
}

void Scene::keyReleaseEvent(QKeyEvent* event)
{
    Resources::KEYBOARD()->Update(event, false);
    qDebug()<<"keyReleaseEvent";
}

