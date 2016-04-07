#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTreeWidget>

#include "previewtextureform.h"
#include "previewshaderform.h"
#include "previewmeshform.h"

#include "testgl.h"

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "E:\Projects\For_Git\PacManRun\PacManRun\SRC\Engine\resources.h"
#endif

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void on_exit_triggered();

    void on_new_scene_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_close_scene_triggered();

    void on_close_all_scene_triggered();

    void on_pushButton_del_property_clicked();

    void on_pushButton_add_property_clicked();

    void on_pushButton_add_texture_clicked();

    void on_pushButton_del_texture_clicked();

    void on_treeWidget_texture_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_add_shader_clicked();

    void on_pushButton_del_shader_clicked();

    void on_pushButton_add_mesh_clicked();

    void on_pushButton_del_mesh_clicked();

    void on_treeWidget_shader_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_mesh_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
