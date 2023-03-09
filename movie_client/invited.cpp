#include "invited.h"
#include "ui_invited.h"

Invited::Invited(QTcpSocket *s, QString r, QString u, QString n, QString f, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Invited)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/icon.png"));
    socket = s;
    roomid = r;
    userName = u;
    nickName = n;
    your_friend = f;

    ui->label->setText("您的好友"+your_friend+"邀请你进入TA的房间");
}

Invited::~Invited()
{
    delete ui;
}

void Invited::on_enterButton_clicked()
{
    QJsonObject obj;
    obj.insert("cmd", "enter_room");
    obj.insert("username", userName);
    obj.insert("nickname", nickName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    this->close();
}

void Invited::on_cancelButton_clicked()
{
    this->close();
}
