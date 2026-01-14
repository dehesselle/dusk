/* Dusk - a small utility to switch screens to black
 *
 * https://github.com/dehesselle/dusk
 */

#include "Dusk.h"
#include <QMessageBox>
#include <QTimer>
#include "CheckBox.h"
#include "IdentityOverlay.h"
#include "ui_Dusk.h"
#include "version.hpp"

Dusk::Dusk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dusk)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint |
                   Qt::MSWindowsFixedSizeDialogHint);

    for (int i = 0; i < QApplication::screens().count();
         ++i) { // create checkboxes for every display

        CheckBox *checkBox = new CheckBox(this, i);
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
   switch(event->key())
   {
      case Qt::Key_Shift:
      {
          for (int i = 0; i < QApplication::screens().count(); ++i) {
              IdentityOverlay *overlay = new IdentityOverlay(this, i);
              overlay->showFullScreen(); // this also activates the new window...
              activateWindow();          // ...but we don't want that
              QTimer::singleShot(2000, overlay, SLOT(deleteLater()));
          }
         break;
      }
      case Qt::Key_F1:
      {
          QMessageBox::about(this,
                             "About Dusk",
                             QString("Dusk ") + PROJECT_VERSION + QString("\n\n")
                                 + "https://github.com/dehesselle/dusk\n"
                                   "Icon by MazeNL77.");
          QMessageBox::aboutQt(this);
          break;
      }
      case Qt::Key_1:
      case Qt::Key_2:
      case Qt::Key_3:
      case Qt::Key_4:
      case Qt::Key_5:
      case Qt::Key_6:
      case Qt::Key_7:
      case Qt::Key_8:
      case Qt::Key_9:
      {
         int displayNo = event->text().toInt() - 1;

         if (displayNo < ui->verticalLayout->count())
         {
            CheckBox* checkBox = dynamic_cast<CheckBox*>(
                     ui->verticalLayout->itemAt(displayNo)->widget());
            checkBox->toggle();
         }
      }
      default:
      {
         break;
      }
   }
}
