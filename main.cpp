#include "mainwindow.h"
#include <QApplication>
#include "ntree.h"

void llenarTab();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    vector<vector<int> > tablero;
    NTree<vector<vector<int> > > tree(tablero,3);

    return a.exec();
}
