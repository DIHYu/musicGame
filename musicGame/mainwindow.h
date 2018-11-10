#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QSound>
#include <QPixmap>
#include "menu.h"
#include "background.h"
#include "game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void init();

    int  flag;
    int  *backgroundChange;
    int  *backgroundChanged;
    int  Window_Width ;
    int  Window_Height ;

    Menu        *m;
    QSound      *s;
    Background  *background;
    QImage      *img;
signals:
    void changeBackground();

};

#endif // MAINWINDOW_H
