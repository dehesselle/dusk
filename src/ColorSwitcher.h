/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef COLORSWITCHER_H
#define COLORSWITCHER_H

#include <QThread>

class ColorSwitcher : public QThread
{
   Q_OBJECT

public:
   ColorSwitcher();
   void setItemNo(const int& itemNo);
   void run();

signals:
   void setColor(int itemNo);
   void resetColor(int itemNo);

private:
   int m_itemNo;
};

#endif // COLORSWITCHER_H
