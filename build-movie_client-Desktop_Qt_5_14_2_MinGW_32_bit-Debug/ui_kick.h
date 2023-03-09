/********************************************************************************
** Form generated from reading UI file 'kick.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KICK_H
#define UI_KICK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Kick
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *kickButton;

    void setupUi(QWidget *Kick)
    {
        if (Kick->objectName().isEmpty())
            Kick->setObjectName(QString::fromUtf8("Kick"));
        Kick->resize(300, 400);
        Kick->setMinimumSize(QSize(300, 400));
        Kick->setMaximumSize(QSize(300, 400));
        Kick->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        verticalLayout = new QVBoxLayout(Kick);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Kick);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        kickButton = new QPushButton(Kick);
        kickButton->setObjectName(QString::fromUtf8("kickButton"));
        kickButton->setMinimumSize(QSize(0, 30));
        kickButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));

        verticalLayout->addWidget(kickButton);


        retranslateUi(Kick);

        QMetaObject::connectSlotsByName(Kick);
    } // setupUi

    void retranslateUi(QWidget *Kick)
    {
        Kick->setWindowTitle(QCoreApplication::translate("Kick", "Form", nullptr));
        kickButton->setText(QCoreApplication::translate("Kick", "\350\270\242\345\207\272\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kick: public Ui_Kick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KICK_H
