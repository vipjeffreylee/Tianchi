#-------------------------------------------------
#
# Project created by QtCreator 2013-03-27T10:52:19
#
#-------------------------------------------------
QT += sql network script axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#release {
#    TARGET = jsk_release
#}
#debug {
#    TARGET = jsk_debug
#}
#win32 {
#}

TARGET = jskd
DESTDIR = ..\bin
TEMPLATE = lib

DEFINES += JSK_LIBRARY

INCLUDEPATH += .

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Version.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/AdvAPI32.lib"

HEADERS +=\
    jsk_qglobal.h \
    jsk_Utils.h \
    jsk_json.h \
    jsk_Log.h \
    jsk_MSExcel.h \
    JSKDateEdit.h \
    DlgHeaderSetup.h \
    IMEEngine.h \
    jsk_Smtp.h \
    jsk_Classes.h \
    jsk.h

SOURCES += \
    src/jsk_Utils.cpp \
    src/jsk_json.cpp \
    src/jsk_Log.cpp \
    src/jsk_MSExcel.cpp \
    src/JSKDateEdit.cpp \
    src/DlgHeaderSetup.cpp \
    src/IMEEngine.cpp \
    src/jsk_Smtp.cpp \
    src/jsk_Classes.cpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES +=

RESOURCES += \
    res/res.qrc

FORMS += \
    src/DlgHeaderSetup.ui

