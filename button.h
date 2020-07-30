#ifndef BUTTON_H
#define BUTTON_H
#include <qwidget.h>
#include <qpushbutton.h>

class Button:public QWidget 
{
	Q_OBJECT
public:
	Button(QWidget *parent = 0, const char *name = 0);
public slots:

signals:

protected:
	void resizeEvent(QResizeEvent*);
private:
	QPushButton *button;
};

#endif
