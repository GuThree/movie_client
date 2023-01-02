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
#include <QtWidgets/QListView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Room
{
public:
    QFrame *frame;
    QTextBrowser *textBrowser;
    QListView *listView;

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
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(Room);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1040, 310, 290, 450));
        listView = new QListView(Room);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(1040, 30, 290, 270));

        retranslateUi(Room);

        QMetaObject::connectSlotsByName(Room);
    } // setupUi

    void retranslateUi(QWidget *Room)
    {
        Room->setWindowTitle(QCoreApplication::translate("Room", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Room: public Ui_Room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_H
