#ifndef BUTTON_H
#define BUTTON_H
#include <qwidget.h>
#include <qpushbutton.h>

class Button:public QWidget 
{
  Q_OBJECT
public:
  Button(QWidget *parent = 0, const char *name = 0);
  int state = 0;
  /*
  	3 states:
  	0 -> default button, not discovered
  	1 -> left clicked, can be bomb or number.
  	2 -> right clicked (flagged)
  */
public slots:
  void changeState();
signals:
  void clicked();
private:
  QPushButton *button;
};

#endif
