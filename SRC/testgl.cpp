#include "testgl.h"

void testgl::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    QMatrix4x4 mat;
    mat.ortho(-2, 2, -2, 2, -2, 2);
    glLoadMatrixf(mat.data());

}

void testgl::paintGL()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);

    Mesh* mesh = 0;
    mesh = Resources::MESH()->GetValue(0);

    if (mesh!=0)
    {
        qDebug()<<"ERROR";
        Sprite* sprite = new Sprite;
        sprite->SetShaderKey(0);
        sprite->SetMeshKey(0);
        sprite->SetTextureKey(0);
        sprite->Create();
        Resources::SPRITE()->Add(0, sprite);

        QMatrix4x4 mat;
        mat.ortho(-2, 2, -2, 2, -2, 2);

        QMatrix4x4 cam;
        cam.lookAt(QVector3D(0, 0, -1), QVector3D(0, 0, 1), QVector3D(0, 1, 0));

        Transformer tr;
        tr.SetScal(QVector3D(32, 32, 1));
        tr.SetPos(QVector3D(5, 5, 0));
        Resources::SPRITE()->GetValue(0)->Bind();
        Resources::SPRITE()->GetValue(0)->GetShader()->setUniformValue(Resources::SPRITE()->GetValue(0)->GetShader()->GetNameMatrixPos().toStdString().c_str(),
                                                                                            mat *
                                                                                            cam *
                                                                                            tr.GetMatrix());
        glDrawArrays(GL_TRIANGLES, 0, Resources::SPRITE()->GetValue(0)->GetMesh()->GetCountVertex());
    }

    glEnd();
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
