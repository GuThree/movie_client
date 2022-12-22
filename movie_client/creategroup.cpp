#include "creategroup.h"
#include "ui_creategroup.h"

CreateGroup::CreateGroup(QTcpSocket *s, QString u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroup)
{
    ui->setupUi(this);
    socket = s;
    userName = u;
}

CreateGroup::~CreateGroup()
{
    delete ui;
}

// 点击取消创建群聊
void CreateGroup::on_cancelButton_clicked()
{
    this->close();
}

// 创建群聊按钮被点击
void CreateGroup::on_createButton_clicked()
{
    QString groupName = ui->lineEdit->text();
    QJsonObject obj;
    obj.insert("cmd", "create_group");
    obj.insert("user", userName);
    obj.insert("group", groupName);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    this->close();
}
