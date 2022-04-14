#include "mainwindow.h"
#include "filebrowser.h"
#include <fstream>
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    system ( "start C:/Users/Michal/OneDrive/Documents/voice_control/main/main.exe");
    w.check_actual_commands();
    w.show();


    return a.exec();
}
