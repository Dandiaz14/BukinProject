#include "mainwindow.h"
#include "admin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///a.setStyle("fusion");

    ///MainWindow w;
    admin adm;
    adm.start();

    return a.exec();
}
