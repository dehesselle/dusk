/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef BLACKOVERLAY_H
#define BLACKOVERLAY_H

#include <QObject>
#include "Overlay.h"

class BlackOverlay : public Overlay
{
public:
   Q_OBJECT
public:
   explicit BlackOverlay(QWidget *parent = nullptr, int screenNo = 0);

protected:
   virtual void wheelEvent(QWheelEvent *event);
   virtual void mousePressEvent(QMouseEvent *event);

public slots:
   void hideMessage();

};

#endif // BLACKOVERLAY_H
