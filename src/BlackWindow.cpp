/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "BlackWindow.h"
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <QFont>
#include <QTimer>

BlackWindow::BlackWindow(QWidget *parent, int screenNo) : QMainWindow(parent),
   m_screenNo(screenNo),
   m_opacity(0.9)
{
   QRect scrGeo = QApplication::desktop()->screenGeometry(m_screenNo);
   move(QPoint(scrGeo.x(), scrGeo.y()));

   setStyleSheet("background-color:black;");
   setWindowOpacity(m_opacity);

// DEPRECATED
// When using QWidget instead of QMainWindow, every overlay is a window
// thats visiable in the taskbar.
//   setWindowIcon(QIcon(":/icons/monitor_black.ico"));
//   setWindowTitle(QString("Dusk Overlay (display ") +
//                  QString::number(m_screenNo + 1) + ")");

   m_hint = new QLabel;
   m_hint->setText(QString("Display ") + QString::number(m_screenNo + 1) +
                   "\n\n" + "scrolling up/down\nadjusts opacity");
   m_hint->setStyleSheet("font-weight: bold; color: red;");
   m_hint->setAlignment(Qt::AlignCenter);

   // Usually one has to create a layout and use QWidget::setLayout(),
   // but QMainWindow is special in that case.

   QHBoxLayout* layout = new QHBoxLayout;
   m_hint->setLayout(layout);

   {
      QFont font = m_hint->font();
      font.setPointSize(60);
      m_hint->setFont(font);
   }

   setCentralWidget(m_hint);
   QTimer::singleShot(2000, this, SLOT(hideHint()));
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

void BlackWindow::hideHint()
{
   m_hint->hide();
}

void BlackWindow::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)
   {
      if (m_hint->isHidden())   // nothing else is using m_hint right now,
                                // e.g. the initial message (see constructor)
                                // is already gone
      {
         m_hint->setText(QString("Display ") + QString::number(m_screenNo + 1) +
                         "\n\n" + "click again\nto close");

         // We are reusing the properties (font size, color etc.) that have
         // already been set in the constructor.

         m_hint->show();
         QTimer::singleShot(2000, this, SLOT(hideHint()));
      }
      else    // something else is using m_hint right now, we need to check
              // if it's the "click again" message
      {
         if (m_hint->text().contains("click again"))
         {
            close();
         }
      }
   }
}
