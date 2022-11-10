QT       += core gui
include(QtGifImage/src/gifimage/qtgifimage.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    View.cpp \
    model.cpp \
    opengl_widget.cpp
HEADERS += \
    controller.h \
    View.h \
    model.h \
    opengl_widget.h \
    obj_data.h \
    settings.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    obj_loader.qrc

DISTFILES += \
    Resources/settings.conf \
    settings.conf
