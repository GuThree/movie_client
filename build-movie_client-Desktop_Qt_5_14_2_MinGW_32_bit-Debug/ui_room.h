/********************************************************************************
** Form generated from reading UI file 'room.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_H
#define UI_ROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <openglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Room
{
public:
    QFrame *frame;
    QPushButton *videoButton;
    QPushButton *kickButton;
    OpenglWidget *openglWidget;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QListWidget *listWidget;
    QPushButton *inviteButton;
    QPushButton *leaveButton;

    void setupUi(QWidget *Room)
    {
        if (Room->objectName().isEmpty())
            Room->setObjectName(QString::fromUtf8("Room"));
        Room->resize(1360, 790);
        Room->setMinimumSize(QSize(1360, 790));
        Room->setMaximumSize(QSize(1360, 790));
        frame = new QFrame(Room);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 30, 1000, 730));
        frame->setMinimumSize(QSize(1000, 730));
        frame->setMaximumSize(QSize(1000, 730));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        videoButton = new QPushButton(frame);
        videoButton->setObjectName(QString::fromUtf8("videoButton"));
        videoButton->setGeometry(QRect(810, 700, 80, 30));
        kickButton = new QPushButton(frame);
        kickButton->setObjectName(QString::fromUtf8("kickButton"));
        kickButton->setGeometry(QRect(900, 700, 80, 30));
        openglWidget = new OpenglWidget(frame);
        openglWidget->setObjectName(QString::fromUtf8("openglWidget"));
        openglWidget->setGeometry(QRect(0, 0, 1000, 680));
        textBrowser = new QTextBrowser(Room);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1040, 310, 290, 410));
        textBrowser->setMinimumSize(QSize(290, 410));
        textBrowser->setMaximumSize(QSize(290, 410));
        lineEdit = new QLineEdit(Room);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1040, 730, 240, 30));
        lineEdit->setMinimumSize(QSize(240, 30));
        lineEdit->setMaximumSize(QSize(240, 30));
        sendButton = new QPushButton(Room);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(1280, 730, 50, 30));
        sendButton->setMinimumSize(QSize(50, 30));
        sendButton->setMaximumSize(QSize(50, 30));
        listWidget = new QListWidget(Room);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(1040, 70, 290, 230));
        listWidget->setMinimumSize(QSize(290, 230));
        listWidget->setMaximumSize(QSize(290, 230));
        inviteButton = new QPushButton(Room);
        inviteButton->setObjectName(QString::fromUtf8("inviteButton"));
        inviteButton->setGeometry(QRect(1040, 30, 130, 30));
        leaveButton = new QPushButton(Room);
        leaveButton->setObjectName(QString::fromUtf8("leaveButton"));
        leaveButton->setGeometry(QRect(1200, 30, 130, 30));

        retranslateUi(Room);

        QMetaObject::connectSlotsByName(Room);
    } // setupUi

    void retranslateUi(QWidget *Room)
    {
        Room->setWindowTitle(QCoreApplication::translate("Room", "Form", nullptr));
        videoButton->setText(QCoreApplication::translate("Room", "\351\200\211\346\213\251\350\247\206\351\242\221", nullptr));
        kickButton->setText(QCoreApplication::translate("Room", "\350\270\242\345\207\272\346\210\220\345\221\230", nullptr));
        sendButton->setText(QCoreApplication::translate("Room", "\345\217\221\351\200\201", nullptr));
        inviteButton->setText(QCoreApplication::translate("Room", "\351\202\200\350\257\267\345\245\275\345\217\213", nullptr));
        leaveButton->setText(QCoreApplication::translate("Room", "\351\200\200\345\207\272\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Room: public Ui_Room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_H
