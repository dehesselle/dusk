/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "ColorSwitcher.h"

ColorSwitcher::ColorSwitcher()
{
}

void ColorSwitcher::run()
{
   for (int i=0; i<5; i++)
   {
      emit setColor(m_itemNo);
      msleep(200);
      emit resetColor(m_itemNo);
      msleep(200);
   }
}

void ColorSwitcher::setItemNo(const int &itemNo)
{
   m_itemNo = itemNo;
}
