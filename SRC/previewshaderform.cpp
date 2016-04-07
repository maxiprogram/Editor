#include "previewshaderform.h"
#include "ui_previewshaderform.h"

PreviewShaderForm::PreviewShaderForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewShaderForm)
{
    ui->setupUi(this);
}

PreviewShaderForm::~PreviewShaderForm()
{
    delete ui;
}

void PreviewShaderForm::SetKey(QString key)
{
    this->key = key;
}
void PreviewShaderForm::SetPathVert(QString path_vert)
{
    this->path_vert = path_vert;
}

void PreviewShaderForm::SetPathFrag(QString path_frag)
{
    this->path_frag = path_frag;
}

void PreviewShaderForm::on_pushButton_cancel_clicked()
{
    this->close();
}

void PreviewShaderForm::showEvent(QShowEvent* event)
{
    QFile file(path_vert);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Не удалось открыть файл '"+path_vert+"'!");
        return;
    }
    QByteArray byte = file.readAll();
    file.close();
    ui->textEdit_vert->setText(byte);

    file.setFileName(path_frag);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Не удалось открыть файл '"+path_frag+"'!");
        return;
    }
    byte.clear();
    byte = file.readAll();
    file.close();
    ui->textEdit_frag->setText(byte);
}

void PreviewShaderForm::on_pushButton_save_clicked()
{
    QFile file(path_vert);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Не удалось открыть файл '"+path_vert+"'!");
        return;
    }
    QByteArray byte;
    byte.append(ui->textEdit_vert->toPlainText());
    file.write(byte);
    file.close();

    file.setFileName(path_frag);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!file.isOpen())
    {
        QMessageBox::warning(this, "Ошибка открытия файла", "Не удалось открыть файл '"+path_frag+"'!");
        return;
    }
    byte.clear();
    byte.append(ui->textEdit_frag->toPlainText());
    file.write(byte);
    file.close();

    Shader* shader = new Shader;
    bool flag = shader->Load(path_vert, path_frag);
    if (!flag)
    {
        QMessageBox::warning(this, "Изменение шейдера", "Не удалось изменить шейдер! Проверте синтаксис.");
        delete shader;
        return;
    }
    Resources::SHADER()->Delete(key.toInt());
    Resources::SHADER()->Add(key.toInt(), shader);
    this->close();
}
