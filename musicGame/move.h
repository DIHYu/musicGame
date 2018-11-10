#ifndef MOVE_H
#define MOVE_H
#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QThread>
#include <QObject>
#include "score.h"

class Move : public QWidget
{
    Q_OBJECT
public:
    Move(Score *score);
    void move_Up(QLabel **l, QPoint **p, int *o,int *t);
    void move_Left(QLabel **l, QPoint **p, int *o,int *t);
    void move_Down(QLabel **l, QPoint **p, int *o,int *t);
    void move_Right(QLabel **l, QPoint **p, int *o,int *t);
    void move(QLabel **l, QPoint **p, int *o,int *t,int n);
   void miss(QLabel *l,QPoint *p,int *o ,int *t);
private:
   Score    *s;
   QThread  *t1;
   QObject  *o1;
signals:
   void asd();


};


#endif // MOVE_H
