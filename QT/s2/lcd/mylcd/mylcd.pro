CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(myqlcdplugin)
TEMPLATE    = lib

HEADERS     = myqlcdplugin.h
SOURCES     = myqlcdplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = /home2/users/alumnes/1181392/dades/idi/qt/s2/designer
INSTALLS    += target

include(myqlcd.pri)
