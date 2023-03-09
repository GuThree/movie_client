/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userLineEdit;
    QLineEdit *passwdLineEdit;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLabel *label_3;
    QLabel *logo;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(420, 720);
        Widget->setMinimumSize(QSize(420, 720));
        Widget->setMaximumSize(QSize(420, 720));
        Widget->setStyleSheet(QString::fromUtf8("QWidget#Widget{\n"
"	background-color:rgb(225, 229, 228);\n"
"}\n"
"QPushButton#registerButton{\n"
"	background-color:rgb(163, 183, 160);\n"
"	border-radius:10px;\n"
"}\n"
"QPushButton#loginButton{\n"
"	background-color:rgb(163, 183, 160);\n"
"	border-radius:10px;\n"
"}\n"
"QLineEdit#userLineEdit{\n"
"	background-color:rgb(163, 183, 160);\n"
"	border-radius:5px;\n"
"}\n"
"QLineEdit#passwdLineEdit{\n"
"	background-color:rgb(163, 183, 160);\n"
"	border-radius:5px;\n"
"}\n"
""));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 240, 70, 40));
        label->setMinimumSize(QSize(70, 40));
        label->setMaximumSize(QSize(70, 40));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 350, 70, 40));
        label_2->setMinimumSize(QSize(70, 40));
        label_2->setMaximumSize(QSize(70, 40));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        userLineEdit = new QLineEdit(Widget);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setGeometry(QRect(130, 245, 250, 30));
        userLineEdit->setMinimumSize(QSize(250, 30));
        userLineEdit->setMaximumSize(QSize(250, 30));
        passwdLineEdit = new QLineEdit(Widget);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setGeometry(QRect(130, 355, 250, 30));
        passwdLineEdit->setMinimumSize(QSize(250, 30));
        passwdLineEdit->setMaximumSize(QSize(250, 30));
        registerButton = new QPushButton(Widget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(40, 590, 340, 40));
        registerButton->setMinimumSize(QSize(340, 40));
        registerButton->setMaximumSize(QSize(340, 40));
        registerButton->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(40, 510, 340, 40));
        loginButton->setMinimumSize(QSize(340, 40));
        loginButton->setMaximumSize(QSize(340, 40));
        loginButton->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 160, 60, 40));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        logo = new QLabel(Widget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(120, 40, 180, 72));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        registerButton->setText(QCoreApplication::translate("Widget", "\345\216\273\346\263\250\345\206\214", nullptr));
        loginButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
