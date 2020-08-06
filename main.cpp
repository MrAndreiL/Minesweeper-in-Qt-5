#include <qapplication.h>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QRandomGenerator>
#include "button.h"


// Main game class.
class Minesweeper:public QWidget
{
public:
  Minesweeper(QWidget *parent = 0, const char *name = 0, qint32 bombs = 10);
private:
  QPushButton *quit;
  QLabel *labels[3];
  QLabel *elements[9][9];
  Button *values[9][9];
  qint32 table[9][9];
  void getRandomBombs(qint32 table[9][9], qint32 bombs);
};

Minesweeper::Minesweeper(QWidget *parent, const char *name, qint32 bombs):QWidget(parent, Qt::Window)
{
   // Set the window's default Size.
   setMinimumSize(520, 400);
   setMaximumSize(520, 400);

   // Simple quit button.
   quit = new QPushButton("Quit", this);
   quit->setFont(QFont("Times", 18, QFont::Bold));
   quit->setGeometry(215, 360, 70, 30);
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

   qint32 startx = 40;
   qint32 starty = 30;
   getRandomBombs(table, bombs);
   for (qint32 i = 0; i < 9; i++)
       for (qint32 j = 0; j < 9; j++) {
         elements[i][j] = new QLabel(this);
         elements[i][j]->setGeometry(startx + (j + 1) * 40, starty + (i + 1) * 30, 35, 30);
         elements[i][j]->setStyleSheet("background-image: url(:/resources/img/bomb.jpg)");
       }

   // Draw the main board.
   for (qint32 i = 0; i < 9; i++)
     for (qint32 j = 0; j < 9; j++) {
   	 	values[i][j] = new Button(this);
        values[i][j]->setGeometry(startx + (j + 1) * 40, starty + (i + 1) * 30, 40, 40);
     }
}

void Minesweeper::getRandomBombs(qint32 table[9][9], qint32 bombs)
{
   for (qint32 i = 0; i < 9; i++)
       for(qint32 j = 0; j < 9; j++)
           table[i][j] = 0;

   while(bombs > 0)
   {
       qint32 i = QRandomGenerator::global()->bounded(0, 8);
       qint32 j = QRandomGenerator::global()->bounded(0, 8);
       if (table[i][j] == 0) {
           table[i][j] = 1;
           bombs--;
       }
   }
}

int main(int argc, char **argv)
{
   QApplication *app = new QApplication(argc, argv);

   Minesweeper *game = new Minesweeper();
   game->setGeometry(500, 250, 400, 400);
   game->show();

   return app->exec();
}
