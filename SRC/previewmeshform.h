#ifndef PREVIEWMESHFORM_H
#define PREVIEWMESHFORM_H

#include <QDialog>

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "Engine/resources.h"
#endif

namespace Ui {
class PreviewMeshForm;
}

class PreviewMeshForm : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewMeshForm(QWidget *parent = 0);
    ~PreviewMeshForm();

    void showEvent(QShowEvent* event);
    void SetKey(QString key);

private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::PreviewMeshForm *ui;
    QString key;
};

#endif // PREVIEWMESHFORM_H
