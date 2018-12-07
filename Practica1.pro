#-------------------------------------------------
#
# Project created by QtCreator 2018-08-27T19:10:51
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Practica1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    registerwindow.cpp \
    bukinwindow.cpp \
    profilewindow.cpp \
    user.cpp \
    admin.cpp \
    categorywindow.cpp \
    book.cpp \
    modifywindow.cpp \
    bookwindow.cpp \
    bookwidget.cpp \
    mybookwindow.cpp \
    favoriteswindow.cpp \
    sortwindow.cpp \
    categorytemplate.cpp \
    node.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    registerwindow.h \
    bukinwindow.h \
    profilewindow.h \
    user.h \
    admin.h \
    categorywindow.h \
    book.h \
    modifywindow.h \
    bookwindow.h \
    bookwidget.h \
    mybookwindow.h \
    favoriteswindow.h \
    sortwindow.h \
    categorytemplate.h \
    node.h

FORMS += \
        mainwindow.ui \
    login.ui \
    registerwindow.ui \
    bukinwindow.ui \
    profilewindow.ui \
    categorywindow.ui \
    modifywindow.ui \
    bookwindow.ui \
    bookwidget.ui \
    mybookwindow.ui \
    favoriteswindow.ui \
    sortwindow.ui \
    categorytemplate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics.qrc
