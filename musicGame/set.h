#ifndef SET_H
#define SET_H
#include <QDialog>
#include <QComboBox>

class Set : public QDialog
{
    Q_OBJECT
public:
    Set(QWidget *parent = 0);
    static int setGameWindow;
private:
    QComboBox *gameWindow;

};




#endif // SET_H
