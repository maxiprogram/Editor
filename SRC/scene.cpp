#include "scene.h"

void Scene::SetKeyScene(QString name)
{
    this->key = name;
}

void Scene::SetProjection(DataProjection proj)
{
    this->data_proj = proj;
    //qDebug()<<"onSetProjection"<<projection;
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

    QMatrix4x4 mat;
    mat.ortho(0, 800, 0, 600, 0, 2);
    //projection = mat;


    QMatrix4x4 cam;
    cam.lookAt(QVector3D(0, 0, 1), QVector3D(0, 0, -1), QVector3D(0, 1, 0));

    Transformer tr;
    tr.SetScal(QVector3D(132, 207, 1));
    tr.SetPos(QVector3D(0, 0, 0));
    Resources::SPRITE()->GetValue(0)->Bind();
    Resources::SPRITE()->GetValue(0)->GetShader()->setUniformValue(Resources::SPRITE()->GetValue(0)->GetShader()->GetNameMatrixPos().toStdString().c_str(),
                                                                                        projection *
                                                                                        cam *
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
