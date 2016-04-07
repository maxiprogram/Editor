#ifndef PREVIEWTEXTUREFORM_H
#define PREVIEWTEXTUREFORM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class PreviewTextureForm;
}

class PreviewTextureForm : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewTextureForm(QWidget *parent = 0);
    ~PreviewTextureForm();

    void showEvent(QShowEvent* event);
    void SetPath(QString path);
    void SetKey(QString key);

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::PreviewTextureForm *ui;
    QString key;
    QString path;
    QImage image;
};

#endif // PREVIEWTEXTUREFORM_H
