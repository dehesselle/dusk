#include <QFont>
#include <QString>
#include <QTimer>
#include <QMouseEvent>
#include <QWheelEvent>
#include "BlackOverlay.h"

BlackOverlay::BlackOverlay(QWidget *parent, int screenNo) :
   Overlay(parent, screenNo)
{
   setStyleSheet("background-color:black;");
   setWindowOpacity(0.9);

   m_message->setText(QString("Display ") + QString::number(m_screenNo + 1) +
                      "\n\n" + "scrolling up/down\nadjusts opacity");
   m_message->setStyleSheet("font-weight: bold; color: red;");
   m_message->setAlignment(Qt::AlignCenter);

   {
      QFont font = m_message->font();
      font.setPointSize(60);
      m_message->setFont(font);
   }

   QTimer::singleShot(2000, this, SLOT(hideMessage()));
}


void BlackOverlay::hideMessage()
{
   m_message->hide();
}

void BlackOverlay::wheelEvent(QWheelEvent *event)
{
   if (event->orientation() == Qt::Vertical)
   {
      if (event->delta() > 0)
      {
         if (windowOpacity() < 1.0)
            setWindowOpacity(windowOpacity() + 0.1);
      }
      else
      {
         if (windowOpacity() > 0.2)
            setWindowOpacity(windowOpacity() - 0.1);
      }
   }

   event->accept();
}


void BlackOverlay::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)
   {
      if (m_message->isHidden())   // nothing else is using m_hint right now,
                                // e.g. the initial message (see constructor)
                                // is already gone
      {
         m_message->setText(QString("Display ") + QString::number(m_screenNo + 1) +
                         "\n\n" + "click again\nto close");

         // We are reusing the properties (font size, color etc.) that have
         // already been set in the constructor.

         m_message->show();
         QTimer::singleShot(2000, this, SLOT(hideMessage()));
      }
      else    // something else is using m_hint right now, we need to check
              // if it's the "click again" message
      {
         if (m_message->text().contains("click again"))
         {
            close();
         }
      }
   }
}
