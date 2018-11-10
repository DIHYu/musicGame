#include "circle.h"
#include <QPoint>
#include "game.h"
#include "score.h"
#define circle_Size 150


Circle :: Circle(Game *g,Score *s)
{
    this ->s = s;
    max = 8;
    init(g);
}
void Circle :: add_triangle()
{
    N_max = 3;
    for(int i = 0 ; i < N_max ; i++)
    {
        if(i == 0)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1150,50,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(920,400,circle_Size,circle_Size);
            C[i]  ->setX(920); C[i]  ->setY(400);
            trC[i]->setX(1150);trC[i]->setY(50);
        }
        else if(i == 1)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(720,720,circle_Size,circle_Size);
            trC[i]->setX(720);
            trC[i]->setY(720);
        }
        else if(i == 2)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1550,720,circle_Size,circle_Size);
            trC[i]->setX(1550);
            trC[i]->setY(720);
        }
    }
    blueCircle ->setPixmap(QPixmap::fromImage(*Data_blueCircle));
    redCircle  ->setPixmap(QPixmap::fromImage(*Data_redCircle));
    blueCircle ->setGeometry(1120,400,circle_Size,circle_Size);
    redCircle  ->setGeometry(1320,400,circle_Size,circle_Size);
    bC->setX(1120);bC->setY(400);
    rC->setX(1320);rC->setY(400);
}
void Circle :: add_octagon()
{
    N_max = 8;
    for(int i = 0 ; i < N_max ; i++)
    {
        if(i == 0)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(950,0,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(1650,450,circle_Size,circle_Size);
            C[i]  ->setX(1650);C[i]  ->setY(450);
            trC[i]->setX(950);trC[i]->setY(0);
        }
        else if(i == 1)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1400,0,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(1175,100,circle_Size,circle_Size);
            C[i]  ->setX(1175);C[i]  ->setY(100);
            trC[i]->setX(1400);trC[i]->setY(0);
        }
        else if(i == 2)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(600,250,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(750,450,circle_Size,circle_Size);
            C[i]  ->setX(750);C[i]  ->setY(450);
            trC[i]->setX(600);trC[i]->setY(250);
        }
        else if(i == 3)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(600,650,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(950,450,circle_Size,circle_Size);
            C[i]  ->setX(950);C[i]  ->setY(450);
            trC[i]->setX(600);trC[i]->setY(650);
        }
        else if(i == 4)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(950,930,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(1175,850,circle_Size,circle_Size);
            C[i]  ->setX(1175);C[i]  ->setY(850);
            trC[i]->setX(950);trC[i]->setY(930);
        }
        else if(i == 5)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1400,930,circle_Size,circle_Size);
            circle[i]   ->setPixmap(QPixmap::fromImage(*Data_circle));
            circle[i]   ->setGeometry(1450,450,circle_Size,circle_Size);
            C[i]  ->setX(1450);C[i]  ->setY(450);
            trC[i]->setX(1400);trC[i]->setY(930);
        }
        else if(i == 6)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1770,250,circle_Size,circle_Size);
            trC[i]->setX(1770);trC[i]->setY(250);
        }
        else if(i == 7)
        {
            trCircle[i] ->setPixmap(QPixmap::fromImage(*Data_trCircle));
            trCircle[i] ->setGeometry(1770,650,circle_Size,circle_Size);
            trC[i]->setX(1770);trC[i]->setY(650);
        }
    }
    blueCircle ->setPixmap(QPixmap::fromImage(*Data_blueCircle));
    redCircle  ->setPixmap(QPixmap::fromImage(*Data_redCircle));
    blueCircle ->setGeometry(1175,300,circle_Size,circle_Size);
    redCircle  ->setGeometry(1175,600,circle_Size,circle_Size);
    bC->setX(1120);bC->setY(400);
    rC->setX(1320);rC->setY(400);
    killed = false;
    completed = false;
}
void Circle :: init(Game *g)
{
    circle     = new QLabel *[max-2];trCircle  = new QLabel *[max];
    blueCircle = new QLabel(g);redCircle = new QLabel(g);
    /**************** load img data ***************************/
    Data_circle     = new QImage;Data_trCircle  = new QImage;
    Data_blueCircle = new QImage;Data_redCircle = new QImage;
    Data_circle     ->load("image/circle/circle.png");
    Data_trCircle   ->load("image/circle/trCircle.png");
    Data_blueCircle ->load("image/circle/blueCircle.png");
    Data_redCircle  ->load("image/circle/redCircle.png");
    *Data_circle     = Data_circle     ->scaled(circle_Size,circle_Size);
    *Data_trCircle   = Data_trCircle   ->scaled(circle_Size,circle_Size);
    *Data_blueCircle = Data_blueCircle ->scaled(circle_Size,circle_Size);
    *Data_redCircle  = Data_redCircle  ->scaled(circle_Size,circle_Size);
    /********* Light **************/
    L_circle = new QImage;L_redCircle = new QImage;L_blueCircle = new QImage;
    L_circle     ->load("image/circle/L_circle.png");
    L_redCircle  ->load("image/circle/L_redCircle.png");
    L_blueCircle ->load("image/circle/L_blueCircle.png");
    *L_circle     = L_circle ->scaled(circle_Size,circle_Size);
    *L_redCircle  = L_redCircle ->scaled(circle_Size,circle_Size);
    *L_blueCircle = L_blueCircle ->scaled(circle_Size,circle_Size);
    /********* point *********/
    trC = new QPoint *[max];
    C   = new QPoint *[max];
    pt  = new QPoint;
    bC  = new QPoint;rC  = new QPoint;

    check_circle = new bool [max-2];
    for(int i = 0 ; i < max ;i++)
    {
        if(i < max - 2)
        {
            circle[i] = new QLabel(g);
            circle[i] ->installEventFilter(this);
        }
        trCircle[i] = new QLabel(g);
        trCircle[i] ->installEventFilter(this);

        trC[i] = new QPoint;
        C[i]   = new QPoint;

        check_circle[i] = new bool;
        check_circle[i] = false;
    }

    blueCircle ->installEventFilter(this);
    redCircle  ->installEventFilter(this);
}
bool Circle ::  eventFilter(QObject *o, QEvent *e)
{
    if(!completed)
    {
        for(int i = 0 ; i < N_max ; i++)
        {
            if(o == circle[i])
                check(e,circle[i],C[i]);
        }
        if(o == blueCircle)
            check(e,blueCircle,bC);
        if(o == redCircle)
            check(e,redCircle,rC);
    }
    else
    {
        if(o == redCircle)
        {
            if(e->type() == QEvent::MouseButtonPress)
            {
                redCircle->setPixmap(QPixmap::fromImage(*L_redCircle));
                press = true;
            }
            if(e->type() == QEvent::MouseMove && press == true)
            {
                for(int i = 0 ; i < N_max - 2 ;i ++)
                {
                    if(qAbs(C[i]->x() + 75 - pt->x()) < 50 &&
                            qAbs(C[i]->y() + 75 - pt->y()) < 50 &&
                                check_circle[i] == false)
                    {
                        circle[i]->setPixmap(QPixmap::fromImage(*L_circle));
                        check_circle[i] = true;
                    }
                    if(qAbs(bC->x() + 75 -pt->x()) < 50 &&
                           qAbs(bC->y() + 75 - pt->y()) < 50)
                    {
                        qDebug("%d",complete_count);
                        boolCheck();
                        if(complete_count == N_max - 2)
                        {
                            complete_count++;
                            blueCircle ->setPixmap(QPixmap::fromImage(*L_blueCircle));
                            if(N_max == 3)
                                s->setGrade(10000);
                            else
                                s->setGrade(15000);
                            kill();
                            break;
                        }
                        else
                            clean();
                    }
                }
            }
            if(e->type() == QEvent::MouseButtonRelease)
                   clean();
        }
    }
    return QWidget::eventFilter(o, e);
}
void Circle :: check(QEvent *e,QLabel *l,QPoint *p)
{
    if(e->type() == QEvent::MouseButtonPress)
        press = true ;
    if(e->type() == QEvent::MouseMove && press == true)
        l ->setGeometry(pt->x() - 75,pt->y() - 75,circle_Size,circle_Size);
    if(e->type() == QEvent::MouseButtonRelease)
    {
        for(int j = 0 ; j < N_max ; j++)
        {
            if(qAbs(pt->x() - trC[j]->x()) < 100 &&
                    qAbs(pt->y()- trC[j]->y()) < 100)
            {
                l ->setGeometry(trC[j]->x(),trC[j]->y(),circle_Size,circle_Size);
                p->setX(trC[j]->x());p->setY(trC[j]->y());
                count++;
                if(count == N_max)
                    for(int i = 0 ; i < N_max ; i++)
                    {
                        trCircle[i]->resize(0,0);
                        completed = true;
                    }
                break;
            }
            else
                l ->setGeometry(p->x(),p->y(),circle_Size,circle_Size);
        }
        press = false ;
    }
}
void Circle :: clean()
{
    for(int i = 0 ; i < N_max -2 ; i++)
    {
       circle[i]->setPixmap(QPixmap::fromImage(*Data_circle));
       check_circle[i] = false;
    }
    redCircle->setPixmap(QPixmap::fromImage(*Data_redCircle));
    complete_count = 0;
}
void Circle :: kill()
{
    if(!killed)
    {
        for(int i = 0 ; i < N_max ; i++)
        {
           if(i < N_max - 2)
           {
             circle[i]->resize(0,0);
             check_circle[i] = false;
           }
           trCircle[i]->resize(0,0);
        }
        blueCircle->resize(0,0);
        redCircle->resize(0,0);
        complete_count = 0;
        killed = true ;
        count = 0;
    }
}

void Circle :: boolCheck()
{
    for(int i = 0 ; i < N_max -2 ; i++)
    {
        if(check_circle[i] && complete_count < N_max - 2)
            complete_count++;
    }
}

void Circle :: setPos(QPoint *pt)
{
    this->pt = pt;
}
