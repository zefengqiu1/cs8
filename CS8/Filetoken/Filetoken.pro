TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ../strtoken/stringtokenizer.cpp \
    ../strtoken/table.cpp \
    ../strtoken/token.cpp

HEADERS += \
    ../strtoken/stringtokenizer.h \
    ../strtoken/table.h \
    ../strtoken/token.h \
    FileTokenizer.h \
    output.h \
    worker_report.h
