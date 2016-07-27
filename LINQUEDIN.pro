#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T13:29:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LINQUEDIN
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    db.cpp \
    linkedinadmin.cpp \
    linkedinclient.cpp \
    rete.cpp \
    utente.cpp \
    utentebasic.cpp \
    utentebusiness.cpp \
    utenteexecutive.cpp \
    profilo.cpp \
    info.cpp \
    adminwindow.cpp \
    controller.cpp \
    userwindow.cpp


HEADERS  += mainwindow.h \
    db.h \
    linkedinadmin.h \
    linkedinclient.h \
    rete.h \
    utente.h \
    utentebasic.h \
    utentebusiness.h \
    utenteexecutive.h \
    profilo.h \
    info.h \
    adminwindow.h \
    controller.h \
    eccezioni.h \
    userwindow.h


OTHER_FILES += \
    LINKEDINDB \
    LINKEDINRETE \
