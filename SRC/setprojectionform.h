#ifndef SETPROJECTIONFORM_H
#define SETPROJECTIONFORM_H

#include <QDialog>
#include <QMatrix4x4>

struct DataProjection
{
    bool ortho;
    float near_;
    float far_;
    float angle;
};

namespace Ui {
class SetProjectionForm;
}

class SetProjectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit SetProjectionForm(QWidget *parent = 0);
    ~SetProjectionForm();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_apply_clicked();

    void on_radioButton_ortho_clicked();

    void on_radioButton_perspective_clicked();

signals:
    void send_projection(DataProjection proj);

private:
    Ui::SetProjectionForm *ui;
};

#endif // SETPROJECTIONFORM_H
