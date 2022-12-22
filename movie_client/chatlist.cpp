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

//    connect(ui->friendList, &QListWidget::itemDoubleClicked, this, &Chatlist::on_friendList_double_clicked);
//    connect(ui->groupList, &QListWidget::itemDoubleClicked, this, &Chatlist::on_groupList_double_clicked);

}

Chatlist::~Chatlist()
{
    delete ui;
}

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
}

void Chatlist::client_login_reply(QString fri)
{
    QString str = QString("%1好友上线").arg(fri);
    QMessageBox::information(this, "好友上线提醒", str);
}

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


//

void Chatlist::on_addFriendButton_clicked()
{
    Addfriend *addFriendWidget = new Addfriend(socket, userName);
    addFriendWidget->show();
}

void Chatlist::on_createGroupButton_clicked()
{
    CreateGroup *createGroupWidget = new CreateGroup(socket, userName);
    createGroupWidget->show();
}
