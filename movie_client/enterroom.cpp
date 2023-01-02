#include "enterroom.h"
#include "ui_enterroom.h"

EnterRoom::EnterRoom(QTcpSocket *s, QString u, QString n, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterRoom)
{
    ui->setupUi(this);
    socket = s;
    userName = u;
    nickName = n;
}

EnterRoom::~EnterRoom()
{
    delete ui;
}

void EnterRoom::on_enterButton_clicked()
{
    QString roomid = ui->lineEdit->text();
    QJsonObject obj;
    obj.insert("cmd", "enter_room");
    obj.insert("username", userName);
    obj.insert("nickname", nickName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    this->close();
}

void EnterRoom::on_cancelButton_clicked()
{
    this->close();
}
