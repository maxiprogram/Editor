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
