/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "Dusk.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dusk dusk;
    dusk.show();

    return app.exec();
}
