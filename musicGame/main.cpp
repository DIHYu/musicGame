#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int restart = a.exec();
    if(restart == 777)
    {
        QProcess::startDetached(a.applicationFilePath(), QStringList());
        return 0;
    }
    return restart;
}
