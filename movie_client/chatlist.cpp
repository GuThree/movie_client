#include "chatlist.h"
#include "ui_chatlist.h"

Chatlist::Chatlist(QTcpSocket *s, QString fri, QString group, QString u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chatlist)
{
    ui->setupUi(this);
    userName = u;
    socket = s;
    connect(socket, &QTcpSocket::readyRead, this, &Chatlist::server_reply);

    // 陈列用户的好友和群聊内容
    QStringList friList = fri.split('|');
    for (int i = 0; i < friList.size(); i++)
    {
        if (friList.at(i) != "")
        {
            ui->friendList->addItem(friList.at(i));
        }
    }
    QStringList groList = group.split('|');
    for (int i = 0; i < groList.size(); i++)
    {
        if (groList.at(i) != "")
        {
            ui->groupList->addItem(groList.at(i));
        }
    }

    connect(ui->friendList, &QListWidget::itemDoubleClicked, this, &Chatlist::on_friendList_double_clicked);
    connect(ui->groupList, &QListWidget::itemDoubleClicked, this, &Chatlist::on_groupList_double_clicked);
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
    else if (cmd == "add_reply")
    {
        client_add_friend_reply(obj);
    }
    else if (cmd == "add_friend_reply")
    {
        QString str = QString("%1把你添加为好友").arg(obj.value("result").toString());
        QMessageBox::information(this, "添加好友提醒", str);
        ui->friendList->addItem(obj.value("result").toString());
    }
    else if (cmd == "create_group_reply")
    {
        client_create_group_reply(obj);
    }
    else if (cmd == "add_group_reply")
    {
        client_add_group_reply(obj);
    }
    else if (cmd == "private_chat_reply")
    {
        client_private_chat_reply(obj.value("result").toString());
    }
    else if (cmd == "private_chat")
    {
        client_chat_reply(obj);
    }
    else if (cmd == "get_group_member_reply")
    {
        client_get_group_member_reply(obj);
    }
    else if (cmd == "group_chat")
    {
        client_group_chat_reply(obj);
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
    else if (cmd == "friend_offline")
    {
        client_friend_offline(obj.value("friend").toString());
    }
}

// 好友登录服务器提醒用户
void Chatlist::client_login_reply(QString fri)
{
    QString str = QString("%1好友上线").arg(fri);
    QMessageBox::information(this, "好友上线提醒", str);
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
        ui->friendList->addItem(obj.value("friend").toString());
    }
}

// 创建群聊后服务器回复
void Chatlist::client_create_group_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "group_exist")
    {
        QMessageBox::warning(this, "创建群提示", "群已经存在");
    }
    else if (obj.value("result").toString() == "success")
    {
        ui->groupList->addItem(obj.value("group").toString());
    }
}

// 添加群聊后服务器回复
void Chatlist::client_add_group_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "group_not_exist")
    {
        QMessageBox::warning(this, "添加群提示", "群不存在");
    }
    else if (obj.value("result").toString() == "user_in_group")
    {
        QMessageBox::warning(this, "添加群提示", "已经在群里面");
    }
    else if (obj.value("result").toString() == "success")
    {
        ui->groupList->addItem(obj.value("group").toString());
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

// 服务器回应获取群成员
void Chatlist::client_get_group_member_reply(QJsonObject obj)
{
    emit signal_to_sub_widget_member(obj);
}

// 群聊有消息变动时服务器回复
void Chatlist::client_group_chat_reply(QJsonObject obj)
{
    int flag = 0;
    for (int i = 0; i < groupWidgetList.size(); i++)
    {
        if (groupWidgetList.at(i).name == obj.value("group").toString())
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        QString groupName = obj.value("group").toString();
        GroupChat *groupChatWidget = new GroupChat(socket, groupName, userName, this, &groupWidgetList);
        groupChatWidget->setWindowTitle(groupName);
        groupChatWidget->show();

        groupWidgetInfo g = {groupChatWidget, groupName};
        groupWidgetList.push_back(g);
    }

    emit signal_to_sub_widget_group(obj);
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

// 好友线下时服务器回复
void Chatlist::client_friend_offline(QString fri)
{
    QString str = QString("%1下线").arg(fri);
    QMessageBox::information(this, "下线提醒", str);
}

/*-----下面是点击事件处理-----*/

// 添加好友按键被点击
void Chatlist::on_addFriendButton_clicked()
{
    Addfriend *addFriendWidget = new Addfriend(socket, userName);
    addFriendWidget->show();
}

// 创建群聊按键被点击
void Chatlist::on_createGroupButton_clicked()
{
    CreateGroup *createGroupWidget = new CreateGroup(socket, userName);
    createGroupWidget->show();
}

// 添加群聊按键被点击
void Chatlist::on_addGroupButton_clicked()
{
    AddGroup *addGroupWidget = new AddGroup(socket, userName);
    addGroupWidget->show();
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

// 双击群聊列表
void Chatlist::on_groupList_double_clicked()
{
    QString groupName = ui->groupList->currentItem()->text();
    GroupChat *groupChatWidget = new GroupChat(socket, groupName, userName, this, &groupWidgetList);
    groupChatWidget->setWindowTitle(groupName);
    groupChatWidget->show();

    groupWidgetInfo g = {groupChatWidget, groupName};
    groupWidgetList.push_back(g);
}

// 关闭窗口
void Chatlist::closeEvent(QCloseEvent *event)
{
    QJsonObject obj;
    obj.insert("cmd", "offline");
    obj.insert("user", userName);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    socket->flush();

    event->accept();
}
