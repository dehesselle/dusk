/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef BLACKWINDOW_H
#define BLACKWINDOW_H

#include <QMainWindow>
#include <QLabel>

class BlackWindow : public QMainWindow
{
   Q_OBJECT
public:
   explicit BlackWindow(QWidget *parent = 0, int screenNo = 0);

   int m_screenNo;
   qreal m_opacity;

protected:
   virtual void closeEvent(QCloseEvent *event);
   virtual void wheelEvent(QWheelEvent *event);
   virtual void keyPressEvent(QKeyEvent *event);
   virtual void mousePressEvent(QMouseEvent *event);

private:
   QLabel* m_hint;

signals:
   void windowClosed(int screenNo);

public slots:
   void hideHint();
};

#endif // BLACKWINDOW_H
