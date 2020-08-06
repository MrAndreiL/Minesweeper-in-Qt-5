#include "button.h"
#include <qfont.h>

Button::Button(QWidget *parent, const char *name):QWidget(parent, 0)
{
   button = new QPushButton(this);
   button->setFont(QFont("Times", 18, QFont::Bold));
   button->setGeometry(0, 0, width(), height());
   button->setStyleSheet("background-image: url(:/resources/img/button.png)");
   connect(button, SIGNAL(clicked()), SIGNAL(clicked()));
   connect(button, SIGNAL(clicked()), SLOT(changeState()));
}

void Button::changeState()
{
   state = 1;
   button->setVisible(false);
}
