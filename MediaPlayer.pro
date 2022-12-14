#-------------------------------------------------
#
# Project created by QtCreator 2022-09-27T17:44:47
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets
LIBS += -luser32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer
TEMPLATE = app

CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    myslider.cpp \
    dragmenu.cpp \
    clickvideo.cpp

HEADERS += \
        widget.h \
    myslider.h \
    dragmenu.h \
    clickvideo.h

FORMS += \
        widget.ui

RESOURCES += \
    sources.qrc
