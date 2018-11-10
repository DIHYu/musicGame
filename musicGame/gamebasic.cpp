#include "gamebasic.h"
#include "game.h"
#define Arrow_Size 130

Gamebasic :: Gamebasic(Game *g,Score *score):
    s(score)
{
    init(g);
    *basicData_Up    = basicData_Up   ->scaled(Arrow_Size,Arrow_Size);
    *basicData_Left  = basicData_Left ->scaled(Arrow_Size,Arrow_Size);
    *basicData_Down  = basicData_Down ->scaled(Arrow_Size,Arrow_Size);
    *basicData_Right = basicData_Right->scaled(Arrow_Size,Arrow_Size);
    Up    -> setGeometry(Arrow_Size+40,0,Arrow_Size,Arrow_Size);
    Up    -> setPixmap(QPixmap::fromImage(*basicData_Up));
    Left  -> setGeometry(20,0,Arrow_Size,Arrow_Size);
    Left  -> setPixmap(QPixmap::fromImage(*basicData_Left));
    Down  -> setGeometry(Arrow_Size*2+60,0,Arrow_Size,Arrow_Size);
    Down  -> setPixmap(QPixmap::fromImage(*basicData_Down));
    Right -> setGeometry(Arrow_Size*3+80,0,Arrow_Size,Arrow_Size);
    Right -> setPixmap(QPixmap::fromImage(*basicData_Right));

}
void Gamebasic :: init(Game *g)
{
    Up    = new QLabel(g);
    Left  = new QLabel(g);
    Down  = new QLabel(g);
    Right = new QLabel(g);
    basicData_Up   = new QImage;basicData_Left  = new QImage;
    basicData_Down = new QImage;basicData_Right = new QImage;
    basicData_Up    ->load("image/arrow/B_UpArrow.png");
    basicData_Left  ->load("image/arrow/B_LeftArrow.png");
    basicData_Down  ->load("image/arrow/B_DownArrow.png");
    basicData_Right ->load("image/arrow/B_RightArrow.png");
    /**************** Cl set ******************/
    Cl_Up   = new QImage;Cl_Left  = new QImage;
    Cl_Down = new QImage;Cl_Right = new QImage;
    Cl_Up    ->load("image/arrow/Cl_UpArrow.png");
    Cl_Left  ->load("image/arrow/Cl_LeftArrow.png");
    Cl_Down  ->load("image/arrow/Cl_DownArrow.png");
    Cl_Right ->load("image/arrow/Cl_RightArrow.png");
    *Cl_Up    = Cl_Up->scaled(Arrow_Size+20,Arrow_Size+20);
    *Cl_Left  = Cl_Left->scaled(Arrow_Size+20,Arrow_Size+20);
    *Cl_Down  = Cl_Down->scaled(Arrow_Size+20,Arrow_Size+20);
    *Cl_Right = Cl_Right->scaled(Arrow_Size+20,Arrow_Size+20);

}
void Gamebasic :: press_Up(bool check , int count)
{
    *basicData_Up = basicData_Up->scaled(Arrow_Size+20,Arrow_Size+20);
    Up->setGeometry(Arrow_Size+40,0,Arrow_Size+20,Arrow_Size+20);
    Up->setPixmap(QPixmap::fromImage(*basicData_Up));
    if(check)
    {
         Up->setPixmap(QPixmap::fromImage(*Cl_Up));
         s->printScore(s->countScore(count));
    }

}
void Gamebasic :: press_Down(bool check , int count)
{
    *basicData_Down = basicData_Down->scaled(Arrow_Size+20,Arrow_Size+20);
    Down->setGeometry(Arrow_Size*2+60,0,Arrow_Size+20,Arrow_Size+20);
    Down->setPixmap(QPixmap::fromImage(*basicData_Down));
    if(check)
    {
         Down->setPixmap(QPixmap::fromImage(*Cl_Down));
         s->printScore(s->countScore(count));
    }
}
void Gamebasic :: press_Left(bool check , int count)
{
    *basicData_Left = basicData_Left->scaled(Arrow_Size+20,Arrow_Size+20);
    Left->setGeometry(20,0,Arrow_Size+20,Arrow_Size+20);
    Left->setPixmap(QPixmap::fromImage(*basicData_Left));
    if(check)
    {
         Left->setPixmap(QPixmap::fromImage(*Cl_Left));
         s->printScore(s->countScore(count));
    }
}
void Gamebasic :: press_Right(bool check , int count)
{
    *basicData_Right = basicData_Right->scaled(Arrow_Size+20,Arrow_Size+20);
    Right->setGeometry(Arrow_Size*3+80,0,Arrow_Size+20,Arrow_Size+20);
    Right->setPixmap(QPixmap::fromImage(*basicData_Right));
    if(check)
    {
         Right->setPixmap(QPixmap::fromImage(*Cl_Right));
         s->printScore(s->countScore(count));
    }
}
void Gamebasic :: release_Up()
{
    *basicData_Up = basicData_Up->scaled(Arrow_Size,Arrow_Size);
    Up->setGeometry(Arrow_Size+40,0,Arrow_Size,Arrow_Size);
    Up->setPixmap(QPixmap::fromImage(*basicData_Up));
}
void Gamebasic :: release_Down()
{
    *basicData_Down = basicData_Down->scaled(Arrow_Size,Arrow_Size);
    Down->setGeometry(Arrow_Size*2+60,0,Arrow_Size,Arrow_Size);
    Down->setPixmap(QPixmap::fromImage(*basicData_Down));
}
void Gamebasic :: release_Left()
{
    *basicData_Left = basicData_Left->scaled(Arrow_Size,Arrow_Size);
    Left->setGeometry(20,0,Arrow_Size,Arrow_Size);
    Left->setPixmap(QPixmap::fromImage(*basicData_Left));
}
void Gamebasic :: release_Right()
{
    *basicData_Right = basicData_Right->scaled(Arrow_Size,Arrow_Size);
    Right->setGeometry(Arrow_Size*3+80,0,Arrow_Size,Arrow_Size);
    Right->setPixmap(QPixmap::fromImage(*basicData_Right));
}
