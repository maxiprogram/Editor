#ifndef CREATEGAMEOBJECT2DFORM_H
#define CREATEGAMEOBJECT2DFORM_H

#include <QDialog>

namespace Ui {
class CreateGameObject2DForm;
}

class CreateGameObject2DForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGameObject2DForm(QWidget *parent = 0);
    ~CreateGameObject2DForm();

private:
    Ui::CreateGameObject2DForm *ui;
};

#endif // CREATEGAMEOBJECT2DFORM_H
