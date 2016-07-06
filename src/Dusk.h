#ifndef DUSK_H
#define DUSK_H

#include <QDialog>
#include <QSignalMapper>
#include <QMap>
#include <QKeyEvent>

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

private:
   Ui::Dusk *ui;
   QSignalMapper* m_signalMapper;
   typedef QMap<int,QWidget*> WindowMap;
   WindowMap m_windows;
};

#endif // DUSK_H
