#ifndef MENUPUSHBUTTON_H
#define MENUPUSHBUTTON_H
#include <QLabel>
#include <QMouseEvent>
class MenuPushButton : public QLabel
{
    Q_OBJECT

public:
    MenuPushButton(QWidget *parent = 0);
    static bool handleBtn;
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:
    void clicked();
};



#endif // MENUPUSHBUTTON_H
