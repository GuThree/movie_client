#ifndef INVITED_H
#define INVITED_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class Invited;
}

class Invited : public QWidget
{
    Q_OBJECT

public:
    explicit Invited(QTcpSocket *s, QString r, QString u, QString n, QString f, QWidget *parent = nullptr);
    ~Invited();

private slots:
    void on_enterButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Invited *ui;
    QTcpSocket *socket;
    QString userName;
    QString nickName;
    QString your_friend;
    QString roomid;
};

#endif // INVITED_H
