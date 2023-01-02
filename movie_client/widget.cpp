#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress("47.112.153.10"), 8000);

    connect(socket, &QTcpSocket::connected, this, &Widget::connect_success);
    connect(socket, &QTcpSocket::readyRead, this, &Widget::server_reply);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect_success()
{
    QMessageBox::information(this, "连接提示", "连接服务器成功");
}

// 服务器回复行为
void Widget::server_reply()
{
    QByteArray ba = socket->readAll();
    QJsonObject obj = QJsonDocument::fromJson(ba).object();
    QString cmd = obj.value("cmd").toString();
    if (cmd == "login_reply")
    {
        client_login_handler(obj.value("result").toString(), obj.value("friend").toString());
    }
}

void Widget::back_page()
{
    connect(socket, &QTcpSocket::readyRead, this, &Widget::server_reply);
}

// 登录按钮被点击
void Widget::on_loginButton_clicked()
{
    QString username = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "login");
    obj.insert("username", username);
    obj.insert("password", password);

    userName = username;

    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 去注册按钮被点击
void Widget::on_registerButton_clicked()
{
    this->hide();
    socket->disconnect(SIGNAL(readyRead()));
    Register *registerWidget = new Register(socket, this);
    registerWidget->setWindowTitle("注册");
    QDesktopWidget *desktop = QApplication::desktop();
    registerWidget->move((desktop->width() - registerWidget->width())/ 2, (desktop->height() - registerWidget->height()) /2);
    registerWidget->show();
}

// 登录后服务器回复处理
void Widget::client_login_handler(QString res, QString fri)
{
    if (res == "user_not_exist")
    {
        QMessageBox::warning(this, "登录提示", "用户不存在");
    }
    else if (res == "password_error")
    {
        QMessageBox::warning(this, "登录提示", "密码错误");
    }
    else if (res == "success")
    {
        this->hide();
        socket->disconnect(SIGNAL(readyRead()));
        Chatlist *c = new Chatlist(socket, fri, userName);
        c->setWindowTitle(userName);
        c->show();
    }
}
