QT += core
QT -= gui

TARGET = Processor_Management
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp

LIBS += -pthread
