/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef OVERLAY_H
#define OVERLAY_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>
#include <QCloseEvent>
#include <QKeyEvent>

class Overlay : public QMainWindow
{
   Q_OBJECT
public:
   explicit Overlay(QWidget *parent = nullptr, int screenNo = 0);

   int m_screenNo;

protected:
   virtual void closeEvent(QCloseEvent *event);
   virtual void keyPressEvent(QKeyEvent *event);

   QLabel* m_message;

signals:
   void overlayClosed();
};

#endif // OVERLAY_H
