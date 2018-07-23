#-------------------------------------------------
#
# Project created by QtCreator 2018-07-23T18:28:17
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TEMPLATE = lib

DEFINES += DOCKUI_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11
CONFIG += debug_and_release

INCLUDEPATH += .    $$PWD/../include

win32{
    CONFIG -= flat
}

#临时文件
UI_DIR = $$PWD/temp
RCC_DIR = $$PWD/temp
MOC_DIR = $$PWD/temp

contains(QT_ARCH, i386) {
    #生成路径
    DESTDIR = $$PWD/../lib/x86

    #临时文件路径
    CONFIG(debug, debug|release): OBJECTS_DIR = $$PWD/../temp/x86/debug
    else: OBJECTS_DIR = $$PWD/../temp/x86/release

}else {
     #生成路径
    DESTDIR = $$PWD/../lib/x64

    #临时文件路径
    CONFIG(debug, debug|release):OBJECTS_DIR = $$PWD/../temp/x64/debug
    else:OBJECTS_DIR = $$PWD/../temp/x64/release
}

#生成目标名称
CONFIG(debug, debug|release): TARGET = dockuid
else:TARGET= dockui

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        dockui.cpp \
        dockui_base.cpp \
        dockui_dockpage.cpp \
        dockui_tabpage.cpp


HEADERS += \
        $$PWD/../include/dockui.h \
        $$PWD/../include/dockui_global.h \
        $$PWD/../include/dockui_defines.h \
        $$PWD/../include/dockui_base.h \
        dockui_dockpage.h \
        dockui_tabpage.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
