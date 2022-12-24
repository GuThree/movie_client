/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *userLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *passwdLineEdit;
    QPushButton *registerButton;
    QPushButton *loginButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(420, 720);
        Register->setMinimumSize(QSize(420, 720));
        Register->setMaximumSize(QSize(420, 720));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 110, 70, 40));
        label->setMinimumSize(QSize(70, 40));
        label->setMaximumSize(QSize(70, 40));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 210, 70, 40));
        label_2->setMinimumSize(QSize(70, 40));
        label_2->setMaximumSize(QSize(70, 40));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 310, 70, 40));
        label_3->setMinimumSize(QSize(70, 40));
        label_3->setMaximumSize(QSize(70, 40));
        userLineEdit = new QLineEdit(Register);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setGeometry(QRect(130, 115, 250, 30));
        userLineEdit->setMinimumSize(QSize(250, 30));
        userLineEdit->setMaximumSize(QSize(250, 30));
        nameLineEdit = new QLineEdit(Register);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(130, 215, 250, 30));
        nameLineEdit->setMinimumSize(QSize(250, 30));
        nameLineEdit->setMaximumSize(QSize(250, 30));
        passwdLineEdit = new QLineEdit(Register);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setGeometry(QRect(130, 315, 250, 30));
        passwdLineEdit->setMinimumSize(QSize(250, 30));
        passwdLineEdit->setMaximumSize(QSize(250, 30));
        registerButton = new QPushButton(Register);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(40, 510, 340, 40));
        registerButton->setMinimumSize(QSize(340, 40));
        registerButton->setMaximumSize(QSize(340, 40));
        loginButton = new QPushButton(Register);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(40, 590, 340, 40));
        loginButton->setMinimumSize(QSize(340, 40));
        loginButton->setMaximumSize(QSize(340, 40));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\230\265\347\247\260</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        registerButton->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        loginButton->setText(QCoreApplication::translate("Register", "\345\216\273\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
