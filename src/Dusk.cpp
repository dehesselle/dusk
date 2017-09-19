/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "Dusk.h"
#include "ui_Dusk.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTimer>
#include "IdentityOverlay.h"
#include "CheckBox.h"

Dusk::Dusk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dusk)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    for (int i=0; i<QApplication::desktop()->numScreens(); ++i)
    {  // create checkboxes for every display


       CheckBox* checkBox = new CheckBox(this, i);
       ui->verticalLayout->addWidget(checkBox);
    }

    resize(minimumSizeHint());
}

Dusk::~Dusk()
{
   delete ui;
}


void Dusk::keyPressEvent(QKeyEvent* event)
{
   int keyEvent = event->key();

   switch(keyEvent)
   {
      case Qt::Key_Shift:
      {
         for (int i=0; i<QApplication::desktop()->numScreens(); ++i)
         {
            IdentityOverlay *overlay = new IdentityOverlay(this, i);
            overlay->showFullScreen();  // this also activates the new window...
            activateWindow();           // ...but we don't want that
            QTimer::singleShot(2000, overlay, SLOT(deleteLater()));
         }
         break;
      }
      case Qt::Key_F1:
      {
         QMessageBox::about(this, "About Dusk",
                            QString("Dusk v0.5\n\nThis is a small ") +
                            "tool to switch displays to black.\n" +
                            "https://github.com/dehesselle/dusk\n\n" +
                            "Developed using msys2, mingw-w64 and Qt.\n"
                            "Icon by http://aablab.deviantart.com.");
         break;
      }
      default:
      {
         int screenNo = -1;

         switch(keyEvent)
         {
            case Qt::Key_1: screenNo = 0; break;
            case Qt::Key_2: screenNo = 1; break;
            case Qt::Key_3: screenNo = 2; break;
            case Qt::Key_4: screenNo = 3; break;
            case Qt::Key_5: screenNo = 4; break;
            case Qt::Key_6: screenNo = 5; break;
            case Qt::Key_7: screenNo = 6; break;
            case Qt::Key_8: screenNo = 7; break;
            case Qt::Key_9: screenNo = 8; break;
            default:                      break;
         }

         if (screenNo >= 0 and
             screenNo < ui->verticalLayout->count())
         {
            CheckBox* checkBox = dynamic_cast<CheckBox*>(ui->verticalLayout->itemAt(screenNo)->widget());
            checkBox->toggle();
         }
      }
   }
}
