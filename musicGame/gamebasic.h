#ifndef GAMEBASIC_H
#define GAMEBASIC_H
#include "score.h"
#include <QWidget>
#include <QLabel>
class Game;

class Gamebasic : public QWidget
{
    Q_OBJECT
public:
    Gamebasic(Game *g,Score *score);
    void press_Up(bool check,int count);void press_Down(bool check , int count);
    void press_Left(bool check , int count);void press_Right(bool check , int count);
    void release_Up();void release_Down();
    void release_Left();void release_Right();
private:
    void init(Game *g);

    Score  *s;
    QImage *basicData_Up,*basicData_Left,*basicData_Down,*basicData_Right;
    QImage *Cl_Up,*Cl_Left,*Cl_Down,*Cl_Right;
    QLabel *Up,*Left,*Down,*Right;
    QLabel *score_outPut;

};

#endif // GAMEBASIC_H
