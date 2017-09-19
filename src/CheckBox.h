#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QObject>
#include <QCheckBox>

class CheckBox : public QCheckBox
{
   Q_OBJECT
public:
   explicit CheckBox(QWidget *parent = nullptr, int screenNo = 0);

private:
   int m_screenNo;

signals:
   void unchecked();

private slots:
   void uncheck();
   void on_stateChanged(int state);

};

#endif // CHECKBOX_H
