#include "button.h"
#include <qfont.h>

Button::Button(QWidget *parent, const char *name):QWidget(parent, 0)
{
	button = new QPushButton("", this);
	button->setFont(QFont("Times", 18, Qt::Bold));
	button->setGeometry(0, 0, width(), height());
}