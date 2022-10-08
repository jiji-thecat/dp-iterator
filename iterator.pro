QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickable-label.cpp \
    creature-char-iterator.cpp \
    creature-char.cpp \
    creature-list-iterator.cpp \
    creature-list.cpp \
    creature-vector-iterator.cpp \
    creature-vector.cpp \
    creature.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    aggregate-interface.h \
    clickable-label.h \
    creature-char-iterator.h \
    creature-char.h \
    creature-list-iterator.h \
    creature-list.h \
    creature-vector-iterator.h \
    creature-vector.h \
    creature.h \
    iterator-interface.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
