QT += sql network script 
greaterThan(QT_MAJOR_VERSION, 4) { 
    QT += widgets
    win32:QT += axcontainer
} else {
    win32:CONFIG += qaxcontainer
    DEFINES += QT_WIDGETS_LIB
}

#DESTDIR = bin
TARGET = tianchi
TEMPLATE = lib

DEFINES += TIANCHI_LIBRARY

INCLUDEPATH += include

win32:LIBS += -lversion -ladvapi32 -lole32

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

