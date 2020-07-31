#include <qapplication.h>
#include <QPushButton>
#include <qfont.h>
#include "button.h"


// Main game class.
class Minesweeper:public QWidget
{
public:
  Minesweeper(QWidget *parent = 0, const char *name = 0);
private:
  QPushButton *quit;
  Button *values[9][9];
};

Minesweeper::Minesweeper(QWidget *parent, const char *name):QWidget(parent, Qt::Window)
{
   // Set the window's default Size.
   setMinimumSize(520, 520);
   setMaximumSize(520, 520);

   quit = new QPushButton("Quit", this);
   quit->setFont(QFont("Times", 18, QFont::Bold));
   quit->setGeometry(215, 470, 70, 30);
   connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

int main(int argc, char **argv)
{
   QApplication *app = new QApplication(argc, argv);

   Minesweeper *game = new Minesweeper();
   game->setGeometry(500, 250, 520, 520);
   game->show();

   return app->exec();
}
