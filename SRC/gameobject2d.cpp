#include "gameobject2d.h"

GameObject2D::GameObject2D()
{

}

GameObject2D::~GameObject2D()
{

}

void GameObject2D::Init(QHash<QString, QString> property)
{
    this->property = property;
    initializeOpenGLFunctions();
}

void GameObject2D::Update(float dt)
{

}

void GameObject2D::Draw()
{
    ///*Вывод на экран
    Resources::SPRITE()->GetValue(property.value("id_sprite").toInt())->Bind(256, 256);
    Resources::SPRITE()->GetValue(property.value("id_sprite").toInt())->GetShader()->setUniformValue(Resources::SPRITE()->GetValue(property.value("id_sprite").toInt())->GetShader()->GetNameMatrixPos().toStdString().c_str(),
                                                                                    Setting::GetProjection() *
                                                                                    Resources::CAMERA()->GetCurrentCamera()->GetMatrix() *
                                                                                    this->GetMatrix());
    glDrawArrays(GL_TRIANGLES, 0, Resources::SPRITE()->GetValue(property.value("id_sprite").toInt())->GetMesh()->GetCountVertex());
    Resources::SPRITE()->GetValue(property.value("id_sprite").toInt())->UnBind();
    //Вывод  на экран*/
}
