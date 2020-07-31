#include <qapplication.h>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include "button.h"


// Main game class.
class Minesweeper:public QWidget
{
public:
  Minesweeper(QWidget *parent = 0, const char *name = 0, int bombs = 4);
  int numBombs;
private:
  QPushButton *quit;
  QLabel *labels[3];
  Button *values[9][9];
};

Minesweeper::Minesweeper(QWidget *parent, const char *name, int bombs):QWidget(parent, Qt::Window)
{
   // Set the window's default Size.
   setMinimumSize(520, 520);
   setMaximumSize(520, 520);

   // Simple quit button.
   quit = new QPushButton("Quit", this);
   quit->setFont(QFont("Times", 18, QFont::Bold));
   quit->setGeometry(215, 470, 70, 30);
   connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

   // Labels.
   labels[0] = new QLabel(this);
   labels[0]->setText("Minesweeper!\n Easy Difficulty(9x9)");
   labels[0]->move(70, 10);
   labels[0]->setFont(QFont("Times", 13, QFont::Bold));

   labels[1] = new QLabel(this);
   labels[1]->setText("Bombs Left:");
   labels[1]->move(300, 25);
   labels[1]->setFont(QFont("Times", 13, QFont::Bold));

   labels[2] = new QLabel(this);
   labels[2]->setNum(bombs);
   labels[2]->move(400, 25);
   labels[2]->setFont(QFont("Times", 13, QFont::Bold));

   // Draw the main board.
   int startx = 40;
   int starty = 35;
   for (int i = 0; i < 9; i++)
     for (int j = 0; j < 9; j++) {
   	 	values[i][j] = new Button(this);
        values[i][j]->setGeometry(startx + (i + 1) * 40, starty + (j + 1) * 40, 40, 40);
     }
}

int main(int argc, char **argv)
{
   QApplication *app = new QApplication(argc, argv);

   Minesweeper *game = new Minesweeper();
   game->setGeometry(500, 250, 520, 520);
   game->show();

   return app->exec();
}
