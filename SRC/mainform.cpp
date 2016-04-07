#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->panel_shader->setVisible(false);
    ui->panel_mesh->setVisible(false);
    ui->panel_texture->setVisible(false);
    ui->panel_sprite->setVisible(false);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::onSendTreeShader()
{
    emit send_tree_shader(ui->treeWidget_shader);
}

void MainForm::onSendTreeMesh()
{
    emit send_tree_mesh(ui->treeWidget_mesh);
}

void MainForm::onSendTreeTexture()
{
    emit send_tree_texture(ui->treeWidget_texture);
}

void MainForm::on_exit_triggered()
{
    this->close();
}

//Создание вкладки (new_scene)
void MainForm::on_new_scene_triggered()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->addTab(new QWidget(ui->tabWidget), "*new_scene"));

    QVBoxLayout *layout = new QVBoxLayout(ui->tabWidget->currentWidget());
    testgl* gl = new testgl(ui->tabWidget->currentWidget());
    layout->addWidget(gl);
    gl->show();
}

//Закрытие вкладки
void MainForm::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

//Закрытие текущей вкладки
void MainForm::on_close_scene_triggered()
{
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

//Закрытие всех вкладок
void MainForm::on_close_all_scene_triggered()
{
    ui->tabWidget->clear();
}

//Добавление параметра в панель параметров
void MainForm::on_pushButton_add_property_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_property);
    item->setText(0, "name");
    item->setText(1, "value");
    item->setFlags(item->flags()|Qt::ItemIsEditable);
    ui->treeWidget_property->insertTopLevelItem(ui->treeWidget_property->topLevelItemCount(), item);
}

//Удаление параметра из панели параметров
void MainForm::on_pushButton_del_property_clicked()
{
    delete ui->treeWidget_property->currentItem();
}

//Добавление шейдера в панель шейдеров
void MainForm::on_pushButton_add_shader_clicked()
{
    QString filename_vert = QFileDialog::getOpenFileName(this, "Выбор файла вершинного шейдела", ".", "Вершинный шейдер (*.vert);;Все файлы (*.*)");
    if (filename_vert=="")
        return;
    QString filename_frag = QFileDialog::getOpenFileName(this, "Выбор файла фрагментного шейдела", ".", "Фрагментный шейдер (*.frag);;Все файлы (*.*)");
    if (filename_frag=="")
        return;

    Shader* shader = new Shader;
    bool flag = shader->Load(filename_vert, filename_frag);
    if (!flag)
    {
        QMessageBox::warning(this, "Добавление шейдера", "Не удалось добавить шейдер!");
        delete shader;
        return;
    }


    int key = ui->treeWidget_shader->topLevelItemCount();
    Resources::SHADER()->Add(key, shader);
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_shader);
    item->setText(0, QString::number(key));
    item->setText(1, filename_vert);
    item->setText(2, filename_frag);
    ui->treeWidget_shader->insertTopLevelItem(ui->treeWidget_shader->topLevelItemCount(), item);
}

//Удаление шейдера из панели шейдеров
void MainForm::on_pushButton_del_shader_clicked()
{
    if (ui->treeWidget_shader->topLevelItemCount()>0)
    {
        int key = ui->treeWidget_shader->currentItem()->text(0).toInt();
        Resources::SHADER()->Delete(key);
        delete ui->treeWidget_shader->currentItem();
    }
}

//Добавление меша в панель мешей
void MainForm::on_pushButton_add_mesh_clicked()
{

    Mesh* mesh = new Mesh();
    mesh->Create();
    int key = ui->treeWidget_mesh->topLevelItemCount();
    Resources::MESH()->Add(key, mesh);
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_mesh);
    item->setText(0, QString::number(key));
    ui->treeWidget_mesh->insertTopLevelItem(ui->treeWidget_mesh->topLevelItemCount(), item);
}

//Удаление меша из панели мешей
void MainForm::on_pushButton_del_mesh_clicked()
{
    if (ui->treeWidget_mesh->topLevelItemCount()>0)
    {
        int key = ui->treeWidget_mesh->currentItem()->text(0).toInt();
        Resources::MESH()->Delete(key);
        delete ui->treeWidget_mesh->currentItem();
    }
}

//Добавление текстуры в панель текстур
void MainForm::on_pushButton_add_texture_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Выбор файла текстуры", ".", "Изображение (*.png *.jpg *.jpeg *.bmp);;Все файлы (*.*)");
    if (filename=="")
        return;
    Texture* tex = new Texture;
    bool flag = tex->Load(filename);
    if (!flag)
    {
        QMessageBox::warning(this, "Добавление текстуры", "Не удалось открыть текстуру!");
        delete tex;
        return;
    }

    tex->Create();
    int key = ui->treeWidget_texture->topLevelItemCount();
    Resources::TEXTURE()->Add(key, tex);
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_texture);
    item->setText(0, QString::number(key));
    item->setText(1, filename);
    ui->treeWidget_texture->insertTopLevelItem(ui->treeWidget_texture->topLevelItemCount(), item);

}

//Удаление текстуры из панели текстуры
void MainForm::on_pushButton_del_texture_clicked()
{
    if (ui->treeWidget_texture->topLevelItemCount()>0)
    {
        int key = ui->treeWidget_texture->currentItem()->text(0).toInt();
        Resources::TEXTURE()->Delete(key);
        delete ui->treeWidget_texture->currentItem();
    }
}

//Добавление спрайта в панель спрайтов
void MainForm::on_pushButton_add_sprite_clicked()
{
    AddSpriteForm* f = new AddSpriteForm;
    connect(f, SIGNAL(get_tree_shader()), this, SLOT(onSendTreeShader()));
    connect(this, SIGNAL(send_tree_shader(QTreeWidget*)), f, SLOT(onRecievTreeShader(QTreeWidget*)));
    connect(f, SIGNAL(get_tree_mesh()), this, SLOT(onSendTreeMesh()));
    connect(this, SIGNAL(send_tree_mesh(QTreeWidget*)), f, SLOT(onRecievTreeMesh(QTreeWidget*)));
    connect(f, SIGNAL(get_tree_texture()), this, SLOT(onSendTreeTexture()));
    connect(this, SIGNAL(send_tree_texture(QTreeWidget*)), f, SLOT(onRecievTreeTexture(QTreeWidget*)));
    connect(f, SIGNAL(send_tree_sprite(QString,QString,QString,QString)), this, SLOT(onAppendTreeSprite(QString,QString,QString,QString)));
    f->setWindowTitle("Добавление спрайта");
    f->SetKey(QString::number(ui->treeWidget_sprite->topLevelItemCount()));
    f->show();
}

//Добавление в панель спрайтов
void MainForm::onAppendTreeSprite(QString key_sprite, QString key_shader, QString key_mesh, QString key_texture)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget_sprite);
    item->setText(0, key_sprite);
    item->setText(1, key_shader);
    item->setText(2, key_mesh);
    item->setText(3, key_texture);
    ui->treeWidget_sprite->insertTopLevelItem(ui->treeWidget_sprite->topLevelItemCount(), item);
}

//Удаление спрайта из панели спрайтов
void MainForm::on_pushButton_del_sprite_clicked()
{
    if (ui->treeWidget_sprite->topLevelItemCount()>0)
    {
        int key = ui->treeWidget_sprite->currentItem()->text(0).toInt();
        Resources::SPRITE()->Delete(key);
        delete ui->treeWidget_sprite->currentItem();
    }
}

//Двойной щелчок шейдеры - просмотр шейдера
void MainForm::on_treeWidget_shader_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    PreviewShaderForm* f = new PreviewShaderForm(this);
    f->setWindowTitle("Просмотр шейдеров: ID key "+item->text(0));
    f->SetKey(item->text(0));
    f->SetPathVert(item->text(1));
    f->SetPathFrag(item->text(2));
    f->show();
}

//Двойной щелчок меши - просмотр меша
void MainForm::on_treeWidget_mesh_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    PreviewMeshForm* f = new PreviewMeshForm(this);
    f->setWindowTitle("Просмотр меша: ID key "+item->text(0));
    f->SetKey(item->text(0));
    f->show();
}

//Двойной щелчок текстуры - просмотр изображения
void MainForm::on_treeWidget_texture_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    PreviewTextureForm* f = new PreviewTextureForm(this);
    f->setWindowTitle("Просмотр текстуры: "+item->text(1));
    f->SetKey(item->text(0));
    f->SetPath(item->text(1));
    f->show();
}

//Двойной щелчок спрайты - просмотр спрайта
void MainForm::on_treeWidget_sprite_itemDoubleClicked(QTreeWidgetItem *item, int column)
{

}

