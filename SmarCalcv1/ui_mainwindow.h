/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_sign;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_div;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_5;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_0;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_right;
    QPushButton *pushButton_x;
    QPushButton *pushButton_left;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_log;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_plot;
    QPushButton *pushButton_exp;
    QLabel *label;
    QLineEdit *lineEdit_X;
    QSpinBox *min_X;
    QLabel *label_2;
    QSpinBox *max_X;
    QLabel *label_3;
    QSpinBox *min_Y;
    QLabel *label_4;
    QSpinBox *max_Y;
    QLabel *label_5;
    QCustomPlot *Grafic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(951, 379);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("calculator_icon.icns");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("calculator_icon.icns"), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_show = new QLabel(centralwidget);
        result_show->setObjectName("result_show");
        result_show->setGeometry(QRect(0, 10, 471, 71));
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	qproperty-alignment:  'AlignVCenter | AlignRight';\n"
"}\n"
""));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName("pushButton_AC");
        pushButton_AC->setGeometry(QRect(0, 80, 61, 61));
        pushButton_sign = new QPushButton(centralwidget);
        pushButton_sign->setObjectName("pushButton_sign");
        pushButton_sign->setGeometry(QRect(70, 80, 61, 61));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(140, 80, 61, 61));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(210, 80, 61, 61));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(1, 140, 60, 61));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(140, 139, 61, 61));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName("pushButton_mult");
        pushButton_mult->setGeometry(QRect(210, 139, 61, 61));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(70, 139, 61, 61));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 200, 61, 61));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(140, 200, 61, 61));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(210, 200, 61, 61));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(70, 200, 61, 61));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(0, 260, 61, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 260, 61, 61));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(140, 260, 61, 61));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(210, 260, 61, 61));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(0, 320, 131, 61));
        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName("pushButton_equals");
        pushButton_equals->setGeometry(QRect(210, 320, 61, 61));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(140, 320, 61, 61));
        pushButton_right = new QPushButton(centralwidget);
        pushButton_right->setObjectName("pushButton_right");
        pushButton_right->setGeometry(QRect(420, 139, 61, 61));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(350, 139, 61, 61));
        pushButton_left = new QPushButton(centralwidget);
        pushButton_left->setObjectName("pushButton_left");
        pushButton_left->setGeometry(QRect(280, 139, 61, 61));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(280, 200, 61, 61));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(350, 200, 61, 61));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(420, 200, 61, 61));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(280, 260, 61, 61));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(350, 260, 61, 61));
        pushButton_acos->setIconSize(QSize(16, 16));
        pushButton_acos->setCheckable(false);
        pushButton_acos->setAutoRepeat(false);
        pushButton_acos->setAutoExclusive(false);
        pushButton_acos->setAutoDefault(false);
        pushButton_acos->setFlat(false);
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(420, 260, 61, 61));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(280, 320, 61, 61));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(350, 320, 61, 61));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(420, 320, 61, 61));
        pushButton_plot = new QPushButton(centralwidget);
        pushButton_plot->setObjectName("pushButton_plot");
        pushButton_plot->setGeometry(QRect(280, 80, 61, 61));
        pushButton_exp = new QPushButton(centralwidget);
        pushButton_exp->setObjectName("pushButton_exp");
        pushButton_exp->setGeometry(QRect(350, 80, 61, 61));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 90, 61, 16));
        lineEdit_X = new QLineEdit(centralwidget);
        lineEdit_X->setObjectName("lineEdit_X");
        lineEdit_X->setGeometry(QRect(420, 110, 61, 21));
        lineEdit_X->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        min_X = new QSpinBox(centralwidget);
        min_X->setObjectName("min_X");
        min_X->setGeometry(QRect(597, 345, 61, 31));
        min_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        min_X->setMinimum(-1000000);
        min_X->setMaximum(1000000);
        min_X->setValue(-10);
        min_X->setDisplayIntegerBase(10);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 330, 51, 16));
        max_X = new QSpinBox(centralwidget);
        max_X->setObjectName("max_X");
        max_X->setGeometry(QRect(667, 345, 61, 31));
        max_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max_X->setMinimum(-1000000);
        max_X->setMaximum(1000000);
        max_X->setValue(10);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(670, 330, 51, 16));
        min_Y = new QSpinBox(centralwidget);
        min_Y->setObjectName("min_Y");
        min_Y->setGeometry(QRect(737, 345, 61, 31));
        min_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        min_Y->setMinimum(-1000000);
        min_Y->setMaximum(1000000);
        min_Y->setValue(-10);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(740, 330, 51, 16));
        max_Y = new QSpinBox(centralwidget);
        max_Y->setObjectName("max_Y");
        max_Y->setGeometry(QRect(807, 345, 61, 31));
        max_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max_Y->setMinimum(-1000000);
        max_Y->setMaximum(1000000);
        max_Y->setValue(10);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(810, 330, 51, 16));
        Grafic = new QCustomPlot(centralwidget);
        Grafic->setObjectName("Grafic");
        Grafic->setGeometry(QRect(520, 50, 401, 271));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        pushButton_acos->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_sign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_right->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_left->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_plot->setText(QCoreApplication::translate("MainWindow", "PLOT", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Input x", nullptr));
        lineEdit_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "min X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "max X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "min Y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "max Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
