/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef DUSK_H
#define DUSK_H

#include <QDialog>
#include <QKeyEvent>
#include <QString>
#include "Overlay.h"

namespace Ui {
class Dusk;
}

class Dusk : public QDialog
{
    Q_OBJECT

public:
    explicit Dusk(QWidget *parent = 0);
    ~Dusk();

protected:
   virtual void keyPressEvent(QKeyEvent *event);

private:
   Ui::Dusk *ui;
};

#endif // DUSK_H
