#ifndef PREVIEWSHADERFORM_H
#define PREVIEWSHADERFORM_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "E:\Projects\For_Git\PacManRun\PacManRun\SRC\Engine\resources.h"
#endif

namespace Ui {
class PreviewShaderForm;
}

class PreviewShaderForm : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewShaderForm(QWidget *parent = 0);
    ~PreviewShaderForm();

    void showEvent(QShowEvent* event);

    void SetKey(QString key);
    void SetPathVert(QString path_vert);
    void SetPathFrag(QString path_frag);

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::PreviewShaderForm *ui;
    QString key;
    QString path_vert;
    QString path_frag;
};

#endif // PREVIEWSHADERFORM_H
