QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _AFXDLL
LIBS += -lgdi32 -luser32

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/ui

# cpp_utl
DEFINES += BOOST_ASIO_STANDALONE
PATH_CPP_UTL = $$PWD/cpp_utility
INCLUDEPATH += $$PATH_CPP_UTL
               $$PATH_CPP_UTL/3rdpaty

//LIBS += -L$$PATH_CPP_UTL/lib/ -lcpp_utl

# cpp_utl/3rdparty
PATH_CPP_UTL_3RDPARTY = $$PATH_CPP_UTL/3rdparty
INCLUDEPATH += $$PATH_CPP_UTL_3RDPARTY/

# cpp_utl/3rdparty/opencv
PATH_OPENCV = $$PATH_CPP_UTL_3RDPARTY/opencv-3.4.1-win
INCLUDEPATH += $$PATH_OPENCV/include
INCLUDEPATH += $$PATH_OPENCV/include/opencv
INCLUDEPATH += $$PATH_OPENCV/include/opencv2

//LIBS += -L$$PATH_OPENCV/x64/vc14/lib/ -lopencv_world341

SOURCES += \
    main.cpp \
    main_window.cpp \
    qdbmanagepage.cpp \
    qdetectionpage.cpp \
    qdevicedebugpage.cpp \
    qmainpage.cpp \
    qtempaturemonitorpage.cpp

HEADERS += \
    main_window.h \
    qdbmanagepage.h \
    qdetectionpage.h \
    qdevicedebugpage.h \
    qmainpage.h \
    qtempaturemonitorpage.h \
    widgetbase.h

FORMS += \
    main_window.ui

RESOURCES += \
    resource/ui/styles/style_app.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
