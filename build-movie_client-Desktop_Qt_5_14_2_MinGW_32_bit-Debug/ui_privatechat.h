/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrivateChat
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QPushButton *fileButton;

    void setupUi(QWidget *PrivateChat)
    {
        if (PrivateChat->objectName().isEmpty())
            PrivateChat->setObjectName(QString::fromUtf8("PrivateChat"));
        PrivateChat->resize(570, 460);
        PrivateChat->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        textEdit = new QTextEdit(PrivateChat);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 550, 300));
        lineEdit = new QLineEdit(PrivateChat);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 320, 550, 25));
        sendButton = new QPushButton(PrivateChat);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(380, 390, 80, 30));
        sendButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        fileButton = new QPushButton(PrivateChat);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        fileButton->setGeometry(QRect(60, 390, 80, 30));
        fileButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));

        retranslateUi(PrivateChat);

        QMetaObject::connectSlotsByName(PrivateChat);
    } // setupUi

    void retranslateUi(QWidget *PrivateChat)
    {
        PrivateChat->setWindowTitle(QCoreApplication::translate("PrivateChat", "Form", nullptr));
        sendButton->setText(QCoreApplication::translate("PrivateChat", "\345\217\221\351\200\201", nullptr));
        fileButton->setText(QCoreApplication::translate("PrivateChat", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrivateChat: public Ui_PrivateChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H
