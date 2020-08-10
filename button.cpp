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
   if (state == 0) {
       state = 1;
       button->setVisible(false);
   }
}

void Button::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        if (state == 0)
        {
            state = 2;
            button->setStyleSheet("background-image: url(:/resources/img/flag.png)");
        }
        else if (state == 2)
        {
            state = 0;
            button->setStyleSheet("background-image: url(:/resources/img/button.png)");
        }
    }
}
