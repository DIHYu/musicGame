#include "menu.h"
#include "mainwindow.h"
#include <QImage>
#define Light_Max 11
#define Light_Size 35
#define Window_Width 1500
#define Window_Height 900


Menu :: Menu (int *backgroundChange,QWidget *parent):
    QWidget(parent),
    enter(new QSound("media/enter.wav")),
    click(new QSound("media/click.wav")),
    gearSet(new QLabel(this)),
    gear(new QMovie("image/gear.gif"))
{
    this->backgroundChange = backgroundChange;
    init();

    connect(timer,&QTimer::timeout,this,[=]{

        lightOutPut();

    });
    connect(startbtn, &MenuPushButton::clicked,this, [=]{
         click->play();
         *backgroundChange = 3 ;
         player->stop();
         close();
        });
    connect(setbtn, &MenuPushButton::clicked,this, [=]{
        Set *s = new Set;
        click->play();
        s->exec();

        });
     connect(list, &QMediaPlaylist::currentIndexChanged,this,[=]{
        if(*backgroundChange==0)
            *backgroundChange=1;
        else
            *backgroundChange=0;

        qDebug("change");
    });

}
bool Menu :: eventFilter(QObject *o,QEvent *e)
{
    if(o == startbtn )
    {
        if(e->type() == QEvent::Enter)
        {
            setCursor(*cursor);
            startbtn->setPixmap(start->scaled(450,150));
            startbtn->resize(450,150);
            enter->play();
            return true;
        }
        if(e->type() == QEvent::Leave)
        {
            setCursor(Qt::ArrowCursor);
            startbtn->setPixmap(start->scaled(400,130));
            startbtn->resize(400,130);
            return true;
        }
    }
    if(o == setbtn )
    {
        if(e->type() == QEvent::Enter)
        {
            setCursor(*cursor);
            setbtn->setPixmap(set->scaled(250,130));
            setbtn->resize(250,130);
            enter->play();
            return true;
        }
        if(e->type() == QEvent::Leave)
        {
            setCursor(Qt::ArrowCursor);
            setbtn->setPixmap(set->scaled(200,100));
            setbtn->resize(200,100);
            return true;
        }

    }
    return QWidget::eventFilter(o, e);
}
void Menu :: init()
{
    /*****************Set BGM********************/
        player = new QMediaPlayer;
        list   = new QMediaPlaylist;
        list   ->addMedia(QUrl::fromLocalFile("media/backgroundmusic.wav"));
        list   ->addMedia(QUrl::fromLocalFile("media/backgroundmusic2.wav"));
        list   ->setPlaybackMode(QMediaPlaylist::Loop);
        player ->setPlaylist(list);
        player ->play();
    /***************Init basic value******************/
        setLightSpot();
        startbtn = new MenuPushButton(this);
        start    = new QPixmap("image/start.png");
        startbtn->setPixmap(start->scaled(400,130));
        startbtn->setGeometry(50,130,400,130);
        startbtn->installEventFilter(this);
        setbtn = new MenuPushButton(this);
        set    = new QPixmap("image/set.png");
        setbtn->setPixmap(set->scaled(200,100));
        setbtn->setGeometry(55,350,200,100);
        setbtn->installEventFilter(this);
        timer = new QTimer(this);
        timer->start(30);
        gearSet->setMovie(gear);
        gearSet->setGeometry(1380,0,160,173);
        gear->start();

        spot  = new QPixmap;
        spot2 = new QPixmap;
        spot  ->load("image/lightspot.png");
        spot2 ->load("image/lightspot2.png");
        *spot  = spot->scaled(Light_Size,Light_Size);
        *spot2 = spot2->scaled(Light_Size,Light_Size);

        cur = new QPixmap;
        cur->load("image/cursor/cursor.png");
        *cur = cur->scaled(35,35);
        cursor = new QCursor;
        *cursor = QCursor(*cur,-1,-1);
}

void Menu :: setLightSpot()

{
    light = new QPoint *[11];
    lightL = new QLabel *[11];

    for(int i = 0 ; i < Light_Max ;i++ )
    {
        light[i]  = new QPoint ;
        lightL[i] = new QLabel(this);
        light[i]->setX(0);
        light[i]->setY(0);
        lightSet[i] = 0  ;
    }
}

void Menu :: handleLightSpot()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    for(int i = 1 ; i < Light_Max ; i++)
    {
        //*****Return lightspot to (0,0)*******
        if((light[i]->ry())==Window_Height)
        {
            light[i]->ry() = 0;
            light[i]->rx() = 0;
        }
        //************Set a variable form 1 to 30 for rand it's spawn******
        setRand = (qrand()%30)+1;
        if((light[i]->rx()==0) &&
           (light[i]->ry()==0) &&
           (setRand==5))
            light[i]->rx() = (qrand()%Window_Width)+1;
        //***********Set action ********
        if((light[i]->ry()>0) ||
           (light[i]->rx()>0))
        {
            setRand = qrand()%4;
            if((setRand==0||setRand==2) && ((light[i]->rx()--)>0))
                light[i]->rx()--;
            if((setRand==1||setRand==3) && ((light[i]->rx()++)<Window_Width))
                light[i]->rx()++;
            light[i]->ry()++;
        }
    }

}

void Menu :: lightOutPut()
{
    handleLightSpot();

    for(int i = 1 ; i < Light_Max ; i++)
    {
        if((light[i]->rx()>0)||
           (light[i]->ry()>0)){
            //************ Set different image if it run 20 times******
            if(lightSet[i]<20)
            {
                lightL[i]->setGeometry(light[i]->rx(),light[i]->ry(),Light_Size,Light_Size);
                lightL[i]->setPixmap(*spot);
                lightSet[i]++;
            }
            else
            {
                lightL[i]->setGeometry(light[i]->rx(),light[i]->ry(),Light_Size,Light_Size);
                lightL[i]->setPixmap(*spot2);
                lightSet[i]++;
                if(lightSet[i] == 40)
                    lightSet[i] = 0;
            }

        }
    }

}
