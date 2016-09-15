#include "setprojectionform.h"
#include "ui_setprojectionform.h"

SetProjectionForm::SetProjectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetProjectionForm)
{
    ui->setupUi(this);
}

SetProjectionForm::~SetProjectionForm()
{
    delete ui;
}

void SetProjectionForm::on_pushButton_close_clicked()
{
    this->close();
}

void SetProjectionForm::on_pushButton_apply_clicked()
{
    DataProjection projection;

    if (ui->radioButton_ortho->isChecked())
    {
        projection.ortho = true;
        projection.near_ = ui->lineEdit_near->text().toFloat();
        projection.far_ = ui->lineEdit_far->text().toFloat();
        projection.angle = 90;
    } else
    {
        projection.ortho = false;
        projection.near_ = ui->lineEdit_near->text().toFloat();
        projection.far_ = ui->lineEdit_far->text().toFloat();
        projection.angle = ui->lineEdit_angle->text().toFloat();
    }
    emit send_projection(projection);
    this->close();
}

void SetProjectionForm::on_radioButton_ortho_clicked()
{
    ui->lineEdit_angle->setEnabled(false);
}

void SetProjectionForm::on_radioButton_perspective_clicked()
{
    ui->lineEdit_angle->setEnabled(true);
}
