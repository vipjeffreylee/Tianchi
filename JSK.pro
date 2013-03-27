#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:52:19
#
#-------------------------------------------------
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JSK
DESTDIR = bin
TEMPLATE = lib

DEFINES += JSK_LIBRARY

INCLUDEPATH += inc

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Version.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/AdvAPI32.lib"

HEADERS +=\
    inc/jsk.h \
    inc/jsk_Utils.h \
    inc/jsk_qglobal.h

SOURCES += \
    src/jsk_Utils.cpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES +=
