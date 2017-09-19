#include "CheckBox.h"
#include "BlackOverlay.h"

CheckBox::CheckBox(QWidget *parent, int screenNo) :
   QCheckBox(parent),
   m_screenNo(screenNo)
{
   setText(QString("Display ") + QString::number(m_screenNo + 1));
   connect(this, SIGNAL(stateChanged(int)), this, SLOT(on_stateChanged(int)));
}

void CheckBox::on_stateChanged(int state)
{
   switch (state)
   {
      case Qt::Unchecked:
         emit unchecked();
         break;
      case Qt::Checked:
      {
         BlackOverlay *overlay = new BlackOverlay(this, m_screenNo);
         overlay->showFullScreen();   // this also activates the new window...
         activateWindow();            // ...but we don't want that
         connect(this, SIGNAL(unchecked()), overlay, SLOT(deleteLater()));
         connect(overlay, SIGNAL(overlayClosed()), this, SLOT(uncheck()));

         break;
      }
      default:
         break;
   }
}


void CheckBox::uncheck()
{
   setChecked(false);
}
