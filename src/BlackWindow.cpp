#include "BlackWindow.h"
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>

BlackWindow::BlackWindow(QWidget *parent, int screenNo) : QWidget(parent),
   m_screenNo(screenNo)
{
   QRect scrGeo = QApplication::desktop()->screenGeometry(m_screenNo);

   setStyleSheet("background-color:black;");
   move(QPoint(scrGeo.x(), scrGeo.y()));
}


void BlackWindow::closeEvent(QCloseEvent *event)
{
   emit windowClosed(m_screenNo);
   QWidget::closeEvent(event);
}
