QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calculator/s21_calculator.c \
    ../calculator/s21_parser.c \
    ../calculator/s21_polish_notation.c \
    ../calculator/s21_stack.c \
    ../calculator/s21_validator.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../s21_SmartCalculator.h \
    ../s21_SmartCalculator.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

ICON = calculator_icon.icns


TRANSLATIONS += \
    SmarCalcv1_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
