#include "Dusk.h"
#include "ui_Dusk.h"
#include <QDesktopWidget>
#include <QCheckBox>
#include "ColorSwitcher.h"
#include <QMessageBox>

Dusk::Dusk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dusk)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    m_signalMapper = new QSignalMapper(this);

    for (int i=0; i<QApplication::desktop()->numScreens(); ++i)
    {
       QString checkBoxText = "Display " + QString::number(i+1);

       QCheckBox* checkBox = new QCheckBox(this);
       checkBox->setText(checkBoxText);
       ui->verticalLayout->addWidget(checkBox);

       connect(checkBox, SIGNAL(stateChanged(int)), m_signalMapper, SLOT(map(void)));
       m_signalMapper->setMapping(checkBox, checkBoxText);
    }

    connect(m_signalMapper, SIGNAL(mapped(QString)), this, SIGNAL(boxStateChanged(QString)));
    connect(this, SIGNAL(boxStateChanged(QString)), this, SLOT(on_boxStateChanged(QString)));

    QSize size = minimumSizeHint();
    //size.setWidth(size.width() + 20);
    resize(size);
}

Dusk::~Dusk()
{
   delete ui;
}

void Dusk::on_boxStateChanged(const QString& text)
{
   int screenNo = text.section(" ", -1, -1).toInt();  // get number at the end
   --screenNo;

   QCheckBox* checkBox = dynamic_cast<QCheckBox*>(ui->verticalLayout->itemAt(screenNo)->widget());

   if (checkBox->isChecked())
   {
      QRect scrGeo = QApplication::desktop()->screenGeometry(screenNo);
      QWidget* window = new QWidget(this->parentWidget());
      m_windows[screenNo] = window;

      window->setStyleSheet("background-color:black;");
      window->move(QPoint(scrGeo.x(), scrGeo.y()));
      window->showFullScreen();

      activateWindow();
   }
   else
   {
      QWidget* window = m_windows[screenNo];
      delete window;
      m_windows.remove(screenNo);
   }
}

void Dusk::on_Dusk_finished(int result)
{
   Q_UNUSED(result);
   for (WindowMap::iterator it = m_windows.begin(); it != m_windows.end(); ++it)
   {  // delete remaining windows
      QWidget* window = it.value();
      delete window;
   }
}

void Dusk::keyPressEvent(QKeyEvent* event)
{
   int screenNo = QApplication::desktop()->screenNumber(QCursor::pos());
   int keyEvent = event->key();

   switch(keyEvent)
   {
      case Qt::Key_Shift:
      {
         ColorSwitcher* colorSwitcher = new ColorSwitcher;
         colorSwitcher->setItemNo(screenNo);
         connect(colorSwitcher, SIGNAL(setColor(int)), this, SLOT(setColorCheckbox(int)));
         connect(colorSwitcher, SIGNAL(resetColor(int)), this, SLOT(resetColorCheckbox(int)));
         connect(colorSwitcher, SIGNAL(finished()), colorSwitcher, SLOT(deleteLater()));
         colorSwitcher->start();
         break;
      }
      case Qt::Key_F1:
      {
         QMessageBox::about(this, "About Dusk",
                            QString("Dusk v0.1\n\nThis is a small ") +
                            "tool to switch displays to black.\n\n" +
                            "https://github.com/dehesselle/dusk");
         break;
      }
      default:
      {
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
            default:        screenNo = -1; break;
         }

         if (screenNo >= 0 and
             screenNo < ui->verticalLayout->count())
         {
            QCheckBox* checkBox = dynamic_cast<QCheckBox*>(ui->verticalLayout->itemAt(screenNo)->widget());
            checkBox->setChecked(not checkBox->isChecked());
         }
      }
   }
}

void Dusk::setColorCheckbox(int itemNo)
{
   QCheckBox* checkBox = dynamic_cast<QCheckBox*>(ui->verticalLayout->itemAt(itemNo)->widget());
   checkBox->setStyleSheet("QCheckBox { color: red }");
   checkBox->repaint();
}

void Dusk::resetColorCheckbox(int itemNo)
{
   QCheckBox* checkBox = dynamic_cast<QCheckBox*>(ui->verticalLayout->itemAt(itemNo)->widget());
   checkBox->setStyleSheet("QCheckBox { color: black }");
   checkBox->repaint();
}