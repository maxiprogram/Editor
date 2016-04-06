#include "previewtextureform.h"
#include "ui_previewtextureform.h"

PreviewTextureForm::PreviewTextureForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewTextureForm)
{
    ui->setupUi(this);
}

PreviewTextureForm::~PreviewTextureForm()
{
    delete ui;
}

void PreviewTextureForm::SetPath(QString path)
{
    this->path = path;
}

void PreviewTextureForm::SetKey(QString key)
{
    this->key = key;
}

void PreviewTextureForm::showEvent(QShowEvent * event)
{
    if (!image.load(path))
    {
        QMessageBox::warning(this, "Ошибка открытия", "Не удалось открыть файл! "+path);
        return;
    }
    ui->label_image->setPixmap(QPixmap::fromImage(image));
    ui->label_image->adjustSize();
    ui->label_info->setText("ID key: "+key+
                            "\nПуть: "+path+
                            "\nШирина: "+QString::number(image.width())+
                            "\nВысота: "+QString::number(image.height()));
}
