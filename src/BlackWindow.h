/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef BLACKWINDOW_H
#define BLACKWINDOW_H

#include <QWidget>

class BlackWindow : public QWidget
{
   Q_OBJECT
public:
   explicit BlackWindow(QWidget *parent = 0, int screenNo = 0);

   int m_screenNo;
   qreal m_opacity;

protected:
   virtual void closeEvent(QCloseEvent *event);
   virtual void wheelEvent(QWheelEvent *event);

signals:
   void windowClosed(int screenNo);

public slots:
};

#endif // BLACKWINDOW_H
