#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_exit_triggered()
{
    this->close();
}

//Создание вкладки (new_scene)
void MainForm::on_new_scene_triggered()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->addTab(new QWidget(ui->tabWidget), "*new_scene"));

    testgl* gl = new testgl(ui->tabWidget->currentWidget());
    //gl->resize(ui->tabWidget->currentWidget()->size());
    //gl->showFullScreen();
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

//Добавление текстуры в панель текстур
void MainForm::on_pushButton_add_texture_clicked()
{
    ui->listWidget_texture->insertItem(ui->listWidget_texture->count(), "texture");
}

//Удаление текстуры из панери текстуры
void MainForm::on_pushButton_del_texture_clicked()
{
    delete ui->listWidget_texture->currentItem();
}
