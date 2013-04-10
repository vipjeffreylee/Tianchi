QT += sql network script axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#DESTDIR = bin
TARGET = tianchi
TEMPLATE = lib

DEFINES += TIANCHI_LIBRARY

INCLUDEPATH += include

LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/Version.lib" \
        "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/AdvAPI32.lib"

HEADERS += \
    include/IMEEngine.h \
    include/msime.h \
    include/tc_qglobal.h \
    include/tc_Smtp.h \
    include/tc_Utils.h \
    include/tc_MSExcel.h \
    include/tc_json.h \
    include/tc_Classes.h \
    include/tc_DlgHeaderSetup.h \
    include/tcv_DateEdit.h \
    include/tc_LogTiny.h

SOURCES += \
    source/IMEEngine.cpp \
    source/tc_DlgHeaderSetup.cpp \
    source/tc_Classes.cpp \
    source/tc_json.cpp \
    source/tc_MSExcel.cpp \
    source/tc_Smtp.cpp \
    source/tc_Utils.cpp \
    source/tcv_DateEdit.cpp \
    source/tc_LogTiny.cpp

FORMS += \
    source/tc_DlgHeaderSetup.ui

RESOURCES += resource/res.qrc

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

