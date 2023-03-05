#include "chatlist.h"
#include "ui_chatlist.h"

Chatlist::Chatlist(QTcpSocket *s, QString fri_id, QString fri_nick, QString u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chatlist)
{
    ui->setupUi(this);
    userName = u;
    socket = s;
    connect(socket, &QTcpSocket::readyRead, this, &Chatlist::server_reply);

    // 陈列用户的好友和群聊内容
    QStringList f_id = fri_id.split('|');
    QStringList f_nick = fri_nick.split('|');
    for (int i = 0; i < f_id.size(); i++)
    {
        if (f_id.at(i) != "")
        {
            friendlist[f_id.at(i)] = f_nick.at(i);
            ui->friendList->addItem(f_nick.at(i));
        }
    }

    // 获取该用户昵称
    QJsonObject obj;
    obj.insert("cmd", "get_nick");
    obj.insert("username", userName);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    connect(ui->friendList, &QListWidget::itemDoubleClicked, this, &Chatlist::on_friendList_double_clicked);
}

Chatlist::~Chatlist()
{
    delete ui;
}

// 服务器回复行为
void Chatlist::server_reply(){
    QByteArray ba = socket->readAll();
    QJsonObject obj = QJsonDocument::fromJson(ba).object();
    QString cmd = obj.value("cmd").toString();
    if (cmd == "friend_login")
    {
        client_login_reply(obj.value("friend").toString());
    }
    else if (cmd == "nickname_reply")
    {
        client_nickname_reply(obj.value("nickname").toString());
    }
    else if (cmd == "add_reply")
    {
        client_add_friend_reply(obj);
    }
    else if (cmd == "add_friend_reply")
    {
        QString str = QString("%1把你添加为好友").arg(obj.value("result").toString());
        QMessageBox::information(this, "添加好友提醒", str);
        friendlist[obj.value("result").toString()] = obj.value("nickname").toString();
        ui->friendList->addItem(obj.value("nickname").toString());
        for (int i = 0; i < roomWidgetList.size(); i++)
        {
            roomWidgetList.at(i).w->reset_friends(friendlist);
        }
    }
    else if (cmd == "create_room_reply")
    {
        client_create_room_reply(obj);
    }
    else if (cmd == "enter_room_reply")
    {
        client_enter_room_reply(obj);
    }
    else if (cmd == "invite_reply")
    {
        client_invite_room_reply(obj);
    }
    else if (cmd == "leave_room_reply")
    {
        client_leave_room_reply(obj);
    }
    else if (cmd == "private_chat_reply")
    {
        client_private_chat_reply(obj.value("result").toString());
    }
    else if (cmd == "private_chat")
    {
        client_chat_reply(obj);
    }
    else if (cmd == "get_room_member_reply")
    {
        client_get_room_member_reply(obj);
    }
    else if (cmd == "room_chat")
    {
        client_room_chat_reply(obj);
    }
    else if (cmd == "send_file_reply")
    {
        client_send_file_reply(obj.value("result").toString());
    }
    else if (cmd == "send_file_port_reply")
    {
        client_send_file_port_reply(obj);
    }
    else if (cmd == "recv_file_port_reply")
    {
        client_recv_file_port_reply(obj);
    }
}

// 好友登录服务器提醒用户
void Chatlist::client_login_reply(QString fri)
{
    QString str = QString("%1好友上线").arg(fri);
    QMessageBox::information(this, "好友上线提醒", str);
}

// 在服务器获取用户昵称
void Chatlist::client_nickname_reply(QString nick)
{
    this->nickName = nick;
    this->setWindowTitle(nickName);
}

// 添加好友后服务器回复
void Chatlist::client_add_friend_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "user_not_exist")
    {
        QMessageBox::warning(this, "添加好友提醒", "好友不存在");
    }
    else if (obj.value("result").toString() == "already_friend")
    {
        QMessageBox::warning(this, "添加好友提醒", "已经是好友关系");
    }
    else if (obj.value("result").toString() == "success")
    {
        QMessageBox::information(this, "添加好友提醒", "好友添加成功");
        friendlist[obj.value("friend_id").toString()] = obj.value("friend_nick").toString();
        ui->friendList->addItem(obj.value("friend_nick").toString());
        for (int i = 0; i < roomWidgetList.size(); i++)
        {
            roomWidgetList.at(i).w->reset_friends(friendlist);
        }
    }
}

// 创建房间后服务器回复
void Chatlist::client_create_room_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "room_exist")
    {
        QString roomid;
        char c;
        for(int i = 0; i < 6; i++)
        {
            if (rand()%2)
                c = '0' + rand()%9;
            else
                c = 'a' + rand()%26;
            roomid.push_back(c);
        }
        QJsonObject obj;
        obj.insert("cmd", "create_room");
        obj.insert("username", userName);
        obj.insert("roomid", roomid);
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    }
    else if (obj.value("result").toString() == "success")
    {
        Room *room = new Room(socket, obj.value("roomid").toString(), userName, nickName, this, friendlist, &roomWidgetList, true);
        room->setWindowTitle("("+nickName+") "+"房间号:"+obj.value("roomid").toString());
        room->show();
        RoomWidgetInfo rr = {room, obj.value("roomid").toString()};
        roomWidgetList.push_back(rr);
    }
}

// 进入房间后服务器回复
void Chatlist::client_enter_room_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "room_not_exist")
    {
        QMessageBox::warning(this, "添加房间提示", "房间不存在");
    }
    else if (obj.value("result").toString() == "user_in_room")
    {
        QMessageBox::warning(this, "添加房间提示", "已经在房间里面");
    }
    else if (obj.value("result").toString() == "success")
    {
        Room *room = new Room(socket, obj.value("roomid").toString(), userName, nickName, this, friendlist, &roomWidgetList, false);
        room->setWindowTitle("("+nickName+") "+"房间号:"+obj.value("roomid").toString());
        room->show();
        RoomWidgetInfo rr = {room, obj.value("roomid").toString()};
        roomWidgetList.push_back(rr);
    }
    else if (obj.value("result").toString() == "someone_in")
    {
        QJsonObject o;
        o.insert("cmd", "get_room_member");
        o.insert("roomid", obj.value("roomid").toString());
        QByteArray ba = QJsonDocument(o).toJson();
        socket->write(ba);
    }
}

// 邀请好友服务器回复
void Chatlist::client_invite_room_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "success")
    {
        Invited *invited = new Invited(socket, obj.value("roomid").toString(), userName, nickName, obj.value("inviter").toString());
        invited->setWindowTitle("收到好友邀请");
        invited->show();
    }
}

// 离开房间后服务器回复
void Chatlist::client_leave_room_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "success")
    {
        QJsonObject o;
        o.insert("cmd", "get_room_member");
        o.insert("roomid", obj.value("roomid").toString());
        QByteArray ba = QJsonDocument(o).toJson();
        socket->write(ba);
    }
}

// 服务器回复发送端私聊请求
void Chatlist::client_private_chat_reply(QString res)
{
    if (res == "offline")
    {
        QMessageBox::warning(this, "发送提醒", "对方不在线");
    }
}

// 服务器回复接收端私聊请求
void Chatlist::client_chat_reply(QJsonObject &obj)
{
    int flag = 0;
    // 遍历现有打开的聊天窗口，如果已经打开了就不再打开
    for (int i = 0; i < chatWidgetList.size(); i++)
    {
        if (chatWidgetList.at(i).name == obj.value("user_from").toString())
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)   // 聊天窗口没有打开过
    {
        QString friendName = obj.value("user_from").toString();
        PrivateChat *privateChatWidget = new PrivateChat(socket, userName, friendName, this, &chatWidgetList);
        privateChatWidget->setWindowTitle(friendName);
        privateChatWidget->show();

        ChatWidgetInfo c = {privateChatWidget, friendName};
        chatWidgetList.push_back(c);
    }

    emit signal_to_sub_widget(obj);
}

// 服务器回应获取房间成员
void Chatlist::client_get_room_member_reply(QJsonObject obj)
{
    emit signal_to_sub_widget_member(obj);
}

// 群聊有消息变动时服务器回复
void Chatlist::client_room_chat_reply(QJsonObject obj)
{
    emit signal_to_sub_widget_room(obj);
}

// 服务器回复文件发送端传输文件功能异常
void Chatlist::client_send_file_reply(QString res)
{
    if (res == "offline")
    {
        QMessageBox::warning(this, "发送文件提醒", "对方不在线");
    }
    else if (res == "timeout")
    {
        QMessageBox::warning(this, "发送文件提醒", "连接超时");
    }
}

// 服务器回复文件发送端可创建线程进行传输
void Chatlist::client_send_file_port_reply(QJsonObject obj)
{
    SendThread *mySendthread = new SendThread(obj);
    mySendthread->start();
}

// 服务器回复文件接收端可创建线程接收对方文件
void Chatlist::client_recv_file_port_reply(QJsonObject obj)
{
    RecvThread *myRecvThread = new RecvThread(obj);
    myRecvThread->start();
}


/*-----下面是点击事件处理-----*/
// 添加好友按键被点击
void Chatlist::on_addFriendButton_clicked()
{
    Addfriend *addFriendWidget = new Addfriend(socket, userName);
    addFriendWidget->setWindowTitle("添加好友");
    addFriendWidget->show();
}

// 创建房间按键被点击
void Chatlist::on_createRoomButton_clicked()
{
    QString roomid;
    char c;
    for(int i = 0; i < 6; i++)
    {
        if (rand()%2)
            c = '0' + rand()%9;
        else
            c = 'a' + rand()%26;
        roomid.push_back(c);
    }
    QJsonObject obj;
    obj.insert("cmd", "create_room");
    obj.insert("username", userName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 进入房间按键被点击
void Chatlist::on_enterRoomButton_clicked()
{
    EnterRoom *enterRoomWidget = new EnterRoom(socket, userName, nickName);
    enterRoomWidget->setWindowTitle("进入房间");
    enterRoomWidget->show();
}

// 双击好友列表
void Chatlist::on_friendList_double_clicked()
{
    QString friendName = ui->friendList->currentItem()->text();
    PrivateChat *privateChatWidget = new PrivateChat(socket, userName, friendName, this, &chatWidgetList);
    privateChatWidget->setWindowTitle(friendName);
    privateChatWidget->show();

    ChatWidgetInfo c = {privateChatWidget, friendName};
    chatWidgetList.push_back(c);
}

// 关闭窗口
void Chatlist::closeEvent(QCloseEvent *event)
{
    QJsonObject obj;
    obj.insert("cmd", "offline");
    obj.insert("username", userName);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    socket->flush();

    // 关闭所有房间窗口和对话窗口
    while(roomWidgetList.size() > 0)
    {
        roomWidgetList.at(0).w->close();
    }
    while(chatWidgetList.size() > 0)
    {
        chatWidgetList.at(0).w->close();
    }

    event->accept();
}


