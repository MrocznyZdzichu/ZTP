#include "mainwindow.h"
#include "Interface.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *appWindow = new MainWindow;
    Interface::setWindow(appWindow);
    appWindow = NULL;

    Interface::showWindow();

    return a.exec();
}
