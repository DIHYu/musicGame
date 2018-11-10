#include "move.h"
#include <QTime>
#define Max_Arrow 10
#define Arrow_Size 130

Move :: Move(Score *score):
    s(score)
{


}

/*void Move :: move_Up(QLabel **l, QPoint **p, int *o,int *t)
{

}

void Move :: move_Left(QLabel **l, QPoint **p, int *o,int *t)
{

}
void Move :: move_Down(QLabel **l, QPoint **p, int *o,int *t)
{


}
void Move :: move_Right(QLabel **l, QPoint **p, int *o,int *t)
{


}*/
void Move :: move(QLabel **l, QPoint **p, int *o,int *t,int n)
{
    for(int i = 0 ; i < Max_Arrow ; i++)
    {
        if(o[i])
        {
            if(p[i]->y() <= -Arrow_Size)
                miss(l[i],p[i],o,t);
            p[i]->ry() -= n;
            l[i]->setGeometry(p[i]->x(), p[i]->y(),Arrow_Size,Arrow_Size);
        }
    }
}

void Move :: miss(QLabel *l, QPoint *p,int *o,int *t)
{
    s->printScore(0);
    l->clear();
    p->setX(0);p->setY(0);
    o[*t] = 0;
    if(*t == 9)
       *t = 1;
    else
        *t = *t + 1 ;
}
