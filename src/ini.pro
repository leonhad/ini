#-------------------------------------------------
#
# Project created by QtCreator 2018-10-05T16:41:36
#
#-------------------------------------------------

QT       -= core gui

TARGET = ini
TEMPLATE = lib

DEFINES += INI_LIBRARY

#DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += fileinterface.cpp \
    groups.cpp \
    inifile.cpp \
    keys.cpp \
    memoryfile.cpp \
    propertyfile.cpp

HEADERS += ini.h \
    keys.h \
    inifile.h \
    groups.h \
    fileinterface.h \
    memoryfile.h \
    propertyfile.h

unix {
    target.path = /usr/local/lib
    INSTALLS += target
}
