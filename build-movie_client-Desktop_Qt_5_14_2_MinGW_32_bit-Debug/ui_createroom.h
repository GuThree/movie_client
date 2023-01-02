/********************************************************************************
** Form generated from reading UI file 'createroom.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEROOM_H
#define UI_CREATEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateRoom
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *createButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *CreateRoom)
    {
        if (CreateRoom->objectName().isEmpty())
            CreateRoom->setObjectName(QString::fromUtf8("CreateRoom"));
        CreateRoom->resize(400, 300);
        CreateRoom->setMinimumSize(QSize(400, 300));
        CreateRoom->setMaximumSize(QSize(400, 300));
        label = new QLabel(CreateRoom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 70, 30));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));
        lineEdit = new QLineEdit(CreateRoom);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 100, 200, 30));
        createButton = new QPushButton(CreateRoom);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(240, 200, 80, 30));
        cancelButton = new QPushButton(CreateRoom);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(80, 200, 80, 30));

        retranslateUi(CreateRoom);

        QMetaObject::connectSlotsByName(CreateRoom);
    } // setupUi

    void retranslateUi(QWidget *CreateRoom)
    {
        CreateRoom->setWindowTitle(QCoreApplication::translate("CreateRoom", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateRoom", "<html><head/><body><p align=\"center\">\345\210\233\345\273\272\346\210\277\351\227\264</p></body></html>", nullptr));
        createButton->setText(QCoreApplication::translate("CreateRoom", "\345\210\233\345\273\272", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateRoom", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateRoom: public Ui_CreateRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROOM_H
