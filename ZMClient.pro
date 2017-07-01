#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T08:49:25
#
#-------------------------------------------------

QT       += core gui network script
QT += widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZMClient
TEMPLATE = app
#DESTDIR = ..\BIN

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

HEADERS += \
    base64/base64.h \
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
    InterFaceToService/sysuser.h \
    InterFaceToService/sysuserclient.h \
    UIModule/Comm/myimagecomparewidget.h \
    UIModule/Comm/myimagelabel.h \
    UIModule/Comm/myimagewidget.h \
    UIModule/Comm/mytargetbutton.h \
    UIModule/Comm/mytoolbutton.h \
    UIModule/Comm/mywidgetfolder.h \
    UIModule/adddevicedlg.h \
    UIModule/addlibrarydlg.h \
    UIModule/addmonitorpositiondlg.h \
    UIModule/addtargetpersondlg.h \
    UIModule/addtargetpersonimagedlg.h \
    UIModule/addtemplatedlg.h \
    UIModule/editdevicedlg.h \
    UIModule/editmonitorareadlg.h \
    UIModule/editmonitorpositiondlg.h \
    UIModule/edittargetpersondlg.h \
    UIModule/facehistorycompare.h \
    UIModule/faceidentitydiscern.h \
    UIModule/faceonetonpane.h \
    UIModule/faceonetoonepane.h \
    UIModule/librarymanager.h \
    UIModule/logindialog.h \
    UIModule/mainwindow.h \
    UIModule/maptrackpane.h \
    UIModule/monitorareamaintain.h \
    UIModule/monitorconfigpane.h \
    UIModule/monitordevicemaintain.h \
    UIModule/monitorpositionmaintain.h \
    UIModule/realtimemonitorpane.h \
    UIModule/realwarningmanager.h \
    UIModule/selectmonitorpositiondlg.h \
    UIModule/targetpersonmanager.h \
    UIModule/templatemanager.h \
    UIModule/volumeaddtemplatedlg.h \
    UIModule/warningwidget.h \
    reqglobal.h \
    respglobal.h \
    UIModule/warningdisposedlg.h \
    qroundprogressbar.h \
    UIModule/Comm/mycomparedimage.h \
    UIModule/Comm/mysearchedit.h \
    UIModule/Comm/mytwoimagecomparepane.h \
    UIModule/Comm/facehistoryimageitem.h \
    UIModule/Comm/maptrackitem.h \
    UIModule/warningdismonareadialog.h \
    UIModule/warningdisdelsuredialog.h \
    UIModule/Comm/mytablewidget.h \
    UIModule/Comm/mycheckboxheaderview.h \
    UIModule/addmonitorareadlg.h \
    UIModule/warningdismonposdialog.h \
    UIModule/addmonitordevicedialog.h \
    UIModule/editmonitordevicedialog.h \
    UIModule/Comm/targetpersonimageitem.h \
    UIModule/deleteconfirmationdlg.h \
    UIModule/Comm/deleteconfirmationdlg.h \
    UIModule/Comm/templateitem.h \
    UIModule/batchaddtemplatedlg.h \
    UIModule/editlibrarydlg.h \
    UIModule/Comm/noticedlg.h \
    UIModule/Comm/realwarningitem.h \
    UIModule/Comm/warningdisposdlg.h \
    webaxwidget.h

SOURCES += \
    base64/base64.cpp \
    Common/connection.cpp \
    Common/readini.cpp \
    Common/singleton.cpp \
    Common/socketmanager.cpp \
    InterFaceToService/jsonformat.cpp \
    InterFaceToService/objformat.cpp \
    InterFaceToService/sysuserclient.cpp \
    UIModule/Comm/myimagecomparewidget.cpp \
    UIModule/Comm/myimagelabel.cpp \
    UIModule/Comm/myimagewidget.cpp \
    UIModule/Comm/mytargetbutton.cpp \
    UIModule/Comm/mytoolbutton.cpp \
    UIModule/Comm/mywidgetfolder.cpp \
    UIModule/adddevicedlg.cpp \
    UIModule/addlibrarydlg.cpp \
    UIModule/addmonitorpositiondlg.cpp \
    UIModule/addtargetpersondlg.cpp \
    UIModule/addtargetpersonimagedlg.cpp \
    UIModule/addtemplatedlg.cpp \
    UIModule/editdevicedlg.cpp \
    UIModule/editmonitorareadlg.cpp \
    UIModule/editmonitorpositiondlg.cpp \
    UIModule/edittargetpersondlg.cpp \
    UIModule/facehistorycompare.cpp \
    UIModule/faceidentitydiscern.cpp \
    UIModule/faceonetonpane.cpp \
    UIModule/faceonetoonepane.cpp \
    UIModule/librarymanager.cpp \
    UIModule/logindialog.cpp \
    UIModule/mainwindow.cpp \
    UIModule/maptrackpane.cpp \
    UIModule/monitorareamaintain.cpp \
    UIModule/monitorconfigpane.cpp \
    UIModule/monitordevicemaintain.cpp \
    UIModule/monitorpositionmaintain.cpp \
    UIModule/realtimemonitorpane.cpp \
    UIModule/realwarningmanager.cpp \
    UIModule/selectmonitorpositiondlg.cpp \
    UIModule/targetpersonmanager.cpp \
    UIModule/templatemanager.cpp \
    UIModule/volumeaddtemplatedlg.cpp \
    UIModule/warningwidget.cpp \
    main.cpp \
    UIModule/warningdisposedlg.cpp \
    qroundprogressbar.cpp \
    UIModule/Comm/mycomparedimage.cpp \
    UIModule/Comm/mysearchedit.cpp \
    UIModule/Comm/mytwoimagecomparepane.cpp \
    UIModule/Comm/facehistoryimageitem.cpp \
    UIModule/Comm/maptrackitem.cpp \
    UIModule/Comm/mytablewidget.cpp \
    UIModule/warningdismonareadialog.cpp \
    UIModule/warningdisdelsuredialog.cpp \
    UIModule/Comm/mycheckboxheaderview.cpp \
    UIModule/addmonitorareadlg.cpp \
    UIModule/warningdismonposdialog.cpp \
    UIModule/addmonitordevicedialog.cpp \
    UIModule/editmonitordevicedialog.cpp \
    UIModule/Comm/targetpersonimageitem.cpp \
    UIModule/Comm/deleteconfirmationdlg.cpp \
    UIModule/Comm/templateitem.cpp \
    UIModule/batchaddtemplatedlg.cpp \
    UIModule/editlibrarydlg.cpp \
    UIModule/Comm/noticedlg.cpp \
    UIModule/Comm/realwarningitem.cpp \
    UIModule/Comm/warningdisposdlg.cpp

FORMS += \
    UIModule/adddevicedlg.ui \
    UIModule/addlibrary.ui \
    UIModule/addmonitorpositiondlg.ui \
    UIModule/addtargetperson.ui \
    UIModule/addtargetpersonimage.ui \
    UIModule/addtemplate.ui \
    UIModule/editdevicedlg.ui \
    UIModule/editmonitorareadlg.ui \
    UIModule/editmonitorpositiondlg.ui \
    UIModule/edittargetperson.ui \
    UIModule/facehistorycompare.ui \
    UIModule/faceidentitydiscern.ui \
    UIModule/faceonetonpane.ui \
    UIModule/librarymanager.ui \
    UIModule/logindialog.ui \
    UIModule/maptrackpane.ui \
    UIModule/monitorareamaintain.ui \
    UIModule/monitorconfigpane.ui \
    UIModule/monitordevicemaintain.ui \
    UIModule/monitorpositionmaintain.ui \
    UIModule/realwarningmanager.ui \
    UIModule/selectmonitorpositiondlg.ui \
    UIModule/targetpersonmanager.ui \
    UIModule/templatemanager.ui \
    UIModule/volumeaddtemplate.ui \
    UIModule/warnigdisposedlg.ui \
    UIModule/mainwindow.ui \
    UIModule/Comm/mytwoimagecomparepane.ui \
    UIModule/Comm/facehistoryimageitem.ui \
    UIModule/Comm/maptrackitem.ui \
    UIModule/Comm/mytablewidget.ui \
    UIModule/warningdismonareadialog.ui \
    UIModule/warningdisdelsuredialog.ui \
    UIModule/addmonitorareadlg.ui \
    UIModule/warningdismonposdialog.ui \
    UIModule/addmonitordevicedialog.ui \
    UIModule/editmonitordevicedialog.ui \
    UIModule/Comm/targetpersonimageitem.ui \
    UIModule/deletetargetperson.ui \
    UIModule/Comm/templateitem.ui \
    UIModule/batchaddtemplatedlg.ui \
    UIModule/editlibrarydlg.ui \
    UIModule/Comm/noticedlg.ui \
    UIModule/Comm/realwarningitem.ui \
    UIModule/Comm/warningdisposdlg.ui

RESOURCES += \
    Resouce.qrc

DISTFILES += \
    stylesheet.qss \
    config.ini
