/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef IDENTITYOVERLAY_H
#define IDENTITYOVERLAY_H

#include <QObject>
#include "Overlay.h"

class IdentityOverlay : public Overlay
{
public:
   Q_OBJECT
public:
   explicit IdentityOverlay(QWidget *parent = nullptr, int screenNo = 0);
};

#endif // IDENTITYOVERLAY_H
