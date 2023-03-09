/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addfriend
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *addfriendButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Addfriend)
    {
        if (Addfriend->objectName().isEmpty())
            Addfriend->setObjectName(QString::fromUtf8("Addfriend"));
        Addfriend->resize(400, 300);
        Addfriend->setMinimumSize(QSize(400, 300));
        Addfriend->setMaximumSize(QSize(400, 300));
        Addfriend->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        label = new QLabel(Addfriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 70, 30));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        lineEdit = new QLineEdit(Addfriend);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 100, 200, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"border-radius:7px;"));
        addfriendButton = new QPushButton(Addfriend);
        addfriendButton->setObjectName(QString::fromUtf8("addfriendButton"));
        addfriendButton->setGeometry(QRect(240, 200, 80, 30));
        addfriendButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        cancelButton = new QPushButton(Addfriend);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(80, 200, 80, 30));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));

        retranslateUi(Addfriend);

        QMetaObject::connectSlotsByName(Addfriend);
    } // setupUi

    void retranslateUi(QWidget *Addfriend)
    {
        Addfriend->setWindowTitle(QCoreApplication::translate("Addfriend", "Form", nullptr));
        label->setText(QCoreApplication::translate("Addfriend", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\245\275\345\217\213\350\264\246\345\217\267</span></p></body></html>", nullptr));
        addfriendButton->setText(QCoreApplication::translate("Addfriend", "\346\267\273\345\212\240", nullptr));
        cancelButton->setText(QCoreApplication::translate("Addfriend", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addfriend: public Ui_Addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
