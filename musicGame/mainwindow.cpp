#include "mainwindow.h"
#include "menu.h"
#include "movieset.h"
#include <QObject>
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    //background->setScaledContents(true);
    /********** Set a thread to load img **********/
    QObject *o = new QObject;
    QThread *t = new QThread;
    o->moveToThread(t);
    connect(t,&QThread::started,o,[=]{
        /*************** keep load img **************/
        while(1)
        {
            if(*backgroundChange == 3)
            {
                flag = 3 ;
                emit changeBackground();
                break;
            }
            Window_Width++;
            Window_Height++;
            /********* change background *********/
            if(*backgroundChange!=*backgroundChanged)
            {
                Window_Width=1500;
                Window_Height=900;
                switch(*backgroundChange)
                {
                    case 0 :
                        img->load("image/background.jpg");
                        *img = img->scaled(QSize(Window_Width, Window_Height));
                    break;
                    case 1 :
                        img->load("image/background2.jpg");
                        *img = img->scaled(QSize(Window_Width, Window_Height));
                    break;
                }
                flag = 1 ;
            }
            else
            {
                switch(*backgroundChange)
                {
                    case 0 :
                        img->load("image/background.jpg");
                        *img = img->scaled(Window_Width, Window_Height,
                                       Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    break;
                    case 1 :
                    img->load("image/background2.jpg");
                    *img = img->scaled(Window_Width, Window_Height,
                                       Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    break;
                }
            }
             emit changeBackground();
        }
    });
    t->start();
    /************ keep update background ***********/
    connect(this,&MainWindow::changeBackground,this,[=]{
        background->setPixmap(QPixmap::fromImage(*img));
       if(*backgroundChange!=*backgroundChanged && flag == 1
               &&*backgroundChange != 3)
        {
            flag = 0;
            *backgroundChanged = *backgroundChange;

            switch(*backgroundChange)
            {
                case 0 :
                    background->setAlignment(Qt::AlignJustify);
                break;
                case 1 :
                    background->setAlignment(Qt::AlignCenter);
                break;

            }
        }
       if(*backgroundChange == 3 && flag ==3)
       {
           flag = 0;
           background->clear();
           showFullScreen();
           MovieSet *movie = new MovieSet;
           setCentralWidget(movie);
           Game *game = new Game ;
           game->exec();
            t->exit();
            m->deleteLater();
       }

    });
    m = new Menu(backgroundChange);
    setCentralWidget(m);
}

void MainWindow :: init()
{
    /************** Set basic value  ******************/
    Window_Width  = 1500;
    Window_Height = 900;
    flag          = 0;
    backgroundChange  = new int(0) ;
    backgroundChanged = new int(0);
    /********** Set window & background ***************/
    setWindowTitle("file name");
    setFixedSize(Window_Width,Window_Height);
    setAutoFillBackground(true);
    background = new Background(this);
    img = new QImage;
    img->load("image/background.jpg");
    *img = img->scaled(QSize(Window_Width, Window_Height));
    background->setAlignment(Qt::AlignJustify);
    background->setPixmap(QPixmap::fromImage(*img));
    background->resize(Window_Width,Window_Height);

}

MainWindow::~MainWindow()
{

}
