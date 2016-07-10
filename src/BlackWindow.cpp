/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "BlackWindow.h"
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>
#include <QIcon>

BlackWindow::BlackWindow(QWidget *parent, int screenNo) : QWidget(parent),
   m_screenNo(screenNo),
   m_opacity(0.9)
{
   QRect scrGeo = QApplication::desktop()->screenGeometry(m_screenNo);
   move(QPoint(scrGeo.x(), scrGeo.y()));

   setStyleSheet("background-color:black;");
   setWindowOpacity(m_opacity);
   setWindowIcon(QIcon(":/icons/monitor_black.ico"));
}

void BlackWindow::closeEvent(QCloseEvent *event)
{
   emit windowClosed(m_screenNo);
   QWidget::closeEvent(event);
}

void BlackWindow::wheelEvent(QWheelEvent *event)
{
   if (event->orientation() == Qt::Vertical)
   {
      if (event->delta() > 0)
      {
         if (m_opacity < 1.0)
            m_opacity += 0.1;
      }
      else
      {
         if (m_opacity > 0.2)
            m_opacity -= 0.1;
      }

      setWindowOpacity(m_opacity);
   }
   event->accept();
}
