#include "score.h"
#include "game.h"
#define Arrow_Size 130

Score :: Score(Game *g)
{
    init(g);
    /************** Grade set *******************/
    L_grade  = new QLCDNumber(g);
    slider = new QSlider;
    slider ->setValue(0);
    slider ->setRange(0,100600);
    L_grade  ->setGeometry(1620,0,300,100);
    L_grade  ->setPalette(Qt::black);
    L_grade  ->setDigitCount(6);
    L_grade  ->display(0);
    connect(slider,&QSlider::valueChanged,[=]{
        L_grade ->display(slider->value());
    });
}

void Score :: init(Game *g)
{
    /****************** score set *********************/
    data_perfect = new QImage;data_perfect->load("image/score/perfect.png");
    data_great   = new QImage;data_great->load("image/score/great.png");
    data_cool    = new QImage;data_cool->load("image/score/cool.png");
    data_bad     = new QImage;data_bad->load("image/score/bad.png");
    data_miss    = new QImage;data_miss->load("image/score/miss.png");
    score_outPut = new QLabel(g);
    score_outPut->setGeometry(Arrow_Size+30,Arrow_Size*4,150,40);

};

int Score :: countScore(int score)
{
    if((score <= 130 && score >= 100) ||
            (score <= -100 && score >= -130))
        return 4;
    else if((score < 100 && score >= 70) ||
            (score <= -70 && score >-100))
        return 3;
    else if((score < 70 && score >= 20) ||
            (score <= -20 && score >-70))
        return 2;
    else if((score < 20 && score >= -20) ||
            (score < 0 && score >=-20))
        return 1;
    return 0;

}
void Score :: printScore(int score)
{
    switch (score)
    {
       case 4 :        
         score_outPut->setPixmap(QPixmap::fromImage(*data_bad));
         setGrade((per/4)*2);
        break;
       case 3 :
         score_outPut->setPixmap(QPixmap::fromImage(*data_cool));
         setGrade((per/4)*2);
        break;
       case 2 :
         score_outPut->setPixmap(QPixmap::fromImage(*data_great));
          setGrade((per/4)*3);
        break;
       case 1 :
         score_outPut->setPixmap(QPixmap::fromImage(*data_perfect));
         setGrade(per);
        break;
       case 0:
         score_outPut->setPixmap(QPixmap::fromImage(*data_miss));
        break;
    }

}
void Score :: setGrade(float g)
{
    grade += g;
    int i = grade ;
    slider->setValue(i);
}

void Score :: clean()
{
    score_outPut->clear();
}
