#ifndef ADDSPRITEFORM_H
#define ADDSPRITEFORM_H

#include <QDialog>
#include <QTreeWidget>

#include "mainform.h"
#include "previewshaderform.h"
#include "previewmeshform.h"
#include "previewtextureform.h"

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "Engine/resources.h"
#endif

namespace Ui {
class AddSpriteForm;
}

class AddSpriteForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddSpriteForm(QWidget *parent = 0);
    ~AddSpriteForm();

    void showEvent(QShowEvent* event);
    void SetKey(QString key);

public slots:
    void onRecievTreeShader(QTreeWidget* tree_shader);
    void onRecievTreeMesh(QTreeWidget* tree_mesh);
    void onRecievTreeTexture(QTreeWidget* tree_texture);

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_preview_shader_clicked();

    void on_pushButton_preview_mesh_clicked();

    void on_pushButton_preview_texture_clicked();

    void on_pushButto_add_clicked();

signals:
    void get_tree_shader();
    void get_tree_mesh();
    void get_tree_texture();
    void send_tree_sprite(QString key_sprite, QString key_shader, QString key_mesh, QString key_texture);

private:
    Ui::AddSpriteForm *ui;
    QString key;
};

#endif // ADDSPRITEFORM_H
