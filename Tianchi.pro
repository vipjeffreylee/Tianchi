#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:52:19
#
#-------------------------------------------------
QT += sql network script axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tianchi
DESTDIR = bin
TEMPLATE = lib

DEFINES += TIANCHI

INCLUDEPATH += include

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Version.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/AdvAPI32.lib"

HEADERS += \
    include/JSKDateEdit.h \
    include/jsk_Utils.h \
    include/jsk_Smtp.h \
    include/jsk_qglobal.h \
    include/jsk_MSExcel.h \
    include/jsk_Log.h \
    include/jsk_json.h \
    include/jsk_Classes.h \
    include/jsk.h \
    include/IMEEngine.h \
    include/DlgHeaderSetup.h \
    source/msime.h

SOURCES += \
    source/JSKDateEdit.cpp \
    source/jsk_Utils.cpp \
    source/jsk_Smtp.cpp \
    source/jsk_MSExcel.cpp \
    source/jsk_Log.cpp \
    source/jsk_json.cpp \
    source/jsk_Classes.cpp \
    source/IMEEngine.cpp \
    source/DlgHeaderSetup.cpp

RESOURCES += resource/res.qrc

FORMS += source/DlgHeaderSetup.ui

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


