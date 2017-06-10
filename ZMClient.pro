#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T08:49:25
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZMClient
TEMPLATE = app
DESTDIR = ..\BIN

CONFIG += precompile_header
PRECOMPILED_HEADER = stable.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    UIModule/mainwindow.cpp \
    UIModule/logindialog.cpp \
    base64/base64.cpp \
    Common/readini.cpp \
    Common/socketTcp.cpp \
    UIModule/Comm/mytoolbutton.cpp \
    UIModule/Comm/mywidgetfolder.cpp \
    UIModule/Comm/myimagewidget.cpp \
    UIModule/Comm/mytargetbutton.cpp \
    UIModule/warningwidget.cpp \
    UIModule/realtimemonitorpane.cpp \
    UIModule/Comm/myimagecomparewidget.cpp \
    UIModule/Comm/myimagelabel.cpp \
    UIModule/faceonetoonepane.cpp \
    UIModule/faceonetonpane.cpp \
    UIModule/faceidentityrecog.cpp \
    UIModule/facehistorycompare.cpp

FORMS += \
    UIModule/mainwindow.ui \
    UIModule/logindialog.ui

HEADERS += \
    UIModule/mainwindow.h \
    UIModule/logindialog.h \
    stable.h \
    base64/base64.h \
    Common/readini.h \
    Common/socketTcp.h \
    UIModule/Comm/mytoolbutton.h \
    UIModule/Comm/mywidgetfolder.h \
    UIModule/Comm/myimagewidget.h \
    UIModule/Comm/mytargetbutton.h \
    UIModule/warningwidget.h \
    UIModule/realtimemonitorpane.h \
    UIModule/Comm/myimagecomparewidget.h \
    UIModule/Comm/myimagelabel.h \
    UIModule/faceonetoonepane.h \
    UIModule/faceonetonpane.h \
    UIModule/faceidentityrecog.h \
    UIModule/facehistorycompare.h

RESOURCES += \
    Resouce.qrc

DISTFILES +=
