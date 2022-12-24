#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>

class Widget;
#include "widget.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QTcpSocket *, Widget *, QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();
    void server_reply();

private:
    void client_register_handler(QString);

    Ui::Register *ui;
    QTcpSocket *socket;
    Widget *widget;
};

#endif // REGISTER_H
