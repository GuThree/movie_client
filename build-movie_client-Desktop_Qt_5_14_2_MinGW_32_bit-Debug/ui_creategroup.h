/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGroup
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *createButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *CreateGroup)
    {
        if (CreateGroup->objectName().isEmpty())
            CreateGroup->setObjectName(QString::fromUtf8("CreateGroup"));
        CreateGroup->resize(400, 300);
        label = new QLabel(CreateGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 100, 101, 31));
        lineEdit = new QLineEdit(CreateGroup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 100, 211, 31));
        createButton = new QPushButton(CreateGroup);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(80, 190, 80, 20));
        cancelButton = new QPushButton(CreateGroup);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 190, 80, 20));

        retranslateUi(CreateGroup);

        QMetaObject::connectSlotsByName(CreateGroup);
    } // setupUi

    void retranslateUi(QWidget *CreateGroup)
    {
        CreateGroup->setWindowTitle(QCoreApplication::translate("CreateGroup", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateGroup", "<html><head/><body><p align=\"center\">\345\210\233\345\273\272\347\276\244\350\201\212\345\220\215\347\247\260</p></body></html>", nullptr));
        createButton->setText(QCoreApplication::translate("CreateGroup", "\345\210\233\345\273\272", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateGroup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroup: public Ui_CreateGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
