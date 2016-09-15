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
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex3f(0.0, 0.0, 0.0);

//    glColor3f(1.0, 0.0, 0.0);
//    glVertex3f(1.0, 0.0, 0.0);

//    glColor3f(1.0, 0.0, 0.0);
//    glVertex3f(0.0, 1.0, 0.0);
//    glEnd();


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
