#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T20:28:19
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets
RC_FILE = ico.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menu.cpp \
    set.cpp \
    menupushbutton.cpp \
    background.cpp \
    game.cpp \
    movieset.cpp \
    score.cpp \
    gamebasic.cpp \
    move.cpp \
    circle.cpp

HEADERS  += mainwindow.h \
    menu.h \
    set.h \
    menupushbutton.h \
    background.h \
    game.h \
    movieset.h \
    score.h \
    gamebasic.h \
    move.h \
    circle.h
