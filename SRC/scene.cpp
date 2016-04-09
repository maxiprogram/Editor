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


    Shader* shader = new Shader;
    shader->Load("default.vert", "default.frag");
    Resources::SHADER()->Add(0, shader);
    Mesh* mesh = new Mesh;
    mesh->Create();
    Resources::MESH()->Add(0, mesh);
    Texture* tex = new Texture;
    tex->Load("blood.png");
    tex->Create();
    Resources::TEXTURE()->Add(0, tex);
    Sprite* sprite = new Sprite;
    sprite->SetShaderKey(0);
    sprite->SetMeshKey(0);
    sprite->SetTextureKey(0);
    sprite->Create();
    Resources::SPRITE()->Add(0, sprite);

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

    Transformer tr;
    tr.SetScal(QVector3D(132, 207, 1));
    tr.SetPos(QVector3D(0, 0, 0));
    Resources::SPRITE()->GetValue(0)->Bind();
    Resources::SPRITE()->GetValue(0)->GetShader()->setUniformValue(Resources::SPRITE()->GetValue(0)->GetShader()->GetNameMatrixPos().toStdString().c_str(),
                                                                                        projection *
                                                                                        Resources::CAMERA()->GetValue("camera_"+key)->GetMatrix() *
                                                                                        tr.GetMatrix());
    glDrawArrays(GL_TRIANGLES, 0, Resources::SPRITE()->GetValue(0)->GetMesh()->GetCountVertex());
    Resources::SPRITE()->GetValue(0)->UnBind();

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
        projection.ortho(0, w, 0, h, data_proj.near, data_proj.far);
    else
        projection.perspective(data_proj.angle, w/h, data_proj.near, data_proj.far);
}
