#include "menupushbutton.h"

bool MenuPushButton :: handleBtn = 0;


MenuPushButton :: MenuPushButton(QWidget *parent) :
    QLabel(parent)
{


}

void MenuPushButton :: mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        handleBtn = true;
    }

}
void MenuPushButton :: mouseReleaseEvent(QMouseEvent *)
{
    if(handleBtn)
    {
        handleBtn = false;
        emit clicked();
    }

}
