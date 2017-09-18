/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include <QApplication>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QRect>
#include <QWidget>
#include "Overlay.h"

Overlay::Overlay(QWidget *parent, int screenNo) :
   QMainWindow(parent),
   m_screenNo(screenNo)
{
   QRect scrGeo = QApplication::desktop()->screenGeometry(m_screenNo);
   move(QPoint(scrGeo.x(), scrGeo.y()));

   m_message = new QLabel(this);

   // Usually one has to create a layout and use QWidget::setLayout(),
   // but QMainWindow is special in that case.

   QHBoxLayout* layout = new QHBoxLayout;
   m_message->setLayout(layout);

   setCentralWidget(m_message);
}

void Overlay::closeEvent(QCloseEvent *event)
{
   emit windowClosed(m_screenNo);
   QWidget::closeEvent(event);
}

void Overlay::keyPressEvent(QKeyEvent *event)
{
   QApplication::sendEvent(parentWidget(), event);
}

