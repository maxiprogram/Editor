#ifndef CREATEGAMEOBJECT2DFORM_H
#define CREATEGAMEOBJECT2DFORM_H

#include <QDialog>

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "Engine/resources.h"
#endif

#include"gameobject2d.h"

namespace Ui {
class CreateGameObject2DForm;
}

class CreateGameObject2DForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGameObject2DForm(QWidget *parent = 0);
    ~CreateGameObject2DForm();
    QString key_scene;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateGameObject2DForm *ui;
};

#endif // CREATEGAMEOBJECT2DFORM_H
