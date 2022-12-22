/********************************************************************************
** Form generated from reading UI file 'addgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUP_H
#define UI_ADDGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGroup
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *AddGroup)
    {
        if (AddGroup->objectName().isEmpty())
            AddGroup->setObjectName(QString::fromUtf8("AddGroup"));
        AddGroup->resize(400, 300);
        label = new QLabel(AddGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 81, 31));
        lineEdit = new QLineEdit(AddGroup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 100, 191, 31));
        addButton = new QPushButton(AddGroup);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(70, 200, 80, 20));
        cancelButton = new QPushButton(AddGroup);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 200, 80, 20));

        retranslateUi(AddGroup);

        QMetaObject::connectSlotsByName(AddGroup);
    } // setupUi

    void retranslateUi(QWidget *AddGroup)
    {
        AddGroup->setWindowTitle(QCoreApplication::translate("AddGroup", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddGroup", "<html><head/><body><p align=\"center\">\346\267\273\345\212\240\347\276\244\345\217\267</p></body></html>", nullptr));
        addButton->setText(QCoreApplication::translate("AddGroup", "\346\267\273\345\212\240", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddGroup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroup: public Ui_AddGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUP_H
