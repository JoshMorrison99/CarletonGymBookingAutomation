#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon(":/imgs/C:/Users/joshm/OneDrive/Desktop/icon.ico"));
    w.show();
    return a.exec();
}
