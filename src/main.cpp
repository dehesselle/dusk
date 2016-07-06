#include "Dusk.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dusk w;
    w.show();

    return a.exec();
}
