#include "addspriteform.h"
#include "ui_addspriteform.h"

AddSpriteForm::AddSpriteForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSpriteForm)
{
    ui->setupUi(this);
}

AddSpriteForm::~AddSpriteForm()
{
    delete ui;
}

void AddSpriteForm::SetKey(QString key)
{
    this->key = key;
}

void AddSpriteForm::on_pushButton_cancel_clicked()
{
    this->close();
}

void AddSpriteForm::showEvent(QShowEvent* event)
{
    ui->lineEdit_key->setText(key);

    ui->comboBox_shader->clear();
    ui->comboBox_mesh->clear();
    ui->comboBox_texture->clear();

    QHash<int, Shader*>* hash_shader = Resources::SHADER()->GetHash();
    QHash<int, Shader*>::iterator it_shader = hash_shader->begin();
    while(it_shader!=hash_shader->end())
    {
        ui->comboBox_shader->addItem(QString::number(it_shader.key()));
        it_shader++;
    }

    QHash<int, Mesh*>* hash_mesh = Resources::MESH()->GetHash();
    QHash<int, Mesh*>::iterator it_mesh = hash_mesh->begin();
    while(it_mesh!=hash_mesh->end())
    {
        ui->comboBox_mesh->addItem(QString::number(it_mesh.key()));
        it_mesh++;
    }

    QHash<int, Texture*>* hash_texture = Resources::TEXTURE()->GetHash();
    QHash<int, Texture*>::iterator it_texture = hash_texture->begin();
    while(it_texture!=hash_texture->end())
    {
        ui->comboBox_texture->addItem(QString::number(it_texture.key()));
        it_texture++;
    }
}

void AddSpriteForm::on_pushButton_preview_shader_clicked()
{
    emit get_tree_shader();
}

void AddSpriteForm::onRecievTreeShader(QTreeWidget* tree)
{
    PreviewShaderForm* f = new PreviewShaderForm(this);

    QTreeWidget* tree_shader = tree;

    QTreeWidgetItem* item;
    for(int i=0; i<tree_shader->topLevelItemCount(); i++)
    {
        if (tree_shader->topLevelItem(i)->text(0)==ui->comboBox_shader->currentText())
        {
            item = tree_shader->topLevelItem(i);
            break;
        }
    }

    f->setWindowTitle("Просмотр шейдеров: ID key "+item->text(0));
    f->SetKey(item->text(0));
    f->SetPathVert(item->text(1));
    f->SetPathFrag(item->text(2));
    f->show();
}

void AddSpriteForm::on_pushButton_preview_mesh_clicked()
{
    emit get_tree_mesh();
}

void AddSpriteForm::onRecievTreeMesh(QTreeWidget* tree)
{
    PreviewMeshForm* f = new PreviewMeshForm(this);

    QTreeWidget* tree_mesh = tree;

    QTreeWidgetItem* item;
    for(int i=0; i<tree_mesh->topLevelItemCount(); i++)
    {
        if (tree_mesh->topLevelItem(i)->text(0)==ui->comboBox_mesh->currentText())
        {
            item = tree_mesh->topLevelItem(i);
            break;
        }
    }

    f->setWindowTitle("Просмотр меша: ID key "+item->text(0));
    f->SetKey(item->text(0));
    f->show();
}

void AddSpriteForm::on_pushButton_preview_texture_clicked()
{
    emit get_tree_texture();
}

void AddSpriteForm::onRecievTreeTexture(QTreeWidget* tree)
{
    PreviewTextureForm* f = new PreviewTextureForm(this);

    QTreeWidget* tree_texture = tree;

    QTreeWidgetItem* item;
    for(int i=0; i<tree_texture->topLevelItemCount(); i++)
    {
        if (tree_texture->topLevelItem(i)->text(0)==ui->comboBox_texture->currentText())
        {
            item = tree_texture->topLevelItem(i);
            break;
        }
    }

    f->setWindowTitle("Просмотр текстуры: "+item->text(1));
    f->SetKey(item->text(0));
    f->SetPath(item->text(1));
    f->show();
}

void AddSpriteForm::on_pushButto_add_clicked()
{
    Sprite* sprite = new Sprite;
    sprite->SetShaderKey(ui->comboBox_shader->currentText().toInt());
    sprite->SetMeshKey(ui->comboBox_mesh->currentText().toInt());
    sprite->SetTextureKey(ui->comboBox_texture->currentText().toInt());
    sprite->Create();

    int key = ui->lineEdit_key->text().toInt();
    Resources::SPRITE()->Add(key, sprite);

    emit send_tree_sprite(ui->lineEdit_key->text(), ui->comboBox_shader->currentText(), ui->comboBox_mesh->currentText(), ui->comboBox_texture->currentText());
    this->close();
}
