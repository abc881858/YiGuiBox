#-------------------------------------------------
#
# Project created by QtCreator 2013-09-03T13:11:44
#
#-------------------------------------------------

QT       += core gui sql network

CONFIG += qt3dquick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = one
TEMPLATE = app

TRANSLATIONS+=app_zh_CN.ts
CONFIG += localize_deployment

SOURCES += main.cpp \
    pageone.cpp \
    button.cpp \
    allkey.cpp \
    pagetwo.cpp \
    pagethree.cpp \
    pagefour.cpp \
    pagefive.cpp \
    pagesix.cpp \
    return.cpp \
    mainwindow.cpp \
    carousel.cpp \
    pagenine.cpp \
    pageten.cpp \
    popitem.cpp \
    client.cpp \
    pagea.cpp \
    pageb.cpp \
    pagec.cpp \
    paged.cpp \
    pagef.cpp \
    pageg.cpp \
    pageh.cpp \
    pagej.cpp \
    pagek.cpp \
    pagel.cpp \
    pagem.cpp \
    pagen.cpp \
    pageo.cpp \
    pagep.cpp \
    pageq.cpp \
    pager.cpp \
    pages.cpp \
    paget.cpp \
    pageu.cpp \
    pagew.cpp \
    pagex.cpp \
    pagey.cpp \
    pagez.cpp \
    pageother.cpp \
    pageusual.cpp \
    pageflipview.cpp \
    pageflipmath.cpp \
    pageflipgradienteffect.cpp \
    sqlquerymodel.cpp \
    settings.cpp \
    pagefour3.cpp

HEADERS  += \
    pageone.h \
    button.h \
    allkey.h \
    pagetwo.h \
    pagethree.h \
    pagefour.h \
    pagefive.h \
    pagesix.h \
    return.h \
    mainwindow.h \
    carousel.h \
    pagenine.h \
    pageten.h \
    popitem.h \
    client.h \
    pagea.h \
    pageb.h \
    pagec.h \
    paged.h \
    pagef.h \
    pageg.h \
    pageh.h \
    pagej.h \
    pagek.h \
    pagel.h \
    pagem.h \
    pagen.h \
    pageo.h \
    pagep.h \
    pageq.h \
    pager.h \
    pages.h \
    paget.h \
    pageu.h \
    pagew.h \
    pagex.h \
    pagey.h \
    pagez.h \
    pageother.h \
    pageusual.h \
    pageflipview.h \
    pageflipmath.h \
    pageflipgradienteffect.h \
    sqlquerymodel.h \
    settings.h \
    pagefour3.h

OTHER_FILES +=

RESOURCES += \
    image.qrc
LIBS += -lqextserialport
LIBS += -ldoor -lopencvCamera -lICReader -lscanMode

### -lgprs

target.path=/home/love/test
INSTALLS+=target
