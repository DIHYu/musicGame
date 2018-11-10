#include "game.h"
#include <QCursor>


#define Arrow_Size 130
#define Max_Arrow 10


Game :: Game (QWidget *parent ):
    QDialog(parent),
    score(new Score(this)),
    gamebasic(new Gamebasic(this,score)),
    move(new Move(score)),
    circle(new Circle(this,score))
{
    init();
    time = new QTime;
    f    = new QFile;
    in   = new QTextStream;
    line = new QString;
    f  ->setFileName("data/data.txt");
    f  ->open(QIODevice::ReadOnly);
    in ->setDevice(f);
    /************* cursot set **************/
    QPixmap *cur = new QPixmap;
    cur->load("image/cursor/cursor.png");
    *cur = cur->scaled(35,35);
    QCursor *cursor = new QCursor;
    *cursor = QCursor(*cur,-1,-1);
    setCursor(*cursor);

    desktop = QApplication::desktop();
    *screen = desktop->screenGeometry();
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    setAttribute(Qt::WA_TranslucentBackground,true);
\
    QPalette pal = palette();
    //pal.setColor(QPalette::Background,QColor(0,0,0,255));
    //pal.setColor(QPalette::Foreground,QColor(255,255,255,255));
    pal.setColor(QPalette::Background,Qt::transparent);
    setPalette(pal);

    /************** Game set ********************/
    startTimer(1);
    QTimer *t = new QTimer;
    time->start();
    t->start(1);
    connect(t,&QTimer::timeout,this,[=]{
        run++;
        if(!flag)
        {
            *line = in->readLine();
            data = line->toInt();
            flag = 1;        
        }
        if(qAbs(run-data)< 10 && adjust != data)

        {
            adjust = data;
            *line = in->readLine();
            data = line->toInt();

            addArrow(data);
            flag = 0;
        }
        if(run == 0)
            run = time->elapsed();
        n = run < time->elapsed() ? 5 : 1;
        if(n>1)
            run += n-1;
        emit m_l();
        move->move(D_Up,P_Up,On_Up,top_Up,n);
    });
    connect(this,&Game::m_l,this,[=]
    {
        emit m_d();
        move->move(D_Left,P_Left,On_Left,top_Left,n);

            });
    connect(this,&Game::m_d,this,[=]
    {
        emit m_r();
        move->move(D_Down,P_Down,On_Down,top_Down,n);
            });
    connect(this,&Game::m_r,this,[=]
    {
        move->move(D_Right,P_Right,On_Right,top_Right,n);
            });
    resize(screen->width(),screen->height());
    setMouseTracking(true);
    pt = new QPoint;
}

void Game :: mouseMoveEvent(QMouseEvent *event)
{
    if(mouse)
    {
        *pt = event->globalPos();
        circle->setPos(pt);
    }
}

void Game :: addArrow(int data)
{
    switch(data)
    {
        case 1 :
        add(D_Up,P_Up,G_Up,N_Up,On_Up,Arrow_Size+40);
        break;
        case 2 :
        add(D_Left,P_Left,G_Left,N_Left,On_Left,20);
        break;
        case 3 :
        add(D_Down,P_Down,G_Down,N_Down,On_Down,(Arrow_Size*2)+60);
        break;
        case 4:
        add(D_Right,P_Right,G_Right,N_Right,On_Right,(Arrow_Size*3)+80);
        break;
        case 10:
        score->clean();
        circle->add_triangle();
        break;
        case 11:
        circle->kill();
        break;
        case 12:
        circle->add_octagon();
        break;
        case 13:
        circle->close();
        circle->deleteLater();
        mouse = false;
        case 14:
        score->clean();
        qDebug("clean");
        break;
        case 15:
        end = true ;
        break;
    }
}


void Game :: add(QLabel **l, QPoint **p,QImage *g,int *n,int *o,int x)
{
    if(*n == (Max_Arrow-1))
        *n = 1;
    else
        *n = *n + 1 ;
    o[*n] = 1;
    p[*n]->setX(x);p[*n]->setY(screen->height()-Arrow_Size);
    l[*n]->setPixmap(QPixmap::fromImage(*g));
    l[*n]->setGeometry(p[*n]->x(),p[*n]->y(),Arrow_Size,Arrow_Size);
}



void Game :: init()
{
    desktop = new QDesktopWidget;
    screen  = new QRect;
    /******************* img init **************************/
    G_Up   = new QImage;G_Left = new QImage;
    G_Down = new QImage;G_Right = new QImage;
   /****************** img load **************************/
    G_Up    ->load("image/arrow/G_UpArrow.png");
    G_Left  ->load("image/arrow/G_LeftArrow.png");
    G_Down  ->load("image/arrow/G_DownArrow.png");
    G_Right ->load("image/arrow/G_RightArrow.png");
    *G_Up    = G_Up   ->scaled(Arrow_Size,Arrow_Size);
    *G_Left  = G_Left ->scaled(Arrow_Size,Arrow_Size);
    *G_Down  = G_Down ->scaled(Arrow_Size,Arrow_Size);
    *G_Right = G_Right->scaled(Arrow_Size,Arrow_Size);
    /*************** ling arrow *********************/
    dataLong_Up = new QImage;
    dataLong_Up -> load("image/arrow/G_LongUpArrow.png");
   /***************** set init *************************/
    D_Up    = new QLabel *[Max_Arrow];
    D_Left  = new QLabel *[Max_Arrow];
    D_Down  = new QLabel *[Max_Arrow];
    D_Right = new QLabel *[Max_Arrow];
    P_Up    = new QPoint *[Max_Arrow];
    P_Left  = new QPoint *[Max_Arrow];
    P_Down  = new QPoint *[Max_Arrow];
    P_Right = new QPoint *[Max_Arrow];
    long_Up = new QLabel *[Max_Arrow];
    On_Up   = new int [Max_Arrow];On_Down  = new int [Max_Arrow];
    On_Left = new int [Max_Arrow];On_Right = new int [Max_Arrow];
    for(int i = 0 ; i < Max_Arrow ; i++ )
    {
        On_Up[i]   = 0;On_Down[i] = 0;
        On_Left[i] = 0;On_Right[i] = 0;
        D_Up[i]    = new QLabel(this);
        D_Left[i]  = new QLabel(this);
        D_Down[i]  = new QLabel(this);
        D_Right[i] = new QLabel(this);
        P_Up[i]    = new QPoint;
        P_Left[i]  = new QPoint;
        P_Down[i]  = new QPoint;
        P_Right[i] = new QPoint;
        long_Up[i] = new QLabel(this);
    }
    top_Up = new int(1);top_Left = new int(1);top_Right = new int(1),top_Down = new int(1);
    N_Up   = new int(0);N_Down   = new int(0),N_Left    = new int(0);N_Right  = new int(0);

}


void Game :: keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_Escape :
            break;
        case Qt::Key_Up :
        if(On_Up[*top_Up] && P_Up[*top_Up]->y() <= Arrow_Size)
        {
            gamebasic->press_Up(true,P_Up[*top_Up]->y());
            pressSet(D_Up[*top_Up],P_Up[*top_Up],On_Up,top_Up);
        }
        else
           gamebasic->press_Up(false,0);

        break;
        case  Qt::Key_Left :
        if(On_Left[*top_Left] && P_Left[*top_Left]->y() <= Arrow_Size )
        {
            gamebasic->press_Left(true,P_Left[*top_Left]->y());
            pressSet(D_Left[*top_Left],P_Left[*top_Left],On_Left,top_Left);
        }
        else
           gamebasic->press_Left(false,0);
        break;
        case Qt::Key_Down:
        if(On_Down[*top_Down] && P_Down[*top_Down]->y() <= Arrow_Size)
        {
            gamebasic->press_Down(true,P_Down[*top_Down]->y());
            pressSet(D_Down[*top_Down],P_Down[*top_Down],On_Down,top_Down);
        }
        else
           gamebasic->press_Down(false,0);
        break;
        case Qt::Key_Right:
        if(On_Right[*top_Right] && P_Right[*top_Right]->y() <= Arrow_Size)
        {
            gamebasic->press_Right(true,P_Right[*top_Right]->y());
            pressSet(D_Right[*top_Right],P_Right[*top_Right],On_Right,top_Right);
        }
        else
           gamebasic->press_Right(false,0);
        break;
    }
    if(end)
        qApp->exit(777);
}

void Game :: pressSet(QLabel *l, QPoint *p ,int *o ,int *t)
{
    l->clear();
    p->setX(0);p->setY(0);
    o[*t] = 0 ;
    if(*t == (Max_Arrow-1))
        *t = 1 ;
    else
        *t = *t + 1;
}
void Game :: keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_Escape :
            break;
        case Qt::Key_Up :
        gamebasic->release_Up();
        break;
        case  Qt::Key_Left :
        gamebasic->release_Left();
        break;
        case Qt::Key_Down:
        gamebasic->release_Down();
        break;
        case Qt::Key_Right:
        gamebasic->release_Right();
        break;
    }
}
