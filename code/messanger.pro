QT       += core gui \
    quick
QT+=network
QT+=concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    channelmsgthread.cpp \
    createjoinchannels.cpp \
    createjoingroups.cpp \
    file.cpp \
    groupmsgthread.cpp \
    listupdatethread.cpp \
    login1.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    newuserchats.cpp \
    request.cpp \
    signup.cpp \
    thread1.cpp \
    user.cpp \
    usermsgthread.cpp

HEADERS += \
    channelmsgthread.h \
    createjoinchannels.h \
    createjoingroups.h \
    file.h \
    groupmsgthread.h \
    listupdatethread.h \
    login1.h \
    mainwindow.h \
    message.h \
    newuserchats.h \
    request.h \
    signup.h \
    thread1.h \
    user.h \
    usermsgthread.h

FORMS += \
    createjoinchannels.ui \
    createjoingroups.ui \
    login1.ui \
    mainwindow.ui \
    newuserchats.ui \
    signup.ui \
    thread1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
