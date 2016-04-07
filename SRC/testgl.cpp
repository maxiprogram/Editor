#include "testgl.h"

void testgl::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    QMatrix4x4 mat;
    mat.ortho(0, 800, 0, 600, -10, 10);
    glLoadMatrixf(mat.data());

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

void testgl::paintGL()
{
    ///*Альфа смешивание
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_ALPHA_TEST);
    //Альфа смешивание*/

    ///*Буфер глубины(QSurfaceFormat.setDepthBufferSize(24);)
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
    //glDepthMask(GL_TRUE);
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
    mat.ortho(0, 800, 0, 600, -10, 10);

    QMatrix4x4 cam;
    cam.lookAt(QVector3D(0, 0, 1), QVector3D(0, 0, -1), QVector3D(0, 1, 0));

    Transformer tr;
    tr.SetScal(QVector3D(132, 207, 1));
    tr.SetPos(QVector3D(0, 0, 0));
    Resources::SPRITE()->GetValue(0)->Bind();
    Resources::SPRITE()->GetValue(0)->GetShader()->setUniformValue(Resources::SPRITE()->GetValue(0)->GetShader()->GetNameMatrixPos().toStdString().c_str(),
                                                                                        mat *
                                                                                        cam *
                                                                                        tr.GetMatrix());
    glDrawArrays(GL_TRIANGLES, 0, Resources::SPRITE()->GetValue(0)->GetMesh()->GetCountVertex());

}

void testgl::resizeGL(int w, int h)
{
    //this->resize(w, h);
    //glViewPort(0, 0, w, h);
    //glMatrixMode(GL_PROJECTION);
    //QMatrix4x4 mat;
    //mat.ortho(-5, 5, -5, 5, -5, 5);
    //glLoadMatrixf(mat.data());
}
