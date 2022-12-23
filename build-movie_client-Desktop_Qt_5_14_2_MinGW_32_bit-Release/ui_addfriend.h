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
        label = new QLabel(Addfriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 120, 81, 31));
        lineEdit = new QLineEdit(Addfriend);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 120, 251, 20));
        addfriendButton = new QPushButton(Addfriend);
        addfriendButton->setObjectName(QString::fromUtf8("addfriendButton"));
        addfriendButton->setGeometry(QRect(70, 210, 80, 20));
        cancelButton = new QPushButton(Addfriend);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 210, 80, 20));

        retranslateUi(Addfriend);

        QMetaObject::connectSlotsByName(Addfriend);
    } // setupUi

    void retranslateUi(QWidget *Addfriend)
    {
        Addfriend->setWindowTitle(QCoreApplication::translate("Addfriend", "Form", nullptr));
        label->setText(QCoreApplication::translate("Addfriend", "<html><head/><body><p align=\"center\">\345\245\275\345\217\213\350\264\246\345\217\267</p></body></html>", nullptr));
        addfriendButton->setText(QCoreApplication::translate("Addfriend", "\346\267\273\345\212\240", nullptr));
        cancelButton->setText(QCoreApplication::translate("Addfriend", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addfriend: public Ui_Addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
