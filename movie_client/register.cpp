#include "register.h"
#include "ui_register.h"

Register::Register(QTcpSocket *s, Widget * w, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    socket = s;
    widget = w;

    connect(socket, &QTcpSocket::readyRead, this, &Register::server_reply);
}

Register::~Register()
{
    delete ui;
}

// 服务器回复行为
void Register::server_reply()
{
    QByteArray ba = socket->readAll();
    QJsonObject obj = QJsonDocument::fromJson(ba).object();
    QString cmd = obj.value("cmd").toString();
    if (cmd == "register_reply")
    {
        client_register_handler(obj.value("result").toString());
    }
}

// 注册按钮被点击
void Register::on_registerButton_clicked()
{
    QString username = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();
    QString nickname = ui->nameLineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "register");
    obj.insert("username", username);
    obj.insert("nickname", nickname);
    obj.insert("password", password);

    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 去登录按钮被点击
void Register::on_loginButton_clicked()
{
    socket->disconnect(SIGNAL(readyRead()));
    widget->back_page();
    QDesktopWidget *desktop = QApplication::desktop();
    widget->move((desktop->width() - widget->width())/ 2, (desktop->height() - widget->height()) /2);
    widget->show();
    this->close();
}

// 注册后服务器回复处理
void Register::client_register_handler(QString res)
{
    if (res == "success")
    {
        QMessageBox::information(this, "注册提示", "注册成功");
    }
    else if (res == "failure")
    {
        QMessageBox::warning(this, "注册提示", "注册失败");
    }
}
