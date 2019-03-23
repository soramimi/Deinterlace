
QT       += core gui widgets

TARGET = Deinterlace
TEMPLATE = app

CONFIG += c++11

DESTDIR = $$PWD/_bin

SOURCES += \
	main.cpp \
	MainWindow.cpp \
	ImageWidget.cpp \
    Deinterlace.cpp

HEADERS += \
	MainWindow.h \
	ImageWidget.h \
    Deinterlace.h

FORMS += \
	MainWindow.ui

