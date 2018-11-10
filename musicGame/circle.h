#ifndef CIRCLE_H
#define CIRCLE_H
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>

class Game;
class Score;

class Circle : public QWidget
{
public:
    Circle(Game *g,Score *s);

    void add_triangle();
    void add_octagon();
    void setPos(QPoint *pt);
    void init(Game *g);
    void kill();
private:
    void boolCheck();
    void clean();
    void check(QEvent *e,QLabel *l,QPoint *p);
    QLabel  **circle,**trCircle,*redCircle,*blueCircle;
    QImage  *Data_circle,*Data_trCircle,*Data_redCircle,*Data_blueCircle;
    QImage  *L_circle,*L_blueCircle,*L_redCircle;
    QPoint  *pt,**C,**trC,*bC,*rC;
    bool *check_circle;

    int max   = 0;
    int N_max = 0;
    int count = 0;

    Score *s;

    int complete_count = 0;

    bool completed = false;
    bool killed    = false;

    bool press = false;
protected:
    bool eventFilter(QObject *o, QEvent *e);
};


#endif // CIRCLE_H
