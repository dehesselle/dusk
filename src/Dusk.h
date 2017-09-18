/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#ifndef DUSK_H
#define DUSK_H

#include <QDialog>
#include <QSignalMapper>
#include <QMap>
#include <QKeyEvent>
#include "Overlay.h"

namespace Ui {
class Dusk;
}

class Dusk : public QDialog
{
    Q_OBJECT

public:
    explicit Dusk(QWidget *parent = 0);
    ~Dusk();

protected:
   virtual void keyPressEvent(QKeyEvent *event);

signals:
   void boxStateChanged(const QString& text);

public slots:
   void on_boxStateChanged(const QString& text);

private slots:
   void on_Dusk_finished(int result);
   void setColorCheckbox(int itemNo);
   void resetColorCheckbox(int itemNo);
   void onWindowClosed(int screenNo);

private:
   Ui::Dusk *ui;
   QSignalMapper* m_signalMapper;
   typedef QMap<int,Overlay*> WindowMap;
   WindowMap m_windows;
};

#endif // DUSK_H
