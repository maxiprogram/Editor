#include "previewmeshform.h"
#include "ui_previewmeshform.h"

PreviewMeshForm::PreviewMeshForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewMeshForm)
{
    ui->setupUi(this);
}

PreviewMeshForm::~PreviewMeshForm()
{
    delete ui;
}

void PreviewMeshForm::SetKey(QString key)
{
    this->key = key;
}

void PreviewMeshForm::on_pushButton_cancel_clicked()
{
    this->close();
}

void PreviewMeshForm::showEvent(QShowEvent* event)
{
    ui->textEdit_mesh->clear();

    float* mesh =Resources::MESH()->GetValue(key.toInt())->GetVertex();
    int i = 0;
    while(i<Resources::MESH()->GetValue(key.toInt())->GetCountVertex()*3)
    {
        QString str;
        str = QString::number(mesh[i])+", "+QString::number(mesh[i+1])+", "+QString::number(mesh[i+2]);
        ui->textEdit_mesh->append(str);
        i+=3;
    }
}
