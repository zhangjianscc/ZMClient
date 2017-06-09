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
LIBS += -lpthread libwsock32 libws2_32

SOURCES += main.cpp \
    UIModule/mainwindow.cpp \
    UIModule/logindialog.cpp \
    base64/base64.cpp \
    UIModule/Comm/mytoolbutton.cpp \
    UIModule/Comm/mywidgetfolder.cpp \
    UIModule/Comm/myimagewidget.cpp \
    UIModule/realtimemonitorpane.cpp \
    UIModule/Comm/myimagecomparewidget.cpp \
    Common/connection.cpp \
    Common/readini.cpp \
    Common/singleton.cpp \
    Common/socketmanager.cpp \
    InterFaceToService/jsonformat.cpp \
    InterFaceToService/objformat.cpp \
    InterFaceToService/sysuserclient.cpp

FORMS += \
    UIModule/mainwindow.ui \
    UIModule/logindialog.ui

HEADERS += \
    UIModule/mainwindow.h \
    UIModule/logindialog.h \
    stable.h \
    base64/base64.h \
    UIModule/Comm/mytoolbutton.h \
    UIModule/Comm/mywidgetfolder.h \
    UIModule/Comm/myimagewidget.h \
    UIModule/realtimemonitorpane.h \
    UIModule/Comm/myimagecomparewidget.h \
    Common/conn_exception.h \
    Common/connection.h \
    Common/readini.h \
    Common/singleton.h \
    Common/SocketManager.h \
    InterFaceToService/jsonformat.h \
    InterFaceToService/loginobj.h \
    InterFaceToService/objformat.h \
    InterFaceToService/ParamCommon.h \
    InterFaceToService/ParamsCommon.h \
    InterFaceToService/sysuserclient.h \
    reqglobal.h \
    respglobal.h

RESOURCES += \
    images.qrc

DISTFILES +=
