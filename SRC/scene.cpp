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


    if(press_left_mouse && current_mode==Panaram_Mode_Cursor)
    {
        float x = (float)(current_point_mouse.x()-last_point_mouse.x())/this->width();
        float y = (float)(current_point_mouse.y()-last_point_mouse.y())/this->height();

        Resources::CAMERA()->GetValue("camera_"+key)->MoveRight(-x);
        Resources::CAMERA()->GetValue("camera_"+key)->MoveUp(y);

        qDebug()<<"last:"<<last_point_mouse;
        qDebug()<<"new:"<<current_point_mouse;
        qDebug()<<"Camera:"<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }

    if(press_middle_mouse && current_mode==Panaram_Mode_Cursor)
    {
        float x = (float)(current_point_mouse.x()-last_point_mouse.x())/this->width();
        float y = (float)(current_point_mouse.y()-last_point_mouse.y())/this->height();

        Resources::CAMERA()->GetValue("camera_"+key)->RotateX(360*y);
        Resources::CAMERA()->GetValue("camera_"+key)->RotateY(360*x);

        qDebug()<<"last:"<<last_point_mouse;
        qDebug()<<"new:"<<current_point_mouse;
        qDebug()<<"Camera:"<<Resources::CAMERA()->GetValue("camera_"+key)->GetPos();
    }

    if(press_left_mouse && current_mode==Select_Mode_Cursor)
    {
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        int viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        gluUnProject(current_point_mouse.x(), this->height()-current_point_mouse.y(), -1,
                     (double*)Resources::CAMERA()->GetValue("camera_"+key)->GetMatrix().data(),
                     (double*)projection.data(),
                     viewport,
                     &x, &y, &z
                     );
        qDebug()<<"m_x="<<x<<"m_y="<<y<<"m_z="<<z;
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
    Setting::SetProjection(projection);
}

void Scene::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    {
        press_left_mouse = true;
        last_point_mouse.setX(event->x());
        last_point_mouse.setY(event->y());
        current_point_mouse.setX(event->x());
        current_point_mouse.setY(event->y());
    }
    if(event->button()==Qt::MiddleButton)
    {
        press_middle_mouse = true;
        last_point_mouse.setX(event->x());
        last_point_mouse.setY(event->y());
        current_point_mouse.setX(event->x());
        current_point_mouse.setY(event->y());
    }
    qDebug()<<"mousePressEvent";
    this->update();
}

void Scene::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    {
        press_left_mouse = false;
    }
    if(event->button()==Qt::MiddleButton)
    {
        press_middle_mouse = false;
    }
    qDebug()<<"mouseReleaseEvent";
    this->update();
}

void Scene::mouseMoveEvent(QMouseEvent* event)
{
    if(press_left_mouse)
    {
        last_point_mouse.setX(current_point_mouse.x());
        last_point_mouse.setY(current_point_mouse.y());
        current_point_mouse.setX(event->x());
        current_point_mouse.setY(event->y());
    }
    if(press_middle_mouse)
    {
        last_point_mouse.setX(current_point_mouse.x());
        last_point_mouse.setY(current_point_mouse.y());
        current_point_mouse.setX(event->x());
        current_point_mouse.setY(event->y());
    }
    //qDebug()<<"mouseMoveEvent";
    this->update();
}

void Scene::wheelEvent(QWheelEvent* event)
{
    if(event->angleDelta().y()<0)
        Resources::CAMERA()->GetValue("camera_"+key)->MoveForward(-1);
    else
        Resources::CAMERA()->GetValue("camera_"+key)->MoveForward(1);
    qDebug()<<"type wheel:"<<event->type()<<event->angleDelta();
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

