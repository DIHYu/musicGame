#ifndef GAME_H
#define GAME_H

#include <QPoint>
#include <QDialog>
#include <QKeyEvent>
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>
#include <QTextSTream>
#include <QTimer>
#include <QTime>
#include "score.h"
#include "circle.h"
#include "Gamebasic.h"
#include "move.h"
class Game : public QDialog
{

    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    int data;
private:
    void pressSet(QLabel *l,QPoint *p,int *o,int *t);
    void add(QLabel **l,QPoint **p,QImage *g,int *n,int *o,int x);
    void init();

    QTime      *time;
    Score      *score;
    Move       *move;
    Circle     *circle;
    Gamebasic  *gamebasic;


    int  n = 0;
    int  adjust = 0;
    int  run = 0;
    int  flag = 0;

    QDesktopWidget  *desktop;
    QRect           *screen;
    QImage          *G_Up,*G_Left,*G_Down,*G_Right;
    /******* Long arrow *******/
    QLabel   **long_Up;
    QImage   *dataLong_Up;
    /****** Game set *******/
    QLabel   **D_Up,**D_Left,**D_Down,**D_Right;
    QPoint   **P_Up,**P_Left,**P_Down,**P_Right;

    int  *On_Up,*On_Down,*On_Left,*On_Right;
    int  *N_Up,*N_Left,*N_Down,*N_Right;
    int  *top_Up,*top_Left,*top_Right,*top_Down;

    void addArrow(int data);

    /*********** File set **********/
    QFile        *f;
    QTextStream  *in;
    QString      *line;

    QPoint       *pt;
    void printScore(int score);

    /********* grade  ***********/
    QLCDNumber *grade;
    QSlider *slider;

    bool end   = false;
    bool mouse = true;
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void m_l();
    void m_d();
    void m_r();

};



#endif // GAME_H
