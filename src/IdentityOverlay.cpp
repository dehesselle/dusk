/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include <QFont>
#include <QString>
#include "IdentityOverlay.h"

IdentityOverlay::IdentityOverlay(QWidget *parent, int screenNo) :
   Overlay(parent, screenNo)
{
   setStyleSheet("background-color:black;");
   setWindowOpacity(0.5);

   m_message->setText(QString::number(m_screenNo + 1));
   m_message->setStyleSheet("font-weight: bold; color: red;");
   m_message->setAlignment(Qt::AlignCenter);

   {
      QFont font = m_message->font();
      font.setPointSize(500);
      m_message->setFont(font);
   }
}
