QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chifoumi.cpp \
    main.cpp \
    chifoumivue.cpp

HEADERS += \
    chifoumi.h \
    chifoumivue.h

FORMS += \
    chifoumivue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/ciseau.gif \
    images/ciseau_115.png \
    images/papier.gif \
    images/papier_115.png \
    images/pierre.gif \
    images/pierre_115.png \
    images/rien.gif \
    images/rien_115.png \
    images/versus.gif \
    images/versus_70.png

RESOURCES += \
    images.qrc
