#-------------------------------------------------
#
# Project created by QtCreator 2015-01-01T22:08:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrainFuck
TEMPLATE = app


SOURCES += main.cpp\
        brainfuck.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    brainfuck.h

FORMS    += mainwindow.ui
