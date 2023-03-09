/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chatlist
{
public:
    QPushButton *addFriendButton;
    QPushButton *createRoomButton;
    QPushButton *enterRoomButton;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout;
    QListWidget *friendList;
    QWidget *tab_2;
    QLabel *usernamelabel;
    QLabel *nicknamelabel;

    void setupUi(QWidget *Chatlist)
    {
        if (Chatlist->objectName().isEmpty())
            Chatlist->setObjectName(QString::fromUtf8("Chatlist"));
        Chatlist->resize(360, 750);
        Chatlist->setMinimumSize(QSize(360, 750));
        Chatlist->setMaximumSize(QSize(360, 750));
        Chatlist->setStyleSheet(QString::fromUtf8("background-color:rgb(225, 229, 228);"));
        addFriendButton = new QPushButton(Chatlist);
        addFriendButton->setObjectName(QString::fromUtf8("addFriendButton"));
        addFriendButton->setGeometry(QRect(30, 680, 300, 30));
        addFriendButton->setMinimumSize(QSize(300, 30));
        addFriendButton->setMaximumSize(QSize(300, 30));
        addFriendButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        createRoomButton = new QPushButton(Chatlist);
        createRoomButton->setObjectName(QString::fromUtf8("createRoomButton"));
        createRoomButton->setGeometry(QRect(30, 620, 300, 30));
        createRoomButton->setMinimumSize(QSize(300, 30));
        createRoomButton->setMaximumSize(QSize(300, 30));
        createRoomButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        enterRoomButton = new QPushButton(Chatlist);
        enterRoomButton->setObjectName(QString::fromUtf8("enterRoomButton"));
        enterRoomButton->setGeometry(QRect(30, 560, 300, 30));
        enterRoomButton->setMinimumSize(QSize(300, 30));
        enterRoomButton->setMaximumSize(QSize(300, 30));
        enterRoomButton->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 183, 160);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-radius:7px;"));
        tabWidget = new QTabWidget(Chatlist);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 300, 500));
        tabWidget->setMinimumSize(QSize(300, 500));
        tabWidget->setMaximumSize(QSize(300, 500));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{\n"
"	width:110;\n"
"	font: 11pt \"\351\273\221\344\275\223\";\n"
"}"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout = new QVBoxLayout(tab_1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        friendList = new QListWidget(tab_1);
        friendList->setObjectName(QString::fromUtf8("friendList"));
        friendList->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(friendList);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        usernamelabel = new QLabel(tab_2);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));
        usernamelabel->setGeometry(QRect(0, 0, 300, 30));
        usernamelabel->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        nicknamelabel = new QLabel(tab_2);
        nicknamelabel->setObjectName(QString::fromUtf8("nicknamelabel"));
        nicknamelabel->setGeometry(QRect(0, 30, 300, 30));
        nicknamelabel->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Chatlist);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Chatlist);
    } // setupUi

    void retranslateUi(QWidget *Chatlist)
    {
        Chatlist->setWindowTitle(QCoreApplication::translate("Chatlist", "Form", nullptr));
        addFriendButton->setText(QCoreApplication::translate("Chatlist", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        createRoomButton->setText(QCoreApplication::translate("Chatlist", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        enterRoomButton->setText(QCoreApplication::translate("Chatlist", "\350\277\233\345\205\245\346\210\277\351\227\264", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("Chatlist", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("Chatlist", "\345\245\275\345\217\213", nullptr));
        usernamelabel->setText(QString());
        nicknamelabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Chatlist", "\344\270\252\344\272\272\347\251\272\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chatlist: public Ui_Chatlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
