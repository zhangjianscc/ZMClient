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
<<<<<<< HEAD
    Common/singleton.cpp \
    Common/socketmanager.cpp \
    InterFaceToService/jsonformat.cpp \
    InterFaceToService/objformat.cpp \
    InterFaceToService/sysuserclient.cpp
=======
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
    UIModule/monitorconfigpane.cpp \
    UIModule/targetpersonmanager.cpp \
    UIModule/templatemanager.cpp \
    UIModule/librarymanager.cpp \
    UIModule/realwarningmanager.cpp \
    UIModule/monitorareamaintain.cpp \
    UIModule/monitorpositionmaintain.cpp \
<<<<<<< HEAD
    UIModule/monitordevicemaintain.cpp
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9
=======
    UIModule/monitordevicemaintain.cpp \
    UIModule/maptrackpane.cpp \
    UIModule/warnigdisposedlg.cpp \
    UIModule/addmonitorareadlg.cpp \
    UIModule/editmonitorareadlg.cpp \
    UIModule/addmonitorpositiondlg.cpp \
    UIModule/editmonitorpositiondlg.cpp \
    UIModule/selectmonitorpositiondlg.cpp \
    UIModule/adddevicedlg.cpp \
    UIModule/editdevicedlg.cpp \
    UIModule/addtargetpersondlg.cpp \
    UIModule/addtargetpersonimagedlg.cpp \
    UIModule/edittargetpersondlg.cpp \
    UIModule/addtemplatedlg.cpp \
    UIModule/volumeaddtemplatedlg.cpp \
    UIModule/addlibrarydlg.cpp \
    UIModule/facehistorycompare.cpp \
    UIModule/faceidentitydiscern.cpp \
    UIModule/faceonetonpane.cpp
>>>>>>> mybranch

FORMS += \
    UIModule/mainwindow.ui \
    UIModule/logindialog.ui \
    UIModule/monitorconfigpane.ui \
    UIModule/targetpersonmanager.ui \
    UIModule/templatemanager.ui \
    UIModule/librarymanager.ui \
    UIModule/realwarningmanager.ui \
    UIModule/monitorareamaintain.ui \
    UIModule/monitorpositionmaintain.ui \
    UIModule/monitordevicemaintain.ui \
    UIModule/maptrackpane.ui \
    UIModule/edittargetperson.ui \
    UIModule/addtargetperson.ui \
    UIModule/addtargetpersonimage.ui \
    UIModule/addtemplate.ui \
    UIModule/volumeaddtemplate.ui \
    UIModule/addlibrary.ui \
    UIModule/warnigdisposedlg.ui \
    UIModule/addmonitorareadlg.ui \
    UIModule/editmonitorareadlg.ui \
    UIModule/addmonitorpositiondlg.ui \
    UIModule/editmonitorpositiondlg.ui \
    UIModule/selectmonitorpositiondlg.ui \
    UIModule/adddevicedlg.ui \
    UIModule/editdevicedlg.ui \
    UIModule/faceonetonpane.ui \
    UIModule/faceidentitydiscern.ui \
    UIModule/facehistorycompare.ui

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
<<<<<<< HEAD
    Common/singleton.h \
    Common/SocketManager.h \
    InterFaceToService/jsonformat.h \
    InterFaceToService/loginobj.h \
    InterFaceToService/objformat.h \
    InterFaceToService/ParamCommon.h \
    InterFaceToService/ParamsCommon.h \
    InterFaceToService/sysuserclient.h \
    reqglobal.h \
    respglobal.h \
    InterFaceToService/sysuser.h

RESOURCES += \
    images.qrc
=======
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
    UIModule/monitorconfigpane.h \
    UIModule/targetpersonmanager.h \
    UIModule/templatemanager.h \
    UIModule/librarymanager.h \
    UIModule/realwarningmanager.h \
    UIModule/monitorareamaintain.h \
    UIModule/monitorpositionmaintain.h \
    UIModule/monitordevicemaintain.h \
    UIModule/maptrackpane.h \
    UIModule/warnigdisposedlg.h \
    UIModule/addmonitorareadlg.h \
    UIModule/editmonitorareadlg.h \
    UIModule/addmonitorpositiondlg.h \
    UIModule/editmonitorpositiondlg.h \
    UIModule/selectmonitorpositiondlg.h \
    UIModule/adddevicedlg.h \
    UIModule/editdevicedlg.h \
    UIModule/addtargetpersondlg.h \
    UIModule/addtargetpersonimagedlg.h \
    UIModule/edittargetpersondlg.h \
    UIModule/addtemplatedlg.h \
    UIModule/volumeaddtemplatedlg.h \
    UIModule/addlibrarydlg.h \
    UIModule/facehistorycompare.h \
    UIModule/faceidentitydiscern.h \
    UIModule/faceonetonpane.h

RESOURCES += \
    Resouce.qrc
>>>>>>> ed50c6119402aa2f1d459124d18c94076c1dc3b9

DISTFILES +=
