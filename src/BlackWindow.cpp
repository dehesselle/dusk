/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "BlackWindow.h"
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>

BlackWindow::BlackWindow(QWidget *parent, int screenNo) : QMainWindow(parent),
   m_screenNo(screenNo),
   m_opacity(0.9)
{
   QRect scrGeo = QApplication::desktop()->screenGeometry(m_screenNo);
   move(QPoint(scrGeo.x(), scrGeo.y()));

   setStyleSheet("background-color:black;");
   setWindowOpacity(m_opacity);

// only required if we want to show the windows in the taskbar
//   setWindowIcon(QIcon(":/icons/monitor_black.ico"));
//   setWindowTitle(QString("Dusk Overlay (display ") +
//                  QString::number(m_screenNo + 1) + ")");
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

void BlackWindow::keyPressEvent(QKeyEvent *event)
{
   QApplication::sendEvent(parentWidget(), event);
}
