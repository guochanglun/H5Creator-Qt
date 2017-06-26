#-------------------------------------------------
#
# Project created by QtCreator 2017-06-07T14:20:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = h5Creator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    glabel.cpp \
    gimage.cpp \
    const.cpp \
    styledialog.cpp \
    animationdialog.cpp \
    gtranslateanimationbox.cpp \
    translateanimation.cpp \
    ganimation.cpp \
    gscaleanimation.cpp \
    gscaleanimationbox.cpp \
    attrdialog.cpp \
    gattribute.cpp \
    state.cpp \
    page.cpp \
    gpageoption.cpp \
    gresourcedialog.cpp \
    gimagesrcdialog.cpp \
    gtextchangedialog.cpp \
    gstagedialog.cpp

HEADERS  += mainwindow.h \
    glabel.h \
    gimage.h \
    const.h \
    styledialog.h \
    animationdialog.h \
    gtranslateanimationbox.h \
    translateanimation.h \
    ganimation.h \
    gscaleanimation.h \
    gscaleanimationbox.h \
    attrdialog.h \
    gattribute.h \
    state.h \
    page.h \
    gpageoption.h \
    gresourcedialog.h \
    gimagesrcdialog.h \
    gtextchangedialog.h \
    gstagedialog.h

FORMS    += \
    mainwindow.ui \
    styledialog.ui \
    animationdialog.ui \
    attrdialog.ui \
    gpageoption.ui \
    gresourcedialog.ui \
    gimagesrcdialog.ui \
    gtextchangedialog.ui \
    gstagedialog.ui

RESOURCES += \
    sec.qrc
