#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:52:19
#
#-------------------------------------------------

QT += network opengl sql script scripttools svg webkit xml xmlpatterns multimedia testlib

TARGET = JSK
DESTDIR = ../bin
TEMPLATE = lib

DEFINES += JSK_LIBRARY

INCLUDEPATH += ../inc

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Ole32.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Version.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/AdvAPI32.lib" \
        "C:/Program Files (x86)/Lua/5.1/lib/*.lib"

SOURCES += \
    jsk_Utils.cpp

HEADERS +=\
    ../inc/jsk.h \
    ../inc/jsk_Utils.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES +=
