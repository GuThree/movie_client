#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QList>
#include <QCloseEvent>
#include <QHash>
#include "addfriend.h"
#include "enterroom.h"
#include "sendthread.h"
#include "recvthread.h"


class Room;
#include "room.h"

class PrivateChat;
#include "privatechat.h"

namespace Ui {
class Chatlist;
}

struct ChatWidgetInfo
{
    PrivateChat *w;
    QString name;
};

struct RoomWidgetInfo
{
    Room *w;
    QString name;
};

class Chatlist : public QWidget
{
    Q_OBJECT

public:
    explicit Chatlist(QTcpSocket *, QString, QString, QString, QWidget *parent = nullptr);
    ~Chatlist();
    void closeEvent(QCloseEvent *);

private slots:
    void server_reply();
    void on_addFriendButton_clicked();
    void on_friendList_double_clicked();
    void on_createRoomButton_clicked();
    void on_enterRoomButton_clicked();

signals:
    void signal_to_sub_widget(QJsonObject);
    void signal_to_sub_widget_member(QJsonObject);
    void signal_to_sub_widget_room(QJsonObject);

private:
    void client_login_reply(QString);
    void client_nickname_reply(QString);
    void client_add_friend_reply(QJsonObject &obj);
    void client_create_room_reply(QJsonObject &obj);
    void client_enter_room_reply(QJsonObject &obj);
    void client_private_chat_reply(QString);
    void client_chat_reply(QJsonObject &);
    void client_get_room_member_reply(QJsonObject);
    void client_room_chat_reply(QJsonObject);
    void client_send_file_reply(QString);
    void client_send_file_port_reply(QJsonObject);
    void client_recv_file_port_reply(QJsonObject);

    Ui::Chatlist *ui;
    QTcpSocket *socket;
    QString userName;
    QString nickName;
    QHash<QString, QString> friendlist;
    QList<ChatWidgetInfo> chatWidgetList;           // 现有打开的所有好友聊天窗口信息
    QList<RoomWidgetInfo> roomWidgetList;         // 现有打开的所有群组聊天窗口信息
};

#endif // CHATLIST_H
