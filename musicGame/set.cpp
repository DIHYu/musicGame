#include "set.h"
#include "game.h"
#include <QPalette>
int Set :: setGameWindow = 0;

Set :: Set(QWidget *parent):
    QDialog(parent)
{
    //setStyleSheet("background-color:blue");
    setWindowOpacity(0.4);
    resize(500,500);
    setWindowFlags(Qt::FramelessWindowHint);
    activateWindow();
    /*******************Screen Set********************/
    gameWindow = new QComboBox(this);
    gameWindow->setGeometry(100,100,80,30);
    gameWindow->setEditable(false);
    if(setGameWindow == 0)
    {
        gameWindow->insertItem(0,tr("FullScreen"));
        gameWindow->insertItem(1,tr("windowed"));
    }
    else
    {
        gameWindow->insertItem(1,tr("windowed"));
        gameWindow->insertItem(0,tr("FullScreen"));
    }
    connect(gameWindow,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[=]
    {

        setGameWindow=gameWindow->currentIndex();

    });

}
