#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QList>
#include "addfriend.h"
#include "creategroup.h"
//#include "addgroup.h"
//#include "sendthread.h"
//#include "recvthread.h"

namespace Ui {
class Chatlist;
}

class Chatlist : public QWidget
{
    Q_OBJECT

public:
    explicit Chatlist(QTcpSocket *, QString, QString, QString, QWidget *parent = nullptr);
    ~Chatlist();

private slots:
    void server_reply();

    void on_addFriendButton_clicked();

    void on_createGroupButton_clicked();

private:
    void client_login_reply(QString);
    void client_add_friend_reply(QJsonObject &obj);
    void client_create_group_reply(QJsonObject &obj);
//    void client_add_group_reply(QJsonObject &obj);
//    void client_private_chat_reply(QString);
//    void client_chat_reply(QJsonObject &);
//    void client_get_group_member_reply(QJsonObject);
//    void client_group_chat_reply(QJsonObject);
//    void client_send_file_reply(QString);
//    void client_send_file_port_reply(QJsonObject);
//    void client_recv_file_port_reply(QJsonObject);
//    void client_friend_offline(QString fri);

    Ui::Chatlist *ui;
    QTcpSocket *socket;
    QString userName;
//    QList<ChatWidgetInfo> chatWidgetList;
//    QList<groupWidgetInfo> groupWidgetList;
};

#endif // CHATLIST_H
