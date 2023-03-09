/********************************************************************************
** Form generated from reading UI file 'enterroom.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERROOM_H
#define UI_ENTERROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterRoom
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *cancelButton;
    QPushButton *enterButton;

    void setupUi(QWidget *EnterRoom)
    {
        if (EnterRoom->objectName().isEmpty())
            EnterRoom->setObjectName(QString::fromUtf8("EnterRoom"));
        EnterRoom->resize(400, 300);
        EnterRoom->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        label = new QLabel(EnterRoom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 70, 30));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        lineEdit = new QLineEdit(EnterRoom);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 100, 200, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"border-radius:7px;"));
        cancelButton = new QPushButton(EnterRoom);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(80, 200, 80, 30));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        enterButton = new QPushButton(EnterRoom);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(240, 200, 80, 30));
        enterButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));

        retranslateUi(EnterRoom);

        QMetaObject::connectSlotsByName(EnterRoom);
    } // setupUi

    void retranslateUi(QWidget *EnterRoom)
    {
        EnterRoom->setWindowTitle(QCoreApplication::translate("EnterRoom", "Form", nullptr));
        label->setText(QCoreApplication::translate("EnterRoom", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\210\277\345\217\267</span></p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("EnterRoom", "\345\217\226\346\266\210", nullptr));
        enterButton->setText(QCoreApplication::translate("EnterRoom", "\345\212\240\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterRoom: public Ui_EnterRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERROOM_H
