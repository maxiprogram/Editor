#include "creategameobject2dform.h"
#include "ui_creategameobject2dform.h"

CreateGameObject2DForm::CreateGameObject2DForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGameObject2DForm)
{
    ui->setupUi(this);
}

CreateGameObject2DForm::~CreateGameObject2DForm()
{
    delete ui;
}

void CreateGameObject2DForm::on_pushButton_2_clicked()
{
    close();
}

void CreateGameObject2DForm::on_pushButton_clicked()
{
    QHash<QString, QString> property;
    property.insert("id_sprite", ui->lineEdit_id_sprite->text());
    property.insert("pos_x", "0");
    property.insert("pos_y", "0");
    property.insert("pos_z", "0");
    property.insert("scal_x", "1");
    property.insert("scal_y", "1");
    property.insert("scal_z", "1");
    property.insert("rot_x", "0");
    property.insert("rot_y", "0");
    property.insert("rot_z", "0");
    property.insert("piv_x", "0");
    property.insert("piv_y", "0");
    property.insert("piv_z", "0");

    GameObject* obj = new GameObject2D;
    obj->SetName(ui->lineEdit_name->text());
    obj->Init(property);

    GameScene* scene = Resources::GAMESCENE()->GetValue(key_scene);
    scene->AddGameObject(obj);

    close();
}
