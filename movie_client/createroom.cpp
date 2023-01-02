#include "createroom.h"
#include "ui_createroom.h"

CreateRoom::CreateRoom(QTcpSocket *s, QString u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateRoom)
{
    ui->setupUi(this);
    socket = s;
    userName = u;
}

CreateRoom::~CreateRoom()
{
    delete ui;
}

// 点击取消创建群聊
void CreateRoom::on_cancelButton_clicked()
{
    this->close();
}

// 创建群聊按钮被点击
void CreateRoom::on_createButton_clicked()
{
    QString roomid = ui->lineEdit->text();
    QJsonObject obj;
    obj.insert("cmd", "create_room");
    obj.insert("username", userName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    this->close();
}
