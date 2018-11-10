#ifndef MENU_H
#define MENU_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMutex>
#include <QWaitCondition>
#include <QWidget>
#include <QEvent>
#include <QPoint>
#include <QSound>
#include <QTimer>
#include <QTime>
#include <QMovie>
#include <QLabel>
#include "menupushbutton.h"
#include "set.h"
class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu(int *,QWidget *parent = 0);
    void setLightSpot();
    void handleLightSpot();

    int setRand;

    QPixmap *start;
    QPixmap *set;
private:
    QMediaPlayer    *player;
    QMediaPlaylist  *list;
    QLabel          **lightL;
    QLabel          *gearSet;
    QMovie          *gear;
    QPoint          **light;
    QPixmap         *spot,*spot2;

    MenuPushButton  *startbtn;
    MenuPushButton  *setbtn;
    QTimer          *timer;
    QSound          *enter;
    QSound          *click;
    QPixmap         *cur;
    QCursor         *cursor;

    int lightSet[11];
    int *backgroundChange;
    int *keepThreadSafe;
    int *keepThreadSafeF;

    void lightOutPut();
    void init();
signals:
    void change();
protected:
   // void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *o, QEvent *e);

};



#endif // MENU_H
