#include "mainform.h"
#include <QApplication>
#include <QtOpenGL>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm w;
    w.showMaximized();

    return a.exec();
}
