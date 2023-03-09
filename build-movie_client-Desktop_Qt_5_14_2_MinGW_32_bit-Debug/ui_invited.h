/********************************************************************************
** Form generated from reading UI file 'invited.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITED_H
#define UI_INVITED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Invited
{
public:
    QLabel *label;
    QPushButton *cancelButton;
    QPushButton *enterButton;

    void setupUi(QWidget *Invited)
    {
        if (Invited->objectName().isEmpty())
            Invited->setObjectName(QString::fromUtf8("Invited"));
        Invited->resize(360, 200);
        Invited->setMinimumSize(QSize(360, 200));
        Invited->setMaximumSize(QSize(360, 200));
        Invited->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        label = new QLabel(Invited);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 200, 30));
        label->setStyleSheet(QString::fromUtf8("border-radius:7px;\n"
"background-color:rgb(163, 183, 160);"));
        cancelButton = new QPushButton(Invited);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(50, 140, 80, 25));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        enterButton = new QPushButton(Invited);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(230, 140, 80, 25));
        enterButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));

        retranslateUi(Invited);

        QMetaObject::connectSlotsByName(Invited);
    } // setupUi

    void retranslateUi(QWidget *Invited)
    {
        Invited->setWindowTitle(QCoreApplication::translate("Invited", "Form", nullptr));
        label->setText(QCoreApplication::translate("Invited", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("Invited", "\345\217\226\346\266\210", nullptr));
        enterButton->setText(QCoreApplication::translate("Invited", "\350\277\233\345\205\245\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Invited: public Ui_Invited {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITED_H
