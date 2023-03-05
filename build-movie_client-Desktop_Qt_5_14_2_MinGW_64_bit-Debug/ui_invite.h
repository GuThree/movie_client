/********************************************************************************
** Form generated from reading UI file 'invite.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITE_H
#define UI_INVITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Invite
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *inviteButton;

    void setupUi(QWidget *Invite)
    {
        if (Invite->objectName().isEmpty())
            Invite->setObjectName(QString::fromUtf8("Invite"));
        Invite->resize(300, 400);
        Invite->setMinimumSize(QSize(300, 400));
        Invite->setMaximumSize(QSize(300, 400));
        verticalLayout = new QVBoxLayout(Invite);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Invite);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        inviteButton = new QPushButton(Invite);
        inviteButton->setObjectName(QString::fromUtf8("inviteButton"));
        inviteButton->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(inviteButton);


        retranslateUi(Invite);

        QMetaObject::connectSlotsByName(Invite);
    } // setupUi

    void retranslateUi(QWidget *Invite)
    {
        Invite->setWindowTitle(QCoreApplication::translate("Invite", "Form", nullptr));
        inviteButton->setText(QCoreApplication::translate("Invite", "\351\202\200\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Invite: public Ui_Invite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITE_H
