#include "movieset.h"
#include "game.h"

MovieSet :: MovieSet(QWidget *parent):
    QVideoWidget(parent)
{
    QMediaPlayer * m = new QMediaPlayer(this);
    m->setMedia(QUrl::fromLocalFile("media/movie.avi"));
    m->setVideoOutput(this);
    m->play();


}
