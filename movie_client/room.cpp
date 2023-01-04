#include "room.h"
#include "ui_room.h"

Room::Room(QTcpSocket *s, QString r, QString u, Chatlist *c, QList<RoomWidgetInfo> *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
    socket = s;
    roomid = r;
    userName = u;
    mainWidget = c;
    roomWidgetList = l;

    QJsonObject obj;
    obj.insert("cmd", "get_room_member");
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    connect(mainWidget, &Chatlist::signal_to_sub_widget_member, this, &Room::show_room_member);
    connect(mainWidget, &Chatlist::signal_to_sub_widget_room, this, &Room::show_room_text);
}

Room::~Room()
{
    delete ui;
}

// 发送群聊消息
void Room::on_sendButton_clicked()
{
    QString text = ui->lineEdit->text();
    QJsonObject obj;
    obj.insert("cmd", "room_chat");
    obj.insert("username", userName);
    obj.insert("roomid", roomid);
    obj.insert("text", text);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    ui->lineEdit->clear();
    ui->textBrowser->append(text);
    ui->textBrowser->append("\n");
}

// 展示房间成员
void Room::show_room_member(QJsonObject obj)
{
    if (obj.value("cmd").toString() == "get_room_member_reply")
    {
        if (obj.value("roomid").toString() == roomid)
        {
            ui->listWidget->clear();
            QStringList strList = obj.value("member").toString().split("|");
            for (int i = 0; i < strList.size(); i++)
            {
                ui->listWidget->addItem(strList.at(i));
            }
        }
    }
}

// 显示房间成员发送的消息
void Room::show_room_text(QJsonObject obj)
{
    if (obj.value("cmd").toString() == "room_chat")
    {
        if (obj.value("roomid").toString() == roomid)
        {
            if (this->isMinimized())
            {
                this->showNormal();
            }
            this->activateWindow();
            ui->textBrowser->append(obj.value("text").toString());
            ui->textBrowser->append("\n");
        }
    }
}

// 点击退出房间
void Room::on_leaveButton_clicked()
{
    for (int i = 0; i < roomWidgetList->size(); i++)
    {
        if (roomWidgetList->at(i).name == roomid)
        {
            roomWidgetList->removeAt(i);
        }
    }
    this->close();
}

// 关闭对话框
void Room::closeEvent(QCloseEvent * event)
{
    for (int i = 0; i < roomWidgetList->size(); i++)
    {
        if (roomWidgetList->at(i).name == roomid)
        {
            roomWidgetList->removeAt(i);
        }
    }
    event->accept();
}


