TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    record.h \
    open_hash.h \
    ../chained_hash/chained_hash.h \
    worker_report.h \
    output.h
