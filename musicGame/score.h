#ifndef SCORE_H
#define SCORE_H
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QLCDNumber>
#include <QSlider>

class Game;

class Score : public QWidget
{
    Q_OBJECT
public:
    Score(Game *g);
    int countScore(int score);
    void printScore(int score);
    void setGrade(float g);
    void clean();
private:
    void init(Game *g);
    /*********** Score set **********/
    QImage     *data_perfect,*data_great,*data_cool,*data_bad,*data_miss;
    QLabel     *score_outPut;
    QSlider    *slider;
    QLCDNumber *L_grade;

    float grade = 0;
    double per = 149.1053;

};

#endif // SCORE_H
