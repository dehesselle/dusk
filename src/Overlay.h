/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef OVERLAY_H
#define OVERLAY_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>

class Overlay : public QMainWindow
{
   Q_OBJECT
public:
   explicit Overlay(QWidget *parent = nullptr, int screenNo = 0);

   int m_screenNo;
   qreal m_opacity;

protected:
   virtual void closeEvent(QCloseEvent *event);
//   virtual void wheelEvent(QWheelEvent *event);
   virtual void keyPressEvent(QKeyEvent *event);
//   virtual void mousePressEvent(QMouseEvent *event);

   QLabel* m_message;

signals:
   void windowClosed(int screenNo);

};

#endif // OVERLAY_H
