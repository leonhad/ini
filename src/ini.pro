QT       -= core gui

TARGET = ini
TEMPLATE = lib

DEFINES += INI_LIBRARY

#DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += section.cpp \
    ini.cpp

HEADERS += ini.h \
    keys.h \
    section.h

unix {
    target.path = /usr/local/lib
    INSTALLS += target
}
