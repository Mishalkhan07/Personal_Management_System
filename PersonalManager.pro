QT       += core gui sql printsupport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PersonalManager
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp

SOURCES += \
    mainwindow.cpp \
    user.cpp \
    taskmanager.cpp \
    calendarmanager.cpp \
    financemanager.cpp \
    notemanager.cpp \
    dbmanager.cpp

QT += sql


HEADERS += \
    mainwindow.h \
    user.h \
    taskmanager.h \
    calendarmanager.h \
    financemanager.h \
    notemanager.h \
    dbmanager.h

FORMS += \
    mainwindow.ui \
    login.ui \
    register.ui \
    taskmanager.ui \
    calendarmanager.ui \
    financemanager.ui \
    notemanager.ui

RESOURCES += \
    resources.qrc \
    resources.qrc

INCLUDEPATH += headers
