#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>

#include "testgl.h"

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

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
