TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    stringtokenizer.cpp \
    token.cpp \
    table_function.cpp

HEADERS += \
    stringtokenizer.h \
    token.h \
    output.h \
    worker_report.h \
    table_function.h
